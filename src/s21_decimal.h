#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#define S21_DEC_MAX_FLOAT 7.922816e+28
#define S21_DEC_MIN_FLOAT 1e-28

/*
 * s21_decimal structure:
 * [0], [1], [2] - mant (0 ... 95 bits)
 * [3] - exp (95 ... 127 bits)
 *
 * 0  ... 31 -> bits[0]
 * 32 ... 63 -> bits[1]
 * 64 ... 95 -> bits[2]
 * 95 ... 127 -> bits[3]
 * bits[3] --> Available only 16-23 (101-108) bits
 * bits[3] --> Values: 0-128 (2^7)
 * bits[3] --> 31 (127) bit is sign
 */
typedef struct s21_decimal {
  uint32_t bits[4];
} s21_decimal;

// Arithmetic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Logic
int s21_is_equal(s21_decimal val_1, s21_decimal val_2);
int s21_is_not_equal(s21_decimal val_1, s21_decimal val_2);
int s21_compare(s21_decimal val_1, s21_decimal val_2);
int s21_is_greater(s21_decimal val_1, s21_decimal val_2);
int s21_is_greater_or_equal(s21_decimal val_1, s21_decimal val_2);
int s21_is_less(s21_decimal val_1, s21_decimal val_2);
int s21_is_less_or_equal(s21_decimal val_1, s21_decimal val_2);

// Converters
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

// Math
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);

#endif  // !SRC_S21_DECIMAL_H_