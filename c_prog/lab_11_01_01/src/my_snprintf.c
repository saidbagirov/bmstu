#include "../inc/my_snprintf.h"
#include <stdarg.h>
#include <stdio.h>



void write_char(char *s, size_t n, int *len, char val)
{
    if (*len < n - 1)
        s[*len] = val;
    else if (*len < n)
        s[*len] = '\0';
    (*len)++;
}

void perform_d(char *s, size_t n, int *len, int val)
{
    unsigned int buf;
    if (val < 0)
    {
        write_char(s, n, len, '-');
        buf = -(unsigned int)val;
    }
    else 
        buf = val;
    
    int d = 1;
    while (buf / d > 9)
        d *= 10;
    
    while (d > 0)
    {
        write_char(s, n, len, '0' + buf / d % 10);
        d /= 10;
    }
}

void perform_x(char *s, size_t n, int *len, unsigned int val)
{
    int offset = sizeof(val) * 8 - 4;
    while ((val & (0xfu << offset)) == 0 && offset > 0)
        offset -= 4;

    while (offset >= 0)
    {
        int c = (val >> offset) & 0xf;
        if (c < 10)
            write_char(s, n, len, '0' + c);
        else
            write_char(s, n, len, 'a' + c - 10);

        offset -= 4;
    }
}

void perform_o(char *s, size_t n, int *len, unsigned int val)
{
    int offset = sizeof(val) * 8 - sizeof(val) * 8 % 3;
    while ((val & (0x7u << offset)) == 0 && offset > 0)
        offset -= 3;

    while (offset >= 0)
    {
        write_char(s, n, len, '0' + ((val >> offset) & 0x7u));

        offset -= 3;
    }
}

void perform_s(char *s, size_t n, int *len, const char *val)
{
    if (!val) 
        val = "(null)";
    while (*val)
    {
        write_char(s, n, len, *val);
        val++;
    }
}

int my_snprintf(char *s, size_t n, const char *format, ...)
{
    int result = -1;

    if (format && s)
    {
        va_list args;
        va_start(args, format);

        int len = 0;
        
        int in_spec = 0;
        int spaces;
        int l_count;
        const char *cur = format;
        int no_err = 1;
        while (*cur && no_err)
        {
            if (in_spec)
            {   
                switch (*cur)
                {
                    case 'c':
                        write_char(s, n, &len, va_arg(args, int));
                        in_spec = 0;
                        break;
                    case 'd':
                        while (spaces--)
                            write_char(s, n, &len, ' ');
                        perform_d(s, n, &len, va_arg(args, int));
                        in_spec = 0;
                        break;
                    case 'i':
                        perform_d(s, n, &len, va_arg(args, int));
                        in_spec = 0;
                        break;
                    case 'x':
                        perform_x(s, n, &len, va_arg(args, unsigned int));
                        in_spec = 0;
                        break;
                    case 'o':
                        perform_o(s, n, &len, va_arg(args, unsigned int));
                        in_spec = 0;
                        break;
                    case 's':
                        perform_s(s, n, &len, va_arg(args, const char *));
                        in_spec = 0;
                        break;
                    case '%':
                        write_char(s, n, &len, '%');
                        in_spec = 0;
                        break;
                    case ' ':
                        spaces++;
                        break;
                    case 'l':
                        l_count++;
                        break;
                    default:
                        write_char(s, n, &len, '%');
                        while (spaces--)
                            write_char(s, n, &len, ' ');
                        write_char(s, n, &len, *cur);
                }
            }
            else 
            {
                if (*cur == '%')
                {
                    in_spec = 1;
                    spaces = 0;
                    l_count = 0;
                }
                else
                    write_char(s, n, &len, *cur);
            }
            cur++;
        }

        va_end(args);
        if (len < n) 
            s[len] = '\0';
        else 
            s[n - 1] = '\0';
        result = len;   
    }

    return result;    
}