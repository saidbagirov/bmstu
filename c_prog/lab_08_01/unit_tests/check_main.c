#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../inc/inout.h"
#include "../inc/multiple.h"
#include "../inc/matrixtosqr.h"

int matrix_equal(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2)
{
    int result = 0;
    if(rows1 != rows2 || cols1 != cols2)
    {
        result = 1;
    }
    else
    {
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols1; j++)
            {
                if (matrix1[i][j] != matrix2[i][j])
                {
                    result = 1;
                    break;
                }
            }
        }
    }
    return result;
}

START_TEST(check_matrix_regular_multiple)
{
    int rows1 = 2;
    int cols1 = 2;
    int** matrix1 = calloc(2, sizeof(int*));
    matrix1[0] = calloc(2, sizeof(int));
    matrix1[1] = calloc(2, sizeof(int));
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;
    int** matrix2 = calloc(2, sizeof(int*));
    matrix2[0] = calloc(2, sizeof(int));
    matrix2[1] = calloc(2, sizeof(int));
    matrix2[0][0] = 1;
    matrix2[0][1] = 2;
    matrix2[1][0] = 3;
    matrix2[1][1] = 4;
    int **result = multiple(matrix1, rows1, cols1, matrix2, rows1, cols1);
    int** wanted_result = calloc(2, sizeof(int*));
    wanted_result[0] = calloc(2, sizeof(int));
    wanted_result[1] = calloc(2, sizeof(int));
    wanted_result[0][0] = 7;
    wanted_result[0][1] = 10;
    wanted_result[1][0] = 15;
    wanted_result[1][1] = 22;
    int equal = matrix_equal(result, 2, 2, wanted_result, 2, 2);
    free_matrix(wanted_result, 2);
    free_matrix(result, 2);
    ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(check_matrix_regular_to_sqr)
{
    int** matrix1 = calloc(2, sizeof(int*));
    matrix1[0] = calloc(3, sizeof(int));
    matrix1[1] = calloc(3, sizeof(int));
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[0][2] = 3;
    matrix1[1][0] = 3;
    matrix1[1][1] = 4;
    matrix1[1][2] = 4;
    int rows = 3, cols = 2;
    int **result = matrixtosqr(matrix1, &cols, &rows);
    int** wanted_result = calloc(2, sizeof(int*));
    wanted_result[0] = calloc(2, sizeof(int));
    wanted_result[1] = calloc(2, sizeof(int));
    wanted_result[0][0] = 1;
    wanted_result[0][1] = 3;
    wanted_result[1][0] = 3;
    wanted_result[1][1] = 4;
    int equal = matrix_equal(result, 2, 2, wanted_result, 2, 2);
    free_matrix(wanted_result, 2);
    free_matrix(result, 2);
    ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(check_matrix_regular_to_sqr_col)
{
    int** matrix1 = calloc(3, sizeof(int*));
    matrix1[0] = calloc(2, sizeof(int));
    matrix1[1] = calloc(2, sizeof(int));
    matrix1[2] = calloc(2, sizeof(int));
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[1][0] = 3;
    matrix1[1][1] = 3;
    matrix1[2][0] = 4;
    matrix1[2][1] = 4;
    int rows = 2, cols = 3;
    int **result = matrixtosqr(matrix1, &cols, &rows);
    int** wanted_result = calloc(2, sizeof(int*));
    wanted_result[0] = calloc(2, sizeof(int));
    wanted_result[1] = calloc(2, sizeof(int));
    wanted_result[0][0] = 1;
    wanted_result[0][1] = 2;
    wanted_result[1][0] = 3;
    wanted_result[1][1] = 3;
    int equal = matrix_equal(result, 2, 2, wanted_result, 2, 2);
    free_matrix(wanted_result, 2);
    free_matrix(result, 2);
    ck_assert_int_eq(equal, 0);
}
END_TEST


START_TEST(check_matrix_regular_exp)
{
    int** matrix1 = calloc(2, sizeof(int*));
    matrix1[0] = calloc(2, sizeof(int));
    matrix1[1] = calloc(2, sizeof(int));
    matrix1[0][0] = 1;
    matrix1[0][1] = 3;
    matrix1[1][0] = -1;
    matrix1[1][1] = 2;
    int cols = 2;
    int **result = exponentation(matrix1, cols, 3);
    int** wanted_result = calloc(2, sizeof(int*));
    wanted_result[0] = calloc(2, sizeof(int));
    wanted_result[1] = calloc(2, sizeof(int));
    wanted_result[0][0] = -11;
    wanted_result[0][1] = 12;
    wanted_result[1][0] = -4;
    wanted_result[1][1] = -7;
    int equal = matrix_equal(result, 2, 2, wanted_result, 2, 2);
    free_matrix(wanted_result, 2);
    free_matrix(result, 2);
    ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(check_matrix_regular_exp_0)
{
    int** matrix1 = calloc(2, sizeof(int*));
    matrix1[0] = calloc(2, sizeof(int));
    matrix1[1] = calloc(2, sizeof(int));
    matrix1[0][0] = 1;
    matrix1[0][1] = 3;
    matrix1[1][0] = -1;
    matrix1[1][1] = 2;
    int cols = 2;
    int **result = exponentation(matrix1, cols, 0);
    int** wanted_result = calloc(2, sizeof(int*));
    wanted_result[0] = calloc(2, sizeof(int));
    wanted_result[1] = calloc(2, sizeof(int));
    wanted_result[0][0] = 1;
    wanted_result[0][1] = 0;
    wanted_result[1][0] = 0;
    wanted_result[1][1] = 1;
    int equal = matrix_equal(result, 2, 2, wanted_result, 2, 2);
    free_matrix(wanted_result, 2);
    free_matrix(result, 2);
    ck_assert_int_eq(equal, 0);
}
END_TEST

Suite *calc_all_suite()
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("calc_all");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, check_matrix_regular_multiple);
    tcase_add_test(tc_pos, check_matrix_regular_to_sqr);
    tcase_add_test(tc_pos, check_matrix_regular_to_sqr_col);
    tcase_add_test(tc_pos, check_matrix_regular_exp);
    tcase_add_test(tc_pos, check_matrix_regular_exp_0);
    suite_add_tcase(s, tc_pos);
    return s;
}

int main()
{
    int result = 0;
    Suite *suite = calc_all_suite();
	SRunner *runner = srunner_create(suite);

	srunner_run_all(runner, CK_VERBOSE);
    result = srunner_ntests_failed(runner);
    srunner_free(runner);
    return result;
}
