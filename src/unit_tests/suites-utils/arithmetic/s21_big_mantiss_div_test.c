#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(normal_test_01) {
  s21_big_decimal a = {0};
  s21_big_decimal b = {0};
  s21_big_decimal res = {0};
  s21_big_decimal rem = {0};
  s21_big_decimal expected = {0};

  a.bits[0] = 100;
  b.bits[0] = 100;
  expected.bits[0] = 1;
  s21_big_left_shift(&a, 200);
  s21_big_left_shift(&b, 200);

  int return_code = s21_big_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(res.bits[0], 1);
  ck_assert_uint_eq(s21_big_mantiss_compare(res, expected), 0);
}
END_TEST

START_TEST(normal_test_02) {
  s21_big_decimal a = {0};
  s21_big_decimal b = {0};
  s21_big_decimal res = {0};
  s21_big_decimal rem = {0};
  s21_big_decimal expected_res = {0};
  s21_big_decimal expected_rem = {0};

  a.bits[0] = 1230000;
  b.bits[0] = 100000;
  expected_res.bits[0] = 12;
  expected_rem.bits[0] = 30000;

  int return_code = s21_big_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_big_mantiss_compare(res, expected_res), 0);
  ck_assert_uint_eq(s21_big_mantiss_compare(rem, expected_rem), 0);
}
END_TEST

Suite *suite_s21_big_mantiss_div() {
  Suite *suite = suite_create("suite_s21_big_mantiss_div");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, normal_test_02);
  suite_add_tcase(suite, normal_cases);

  return suite;
}
