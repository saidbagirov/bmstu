#include <check.h>
#include <stdio.h>
#include "../inc/matrix.h"



START_TEST(check_matrix_create_zero_size)
{
	matrix l = matrix_create(0, 16);
	ck_assert_int_eq(matrix_valid(&l), 0);
	matrix r = matrix_create(16, 0);
	ck_assert_int_eq(matrix_valid(&r), 0);
}
END_TEST
START_TEST(check_matrix_set_identy)
{
	matrix m = matrix_create(16, 16);
	matrix_set_identy(&m);

	for (size_t x = 0; x < m.w; x++)
	{
		for (size_t y = 0; y < m.h; y++)
		{
			ck_assert_int_eq(matrix_get_elem(&m, x, y), x == y);
		}
	}
	matrix_dispose(&m);
}
END_TEST
START_TEST(check_matrix_multiply_2x2)
{
	int64_t ld[] = {
		1, 2,
		3, 4,
	};
	int64_t rd[] = {
		5, 6,
		7, 8,
	};
	int64_t od[] = {
		19, 22,
		43, 50,
	};

	matrix l = matrix_create(2, 2);
	matrix r = matrix_create(2, 2);
	matrix o = matrix_create(2, 2);
	matrix_set(&l, ld);
	matrix_set(&r, rd);
	matrix_set(&o, od);

	matrix m = matrix_multiply(&l, &r);
	ck_assert_int_eq(matrix_equeals(&m, &o), 1);

	matrix_dispose(&l);
	matrix_dispose(&r);
	matrix_dispose(&o);
	matrix_dispose(&m);
}
END_TEST
START_TEST(check_matrix_multiply_4x4)
{
	int64_t ld[] = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16,
	};
	int64_t rd[] = {
		16, 15, 14, 13,
		12, 11, 10, 9,
		8, 7, 6, 5,
		4, 3, 2, 1,
	};
	int64_t od[] = {
		80, 70, 60, 50,
		240, 214, 188, 162,
		400, 358, 316, 274,
		560, 502, 444, 386,
	};

	matrix l = matrix_create(4, 4);
	matrix r = matrix_create(4, 4);
	matrix o = matrix_create(4, 4);
	matrix_set(&l, ld);
	matrix_set(&r, rd);
	matrix_set(&o, od);

	matrix m = matrix_multiply(&l, &r);

	ck_assert_int_eq(matrix_equeals(&m, &o), 1);

	matrix_dispose(&l);
	matrix_dispose(&r);
	matrix_dispose(&o);
	matrix_dispose(&m);
}
END_TEST
START_TEST(check_matrix_multiply_5x4_8x5)
{
	int64_t ld[] = {
		1, 2, 3, 4, 5, 
		6, 7, 8, 9, 10, 
		11, 12, 13, 14, 15, 
		16, 17, 18, 19, 20,
	};
	int64_t rd[] = {
		40, 39, 28, 27, 26, 25, 24, 23,
		32, 31, 30, 29, 28, 27, 26, 25,
		24, 23, 22, 21, 20, 19, 18, 17,
		16, 15, 14, 13, 12, 11, 10, 9,
		8, 7, 6, 5, 4, 3, 2, 1,
	};
	int64_t od[] = {
		280, 265, 240, 225, 210, 195, 180, 165,
		880, 840, 740, 700, 660, 620, 580, 540,
		1480, 1415, 1240, 1175, 1110, 1045, 980, 915,
		2080, 1990, 1740, 1650, 1560, 1470, 1380, 1290,
	};

	matrix l = matrix_create(5, 4);
	matrix r = matrix_create(8, 5);
	matrix o = matrix_create(8, 4);
	matrix_set(&l, ld);
	matrix_set(&r, rd);
	matrix_set(&o, od);

	matrix m = matrix_multiply(&l, &r);

	ck_assert_int_eq(matrix_equeals(&m, &o), 1);

	matrix_dispose(&l);
	matrix_dispose(&r);
	matrix_dispose(&o);
	matrix_dispose(&m);
}
END_TEST
START_TEST(check_matrix_remove_col)
{
	int64_t md[] = {
		1, 2, 3, 4, 5, 
		6, 7, 8, 9, 10, 
		11, 12, 13, 14, 15, 
		16, 17, 18, 19, 20,
	};
	int64_t od[] = {
		1, 2, 4, 5, 
		6, 7, 9, 10, 
		11, 12, 14, 15, 
		16, 17, 19, 20,
	};

	matrix m = matrix_create(5, 4);
	matrix o = matrix_create(4, 4);
	matrix_set(&m, md);
	matrix_set(&o, od);

	matrix_remove_col(&m, 2);

	ck_assert_int_eq(matrix_equeals(&m, &o), 1);

	matrix_dispose(&o);
	matrix_dispose(&m);
}
END_TEST
START_TEST(check_matrix_remove_row)
{
	int64_t md[] = {
		1, 2, 3, 4, 5, 
		6, 7, 8, 9, 10, 
		11, 12, 13, 14, 15, 
		16, 17, 18, 19, 20,
	};
	int64_t od[] = {
		1, 2, 3, 4, 5, 
		16, 17, 18, 19, 20,
	};

	matrix m = matrix_create(5, 4);
	matrix o = matrix_create(5, 2);
	matrix_set(&m, md);
	matrix_set(&o, od);

	matrix_remove_row(&m, 1);
	matrix_remove_row(&m, 1);

	ck_assert_int_eq(matrix_equeals(&m, &o), 1);

	matrix_dispose(&o);
	matrix_dispose(&m);
}
END_TEST

Suite *test_func_suite()
{
	Suite *suite = suite_create("suite");

	TCase *matrix_func = tcase_create("matrix");
	tcase_add_test(matrix_func, check_matrix_create_zero_size);
	tcase_add_test(matrix_func, check_matrix_set_identy);
	tcase_add_test(matrix_func, check_matrix_multiply_2x2);
	tcase_add_test(matrix_func, check_matrix_multiply_4x4);
	tcase_add_test(matrix_func, check_matrix_multiply_5x4_8x5);
	tcase_add_test(matrix_func, check_matrix_remove_col);
	tcase_add_test(matrix_func, check_matrix_remove_row);
	suite_add_tcase(suite, matrix_func);

	//TCase *mysort_func = tcase_create("mysort_func");
	//tcase_add_test(mysort_func, mysort_regular);
	//suite_add_tcase(suite, mysort_func);

	return suite;
}
int main()
{
	Suite *suite = test_func_suite();
	SRunner *runner = srunner_create(suite);

	srunner_run_all(runner, CK_VERBOSE);
	int success = srunner_ntests_failed(runner);
	srunner_free(runner);
	
	return success;
}