#include <check.h>
#include <stdio.h>
#include "../inc/key.h"
#include "../inc/mysort.h"
#include "../inc/error_codes.h"



int arrays_equeal(int *l, int ll, int *r, int rl)
{
	if (ll != rl)
		return 0;

	if (l == NULL && r == NULL) 
		return 1;
	if (l == NULL || r == NULL) 
		return 0;

	for (int i = 0; i < ll; i++)
		if (l[i] != r[i])
			return 0;

	return 1;
}

START_TEST(key_null_input)
{
	ck_assert_int_eq(key(NULL, NULL, NULL, NULL), MEMORY_ERROR);
}
END_TEST
START_TEST(key_empty_result)
{
	int src[] = { -1, -2 };
	int *src_end = src + 2;
	int *dst;
	int *dst_end;
	ck_assert_int_eq(key(src, src_end, &dst, &dst_end), EMPTY_RESULT);
}
END_TEST
START_TEST(key_regular)
{
	int src[] = { 0, 1, 2, 3, -1, 2, -3, 4, 5 };
	int *src_end = src + 9;

	int *dst;
	int *dst_end;
	
	ck_assert_int_eq(key(src, src_end, &dst, &dst_end), SUCCESS);
	int src_check[] = { 0, 1, 2, 3 };
	int dst_count = 4;

	ck_assert_int_eq(arrays_equeal(dst, dst_end - dst, src_check, dst_count), 1);
	
	free(dst);
}
END_TEST
START_TEST(mysort_regular)
{
	int src[] = { 0, 1, 2, 3, -1, 2, -3, 4, 5 };
	mysort(src, 9, sizeof(int), &cmp_fun);

	int check[] = { -3, -1, 0, 1, 2, 2, 3, 4, 5 };

	ck_assert_int_eq(arrays_equeal(src, 9, check, 9), 1);
}
END_TEST

Suite *test_func_suite()
{
	Suite *suite = suite_create("suite");

	TCase *key_func = tcase_create("key_func");
	tcase_add_test(key_func, key_null_input);
	tcase_add_test(key_func, key_empty_result);
	tcase_add_test(key_func, key_regular);
	suite_add_tcase(suite, key_func);

	TCase *mysort_func = tcase_create("mysort_func");
	tcase_add_test(mysort_func, mysort_regular);
	suite_add_tcase(suite, mysort_func);

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