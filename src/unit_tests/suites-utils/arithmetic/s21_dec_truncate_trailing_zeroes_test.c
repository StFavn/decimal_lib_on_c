#include "suites-utils/s21_decimal_utils_test.h"

static void cycle_cases(char *str, char *exp_str, int exp_scale) {
  s21_decimal a = {0};
  s21_decimal expected = {0};
  s21_str_to_dec(str, &a);
  s21_str_to_dec(exp_str, &expected);

  int status_code = s21_dec_truncate_trailing_zeros(&a);
  ck_assert_uint_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_mantiss_compare(a, expected), 0);
  ck_assert_int_eq(s21_dec_get_scale(a), exp_scale);
}

START_TEST(normal_test_01) {
  char *a_str = "12.000";
  char *exp_str = "12";
  int exp_scale = 0;

  cycle_cases(a_str, exp_str, exp_scale);
}
END_TEST

START_TEST(normal_test_02) {
  char *a_str = "1.100000";
  char *exp_str = "1.1";
  int exp_scale = 1;

  cycle_cases(a_str, exp_str, exp_scale);
}
END_TEST

START_TEST(normal_test_03) {
  char *a_str = "1.001000000";
  char *exp_str = "1.001";
  int exp_scale = 3;

  cycle_cases(a_str, exp_str, exp_scale);
}
END_TEST

START_TEST(normal_test_04) {
  char *a_str = "1100";
  char *exp_str = "1100";
  int exp_scale = 0;

  cycle_cases(a_str, exp_str, exp_scale);
}
END_TEST

START_TEST(normal_test_05) {
  char *a_str = "00000000000";
  char *exp_str = "0";
  int exp_scale = 0;

  cycle_cases(a_str, exp_str, exp_scale);
}
END_TEST

START_TEST(normal_test_06) {
  char *a_str = "-1.001000000";
  char *exp_str = "-1.001";
  int exp_scale = 3;

  cycle_cases(a_str, exp_str, exp_scale);
}
END_TEST

START_TEST(normal_test_07) {
  char *a_str = "0.10000000";
  char *exp_str = "0.1";
  int exp_scale = 1;

  cycle_cases(a_str, exp_str, exp_scale);
}
END_TEST

START_TEST(normal_test_08) {
  char *a_str = "-0.003001";
  char *exp_str = "-0.003001";
  int exp_scale = 6;

  cycle_cases(a_str, exp_str, exp_scale);
}
END_TEST

START_TEST(normal_test_09) {
  char *a_str = "-0.0030000000000";
  char *exp_str = "-0.003";
  int exp_scale = 3;

  cycle_cases(a_str, exp_str, exp_scale);
}
END_TEST

/* ANOMALY */

START_TEST(null_test) {
  ck_assert_uint_eq(s21_dec_truncate_trailing_zeros(NULL), S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(bad_dec_test) {
  s21_decimal a = {0};
  a.bits[3] = 123;
  ck_assert_uint_eq(s21_dec_truncate_trailing_zeros(&a), S21_RETURN_CODE_ERR);
}

Suite *suite_s21_truncate_trailing_zeros() {
  Suite *suite = suite_create("suite_s21_truncate_trailing_zeros");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, normal_test_02);
  tcase_add_test(normal_cases, normal_test_03);
  tcase_add_test(normal_cases, normal_test_04);
  tcase_add_test(normal_cases, normal_test_05);
  tcase_add_test(normal_cases, normal_test_06);
  tcase_add_test(normal_cases, normal_test_07);
  tcase_add_test(normal_cases, normal_test_08);
  tcase_add_test(normal_cases, normal_test_09);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, null_test);
  tcase_add_test(anomaly_cases, bad_dec_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
