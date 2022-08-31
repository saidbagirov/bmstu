#include <stdio.h>
#include "my_functions.h"
int sorts_array_positive_test(int expected_result_array[STR_COUNT][STR_LEN], int expected_error)
{
    //int actual_result_array[STR_COUNT][STR_LEN];
    int input_n[STR_COUNT] = {7, 6};
    int input_count = 2;
    int input_array[STR_COUNT][STR_LEN] = {{2, 4, 7, 8, 1, 5, -4}, {-5, -4, 5, 4, 3, 7}};
    int error = sort_array(input_array, input_n, input_count);
    if (error != expected_error)
    {
        return 1;
    }
    for (int i = 0; i < input_count; i++)
    {
        for (int j = 0; j < input_n[i]; j++)
        {
            if (input_array[i][j] != expected_result_array[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}
int sorts_array_positive_with_one_str(int expected_result_array[STR_COUNT][STR_LEN], int expected_error)
{
    //int actual_result_array[STR_COUNT][STR_LEN];
    int input_n[STR_COUNT] = {12};
    int input_count = 1;
    int input_array[STR_COUNT][STR_LEN] = {{2, 4, 7, 8, 1, 5, -4, 1, 7, 2, 8, -3}};
    int error = sort_array(input_array, input_n, input_count);
    if (error != expected_error)
    {
        return 1;
    }
    for (int i = 0; i < input_count; i++)
    {
        for (int j = 0; j < input_n[i]; j++)
        {
            if (input_array[i][j] != expected_result_array[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}
int sorts_array_positive_with_one_number_in_str(int expected_result_array[STR_COUNT][STR_LEN], int expected_error)
{
    //int actual_result_array[STR_COUNT][STR_LEN];
    int input_n[STR_COUNT] = {1, 6};
    int input_count = 2;
    int input_array[STR_COUNT][STR_LEN] = {{2}, {-5, -4, 5, 4, 3, 7}};
    int error = sort_array(input_array, input_n, input_count);
    if (error != expected_error)
    {
        return 1;
    }
    for (int i = 0; i < input_count; i++)
    {
        for (int j = 0; j < input_n[i]; j++)
        {
            //printf("%d %d\n", input_array[i][j], expected_result_array[i][j]);
            if (input_array[i][j] != expected_result_array[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}
int sorts_array_positive_with_only_even_or_only_odd_numbers(int expected_result_array[STR_COUNT][STR_LEN], int expected_error)
{
    //int actual_result_array[STR_COUNT][STR_LEN];
    int input_n[STR_COUNT] = {6, 6};
    int input_count = 2;
    int input_array[STR_COUNT][STR_LEN] = {{2, 4, -66, -78, 78, 42}, {-5, 3, 5, -77, 3, 7}};
    int error = sort_array(input_array, input_n, input_count);
    if (error != expected_error)
    {
        return 1;
    }
    for (int i = 0; i < input_count; i++)
    {
        for (int j = 0; j < input_n[i]; j++)
        {
            //printf("%d %d\n", input_array[i][j], expected_result_array[i][j]);
            if (input_array[i][j] != expected_result_array[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}
int sorts_array_positive_with_hundred_str(int expected_result_array[STR_COUNT][STR_LEN], int expected_error)
{
    //int actual_result_array[STR_COUNT][STR_LEN];
    int input_n[STR_COUNT] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
    int input_count = 100;
    int input_array[STR_COUNT][STR_LEN] = {{2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}, 
                                           {2, 4, -66, -78, 78, 42}};
    int error = sort_array(input_array, input_n, input_count);
    if (error != expected_error)
    {
        return 1;
    }
    for (int i = 0; i < input_count; i++)
    {
        for (int j = 0; j < input_n[i]; j++)
        {
            //printf("%d %d\n", input_array[i][j], expected_result_array[i][j]);
            if (input_array[i][j] != expected_result_array[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int failed_tests = 0;
    int total_tests = 0;
    int positive_expected_input_with_hundred_str[STR_COUNT][STR_LEN] = {{78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78},
                                                                        {78, 42, 4, 2, -66, -78}};
    int positive_expected_input_with_only_add_or_even_numbers[STR_COUNT][STR_LEN] = {{78, 42, 4, 2, -66, -78}, {-77, -5, 3, 3, 5, 7}}; 
    int positive_expected_input_with_one_number_in_str[STR_COUNT][STR_LEN] = {{2}, {4, -4, -5, 3, 5, 7}};
    int positive_expected_input_with_one_str[STR_COUNT][STR_LEN] = {{8, 8, 4, 2, 2, -4, -3, 1, 1, 5, 7, 7}};
    int positive_expected_input_array[STR_COUNT][STR_LEN] = {{8, 4, 2, -4, 1, 5, 7}, {4, -4, -5, 3, 5, 7}};
    failed_tests += sorts_array_positive_with_hundred_str(positive_expected_input_with_hundred_str, 0);
    total_tests++;
    failed_tests += sorts_array_positive_with_only_even_or_only_odd_numbers(positive_expected_input_with_only_add_or_even_numbers, 0);
    total_tests++;
    failed_tests += sorts_array_positive_with_one_number_in_str(positive_expected_input_with_one_number_in_str, 0);
    total_tests++;
    failed_tests += sorts_array_positive_test(positive_expected_input_array, 0);
    total_tests++;
    failed_tests += sorts_array_positive_with_one_str(positive_expected_input_with_one_str, 0);
    total_tests++;
    printf("Failed tests %d of %d", failed_tests, total_tests);
}