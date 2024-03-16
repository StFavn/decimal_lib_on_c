#ifndef SRC_S21_BIG_DECIMAL_H_
#define SRC_S21_BIG_DECIMAL_H_

#include <stdint.h>

/*
 * s21_big_decimal structure:
 * [0], [1], [2], [3], [4], [5], [6] - mant (0 ... 223 bits)
 * [7] - exp (224 ... 255 bits)
 *
 * 0  ... 31 ->     bits[0]
 * 32 ... 63 ->     bits[1]
 * 64 ... 95 ->     bits[2]
 * 96 ... 127 ->    bits[3]
 * 128 ... 159 ->   bits[4]
 * 160 ... 191 ->   bits[5]
 * 192 ... 223 ->   bits[6]
 * 224 ... 255 ->   bits[7]
 */
typedef struct s21_big_decimal {
  uint32_t bits[8];
} s21_big_decimal;

#endif  // !SRC_S21_BIG_DECIMAL_H_