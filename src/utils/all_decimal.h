#ifndef SRC_UTILS_ALL_DECIMAL_H_
#define SRC_UTILS_ALL_DECIMAL_H_

#include "s21_decimal.h"
#include "utils/arithmetic_decimal.h"
#include "utils/bits_decimal.h"
#include "utils/converters_decimal.h"
#include "utils/logic_decimal.h"
#include "utils/types_decimal.h"

// Output to stdout
void s21_print_decimal_base(const s21_decimal *dec);
void s21_print_decimal(const s21_decimal *dec);
void s21_print_big_decimal_base(const s21_big_decimal *dec);
void s21_print_big_decimal(const s21_big_decimal *dec);
void s21_print_uint32(uint32_t x);

#endif  // SRC_UTILS_ALL_DECIMAL_H_