#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(normal_test_01) {
  s21_big_decimal a = {0};
  a.bits[0] = 1;

  s21_big_dec_mult_by_ten(&a, 3);
  ck_assert_uint_eq(a.bits[0], (uint32_t)(10 * 10 * 10));
}
END_TEST

START_TEST(normal_test_02) {
  s21_big_decimal a = {0};
  a.bits[0] = 1;

  s21_big_dec_mult_by_ten(&a, 60);
  ck_assert_uint_eq(a.bits[0], 0);
  ck_assert_uint_eq(a.bits[1], 268435456);
  ck_assert_uint_eq(a.bits[2], 2489684185);
  ck_assert_uint_eq(a.bits[3], 3613540908);
  ck_assert_uint_eq(a.bits[4], 2585937153);
  ck_assert_uint_eq(a.bits[5], 1327965719);
  ck_assert_uint_eq(a.bits[6], 159);
}
END_TEST

Suite *suite_s21_big_dec_mult10() {
  Suite *suite = suite_create("suite_s21_big_dec_mult10");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, normal_test_02);
  suite_add_tcase(suite, normal_cases);

  return suite;
}
