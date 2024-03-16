#ifndef SRC_UTILS_S21_ARITHM_DECIMAL_H_
#define SRC_UTILS_S21_ARITHM_DECIMAL_H_

#include "s21_big_decimal.h"
#include "s21_decimal.h"

/* DECIMAL */
int s21_mantiss_addition(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal *result);
int s21_mantiss_sub(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
int s21_mantiss_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *res,
                    s21_decimal *rem);

int s21_dec_mult_by_ten(s21_decimal *dec, int ten_power);
int s21_dec_normalize(s21_decimal *value_1, s21_decimal *value_2);
int s21_dec_truncate_trailing_zeros(s21_decimal *dec);
s21_decimal s21_dec_mod(s21_decimal dec);

/* BIG_DECIMAL */
int s21_big_mantiss_addition(s21_big_decimal value_1, s21_big_decimal value_2,
                             s21_big_decimal *result);
int s21_big_mantiss_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);
int s21_big_mantiss_div(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *res, s21_big_decimal *rem);

int s21_big_mantiss_mult(s21_big_decimal left_mult, s21_big_decimal right_mult,
                         s21_big_decimal *result);
int s21_big_dec_mult(s21_big_decimal left_mult, s21_big_decimal right_mult,
                     s21_big_decimal *result);
int s21_big_dec_div(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal *result);

void s21_big_dec_mult_by_ten(s21_big_decimal *dec, int ten_power);
int s21_big_dec_normalize(s21_big_decimal *value_1, s21_big_decimal *value_2);
int s21_big_dec_bank_round(s21_big_decimal *dec, int position);
int s21_big_dec_truncate_trailing_zeros(s21_big_decimal *big_dec);

#endif  // !SRC_UTILS_S21_ARITHM_DECIMAL_H_