#include "suites-core/s21_decimal_core_test.h"

/* NORMAL */

START_TEST(plus_to_minus_test) {
  s21_decimal dec_plus = {0};
  s21_decimal dec_minus = {0};

  s21_str_to_dec("+12345", &dec_plus);
  s21_str_to_dec("-12345", &dec_minus);

  s21_decimal val = {0};

  ck_assert_int_eq(s21_negate(dec_plus, &val), S21_RETURN_CODE_OK);
  ck_assert(s21_is_equal(val, dec_minus));

  ck_assert_int_eq(s21_negate(val, &val), S21_RETURN_CODE_OK);
  ck_assert(s21_is_equal(val, dec_plus));
}
END_TEST

START_TEST(minus_to_plus_test) {
  s21_decimal dec_plus = {0};
  s21_decimal dec_minus = {0};

  s21_str_to_dec("+12345", &dec_plus);
  s21_str_to_dec("-12345", &dec_minus);

  s21_decimal val = {0};

  ck_assert_int_eq(s21_negate(dec_minus, &val), S21_RETURN_CODE_OK);
  ck_assert(s21_is_equal(val, dec_plus));

  ck_assert_int_eq(s21_negate(val, &val), S21_RETURN_CODE_OK);
  ck_assert(s21_is_equal(val, dec_minus));
}
END_TEST

/* EDGE */

START_TEST(zero_plus_minus_test) {
  s21_decimal dec = {0};
  s21_dec_set_sign(&dec, S21_SIGN_MINUS);

  s21_decimal val = {0};

  ck_assert_int_eq(s21_negate(val, &val), S21_RETURN_CODE_OK);
  ck_assert(s21_is_equal(val, dec));

  s21_dec_set_sign(&dec, S21_SIGN_PLUS);

  ck_assert_int_eq(s21_negate(val, &val), S21_RETURN_CODE_OK);
  ck_assert(s21_is_equal(val, dec));
}
END_TEST

/* ANOMALY */

START_TEST(null_test) {
  s21_decimal val = {0};

  ck_assert_int_eq(s21_negate(val, NULL), S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(bad_dec_test) {
  s21_decimal dec = {.bits[3] = 111};
  s21_decimal val = {0};

  // Return `ERR`, but val is set - is correct
  ck_assert_int_eq(s21_negate(dec, &val), S21_RETURN_CODE_ERR);
  s21_dec_set_sign(&dec, S21_SIGN_MINUS);

  ck_assert(s21_is_equal(val, dec));
}
END_TEST

Suite *suite_s21_negate() {
  Suite *suite = suite_create("suite_s21_negate");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, plus_to_minus_test);
  tcase_add_test(normal_cases, minus_to_plus_test);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  tcase_add_test(edge_cases, zero_plus_minus_test);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, null_test);
  tcase_add_test(anomaly_cases, bad_dec_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}