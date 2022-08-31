#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 100
#define STR_COUNT 100
#include "my_functions.h"
/*!
\brief Функция считывает строки файла
\return количество строк файла - успешное считывание, -1 - ошибка.
*/
int read_array(char *path, int n[STR_COUNT], int a[STR_COUNT][STR_LEN])
{
    FILE *f;
    f = fopen(path, "r");
    if (!f)
    {
        printf("File not found!\n");
        return -1;
    }
    if(feof(f))
    {
        printf("Empty file\n");
        return -1;
    }
    int i = 0;
    /*while (!feof(f))
    {
        char str[STR_LEN];
        int count = 0;
        int j = 0;
        fgets(str, STR_LEN, f);
        fscanf(str[0], "%d", a[i][j]);
        printf("%d vvv\n", a[i][j]);
    }*/
    while (!feof(f))
    {
        char str[STR_LEN];
        str[0] = '\0';
        fgets(str, STR_LEN, f);
        if (str[STR_LEN - 2] != '\n' && str[STR_LEN - 2] != '\0')
        {
            printf("Too long string!\n");
            return -1;
        }
        char *tmp;
        tmp = strtok(str, " ");
        if (strlen(str) == 0)
        {
            printf("Empty string or file.\n");
            return -1;
        }
        n[i] = 0;
        a[i][0] = atoi(tmp);
        while (tmp != NULL)
        {
            n[i]++;
            tmp = strtok(NULL, " ");
            if (tmp != NULL)
            {
                a[i][n[i]] = atoi(tmp);
                if (a[i][n[i]] == 0)
                {
                    printf("Error!\n");
                    return -1;
                }
            }
        }
        i++;
    }
    fclose(f);
    return i;
}
/*!
\brief Функция сортирует числа строк.

Сортировка происходит следующим образом: сначала располагаются четные числа в порядке убывания, а затем нечетные в порядке возрастания.
\return 0 - успех.
*/
int print_error(char *path)
{
    FILE *f;
    f = fopen(path, "w");
    fprintf(f, "Error!");
    return 0;
}
int sort_array(int a[STR_COUNT][STR_LEN], int n[STR_COUNT], int count)
{
    for (int i = 0; i < count; i++)
    {
        int chet = 0;
        for(int j = 0; j < n[i]; j++)
        {
            if (a[i][j] % 2 == 0)
            {
                chet++;
                int tmp = a[i][j];
                for (int k = j - 1; k >= 0; k--)
                {
                    a[i][k + 1] = a[i][k];
                }
                a[i][0] = tmp;    
            } 
        }
        int flag = 1;
        do
        {
            flag = 0;
            for (int j = 1; j < chet; j++)
            {
                if (a[i][j] > a[i][j - 1])
                {
                    int tmp = a[i][j];
                    a[i][j] = a[i][j - 1];
                    a[i][j - 1] = tmp;
                    flag = 1;
                }
            }
        } while (flag);
        flag = 1;
        do
        {
            flag = 0;
            for (int j = chet + 1; j < n[i]; j++)
            {
                if (a[i][j] < a[i][j - 1])
                {
                    int tmp = a[i][j];
                    a[i][j] = a[i][j - 1];
                    a[i][j - 1] = tmp;
                    flag = 1;
                }
            }
        } while (flag);
    }
    return 0;
}
/*!
\brief Функция печатает строки в файл.
\return 0 - успех.
*/
int print_in_file(int a[STR_COUNT][STR_LEN], char *path, int count, int n[STR_COUNT])
{
    FILE *f;
    f = fopen(path, "w");
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < n[i]; j++)
        {
            fprintf(f, "%d ", a[i][j]);
        }
        fprintf(f, "\n");
    }   
    return 0; 
}