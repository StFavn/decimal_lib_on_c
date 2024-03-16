#ifndef SRC_UTILS_LOGIC_H_
#define SRC_UTILS_LOGIC_H_

#include <stdbool.h>

#include "s21_big_decimal.h"
#include "s21_decimal.h"

// mantiss
int s21_mantiss_compare(s21_decimal val_1, s21_decimal val_2);
int s21_big_mantiss_compare(s21_big_decimal val_1, s21_big_decimal val_2);

// decimal
int s21_compare(s21_decimal val_1, s21_decimal val_2);
bool s21_dec_is_zero(s21_decimal val);

// big decimal
int s21_big_dec_compare(s21_big_decimal val_1, s21_big_decimal val_2);
bool s21_big_dec_is_equal(s21_big_decimal val_1, s21_big_decimal val_2);
bool s21_big_dec_is_zero(s21_big_decimal val);

#endif  // SRC_UTILS_LOGIC_H_