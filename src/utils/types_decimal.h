#ifndef SRC_S21_TYPES_H_
#define SRC_S21_TYPES_H_

#include "s21_big_decimal.h"
#include "s21_decimal.h"

#define S21_RETURN_CODE_OK 0
#define S21_RETURN_CODE_ERR 1

#define S21_RETURN_TOO_BIG 1  // Число слишком велико или равно бесконечности
#define S21_RETURN_TOO_SML \
  2  // Число слишком мало или равно отрицательной бесконечности
#define S21_RETURN_DIV_BY_ZERO 3  // Деление на 0

#define S21_SIGN_PLUS 0
#define S21_SIGN_MINUS 1

s21_decimal s21_dec_get_max();
s21_decimal s21_dec_get_min();

s21_big_decimal s21_big_dec_get_max();
s21_big_decimal s21_big_dec_get_min();

s21_decimal s21_dec_get_zero_five();
s21_decimal s21_dec_get_one();

#endif  // !SRC_S21_TYPES_H_