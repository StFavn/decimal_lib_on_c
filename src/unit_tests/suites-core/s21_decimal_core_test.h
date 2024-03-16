#ifndef SRC_UNIT_S21_DECIMAL_CORE_TEST_H_
#define SRC_UNIT_S21_DECIMAL_CORE_TEST_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_big_decimal.h"
#include "../s21_decimal.h"
#include "test_utils.h"
#include "utils/all_decimal.h"

// Arithmetic
Suite *suite_s21_add();
Suite *suite_s21_sub();
Suite *suite_s21_mul();
Suite *suite_s21_div();

// Logic
Suite *suite_s21_is_equal();
Suite *suite_s21_is_not_equal();
Suite *suite_s21_is_greater();
Suite *suite_s21_is_greater_or_equal();
Suite *suite_s21_is_less();
Suite *suite_s21_is_less_or_equal();

// Converters
Suite *suite_s21_float_to_dec();
Suite *suite_s21_dec_to_float();
Suite *suite_s21_int_to_dec();
Suite *suite_s21_dec_to_int();

// Math
Suite *suite_s21_negate();
Suite *suite_s21_truncate();
Suite *suite_s21_floor();
Suite *suite_s21_round();

#endif  // SRC_UNIT_S21_DECIMAL_CORE_TEST_H_