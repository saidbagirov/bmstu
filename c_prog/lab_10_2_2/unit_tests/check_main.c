#include <check.h>
#include <stdio.h>
#include "../inc/list.h"



START_TEST(check_list_val)
{
	node *root = list_create();
	
	node *cur = root;
	cur->mul = 6;

	cur = cur->next = list_create();
	cur->mul = 0;

	cur = cur->next = list_create();
	cur->mul = 2;

	cur = cur->next = list_create();
	cur->mul = 4;

	int val = list_val(root, 7);

	ck_assert_int_eq(val, 1476);

	list_dispose(root);
}
END_TEST
START_TEST(check_list_ddx)
{
	node *root = list_create();
	
	node *cur = root;
	cur->mul = 6;

	cur = cur->next = list_create();
	cur->mul = 0;

	cur = cur->next = list_create();
	cur->mul = 2;

	cur = cur->next = list_create();
	cur->mul = 4;

	node *ddx = list_ddx(root);

	cur = ddx;
	ck_assert_int_eq(cur->mul, 12);

	cur = cur->next;
	ck_assert_int_eq(cur->mul, 4);

	cur = cur->next;
	ck_assert_int_eq(cur->mul, 0);

	ck_assert_ptr_eq(cur->next, NULL);

	list_dispose(root);
	list_dispose(ddx);
}
END_TEST
START_TEST(check_list_sum)
{
	node *lroot = list_create();

	node *cur = lroot;
	cur->mul = 6;

	cur = cur->next = list_create();
	cur->mul = 0;

	cur = cur->next = list_create();
	cur->mul = 2;

	cur = cur->next = list_create();
	cur->mul = 4;
	
	node *rroot = list_create();

	cur = rroot;
	cur->mul = 0;

	cur = cur->next = list_create();
	cur->mul = 4;
	
	cur = cur->next = list_create();
	cur->mul = 12;

	node *root = list_sum(lroot, rroot);

	cur = root;
	ck_assert_int_eq(cur->mul, 4);

	cur = cur->next;
	ck_assert_int_eq(cur->mul, 14);
	
	cur = cur->next;
	ck_assert_int_eq(cur->mul, 4);
	
	cur = cur->next;
	ck_assert_int_eq(cur->mul, 6);

	ck_assert_ptr_eq(cur->next, NULL);

	list_dispose(lroot);
	list_dispose(rroot);
	list_dispose(root);
}
END_TEST
START_TEST(check_list_dvd)
{
	node *root = list_create();
	
	node *cur = root;
	cur->mul = 6;

	cur = cur->next = list_create();
	cur->mul = 0;

	cur = cur->next = list_create();
	cur->mul = 2;

	cur = cur->next = list_create();
	cur->mul = 4;
	
	node *lroot, *rroot;
	list_dvd(root, &lroot, &rroot);

	cur = lroot;
	ck_assert_int_eq(cur->mul, 2);

	cur = cur->next;
	ck_assert_int_eq(cur->mul, 6);

	ck_assert_ptr_eq(cur->next, NULL);
	
	cur = rroot;
	ck_assert_int_eq(cur->mul, 4);

	cur = cur->next;
	ck_assert_int_eq(cur->mul, 0);

	ck_assert_ptr_eq(cur->next, NULL);

	list_dispose(lroot);
	list_dispose(rroot);
	list_dispose(root);
}
END_TEST

Suite *test_func_suite()
{
	Suite *suite = suite_create("suite");

	TCase *mysort_func = tcase_create("list");
	tcase_add_test(mysort_func, check_list_val);
	tcase_add_test(mysort_func, check_list_ddx);
	tcase_add_test(mysort_func, check_list_sum);
	tcase_add_test(mysort_func, check_list_dvd);
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