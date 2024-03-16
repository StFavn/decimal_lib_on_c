#include "suites-utils/s21_decimal_utils_test.h"

/* NORMAL */

START_TEST(normal_test) {
  s21_decimal x = {0};
  __uint128_t expected_value = 12300000ULL;
  x.bits[0] = 123;
  int multiplier = 5;

  int init_scale = s21_dec_get_scale(x);
  ck_assert_uint_eq(s21_dec_scale_increase(&x, multiplier), S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_to_uint128_test(x), expected_value);
  ck_assert_uint_eq(s21_dec_get_scale(x), init_scale + multiplier);

  memset(&x, 0, sizeof(s21_decimal));
  x.bits[1] = 2147483648;
  s21_dec_set_scale(&x, 8);
  multiplier = 1;

  init_scale = s21_dec_get_scale(x);
  ck_assert_uint_eq(s21_dec_scale_increase(&x, multiplier), S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_get_bit(x.bits[2], 0), 1);
  ck_assert_uint_eq(s21_get_bit(x.bits[2], 1), 0);
  ck_assert_uint_eq(s21_get_bit(x.bits[2], 2), 1);
  ck_assert_uint_eq(s21_get_bit(x.bits[2], 3), 0);
  ck_assert_uint_eq(s21_dec_get_scale(x), init_scale + multiplier);
}
END_TEST

/* ANOMALY */

START_TEST(overflow_test) {
  s21_decimal x = {0};
  x.bits[2] = 2147483648;
  int multiplier = 1;
  int init_scale = s21_dec_get_scale(x);

  ck_assert_uint_eq(s21_dec_scale_increase(&x, multiplier),
                    S21_RETURN_CODE_ERR);
  ck_assert_uint_eq(s21_dec_get_scale(x), init_scale);
}
END_TEST

START_TEST(huge_multiplier_test) {
  s21_decimal x = {0};
  x.bits[0] = 123;
  int multiplier = 6;
  s21_dec_set_scale(&x, 23);
  int init_scale = s21_dec_get_scale(x);

  ck_assert_uint_eq(s21_dec_scale_increase(&x, multiplier),
                    S21_RETURN_CODE_ERR);
  ck_assert_uint_eq(s21_dec_get_scale(x), init_scale);
}
END_TEST

START_TEST(multiplier_below_zero_test) {
  s21_decimal x = {0};
  x.bits[0] = 123;
  int multiplier = -6;
  s21_dec_set_scale(&x, 23);
  int init_scale = s21_dec_get_scale(x);

  ck_assert_uint_eq(s21_dec_scale_increase(&x, multiplier),
                    S21_RETURN_CODE_ERR);
  ck_assert_uint_eq(s21_dec_get_scale(x), init_scale);
}
END_TEST

Suite *suite_s21_dec_scale_increase() {
  Suite *suite = suite_create("suite_s21_dec_scale_increase");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, overflow_test);
  tcase_add_test(anomaly_cases, huge_multiplier_test);
  tcase_add_test(anomaly_cases, multiplier_below_zero_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
