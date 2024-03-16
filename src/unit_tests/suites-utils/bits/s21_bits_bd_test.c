#include "suites-utils/s21_decimal_utils_test.h"

static const uint32_t not_valid_bits[] = {0, 12, 15, 24, 27, 30};

START_TEST(s21_big_dec_is_valid_test) {
  const uint32_t bits_indxs = not_valid_bits[_i];
  s21_big_decimal dec = {0};
  s21_big_dec_set_sign(&dec, true);

  ck_assert_int_eq(s21_big_dec_is_valid(dec), true);
  ck_assert_int_ne(s21_big_dec_is_valid(dec), false);

  dec.bits[7] = 1;
  ck_assert_int_eq(s21_big_dec_is_valid(dec), false);
  dec.bits[7] = 0;

  s21_set_bit_on(&dec.bits[7], bits_indxs);
  ck_assert_int_eq(s21_big_dec_is_valid(dec), false);
}
END_TEST

static const uint32_t b_shift_list_init[] = {0,   32,  95,  100,
                                             128, 161, 220, 243};
static const uint32_t b_shift_list_result[] = {0, 0, 31, 4, 0, 1, 28, 19};
static const uint8_t b_bits_indx_result[] = {0, 1, 2, 3, 4, 5, 6, 7};

START_TEST(s21_big_dec_set_bit_test) {
  s21_big_decimal dec = {0};

  uint32_t shift = b_shift_list_init[_i];
  uint8_t bits_indx_res = b_bits_indx_result[_i];
  uint32_t shift_res = b_shift_list_result[_i];

  ck_assert_uint_eq(s21_big_dec_is_zero(dec), true);
  s21_big_dec_set_bit(&dec, shift, true);
  ck_assert_uint_eq(s21_get_bit(dec.bits[bits_indx_res], shift_res), true);
  // Проверка s21_dec_get_bit
  ck_assert_uint_eq(s21_big_dec_get_bit(dec, shift), true);

  for (int i = 0; i < 8; ++i) {
    dec.bits[i] = 1;
  }

  ck_assert_uint_eq(s21_big_dec_is_zero(dec), false);
  s21_big_dec_set_bit(&dec, shift, false);
  ck_assert_uint_eq(s21_get_bit(dec.bits[bits_indx_res], shift_res), false);
  // Проверка s21_dec_get_bit
  ck_assert_uint_eq(s21_big_dec_get_bit(dec, shift), false);
}
END_TEST

START_TEST(s21_big_dec_set_sign_test) {
  s21_big_decimal dec = {0};
  s21_big_dec_set_sign(&dec, true);

  ck_assert_uint_eq(dec.bits[7], 2147483648);  // uint 32 со старшей единицей
  ck_assert_uint_eq(s21_big_dec_get_bit(dec, S21_BIG_DEC_SIGN_SHIFT), true);
  ck_assert_uint_eq(s21_big_dec_get_sign(dec), true);

  s21_big_dec_set_sign(&dec, false);
  ck_assert_uint_eq(dec.bits[7], 0);
  ck_assert_uint_eq(s21_big_dec_get_bit(dec, S21_BIG_DEC_SIGN_SHIFT), false);
  ck_assert_uint_eq(s21_big_dec_get_sign(dec), false);
}
END_TEST

START_TEST(s21_big_dec_set_scale_test) {
  s21_big_decimal dec = {0};

  // Задать степень положительного числа
  uint8_t scale = 17;
  ck_assert_int_eq(s21_big_dec_set_scale(&dec, scale), S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_big_dec_is_valid(dec), true);
  ck_assert_uint_eq(dec.bits[7], 1114112);
  ck_assert_uint_eq(dec.bits[7] >> 16, scale);
  ck_assert_uint_eq(s21_big_dec_get_scale(dec), scale);

  scale = 1;
  ck_assert_int_eq(s21_big_dec_set_scale(&dec, scale), S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_big_dec_is_valid(dec), true);
  ck_assert_uint_eq(s21_big_dec_get_scale(dec), scale);

  scale = 28;
  ck_assert_int_eq(s21_big_dec_set_scale(&dec, scale), S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_big_dec_is_valid(dec), true);
  ck_assert_uint_eq(s21_big_dec_get_scale(dec), scale);

  // Задать степень отрицательного числа
  scale = 21;
  s21_big_dec_set_sign(&dec, true);
  ck_assert_int_eq(s21_big_dec_set_scale(&dec, scale), S21_RETURN_CODE_OK);
  uint32_t signed_scale_shifted = (uint32_t)scale << 16;
  s21_set_bit_on(&signed_scale_shifted,
                 31);  // 31 <- старший бит 32-х битного числа
  ck_assert_int_eq(s21_big_dec_is_valid(dec), true);

  ck_assert_uint_eq(dec.bits[7], signed_scale_shifted);
  ck_assert_uint_eq(s21_big_dec_get_scale(dec), scale);

  // Задать некорректную степень
  // ck_assert_int_eq(s21_big_dec_set_scale(&dec, 300), S21_RETURN_CODE_ERR);
  // ck_assert_int_eq(s21_big_dec_is_valid(dec), true);
  // ck_assert_uint_eq(s21_big_dec_get_scale(dec),
  //                   scale);  // Степеь осталась без изменений
}
END_TEST

Suite *suite_s21_bits_big_decimal() {
  Suite *suite = suite_create("suite_s21_bits_big_decimal");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, s21_big_dec_is_valid_test);
  tcase_add_loop_test(normal_cases, s21_big_dec_set_bit_test, 0,
                      GET_SIZE_ARRAY(b_shift_list_init));
  tcase_add_test(normal_cases, s21_big_dec_set_sign_test);
  tcase_add_test(normal_cases, s21_big_dec_set_scale_test);
  suite_add_tcase(suite, normal_cases);

  return suite;
}
