#include "suites-core/s21_decimal_core_test.h"

static void cycle_conversion_cases(int in) {
  s21_decimal dec = {0};

  int status = s21_from_int_to_decimal(in, &dec);
  ck_assert_int_eq(status, S21_RETURN_CODE_OK);

  if (in < 0) {
    ck_assert_uint_eq(s21_dec_get_sign(dec), S21_SIGN_MINUS);
    if (in > INT32_MIN) in *= -1;
  } else {
    ck_assert_uint_eq(s21_dec_get_sign(dec), S21_SIGN_PLUS);
  }

  ck_assert_uint_eq(s21_dec_is_valid(dec), true);
  ck_assert_uint_eq(dec.bits[0], (uint32_t)in);
}

// NORMAL TESTCASES
START_TEST(normal_test_01) {
  int in = 42;
  cycle_conversion_cases(in);
}
END_TEST

START_TEST(normal_test_02) {
  int in = INT32_MAX;
  cycle_conversion_cases(in);
}
END_TEST

START_TEST(normal_test_03) {
  int in = -21;
  cycle_conversion_cases(in);
}
END_TEST

START_TEST(normal_test_04) {
  int in = INT32_MIN;
  cycle_conversion_cases(in);
}
END_TEST

START_TEST(normal_test_05) {
  s21_decimal dec = {0};
  int in = 0;
  int status = s21_from_int_to_decimal(in, &dec);
  ck_assert_int_eq(status, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_is_valid(dec), true);
  ck_assert_uint_eq(s21_dec_is_zero(dec), true);
}
END_TEST

// FAIL TESTCASES
START_TEST(fail_test_01) {
  int in = INT32_MIN;

  int status = s21_from_int_to_decimal(in, NULL);
  ck_assert_int_eq(status, S21_RETURN_CODE_ERR);
}
END_TEST

Suite *suite_s21_int_to_dec() {
  Suite *suite = suite_create("suite_s21_int_to_dec");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, normal_test_02);
  tcase_add_test(normal_cases, normal_test_03);
  tcase_add_test(normal_cases, normal_test_04);
  tcase_add_test(normal_cases, normal_test_05);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, fail_test_01);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
