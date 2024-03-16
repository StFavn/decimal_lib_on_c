#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(normal_test_01) {
  s21_decimal a = s21_dec_init("5");
  s21_decimal b = s21_dec_init("11");
  s21_big_decimal res = {0};
  s21_big_decimal a_big = s21_dec_to_bigdec(a);
  s21_big_decimal b_big = s21_dec_to_bigdec(b);

  int status_code = s21_big_mantiss_mult(a_big, b_big, &res);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(res.bits[0], 55);
}
END_TEST

START_TEST(normal_test_02) {
  s21_decimal a = s21_dec_init("79228162514264337593543950335");
  s21_decimal b = s21_dec_init("11");
  s21_big_decimal res = {0};
  s21_big_decimal a_big = s21_dec_to_bigdec(a);
  s21_big_decimal b_big = s21_dec_to_bigdec(b);
  // 871509787656907713528983453685
  int status_code = s21_big_mantiss_mult(a_big, b_big, &res);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(res.bits[0], 4294967285);
  ck_assert_uint_eq(res.bits[1], 4294967295);
  ck_assert_uint_eq(res.bits[2], 4294967295);
  ck_assert_uint_eq(res.bits[3], 10);
}
END_TEST

Suite *suite_s21_big_dec_mantiss_mult() {
  Suite *suite = suite_create("suite_s21_big_dec_mantiss_mult");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, normal_test_02);
  suite_add_tcase(suite, normal_cases);

  return suite;
}
