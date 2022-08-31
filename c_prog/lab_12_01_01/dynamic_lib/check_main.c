#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "dlib.h"

int arrays_equeal(int *left, int leftlen, int *right, int rightlen)
{
	int key = 1;
	if (leftlen != rightlen)
		key = 0;
	else if (left == NULL || right == NULL) 
		key = 0;
	else if (left == NULL && right == NULL) 
		key = 1;
	else
	{
		for (int i = 0; i < leftlen; i++)
			if (left[i] != right[i])
				key = 0;
	}
	return key;
}

START_TEST(key_null_input)
{
	ck_assert_int_eq(key(NULL, NULL, NULL, NULL), FILTER_ERROR);
}
END_TEST
START_TEST(key_empty_result)
{
	int *src = malloc(2 * sizeof(int));
	src[0] = -1;
	src[1] = -2;
	int *src_end = src + 1;
	int *dst = NULL;
	int *dst_end = NULL;
	int result = key(src, src_end, &dst, &dst_end);
	free(src);
	ck_assert_int_eq(result, EMPTY_RESULT);
}
END_TEST
START_TEST(key_regular)
{
	int *src = malloc(9 * sizeof(int));
	src[0] = 0; src[1] = 1; src[2] = 2;
	src[3] = 3; src[4] = -1; src[5] = 2;
	src[6] = -3; src[7] = 4; src[8] = 5;
	int *src_end = src + 8;

	int *dst = NULL;
	int *dst_end = NULL;
	int key_result = key(src, src_end, &dst, &dst_end);
	free(dst);
	free(src);
	ck_assert_int_eq(key_result, SUCCESS);	
}
END_TEST
START_TEST(mysort_regular)
{
	int src[] = { 0, 1, 2, 3, -1, 2, -3, 4, 5 };
	mysort(src, 9, sizeof(int), &comp);

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