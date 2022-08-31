#include <check.h>
#include <stdio.h>
#include "../inc/my_functions.h"



START_TEST(check_sorting_title)
{
	description_of_films films[5];

	strcpy(films[0].name, "test_name_1");
	strcpy(films[0].author, "test_author_1");
	films[0].date = 19;
	strcpy(films[1].name, "test_name_3");
	strcpy(films[1].author, "test_author_3");
	films[1].date = 9234;
	strcpy(films[2].name, "test_name_2");
	strcpy(films[2].author, "test_author_2");
	films[2].date = 2;
	strcpy(films[3].name, "test_name_3");
	strcpy(films[3].author, "test_author_3");
	films[3].date = 42;
	strcpy(films[4].name, "test_name_5");
	strcpy(films[4].author, "test_author_5");
	films[4].date = 321;

	sorting(films, "title", 5);
	
	ck_assert_int_eq(strcmp(films[0].name, "test_name_1"), 0);
	ck_assert_int_eq(strcmp(films[0].author, "test_author_1"), 0);
	ck_assert_int_eq(films[0].date, 19);
	ck_assert_int_eq(strcmp(films[1].name, "test_name_2"), 0);
	ck_assert_int_eq(strcmp(films[1].author, "test_author_2"), 0);
	ck_assert_int_eq(films[1].date, 2);
	ck_assert_int_eq(strcmp(films[2].name, "test_name_3"), 0);
	ck_assert_int_eq(strcmp(films[2].author, "test_author_3"), 0);
	ck_assert_int_eq(films[2].date, 9234);
	ck_assert_int_eq(strcmp(films[3].name, "test_name_3"), 0);
	ck_assert_int_eq(strcmp(films[3].author, "test_author_3"), 0);
	ck_assert_int_eq(films[3].date, 42);
	ck_assert_int_eq(strcmp(films[4].name, "test_name_5"), 0);
	ck_assert_int_eq(strcmp(films[4].author, "test_author_5"), 0);
	ck_assert_int_eq(films[4].date, 321);
}
END_TEST
START_TEST(check_sorting_name)
{
	description_of_films films[5];

	strcpy(films[0].name, "test_name_1");
	strcpy(films[0].author, "test_author_1");
	films[0].date = 19;
	strcpy(films[1].name, "test_name_3");
	strcpy(films[1].author, "test_author_3");
	films[1].date = 9234;
	strcpy(films[2].name, "test_name_2");
	strcpy(films[2].author, "test_author_2");
	films[2].date = 2;
	strcpy(films[3].name, "test_name_3");
	strcpy(films[3].author, "test_author_3");
	films[3].date = 42;
	strcpy(films[4].name, "test_name_5");
	strcpy(films[4].author, "test_author_5");
	films[4].date = 321;

	sorting(films, "name", 5);
	
	ck_assert_int_eq(strcmp(films[0].name, "test_name_1"), 0);
	ck_assert_int_eq(strcmp(films[0].author, "test_author_1"), 0);
	ck_assert_int_eq(films[0].date, 19);
	ck_assert_int_eq(strcmp(films[1].name, "test_name_2"), 0);
	ck_assert_int_eq(strcmp(films[1].author, "test_author_2"), 0);
	ck_assert_int_eq(films[1].date, 2);
	ck_assert_int_eq(strcmp(films[2].name, "test_name_3"), 0);
	ck_assert_int_eq(strcmp(films[2].author, "test_author_3"), 0);
	ck_assert_int_eq(films[2].date, 9234);
	ck_assert_int_eq(strcmp(films[3].name, "test_name_3"), 0);
	ck_assert_int_eq(strcmp(films[3].author, "test_author_3"), 0);
	ck_assert_int_eq(films[3].date, 42);
	ck_assert_int_eq(strcmp(films[4].name, "test_name_5"), 0);
	ck_assert_int_eq(strcmp(films[4].author, "test_author_5"), 0);
	ck_assert_int_eq(films[4].date, 321);
}
END_TEST
START_TEST(check_sorting_year)
{
	description_of_films films[5];

	strcpy(films[0].name, "test_name_1");
	strcpy(films[0].author, "test_author_1");
	films[0].date = 19;
	strcpy(films[1].name, "test_name_3");
	strcpy(films[1].author, "test_author_3");
	films[1].date = 9234;
	strcpy(films[2].name, "test_name_2");
	strcpy(films[2].author, "test_author_2");
	films[2].date = 2;
	strcpy(films[3].name, "test_name_3");
	strcpy(films[3].author, "test_author_3");
	films[3].date = 42;
	strcpy(films[4].name, "test_name_5");
	strcpy(films[4].author, "test_author_5");
	films[4].date = 321;

	sorting(films, "year", 5);
	
	ck_assert_int_eq(strcmp(films[0].name, "test_name_2"), 0);
	ck_assert_int_eq(strcmp(films[0].author, "test_author_2"), 0);
	ck_assert_int_eq(films[0].date, 2);
	ck_assert_int_eq(strcmp(films[1].name, "test_name_1"), 0);
	ck_assert_int_eq(strcmp(films[1].author, "test_author_1"), 0);
	ck_assert_int_eq(films[1].date, 19);
	ck_assert_int_eq(strcmp(films[2].name, "test_name_3"), 0);
	ck_assert_int_eq(strcmp(films[2].author, "test_author_3"), 0);
	ck_assert_int_eq(films[2].date, 42);
	ck_assert_int_eq(strcmp(films[3].name, "test_name_5"), 0);
	ck_assert_int_eq(strcmp(films[3].author, "test_author_5"), 0);
	ck_assert_int_eq(films[3].date, 321);
	ck_assert_int_eq(strcmp(films[4].name, "test_name_3"), 0);
	ck_assert_int_eq(strcmp(films[4].author, "test_author_3"), 0);
	ck_assert_int_eq(films[4].date, 9234);
}
END_TEST
START_TEST(check_searching_title)
{
	description_of_films films[5];

	strcpy(films[0].name, "test_name_1");
	strcpy(films[0].author, "test_author_1");
	films[0].date = 19;
	strcpy(films[1].name, "test_name_3");
	strcpy(films[1].author, "test_author_3");
	films[1].date = 9234;
	strcpy(films[2].name, "test_name_2");
	strcpy(films[2].author, "test_author_2");
	films[2].date = 2;
	strcpy(films[3].name, "test_name_3");
	strcpy(films[3].author, "test_author_3");
	films[3].date = 42;
	strcpy(films[4].name, "test_name_5");
	strcpy(films[4].author, "test_author_5");
	films[4].date = 321;
	
	sorting(films, "title", 5);
	ck_assert_int_eq(searching(films, "test_name_5", "title", 5), 4);
}
END_TEST
START_TEST(check_searching_name)
{
	description_of_films films[5];

	strcpy(films[0].name, "test_name_1");
	strcpy(films[0].author, "test_author_1");
	films[0].date = 19;
	strcpy(films[1].name, "test_name_3");
	strcpy(films[1].author, "test_author_3");
	films[1].date = 9234;
	strcpy(films[2].name, "test_name_2");
	strcpy(films[2].author, "test_author_2");
	films[2].date = 2;
	strcpy(films[3].name, "test_name_3");
	strcpy(films[3].author, "test_author_3");
	films[3].date = 42;
	strcpy(films[4].name, "test_name_5");
	strcpy(films[4].author, "test_author_5");
	films[4].date = 321;
	
	sorting(films, "name", 5);
	ck_assert_int_eq(searching(films, "test_author_5", "name", 5), 4);
}
END_TEST
START_TEST(check_searching_year)
{
	description_of_films films[5];

	strcpy(films[0].name, "test_name_1");
	strcpy(films[0].author, "test_author_1");
	films[0].date = 19;
	strcpy(films[1].name, "test_name_3");
	strcpy(films[1].author, "test_author_3");
	films[1].date = 9234;
	strcpy(films[2].name, "test_name_2");
	strcpy(films[2].author, "test_author_2");
	films[2].date = 2;
	strcpy(films[3].name, "test_name_3");
	strcpy(films[3].author, "test_author_3");
	films[3].date = 42;
	strcpy(films[4].name, "test_name_5");
	strcpy(films[4].author, "test_author_5");
	films[4].date = 321;
	
	sorting(films, "year", 5);
	ck_assert_int_eq(searching(films, "321", "year", 5), 3);
}
END_TEST
START_TEST(check_charbinnarysearch)
{
	char chars[5][NAME_LEN];
	strcpy(chars[0], "a");
	strcpy(chars[1], "b");
	strcpy(chars[2], "c");
	strcpy(chars[3], "d");
	strcpy(chars[4], "e");
	
	ck_assert_int_eq(charbinnarysearch("b", chars, NAME_LEN, 5), 1);
}
END_TEST
START_TEST(check_intbinnarysearch)
{
	int ints[] = { 0, 1, 2, 3, 4 };
	
	ck_assert_int_eq(intbinnarysearch(2, ints, sizeof(int), 5), 2);
}
END_TEST

Suite *test_func_suite()
{
	Suite *suite = suite_create("suite");

	TCase *mysort_func = tcase_create("list");
	tcase_add_test(mysort_func, check_sorting_title);
	tcase_add_test(mysort_func, check_sorting_name);
	tcase_add_test(mysort_func, check_sorting_year);
	tcase_add_test(mysort_func, check_searching_title);
	tcase_add_test(mysort_func, check_searching_name);
	tcase_add_test(mysort_func, check_searching_year);
	tcase_add_test(mysort_func, check_charbinnarysearch);
	tcase_add_test(mysort_func, check_intbinnarysearch);
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