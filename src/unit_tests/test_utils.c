#include "test_utils.h"

#include <math.h>

#include "utils/bits_decimal.h"

__uint128_t s21_dec_to_uint128_test(s21_decimal dec) {
  __uint128_t res = 0;
  for (size_t i = 0; i < S21_DEC_MANT_BITS; ++i) {
    __uint128_t tmp = powl(2, i);
    bool mantissa_bit = s21_dec_get_bit(dec, i);
    res += mantissa_bit * tmp;
  }
  return res;
}

__uint128_t s21_big_dec_to_uint128_test(s21_big_decimal dec) {
  __uint128_t res = 0;
  for (size_t i = 0; i < S21_BIG_DEC_MANT_BITS; ++i) {
    __uint128_t tmp = powl(2, i);
    bool mantissa_bit = s21_big_dec_get_bit(dec, i);
    res += mantissa_bit * tmp;
  }
  return res;
}