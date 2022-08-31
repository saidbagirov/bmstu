#include <check.h>
#include <stdio.h>
#include "../inc/list.h"
#include "../inc/transaction.h"



int compare_ints(const void *l, const void *r)
{
	if (*((int *)l) < (*((int *)r))) return -1;
	if (*((int *)l) > (*((int *)r))) return 1;
	return 0;
}

START_TEST(check_transaction_create)
{
	transaction *t = transaction_create(666, "the_sender_name", "the_recepient_name");
	ck_assert_int_eq(t->value == 666, 1);
	transaction_dispose(t);
}
END_TEST
START_TEST(check_transaction_compare)
{
	transaction *lt = transaction_create(666, "the_sender_name", "the_recepient_name");
	transaction *rt = transaction_create(6666, "uthe_sender_name", "uthe_recepient_name");
	
	ck_assert_int_eq(transaction_compare_value(lt, rt), -1);
	ck_assert_int_eq(transaction_compare_sender(lt, rt), -1);
	ck_assert_int_eq(transaction_compare_recepient(lt, rt), -1);

	transaction_dispose(lt);
	transaction_dispose(rt);
}
END_TEST
START_TEST(check_list_find)
{
	node *root = list_create();
	node *cur = root;
	for (size_t i = 0; i < 9; i++)
		cur = cur->next = list_create();

	cur = root;
	for (size_t i = 0; i < 10; i++)
	{
		cur->data = malloc(sizeof(int));
		*((int *)cur->data) = i;
		cur = cur->next;
	}	

	int i_cur = 5;
	int i_next = i_cur + 1; 

	cur = find(root, &i_cur, &compare_ints);

	ck_assert_int_eq(compare_ints(&i_cur, cur->data), 0);
	ck_assert_int_eq(compare_ints(&i_next, cur->next->data), 0);

	cur = root;
	for (size_t i = 0; i < 10; i++)
	{
		free(cur->data);
		cur = cur->next;
	}

	list_dispose(root);
}
END_TEST
START_TEST(check_list_sort)
{
	node *root = list_create();
	node *cur = root;
	for (size_t i = 0; i < 9; i++)
		cur = cur->next = list_create();

	cur = root;
	for (size_t i = 0; i < 10; i++)
	{
		cur->data = malloc(sizeof(int));
		*((int *)cur->data) = 10 - i;
		cur = cur->next;
	}	

	root = sort(root, &compare_ints);

	cur = root;
	for (size_t i = 1; i <= 10; i++)
	{
		ck_assert_int_eq(compare_ints(&i, cur->data), 0);
		cur = cur->next;
	}

	cur = root;
	for (size_t i = 0; i < 10; i++)
	{
		free(cur->data);
		cur = cur->next;
	}

	list_dispose(root);
}
END_TEST

Suite *test_func_suite()
{
	Suite *suite = suite_create("suite");

	TCase *matrix_func = tcase_create("transaction");
	tcase_add_test(matrix_func, check_transaction_create);
	tcase_add_test(matrix_func, check_transaction_compare);
	suite_add_tcase(suite, matrix_func);

	TCase *mysort_func = tcase_create("list");
	tcase_add_test(mysort_func, check_list_find);
	tcase_add_test(mysort_func, check_list_sort);
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