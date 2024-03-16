#ifndef SRC_UTILS_CONVERTERS_DECIMAL_H_
#define SRC_UTILS_CONVERTERS_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_big_decimal.h"
#include "s21_decimal.h"

int s21_str_to_dec(char *str, s21_decimal *dec);
s21_big_decimal s21_dec_to_bigdec(const s21_decimal dec);
int s21_bigdec_to_dec(s21_big_decimal big_dec, s21_decimal *dec);

// Helpers
long double s21_dec_to_ld(const s21_decimal *dec);
s21_decimal s21_dec_init(char *dec_str);

#endif  // SRC_UTILS_CONVERTERS_DECIMAL_H_