#include <string.h>

#include "s21_decimal.h"
#include "utils/arithmetic_decimal.h"
#include "utils/bits_decimal.h"
#include "utils/converters_decimal.h"
#include "utils/logic_decimal.h"
#include "utils/types_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return S21_RETURN_CODE_ERR;

  if (s21_dec_get_sign(value) == S21_SIGN_PLUS) {
    s21_dec_set_sign(&value, S21_SIGN_MINUS);
  } else {
    s21_dec_set_sign(&value, S21_SIGN_PLUS);
  }

  *result = value;
  return s21_dec_is_valid(*result) ? S21_RETURN_CODE_OK : S21_RETURN_CODE_ERR;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if ((result == NULL) || !s21_dec_is_valid(value)) return S21_RETURN_CODE_ERR;

  uint32_t value_scale = s21_dec_get_scale(value);
  bool is_value_minus = s21_dec_get_sign(value);

  if (value_scale == 0 || s21_dec_is_zero(value)) {
    *result = value;
  } else {
    if (is_value_minus) s21_dec_set_sign(&value, S21_SIGN_PLUS);
    s21_decimal divider = s21_dec_get_one();
    s21_dec_mult_by_ten(&divider, value_scale);
    s21_decimal rem = {0};

    s21_dec_set_scale(&value, 0);
    s21_mantiss_div(value, divider, result, &rem);

    if (is_value_minus) s21_dec_set_sign(result, S21_SIGN_MINUS);
  }

  s21_dec_set_scale(result, 0);
  return s21_dec_is_valid(*result) ? S21_RETURN_CODE_OK : S21_RETURN_CODE_ERR;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  if ((result == NULL) || !s21_dec_is_valid(value)) return S21_RETURN_CODE_ERR;

  bool is_value_minus = s21_dec_get_sign(value);

  s21_dec_truncate_trailing_zeros(&value);
  bool is_integer = (s21_dec_get_scale(value) == 0);
  s21_truncate(value, result);

  if (is_value_minus && !is_integer) {
    const s21_decimal one = s21_dec_get_one();
    s21_mantiss_addition(*result, one, result);
  }

  return s21_dec_is_valid(*result) ? S21_RETURN_CODE_OK : S21_RETURN_CODE_ERR;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  if ((result == NULL) || !s21_dec_is_valid(value)) return S21_RETURN_CODE_ERR;

  int sign = s21_dec_get_sign(value);
  value = s21_dec_mod(value);

  const s21_decimal frac = s21_dec_get_frac(value);
  s21_truncate(value, &value);

  const s21_decimal one = s21_dec_get_one();
  const s21_decimal zero_five = s21_dec_get_zero_five();
  if (s21_is_equal(frac, zero_five)) {
    s21_decimal tmp = {0};
    s21_decimal rem = {0};
    s21_mantiss_div(value, s21_dec_init("2"), &tmp, &rem);

    if (!s21_is_equal(rem, s21_dec_init("0"))) {
      s21_add(value, one, &value);
    }
  } else if (s21_is_greater(frac, zero_five)) {
    s21_add(value, one, &value);
  }

  *result = value;
  s21_dec_set_sign(result, sign);

  return s21_dec_is_valid(*result) ? S21_RETURN_CODE_OK : S21_RETURN_CODE_ERR;
}