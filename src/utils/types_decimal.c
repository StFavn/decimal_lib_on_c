#include "utils/types_decimal.h"

#include "utils/bits_decimal.h"

s21_decimal s21_dec_get_max() {
  s21_decimal res = {
      .bits[0] = 0xFFFFFFFF, .bits[1] = 0xFFFFFFFF, .bits[2] = 0xFFFFFFFF};

  return res;
}

s21_big_decimal s21_big_dec_get_max() {
  s21_big_decimal res = {.bits[0] = 0xFFFFFFFF,
                         .bits[1] = 0xFFFFFFFF,
                         .bits[2] = 0xFFFFFFFF,
                         .bits[3] = 0xFFFFFFFF,
                         .bits[4] = 0xFFFFFFFF,
                         .bits[5] = 0xFFFFFFFF,
                         .bits[6] = 0xFFFFFFFF};
  return res;
}

s21_decimal s21_dec_get_min() {
  s21_decimal res = s21_dec_get_max();

  s21_dec_set_sign(&res, S21_SIGN_MINUS);

  return res;
}

s21_big_decimal s21_big_dec_get_min() {
  s21_big_decimal res = s21_big_dec_get_max();

  s21_big_dec_set_sign(&res, S21_SIGN_MINUS);

  return res;
}

s21_decimal s21_dec_get_zero_five() {
  s21_decimal res = {.bits[0] = 5};
  s21_dec_set_scale(&res, 1);

  return res;
}

s21_decimal s21_dec_get_one() {
  s21_decimal res = {.bits[0] = 1};
  return res;
}
