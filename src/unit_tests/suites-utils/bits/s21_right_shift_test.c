#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(normal_test_01) {
  // Сдвиг нуля
  s21_decimal dec = {0};
  int shift = 2;
  int res = s21_right_shift(&dec, shift);

  ck_assert_uint_eq(res, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_is_zero(dec), true);
  ck_assert_uint_eq(s21_dec_is_valid(dec), true);
}
END_TEST

START_TEST(normal_test_02) {
  s21_decimal dec = {0};
  char *number_str = "147573952589676412928";
  s21_str_to_dec(number_str, &dec);

  int shift = 64;
  int res = s21_right_shift(&dec, shift);

  ck_assert_uint_eq(res, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_to_uint128_test(dec), 8);
  ck_assert_uint_eq(s21_dec_is_valid(dec), true);
}
END_TEST

START_TEST(normal_test_03) {
  // Сдвиг на ноль
  s21_decimal dec = {0};
  s21_decimal buff = {0};
  char *number_str = "147573952589676412928";
  s21_str_to_dec(number_str, &dec);
  buff = dec;

  int shift = 0;
  int res = s21_right_shift(&dec, shift);

  ck_assert_uint_eq(res, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_is_equal(dec, buff), true);
  ck_assert_uint_eq(s21_dec_is_valid(dec), true);
}
END_TEST

START_TEST(normal_test_04) {
  // Сдвиг на ноль
  s21_decimal dec = {0};
  char *number_str = "40000000000";
  s21_str_to_dec(number_str, &dec);

  int shift = 35;
  int res = s21_right_shift(&dec, shift);

  ck_assert_uint_eq(res, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_to_uint128_test(dec), 1);
  ck_assert_uint_eq(s21_dec_is_valid(dec), true);
}
END_TEST

START_TEST(fail_test_01) {
  int shift = 2;
  int res = s21_right_shift(NULL, shift);

  ck_assert_uint_eq(res, S21_RETURN_CODE_ERR);
}
END_TEST

Suite *suite_s21_right_shift() {
  Suite *suite = suite_create("suite_s21_right_shift");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, normal_test_02);
  tcase_add_test(normal_cases, normal_test_03);
  tcase_add_test(normal_cases, normal_test_04);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, fail_test_01);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
