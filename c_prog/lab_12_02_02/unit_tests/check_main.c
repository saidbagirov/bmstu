#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/libfib.h"



START_TEST(check_fill_fib)
{
	const size_t len = 10;
	int fib[len];

	fill_fib(fib, len);

	ck_assert_int_eq(fib[0], 0);
	ck_assert_int_eq(fib[1], 1);
	ck_assert_int_eq(fib[2], 1);
	ck_assert_int_eq(fib[3], 2);
	ck_assert_int_eq(fib[4], 3);
	ck_assert_int_eq(fib[5], 5);
	ck_assert_int_eq(fib[6], 8);
	ck_assert_int_eq(fib[7], 13);
	ck_assert_int_eq(fib[8], 21);
	ck_assert_int_eq(fib[9], 34);
}
END_TEST
START_TEST(check_copy_unique)
{
	int src[] = { 1, 2, 3, 0, 4, 5, 1, 6, -1, 8, 7, 9, 7 };

	size_t len = copy_unique(src, sizeof(src) / sizeof(int), NULL);
	ck_assert_int_eq(len, 11);

	int *dst = malloc(len * sizeof(int));
	copy_unique(src, sizeof(src) / sizeof(int), dst);

	ck_assert_int_eq(dst[0], 1);
	ck_assert_int_eq(dst[1], 2);
	ck_assert_int_eq(dst[2], 3);
	ck_assert_int_eq(dst[3], 0);
	ck_assert_int_eq(dst[4], 4);
	ck_assert_int_eq(dst[5], 5);
	ck_assert_int_eq(dst[6], 6);
	ck_assert_int_eq(dst[7], -1);
	ck_assert_int_eq(dst[8], 8);
	ck_assert_int_eq(dst[9], 7);
	ck_assert_int_eq(dst[10], 9);

	free(dst);
}
END_TEST

Suite *test_func_suite()
{
	Suite *suite = suite_create("suite");

	TCase *key_func = tcase_create("libfib");
	tcase_add_test(key_func, check_fill_fib);
	tcase_add_test(key_func, check_copy_unique);
	suite_add_tcase(suite, key_func);

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