#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(s21_dec_to_bigdec_test) {
  // Базовые проверки
  s21_decimal in = {0};
  s21_big_decimal out = {0};

  // 0 && 0
  out = s21_dec_to_bigdec(in);
  ck_assert_uint_eq(s21_big_dec_to_uint128_test(out),
                    s21_dec_to_uint128_test(in));

  // -5 && -5
  in.bits[0] = 0b101;
  s21_dec_set_sign(&in, true);
  out = s21_dec_to_bigdec(in);
  ck_assert_uint_eq(s21_big_dec_to_uint128_test(out),
                    s21_dec_to_uint128_test(in));
  ck_assert_uint_eq(s21_big_dec_get_sign(out), s21_dec_get_sign(in));

  // Проверить сохранение степени (scale)
  s21_dec_set_scale(&in, 21);
  out = s21_dec_to_bigdec(in);
  ck_assert_uint_eq(s21_big_dec_to_uint128_test(out),
                    s21_dec_to_uint128_test(in));
  ck_assert_uint_eq(s21_big_dec_get_scale(out), s21_dec_get_scale(in));
}
END_TEST

Suite *suite_s21_bd_converters() {
  Suite *suite = suite_create("suite_s21_bd_converters");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, s21_dec_to_bigdec_test);
  suite_add_tcase(suite, normal_cases);

  return suite;
}
