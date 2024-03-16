#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(s21_left_shift_test) {
  // Базовые проверки
  s21_decimal res = {0};
  uint32_t shift_amount = 33;
  __uint128_t target_int = 0;

  // Сдвиг нуля
  s21_left_shift(&res, shift_amount);
  target_int = s21_dec_to_uint128_test(res);
  ck_assert_uint_eq(target_int, 0ULL);

  // Сдвиг 1
  res.bits[0] = 1;
  s21_left_shift(&res, shift_amount);
  target_int = s21_dec_to_uint128_test(res);
  ck_assert_uint_eq(target_int, 8589934592ULL);

  // Сдвиг среднего бита
  res.bits[0] = 0;
  res.bits[1] = 1;
  shift_amount = 3;
  s21_left_shift(&res, shift_amount);
  target_int = s21_dec_to_uint128_test(res);
  ck_assert_uint_eq(target_int, 34359738368ULL);
}
END_TEST

START_TEST(normal_test_01) {
  s21_decimal one = {0};
  one.bits[0] = 1;
  s21_decimal res = {0};
  char *res_str = "4611686018427387904";
  s21_str_to_dec(res_str, &res);
  s21_left_shift(&one, 62);
  ck_assert_uint_eq(s21_is_equal(one, res), true);
}
END_TEST

START_TEST(s21_big_left_shift_test) {
  // Базовые проверки
  s21_big_decimal res = {0};
  uint32_t shift_amount = 100;
  __uint128_t target_int = 0;

  // Сдвиг нуля
  s21_big_left_shift(&res, shift_amount);
  target_int = s21_big_dec_to_uint128_test(res);
  ck_assert_uint_eq(target_int, 0ULL);

  // Сдвиг 1
  res.bits[0] = 1;
  s21_big_left_shift(&res, shift_amount);
  // target_int = s21_big_dec_to_uint128_test(res);
  ck_assert_uint_eq(s21_big_dec_get_bit(res, shift_amount), true);

  // Сдвиг среднего бита
  res.bits[0] = 0;
  res.bits[1] = 1;
  shift_amount = 3;
  s21_big_left_shift(&res, shift_amount);
  target_int = s21_big_dec_to_uint128_test(res);
  ck_assert_uint_eq(target_int, 34359738368ULL);
}
END_TEST

START_TEST(s21_left_shift_add_test) {
  // Проверки на сохранение scale & sign; ошибки
  s21_decimal res = {0};
  uint8_t scale = 12;
  uint32_t shift_amount = 63;
  __uint128_t target_int = 0;

  res.bits[0] = 1;
  s21_dec_set_sign(&res, true);
  s21_dec_set_scale(&res, scale);

  // Проверка на нулевой сдвиг
  ck_assert_uint_eq(s21_left_shift(&res, 0), 0);
  target_int = s21_dec_to_uint128_test(res);
  ck_assert_uint_eq(target_int, 1ULL);
  ck_assert_uint_eq(s21_dec_get_sign(res), true);
  ck_assert_uint_eq(s21_dec_get_scale(res), scale);

  // Проверка на сохранение scale & sign
  ck_assert_uint_eq(s21_left_shift(&res, shift_amount), 0);
  target_int = s21_dec_to_uint128_test(res);
  ck_assert_uint_eq(target_int, 9223372036854775808ULL);
  ck_assert_uint_eq(s21_dec_get_sign(res), true);
  ck_assert_uint_eq(s21_dec_get_scale(res), scale);

  // Проверки на ошибочные значения scale
  int invalid_shift_amount = -23;
  ck_assert_uint_eq(s21_left_shift(&res, invalid_shift_amount), 1);
  invalid_shift_amount = 127;
  ck_assert_uint_eq(s21_left_shift(&res, invalid_shift_amount), 1);
}
END_TEST

START_TEST(s21_big_left_shift_add_test) {
  // Проверки на сохранение scale & sign; ошибки
  s21_big_decimal res = {0};
  uint8_t scale = 12;
  uint32_t shift_amount = 63;
  __uint128_t target_int = 0;

  res.bits[0] = 1;
  s21_big_dec_set_sign(&res, true);
  s21_big_dec_set_scale(&res, scale);

  // Проверка на нулевой сдвиг
  ck_assert_uint_eq(s21_big_left_shift(&res, 0), 0);
  target_int = s21_big_dec_to_uint128_test(res);
  ck_assert_uint_eq(target_int, 1ULL);
  ck_assert_uint_eq(s21_big_dec_get_sign(res), true);
  ck_assert_uint_eq(s21_big_dec_get_scale(res), scale);

  // Проверка на сохранение scale & sign
  ck_assert_uint_eq(s21_big_left_shift(&res, shift_amount), 0);
  target_int = s21_big_dec_to_uint128_test(res);
  ck_assert_uint_eq(target_int, 9223372036854775808ULL);
  ck_assert_uint_eq(s21_big_dec_get_sign(res), true);
  ck_assert_uint_eq(s21_big_dec_get_scale(res), scale);

  // Проверки на ошибочные значения scale
  int invalid_shift_amount = -23;
  ck_assert_uint_eq(s21_big_left_shift(&res, invalid_shift_amount), 1);
  invalid_shift_amount = 225;
  ck_assert_uint_eq(s21_big_left_shift(&res, invalid_shift_amount), 1);
}
END_TEST

Suite *suite_s21_left_shift() {
  Suite *suite = suite_create("suite_s21_left_shift");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, s21_left_shift_test);
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, s21_big_left_shift_test);
  tcase_add_test(normal_cases, s21_left_shift_add_test);
  tcase_add_test(normal_cases, s21_big_left_shift_add_test);
  suite_add_tcase(suite, normal_cases);

  return suite;
}
