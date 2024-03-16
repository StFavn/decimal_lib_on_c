#ifndef SRC_UNIT_TESTS_UTILS_H_
#define SRC_UNIT_TESTS_UTILS_H_

#include "../s21_big_decimal.h"
#include "../s21_decimal.h"

// Macroses
#define GET_SIZE_ARRAY(array) (sizeof(array) / sizeof(array[0]))

// Test helpers
__uint128_t s21_dec_to_uint128_test(s21_decimal dec);
__uint128_t s21_big_dec_to_uint128_test(s21_big_decimal dec);

#endif  // SRC_UNIT_TESTS_UTILS_H_