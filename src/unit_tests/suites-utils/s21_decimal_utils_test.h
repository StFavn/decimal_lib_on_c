#ifndef SRC_UNIT_S21_DECIMAL_UTILS_TEST_H_
#define SRC_UNIT_S21_DECIMAL_UTILS_TEST_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_big_decimal.h"
#include "../s21_decimal.h"
#include "../utils/all_decimal.h"
#include "test_utils.h"

// Bits
Suite *suite_s21_bits();
Suite *suite_s21_bits_decimal();
Suite *suite_s21_bits_big_decimal();
Suite *suite_s21_dec_scale_increase();
Suite *suite_s21_big_dec_scale_increase();

// Arithmetic
Suite *suite_s21_left_shift();
Suite *suite_s21_right_shift();
Suite *suite_s21_mantiss_add();
Suite *suite_s21_mantiss_sub();

Suite *suite_s21_normalize();
Suite *suite_s21_dec_normalize();
Suite *suite_s21_big_dec_normalize();
Suite *suite_s21_mantiss_div();
Suite *suite_s21_big_mantiss_div();
Suite *suite_s21_big_dec_mult10();
Suite *suite_s21_big_dec_bank_round();
Suite *suite_s21_truncate_trailing_zeros();
Suite *suite_s21_big_dec_mantiss_mult();
Suite *suite_s21_big_dec_mult();

// Converters
Suite *suite_s21_bd_converters();
Suite *suite_s21_str_to_dec();
Suite *suite_s21_print_decimal();
Suite *suite_s21_float_to_dec();
Suite *suite_s21_convert_bd_to_dec();

// Logic
Suite *suite_s21_compare();
Suite *suite_s21_big_dec_compare();
Suite *suite_s21_big_dec_is_equal();
Suite *suite_s21_dec_is_zero();
Suite *suite_s21_big_dec_is_zero();

#endif  // SRC_UNIT_S21_DECIMAL_UTILS_TEST_H_