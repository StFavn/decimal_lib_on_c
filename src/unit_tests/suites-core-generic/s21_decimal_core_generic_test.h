#ifndef SRC_UNIT_S21_DECIMAL_CORE_GENERIC_TEST_H_
#define SRC_UNIT_S21_DECIMAL_CORE_GENERIC_TEST_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_big_decimal.h"
#include "../s21_decimal.h"
#include "test_utils.h"
#include "utils/all_decimal.h"

// Arithmetic
Suite *all_arithmetic_functions_cases();

#endif  // SRC_UNIT_S21_DECIMAL_CORE_GENERIC_TEST_H_