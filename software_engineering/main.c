/*!
\brief  Ввод всех строк файла, их сортировка, вывод отсортированных строк в файл.

Обрабатывает все строки файла посредством функций файла my_functions.c
Сортировка происходит следующим образом: сначала располагаются четные числа в порядке убывания, а затем нечетные в порядке возрастания
\return 0 - успех, 1 - ошибка.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_functions.h"
int main(int argc, char **argv)
{
    int n[STR_COUNT];
    int a[STR_COUNT][STR_LEN];
    int count = read_array(argv[1], n, a);
    if(count == -1)
    {
        print_error(argv[2]);
        return 1;
    }
    sort_array(a, n, count);
    print_in_file(a, argv[2], count, n);
}