#include "suites-utils/s21_decimal_utils_test.h"

static const uint32_t get_bit_res[] = {0, 1, 1, 1, 1, 0, 1, 1};

START_TEST(get_bit_test) {
  const uint32_t number = 0b01111011;  // 123;

  for (int i = 0; i < 8; ++i) {
    int bit_value = s21_get_bit(number, i);
    ck_assert_uint_eq(bit_value, get_bit_res[7 - i]);
  }
}
END_TEST

START_TEST(set_bit_on_test) {
  uint32_t number = 0b01111011;  // 123;
  // Установить третий бит в 1
  const uint32_t result = 0b01111111;  // 127
  const uint32_t bad_result = 0b01111011;

  s21_set_bit_on(&number, 2);
  ck_assert_uint_eq(number, result);
  ck_assert_uint_ne(number, bad_result);
}
END_TEST

START_TEST(set_bit_off_test) {
  uint32_t number = 0b01111011;  // 123;
  // Установить первый бит в 0
  const uint32_t result = 0b01111010;  // 122
  const uint32_t bad_result = 0b01111011;

  s21_set_bit_off(&number, 0);
  ck_assert_uint_eq(number, result);
  ck_assert_uint_ne(number, bad_result);
}
END_TEST

START_TEST(set_bit_inverse_test) {
  uint32_t number = 0b01111011;  // 123;
  // Инвертировать третий и первый биты
  const uint32_t result = 0b01111110;  // 126
  const uint32_t bad_result = 0b01111011;

  s21_set_bit_inverse(&number, 0);
  s21_set_bit_inverse(&number, 2);

  ck_assert_uint_eq(number, result);
  ck_assert_uint_ne(number, bad_result);
}
END_TEST

START_TEST(is_even_test) {
  const uint32_t even_number = 120;
  const uint32_t odd_number = 123;

  ck_assert_uint_eq(s21_is_even(even_number), !(bool)(even_number % 2));
  ck_assert_uint_eq(s21_is_even(odd_number), !(bool)(odd_number % 2));
}
END_TEST

Suite *suite_s21_bits() {
  Suite *suite = suite_create("suite_s21_bits");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, get_bit_test);
  tcase_add_test(normal_cases, set_bit_on_test);
  tcase_add_test(normal_cases, set_bit_off_test);
  tcase_add_test(normal_cases, set_bit_inverse_test);
  tcase_add_test(normal_cases, is_even_test);
  suite_add_tcase(suite, normal_cases);

  return suite;
}