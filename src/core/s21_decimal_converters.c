#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_decimal.h"
#include "utils/all_decimal.h"

#define BUFF_SIZE 256

// FLT_MAX:             340282346638528859811704183484516925440
// S21DMAX:             79228162514264337593543950335
// FLT_MAX for s21_dec: 79228160000000000000000000000
// 7.922816e+28 << S21DMAX в научной нотации

union float_binary {
  float num_float;
  uint32_t num_int;
};

static bool is_e_notation_plus(const char *str);
bool is_float_value_acceptable(const float num, bool *is_min);
static void trim_trail_zeroes(char *str);
static void get_scale_and_ten_miltiplier(char *res_str, int exp_value,
                                         int *scale, int *ten_mult);
static int get_result_str(const char *str, char *res_str);
static bool get_float_sign(const float num);

/**
 * @brief Осуществить преобразование float в s21_decimal
 * Анализируется 7 значащих цифр научной нотации (1.234567)
 * Ограничение значения (по модулю) float:
 * - меньше 7.922816e+28
 * - больше 1e-28
 * @param src Число float
 * @param dst Указатель на s21_decimal
 * @return Успешное выполнение: 0 OK; Ошибка: 1 ERROR
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (dst == NULL) return S21_RETURN_CODE_ERR;

  // Проверка на корректность s21_decimal избыточна,
  // т.к. мы зануляем целевую область памяти

  memset(dst, 0, sizeof(s21_decimal));
  if (isnan(src) || isinf(src)) return S21_RETURN_CODE_ERR;

  if (src != 0) {
    bool is_min = false;
    if (!is_float_value_acceptable(src, &is_min)) {
      return S21_RETURN_CODE_ERR;
    }
  }

  // Сохранить знак
  bool sign = get_float_sign(src);
  src = fabsf(src);

  char src_str[BUFF_SIZE] = {0};
  char res_str[BUFF_SIZE] = {0};
  sprintf(src_str, "%.6e", src);

  int s_notation_exp = get_result_str(src_str, res_str);

  // Убрать конечные нули
  trim_trail_zeroes(res_str);

  // Вычислить scale и степень 10 (на которую домножается мантисса)
  int scale = 0;
  int ten_mult = 0;
  get_scale_and_ten_miltiplier(res_str, s_notation_exp, &scale, &ten_mult);

  // Заполнить s21_decimal
  uint32_t mantiss_value = 0;
  sscanf(res_str, "%u", &mantiss_value);
  dst->bits[0] = mantiss_value;
  s21_dec_mult_by_ten(dst, ten_mult);
  s21_dec_set_sign(dst, sign);

  int code = 0;
  if (scale > (int)S21_DEC_MAX_SCALE) {
    s21_big_decimal tmp = s21_dec_to_bigdec(*dst);
    s21_big_dec_set_scale(&tmp, scale);
    code = s21_bigdec_to_dec(tmp, dst);
  } else {
    s21_dec_set_scale(dst, scale);
  }

  return (code) ? S21_RETURN_CODE_ERR : S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить преобразование s21_decimal во float
 * Гарантируется 7 значащих цифр (ограничение формата float)
 * @param src Число s21_decimal
 * @param dst Указатель на float
 * @return Успешное выполнение: 0 OK; Ошибка: 1 ERROR
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (dst == NULL) return S21_RETURN_CODE_ERR;
  if (!s21_dec_is_valid(src)) return S21_RETURN_CODE_ERR;

  *dst = (s21_dec_get_sign(src)) ? -0.0 : 0.0;
  if (s21_dec_is_zero(src)) return S21_RETURN_CODE_OK;

  long double ld_mantissa = s21_dec_to_ld(&src);
  uint32_t scale = s21_dec_get_scale(src);

  if (scale == 0) {
    *dst = (float)ld_mantissa;
  } else {
    *dst = (float)(ld_mantissa / (powl(10, scale)));
  }

  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить преобразование int (32bit) в s21_decimal
 * @param src Число int
 * @param dst Указатель на s21_decimal
 * @return Успешное выполнение: 0 OK; Ошибка: 1 ERROR
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) return S21_RETURN_CODE_ERR;

  memset(dst, 0, sizeof(s21_decimal));

  if (src < 0) {
    s21_dec_set_sign(dst, S21_SIGN_MINUS);
    if (src == INT32_MIN) {
      s21_dec_set_bit(dst, 31, true);
    } else {
      src = -src;
      dst->bits[0] = src;
    }
  } else {
    dst->bits[0] = src;
  }

  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить преобразование s21_decimal в int (32bit)
 * @param src Число s21_decimal
 * @param dst Указатель на int
 * @return Успешное выполнение: 0 OK; Ошибка: 1 ERROR
 */
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL) {
    return S21_RETURN_CODE_ERR;
  }

  *dst = 0;

  if (s21_truncate(src, &src) == S21_RETURN_CODE_ERR) {
    return S21_RETURN_CODE_ERR;
  }

  uint32_t h_bit_index = s21_dec_get_high_bit(src);
  if (h_bit_index > S21_UINT32_BITS) {
    return S21_RETURN_CODE_ERR;
  }

  if ((s21_dec_get_sign(src) == S21_SIGN_MINUS) &&
      (h_bit_index == S21_UINT32_BITS)) {
    if (s21_is_have_bits_on(src.bits[0], 0, S21_UINT32_BITS - 2)) {
      return S21_RETURN_CODE_ERR;
    }
  }

  uint32_t l_bit_index = s21_dec_get_low_bit(src);
  uint32_t int_max = (uint32_t)INT32_MAX;

  if ((s21_dec_get_sign(src) == S21_SIGN_PLUS) && (src.bits[0] > int_max)) {
    return S21_RETURN_CODE_ERR;
  }

  if ((l_bit_index != S21_UINT32_BITS) &&
      (s21_dec_get_sign(src) == S21_SIGN_MINUS)) {
    *dst = -src.bits[0];
  } else {
    *dst = src.bits[0];
  }

  return S21_RETURN_CODE_OK;
}

bool get_float_sign(const float num) {
  union float_binary f_bin = {0};
  f_bin.num_float = num;
  return s21_get_bit(f_bin.num_int, 31);
}

bool is_e_notation_plus(const char *str) {
  char *ptr = strchr(str, '+');
  return (ptr != NULL);
}

int get_result_str(const char *str, char *res_str) {
  char *e_ptr = strchr(str, 'e');

  int s_notation_exp = 0;
  int exp_sign = 1;
  bool is_e_plus = is_e_notation_plus(str);

  if (is_e_plus) {
    sscanf(e_ptr, "e+%d", &s_notation_exp);
  } else {
    sscanf(e_ptr, "e-%d", &s_notation_exp);
    exp_sign = -1;
  }

  s_notation_exp *= exp_sign;

  int src_str_len = e_ptr - str;
  res_str[0] = str[0];
  for (int i = 2; i < src_str_len; ++i) {
    res_str[i - 1] = str[i];
  }

  return s_notation_exp;
}

void trim_trail_zeroes(char *str) {
  int str_len = strlen(str);
  for (int i = str_len - 1; i >= 0; --i) {
    if (str[i] == '0') {
      str[i] = '\0';
    } else {
      break;
    }
  }
}

void get_scale_and_ten_miltiplier(char *res_str, int exp_value, int *scale,
                                  int *ten_mult) {
  int mantiss_digit_count = strlen(res_str);
  if (exp_value >= 0) {
    if (exp_value < (mantiss_digit_count - 1)) {
      *scale = mantiss_digit_count - 1 - exp_value;
    } else {
      *ten_mult = (exp_value + 1) - mantiss_digit_count;
    }
  } else {
    *scale = -exp_value + (mantiss_digit_count - 1);
  }
}

bool is_float_value_acceptable(const float num, bool *is_min) {
  bool is_acceptable = true;
  *is_min = false;

  if (isnan(num)) {
    is_acceptable = false;
  } else if ((fabsf(num) > S21_DEC_MAX_FLOAT)) {
    is_acceptable = false;
  } else if ((fabsf(num) < S21_DEC_MIN_FLOAT)) {
    if (num != 0) {
      is_acceptable = false;
      *is_min = true;
    }
  }

  return is_acceptable;
}
