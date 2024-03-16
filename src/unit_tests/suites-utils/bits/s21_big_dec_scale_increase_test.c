#include "suites-utils/s21_decimal_utils_test.h"

/* NORMAL */

START_TEST(normal_big_dec_test) {
  s21_big_decimal big_dec = {0};
  __uint128_t expected_value = 12300000ULL;
  big_dec.bits[0] = 123;
  int multiplier = 5;

  int init_scale = s21_big_dec_get_scale(big_dec);
  ck_assert_uint_eq(s21_big_dec_scale_increase(&big_dec, multiplier),
                    S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_big_dec_to_uint128_test(big_dec), expected_value);
  ck_assert_uint_eq(s21_big_dec_get_scale(big_dec), init_scale + multiplier);

  memset(&big_dec, 0, sizeof(s21_big_decimal));
  big_dec.bits[5] = 2147483648;
  s21_big_dec_set_scale(&big_dec, 8);
  multiplier = 1;

  init_scale = s21_big_dec_get_scale(big_dec);
  ck_assert_uint_eq(s21_big_dec_scale_increase(&big_dec, multiplier),
                    S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_get_bit(big_dec.bits[6], 0), 1);
  ck_assert_uint_eq(s21_get_bit(big_dec.bits[6], 1), 0);
  ck_assert_uint_eq(s21_get_bit(big_dec.bits[6], 2), 1);
  ck_assert_uint_eq(s21_get_bit(big_dec.bits[6], 3), 0);
  ck_assert_uint_eq(s21_big_dec_get_scale(big_dec), init_scale + multiplier);
}
END_TEST

/* ANOMALY */

START_TEST(huge_multiplier_test) {
  s21_big_decimal big_dec = {0};
  big_dec.bits[0] = 123;
  int multiplier = 6;
  s21_big_dec_set_scale(&big_dec, 23);
  int init_scale = s21_big_dec_get_scale(big_dec);

  ck_assert_uint_eq(s21_big_dec_scale_increase(&big_dec, multiplier),
                    S21_RETURN_CODE_ERR);
  ck_assert_uint_eq(s21_big_dec_get_scale(big_dec), init_scale);
}
END_TEST

START_TEST(multiplier_below_zero_test) {
  s21_big_decimal big_dec = {0};
  big_dec.bits[0] = 123;
  int multiplier = -6;
  s21_big_dec_set_scale(&big_dec, 23);
  int init_scale = s21_big_dec_get_scale(big_dec);

  ck_assert_uint_eq(s21_big_dec_scale_increase(&big_dec, multiplier),
                    S21_RETURN_CODE_ERR);
  ck_assert_uint_eq(s21_big_dec_get_scale(big_dec), init_scale);
}
END_TEST

Suite *suite_s21_big_dec_scale_increase() {
  Suite *suite = suite_create("suite_s21_big_dec_scale_increase");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_big_dec_test);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, huge_multiplier_test);
  tcase_add_test(anomaly_cases, multiplier_below_zero_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
