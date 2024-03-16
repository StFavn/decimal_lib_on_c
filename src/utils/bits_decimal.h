#ifndef SRC_UTILS_S21_BITS_DECIMAL_H_
#define SRC_UTILS_S21_BITS_DECIMAL_H_

#include <stdbool.h>

#include "s21_big_decimal.h"
#include "s21_decimal.h"
#include "utils/bits.h"

#define S21_DECIMAL_BITS (sizeof(s21_decimal) * 8)
#define S21_BIG_DECIMAL_BITS (sizeof(s21_big_decimal) * 8)

#define S21_DEC_SIGN_SHIFT S21_DECIMAL_BITS - 1
#define S21_BIG_DEC_SIGN_SHIFT S21_BIG_DECIMAL_BITS - 1

#define S21_DEC_MANT_BITS 96U
#define S21_DEC_MANT_PARTS 3U

#define S21_BIG_DEC_MANT_BITS 224U
#define S21_BIG_DEC_MANT_PARTS 7U

#define S21_DEC_LOW_SCALE_SHIFT 16U
#define S21_DEC_MAX_SCALE 28U

uint32_t s21_dec_get_shift(uint32_t shift, uint8_t *bits_indx,
                           const uint32_t max_bit);

/* DECIMAL */
void s21_dec_set_bit(s21_decimal *dec, uint32_t shift, bool bit);
bool s21_dec_get_bit(s21_decimal dec, uint32_t shift);
void s21_dec_set_sign(s21_decimal *dec, bool sign);
bool s21_dec_get_sign(s21_decimal dec);
uint32_t s21_dec_get_high_bit(s21_decimal dec);
uint32_t s21_dec_get_low_bit(s21_decimal dec);

s21_decimal s21_dec_get_whole(s21_decimal val);
s21_decimal s21_dec_get_frac(s21_decimal val);

bool s21_dec_is_valid(s21_decimal dec);

int s21_left_shift(s21_decimal *dec, uint32_t shift_amount);
int s21_right_shift(s21_decimal *dec, uint32_t shift_amount);

int s21_dec_set_scale(s21_decimal *dec, uint32_t scale);
uint32_t s21_dec_get_scale(s21_decimal dec);
int s21_dec_scale_increase(s21_decimal *dec, int multiplier);

void s21_dec_and(s21_decimal value_1, s21_decimal value_2, s21_decimal *res);
void s21_dec_or(s21_decimal value_1, s21_decimal value_2, s21_decimal *res);

/* BIG_DECIMAL */
void s21_big_dec_set_bit(s21_big_decimal *dec, uint32_t shift, bool bit);
bool s21_big_dec_get_bit(s21_big_decimal dec, uint32_t shift);
void s21_big_dec_set_sign(s21_big_decimal *dec, bool sign);
bool s21_big_dec_get_sign(s21_big_decimal dec);
uint32_t s21_big_dec_get_high_bit(s21_big_decimal dec);

bool s21_big_dec_is_valid(s21_big_decimal dec);

int s21_big_dec_set_scale(s21_big_decimal *dec, uint32_t scale);
uint32_t s21_big_dec_get_scale(s21_big_decimal dec);
int s21_big_dec_scale_increase(s21_big_decimal *dec, int multiplier);

int s21_big_left_shift(s21_big_decimal *dec, uint32_t shift_amount);
int s21_big_right_shift(s21_big_decimal *dec, uint32_t shift_amount);

void s21_big_dec_and(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *res);
void s21_big_dec_or(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal *res);

#endif  // !SRC_UTILS_S21_BITS_DECIMAL_H_