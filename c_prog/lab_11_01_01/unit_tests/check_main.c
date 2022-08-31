#include <check.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include "../inc/my_snprintf.h"



START_TEST(check_my_snprintf_c)
{
	const char *format = "test %% %c%c%c test%c%%";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, 's', 'h', 'i', 't');
	int chk_l = snprintf(chk, len, format, 's', 'h', 'i', 't');

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_c_over)
{
	const char *format = "test %% %c%c%c test%c%%"
	"________________________________________________________________";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, 's', 'h', 'i', 't');
	int chk_l = snprintf(chk, len, format, 's', 'h', 'i', 't');

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_d)
{
	const char *format = "%d test %% %d %d %d test %d %% %d %d";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int v = 1;
	int res_l = my_snprintf(res, len, format, 00, -12, 0, 120032, -32112, v, -v);
	int chk_l = snprintf(chk, len, format, 00, -12, 0, 120032, -32112, v, -v);

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_d_2)
{
	const char *format = "%d";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, -2147483648);
	int chk_l = snprintf(chk, len, format, -2147483648);

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_d_3)
{
	const char *format = "%d";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, 2147483647);
	int chk_l = snprintf(chk, len, format, 2147483647);

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_d_over)
{
	const char *format = "test %% %d%d%d test%d%%"
	"________________________________________________________________";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, -12, 0, 120032, -32112);
	int chk_l = snprintf(chk, len, format, -12, 0, 120032, -32112);

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_i)
{
	const char *format = "test %% %i%i%i test%i%%";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, -12, 0, 120032, -32112);
	int chk_l = snprintf(chk, len, format, -12, 0, 120032, -32112);
	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_i_over)
{
	const char *format = "test %% %i%i%i test%i%%"
	"________________________________________________________________";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, -12, 0, 120032, -32112);
	int chk_l = snprintf(chk, len, format, -12, 0, 120032, -32112);

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_x)
{
	const char *format = "test %% %x%x%x test%x%%";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, -12, 0, 120032, -32112);
	int chk_l = snprintf(chk, len, format, -12, 0, 120032, -32112);
	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_x_over)
{
	const char *format = "test %% %x%x%x test%x%%"
	"________________________________________________________________";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, -12, 0, 120032, -32112);
	int chk_l = snprintf(chk, len, format, -12, 0, 120032, -32112);

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_o)
{
	const char *format = "test %% %o%o%o test%o%%";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, -12, 0, 120032, -32112);
	int chk_l = snprintf(chk, len, format, -12, 0, 120032, -32112);
	
	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_o_over)
{
	const char *format = "test %% %o%o%o test%o%%"
	"________________________________________________________________";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, -12, 0, 120032, -32112);
	int chk_l = snprintf(chk, len, format, -12, 0, 120032, -32112);

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_s)
{
	const char *format = "test %% %o%o%o test%o%%";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, "-12", "0", "120032", "-32112");
	int chk_l = snprintf(chk, len, format, "-12", "0", "120032", "-32112");
	
	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_s_over)
{
	const char *format = "test %% %o%o%o test%o%%"
	"________________________________________________________________";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, "-12", "0", "120032", "-32112");
	int chk_l = snprintf(chk, len, format, "-12", "0", "120032", "-32112");

	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_all)
{
	const char *format = "%%%c%d%i%x%o%s";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, 'F', 123454321, -123454321, 123454321, 123454321, "uuuck");
	int chk_l = snprintf(chk, len, format, 'F', 123454321, -123454321, 123454321, 123454321, "uuuck");
	
	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_empty)
{
	const char *format = "";
	const size_t len = 64;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, 0);
	int chk_l = snprintf(chk, len, format, 0);
	
	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_null)
{
	const char *format = "%s";
	const size_t len = 3;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, NULL);
	int chk_l = snprintf(chk, len, format, NULL);
	
	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST
START_TEST(check_my_snprintf_empty_2)
{
	const char *format = "%s";
	const size_t len = 16;
	char res[len];
	char chk[len];

	int res_l = my_snprintf(res, len, format, "");
	int chk_l = snprintf(chk, len, format, "");
	
	ck_assert_int_eq(res_l, chk_l);
	ck_assert_int_eq(strcmp(res, chk), 0);
}
END_TEST

Suite *test_func_suite()
{
	Suite *suite = suite_create("suite");

	TCase *mysort_func = tcase_create("my_snprintf");
	tcase_add_test(mysort_func, check_my_snprintf_c);
	tcase_add_test(mysort_func, check_my_snprintf_c_over);
	tcase_add_test(mysort_func, check_my_snprintf_d);
	tcase_add_test(mysort_func, check_my_snprintf_d_2);
	tcase_add_test(mysort_func, check_my_snprintf_d_3);
	tcase_add_test(mysort_func, check_my_snprintf_d_over);
	tcase_add_test(mysort_func, check_my_snprintf_i);
	tcase_add_test(mysort_func, check_my_snprintf_i_over);
	tcase_add_test(mysort_func, check_my_snprintf_x);
	tcase_add_test(mysort_func, check_my_snprintf_x_over);
	tcase_add_test(mysort_func, check_my_snprintf_o);
	tcase_add_test(mysort_func, check_my_snprintf_o_over);
	tcase_add_test(mysort_func, check_my_snprintf_s);
	tcase_add_test(mysort_func, check_my_snprintf_s_over);
	tcase_add_test(mysort_func, check_my_snprintf_all);
	tcase_add_test(mysort_func, check_my_snprintf_empty);
	tcase_add_test(mysort_func, check_my_snprintf_null);
	tcase_add_test(mysort_func, check_my_snprintf_empty_2);
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