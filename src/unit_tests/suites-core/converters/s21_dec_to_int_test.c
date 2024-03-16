#include "suites-core/s21_decimal_core_test.h"

static void cycle_conversion_cases(s21_decimal src, char *src_str) {
  s21_str_to_dec(src_str, &src);
  int target = 0;
  int expected = atoi(src_str);
  int status_code = s21_from_decimal_to_int(src, &target);

  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(target, expected);
}

/* NORMAL */

START_TEST(normal_test_01) {
  s21_decimal src = {0};
  char *src_str = "21.420";
  cycle_conversion_cases(src, src_str);
}
END_TEST

START_TEST(normal_test_02) {
  s21_decimal src = {0};
  char *src_str = "-42.00000000001";
  cycle_conversion_cases(src, src_str);
}
END_TEST

START_TEST(normal_test_03) {
  s21_decimal src = {0};
  char *src_str = "12359";
  cycle_conversion_cases(src, src_str);
}
END_TEST

START_TEST(normal_test_04) {
  s21_decimal src = {0};
  char *src_str = "-95684";
  cycle_conversion_cases(src, src_str);
}
END_TEST

START_TEST(normal_test_05) {
  s21_decimal src = {0};
  char *src_str = "127.000";
  cycle_conversion_cases(src, src_str);
}
END_TEST

START_TEST(normal_test_06) {
  s21_decimal src = {0};
  char *src_str = "12445.50000000001";
  cycle_conversion_cases(src, src_str);
}
END_TEST

START_TEST(normal_test_07) {
  s21_decimal src = {0};
  char *src_str = "-12445.50000000001";
  cycle_conversion_cases(src, src_str);
}
END_TEST

/* EDGE */

START_TEST(min_int_test) {
  s21_decimal src = {0};
  char *src_str = "-2147483648";
  cycle_conversion_cases(src, src_str);
}
END_TEST

START_TEST(max_int_test) {
  s21_decimal src = {0};
  char *src_str = "2147483647";
  cycle_conversion_cases(src, src_str);
}
END_TEST

/* ANOMALY */

START_TEST(overflow_max_int_test_0) {
  s21_decimal src = {0};
  int target = 0;
  char *src_str = "2147483648";
  s21_str_to_dec(src_str, &src);

  int status_code = s21_from_decimal_to_int(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(overflow_max_int_test_1) {
  s21_decimal src = {0};
  int target = 0;

  src.bits[1] = 1;

  int status_code = s21_from_decimal_to_int(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(overflow_min_int_test_0) {
  s21_decimal src = {0};
  int target = 0;
  char *src_str = "-2147483649";
  s21_str_to_dec(src_str, &src);

  int status_code = s21_from_decimal_to_int(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(overflow_min_int_test_1) {
  s21_decimal src = {0};
  int target = 0;

  src.bits[1] = 1;
  s21_dec_set_sign(&src, S21_SIGN_MINUS);

  int status_code = s21_from_decimal_to_int(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(null_test) {
  s21_decimal src = {0};
  int status_code = s21_from_decimal_to_int(src, NULL);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(bad_dec_test) {
  s21_decimal src = {.bits[3] = 111};
  int target = 0;
  int status_code = s21_from_decimal_to_int(src, &target);

  // Return `ERR`, but val is set - is correct
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

Suite *suite_s21_dec_to_int() {
  Suite *suite = suite_create("suite_s21_dec_to_int");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, normal_test_02);
  tcase_add_test(normal_cases, normal_test_03);
  tcase_add_test(normal_cases, normal_test_04);
  tcase_add_test(normal_cases, normal_test_05);
  tcase_add_test(normal_cases, normal_test_06);
  tcase_add_test(normal_cases, normal_test_07);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  tcase_add_test(edge_cases, min_int_test);
  tcase_add_test(edge_cases, max_int_test);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, overflow_max_int_test_0);
  tcase_add_test(anomaly_cases, overflow_max_int_test_1);
  tcase_add_test(anomaly_cases, overflow_min_int_test_1);
  tcase_add_test(anomaly_cases, overflow_min_int_test_0);
  tcase_add_test(anomaly_cases, null_test);
  tcase_add_test(anomaly_cases, bad_dec_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
