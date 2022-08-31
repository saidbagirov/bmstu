#include <stdio.h>
#include <stdlib.h>
#include "my_functions.h"
int size_of_file(FILE *f, size_t *size)
{
    if (fseek(f, 0L, SEEK_END))
    {
        return 1;
    }
    if (ftell(f) <= 0)
    {
        return 1;
    }
    *size = ftell(f);
    return fseek(f, 0L, SEEK_SET);
}
int print_nums(char *path)
{
    FILE *f;
    f = fopen(path, "rb");
    if (!f)
    {
        return 1;
    }
    int val;
    size_t size;
    if (!size_of_file(f, &size))
    {
        if (size % sizeof(int))
        {
            return 1;
        }
        for (int i = 0; i < size / sizeof(int); i++)
        {
            if (fread(&val, sizeof(int), 1, f) == 1)
            {
                printf("%d ", val);
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        return 1;
    }
    fclose(f);
    return 0;
}
int random_nums(char *path, int count)
{
    if (count < 1)
    {
        return 1;
    }
    FILE *f;
    f = fopen(path, "wb");
    if (!f)
    {
        return 1;
    }
    for (int i = 0; i < count; i++)
    {
        int value = rand() % 100;
        fwrite(&value, sizeof(int), 1, f);
    }
    fclose(f);
    return 0;
}
int get_number_by_pos(FILE *f, int pos)
{
    int num;
    fseek(f, pos, SEEK_SET);
    fread(&num, sizeof(int), 1, f);
    return num;
}
int put_number_by_pos(FILE *f, int *num, int pos)
{
    fseek(f, pos, SEEK_SET);
    fwrite(num, sizeof(int), 1, f);
    return 0;
}
int sorting(char *path)
{
    FILE *f;
    f = fopen(path, "rb+");
    if (!f)
    {
        return 1;
    }
    size_t size;
    if (size_of_file(f, &size))
    {
        return 1;
    }
    if (size % sizeof(int))
    {
        return 1;
    }
    int check;
    do
    {
        check = 0;
        for (int pos = sizeof(int); pos < size; pos += sizeof(int))
        {
            if (get_number_by_pos(f, pos) > get_number_by_pos(f, pos - sizeof(int)))
            {
                int tmp1 = get_number_by_pos(f, pos);
                int tmp2 = get_number_by_pos(f, pos - sizeof(int));
                put_number_by_pos(f, &tmp1, pos - sizeof(int));
                put_number_by_pos(f, &tmp2, pos);
                check = 1;
            }
        } 
    } while (check == 1);
    fclose(f);
    return 0;
}