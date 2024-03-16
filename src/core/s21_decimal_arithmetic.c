#include <stdbool.h>

#include "s21_decimal.h"
#include "utils/all_decimal.h"

/**
 * @brief Осуществить сложение мантисс с учетом степини
 * (с приведением наибольшей степени слогаемых)
 * @param value_1 Первое слагаемое
 * @param value_2 Второе слагаемое
 * @param result Указатель на результат выполнения операции
 * @return Успешное выполнение: 0 OK; Переполнение: 1 ERROR
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return S21_RETURN_CODE_ERR;
  if (!s21_dec_is_valid(value_1) || !s21_dec_is_valid(value_2))
    return S21_RETURN_CODE_ERR;

  memset(result, 0, sizeof(s21_decimal));

  if (s21_dec_is_zero(value_1) && s21_dec_is_zero(value_2))
    return S21_RETURN_CODE_OK;

  int res_code = S21_RETURN_CODE_OK;
  bool sign_minus_1 = s21_dec_get_sign(value_1);
  bool sign_minus_2 = s21_dec_get_sign(value_2);

  // if a < 0 and b > 0: return s21_sub(b, +a)
  // if a > 0 and b < 0: return s21_sub(+a, b)
  // if a < 0 and b < 0: return -s21_add(+a, +b)

  if (s21_dec_is_zero(value_1)) {
    *result = value_2;
  } else if (s21_dec_is_zero(value_2)) {
    *result = value_1;
  } else if (sign_minus_1 && !sign_minus_2) {
    s21_dec_set_sign(&value_1, S21_SIGN_PLUS);
    res_code = s21_sub(value_2, value_1, result);

  } else if (!sign_minus_1 && sign_minus_2) {
    s21_dec_set_sign(&value_2, S21_SIGN_PLUS);
    res_code = s21_sub(value_1, value_2, result);
  } else if (sign_minus_1 && sign_minus_2) {
    s21_dec_set_sign(&value_1, S21_SIGN_PLUS);
    s21_dec_set_sign(&value_2, S21_SIGN_PLUS);
    res_code = s21_add(value_1, value_2, result);
    if (res_code == S21_RETURN_CODE_OK)
      s21_dec_set_sign(result, S21_SIGN_MINUS);
    else
      res_code = S21_RETURN_TOO_SML;
  } else {
    s21_big_decimal big_value_1 = s21_dec_to_bigdec(value_1);
    s21_big_decimal big_value_2 = s21_dec_to_bigdec(value_2);
    s21_big_decimal big_result = {0};

    res_code = s21_big_dec_normalize(&big_value_1, &big_value_2);

    if (res_code == S21_RETURN_CODE_OK) {
      uint32_t scale = s21_big_dec_get_scale(big_value_1);
      s21_big_dec_set_scale(&big_result, scale);

      res_code =
          s21_big_mantiss_addition(big_value_1, big_value_2, &big_result);

      if (res_code == S21_RETURN_CODE_OK) {
        res_code = s21_bigdec_to_dec(big_result, result);
      }
    }
  }

  s21_dec_truncate_trailing_zeros(result);

  return res_code;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return S21_RETURN_CODE_ERR;
  if (!s21_dec_is_valid(value_1) || !s21_dec_is_valid(value_2))
    return S21_RETURN_CODE_ERR;
  if (s21_dec_is_zero(value_2)) return S21_RETURN_DIV_BY_ZERO;

  s21_dec_truncate_trailing_zeros(&value_1);
  s21_dec_truncate_trailing_zeros(&value_2);
  s21_decimal one = s21_dec_init("1");

  bool sign_value_1 = s21_dec_get_sign(value_1);
  bool sign_value_2 = s21_dec_get_sign(value_2);
  bool res_sign =
      (sign_value_1 ^ sign_value_2) ? S21_SIGN_MINUS : S21_SIGN_PLUS;

  // Деление одинаковых чисел
  if (s21_is_equal(s21_dec_mod(value_1), s21_dec_mod(value_2))) {
    s21_dec_set_sign(&one, res_sign);
    *result = one;
    return S21_RETURN_CODE_OK;
  }

  // Деление на единицу или деление нуля
  if (s21_dec_is_zero(value_1) || s21_is_equal(s21_dec_mod(value_2), one)) {
    s21_dec_set_sign(&value_1, res_sign);
    *result = value_1;
    return S21_RETURN_CODE_OK;
  }

  memset(result, 0, sizeof(s21_decimal));
  if (s21_dec_is_zero(value_1)) return S21_RETURN_CODE_OK;

  s21_big_decimal value_1_big = s21_dec_to_bigdec(value_1);
  s21_big_decimal value_2_big = s21_dec_to_bigdec(value_2);
  s21_big_decimal result_big = {0};

  s21_big_dec_div(value_1_big, value_2_big, &result_big);

  int status_code = s21_bigdec_to_dec(result_big, result);
  s21_dec_truncate_trailing_zeros(result);

  return status_code;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return S21_RETURN_CODE_ERR;
  if (!s21_dec_is_valid(value_1) || !s21_dec_is_valid(value_2))
    return S21_RETURN_CODE_ERR;

  memset(result, 0, sizeof(s21_decimal));
  if (s21_dec_is_zero(value_1) || s21_dec_is_zero(value_2))
    return S21_RETURN_CODE_OK;

  s21_dec_truncate_trailing_zeros(&value_1);
  s21_dec_truncate_trailing_zeros(&value_2);
  s21_decimal one = s21_dec_init("1");

  if ((s21_is_equal(value_1, one)) || (s21_is_equal(value_2, one))) {
    *result = (s21_is_equal(value_1, one)) ? value_2 : value_1;
    return S21_RETURN_CODE_OK;
  }

  s21_big_decimal value_1_big = s21_dec_to_bigdec(value_1);
  s21_big_decimal value_2_big = s21_dec_to_bigdec(value_2);
  s21_big_decimal result_big = {0};

  s21_big_dec_mult(value_1_big, value_2_big, &result_big);

  int status_code = s21_bigdec_to_dec(result_big, result);
  s21_dec_truncate_trailing_zeros(result);

  return status_code;
}

/**
 * @brief Осуществляетвычитание двух s21_decimal
 * @param value_1 Уменьшаемое (большее число)
 * @param value_2 Вычитаемое (меньшее число)
 * @param result Результат вычитания
 * @return Возвращает код ошибки.
 * @return S21_RETURN_CODE_OK - 0 - успешное выполнение
 * @return S21_RETURN_TOO_BIG - 1 - result число слишком большое
 * @return S21_RETURN_TOO_SML - 2 - result число слишком маленькое
 * @note Задействована функция s21_add для случаев с разным знаком;
 * @note Имеется проверка на валидность числа
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return S21_RETURN_CODE_ERR;
  if (!s21_dec_is_valid(value_1) || !s21_dec_is_valid(value_2))
    return S21_RETURN_CODE_ERR;

  memset(result, 0, sizeof(s21_decimal));

  int res_code = S21_RETURN_CODE_OK;
  bool sign_minus_1 = s21_dec_get_sign(value_1);
  bool sign_minus_2 = s21_dec_get_sign(value_2);

  if (s21_is_equal(value_1, value_2)) {
    res_code = S21_RETURN_CODE_OK;
  } else if (s21_dec_is_zero(value_2)) {
    *result = value_1;
  } else if (s21_dec_is_zero(value_1)) {
    *result = value_2;
    s21_dec_set_sign(result, !sign_minus_2);
  } else if ((!sign_minus_1 && !sign_minus_2) &&
             (s21_compare(value_1, value_2) == -1)) {
    // if (a > 0 and b > 0) and (b > a): return -sub(b, a)
    res_code = s21_sub(value_2, value_1, result);
    if (res_code == S21_RETURN_CODE_OK) {
      s21_dec_set_sign(result, S21_SIGN_MINUS);
    }
  } else if ((sign_minus_1 && sign_minus_2) &&
             (s21_compare(value_1, value_2) == 1)) {
    // if (a < 0 and b < 0) and (a > b): return sub(+b, +a)
    s21_dec_set_sign(&value_1, S21_SIGN_PLUS);
    s21_dec_set_sign(&value_2, S21_SIGN_PLUS);
    res_code = s21_sub(value_2, value_1, result);
  } else if ((sign_minus_1 && sign_minus_2) &&
             (s21_compare(value_1, value_2) == -1)) {
    // if (a < 0 and b < 0) and (b > a): return -sub(+a, +b)
    s21_dec_set_sign(&value_1, S21_SIGN_PLUS);
    s21_dec_set_sign(&value_2, S21_SIGN_PLUS);
    res_code = s21_sub(value_1, value_2, result);

    if (res_code == S21_RETURN_CODE_OK) {
      s21_dec_set_sign(result, S21_SIGN_MINUS);
    }
  } else if (!sign_minus_1 && sign_minus_2) {
    // if a > 0 and b < 0: return add(a, b)
    s21_dec_set_sign(&value_2, S21_SIGN_PLUS);
    res_code = s21_add(value_1, value_2, result);
  } else if (sign_minus_1 && !sign_minus_2) {
    // if a < 0 and b > 0 return: -add(a, b)
    s21_dec_set_sign(&value_1, S21_SIGN_PLUS);
    res_code = s21_add(value_1, value_2, result);

    if (res_code == S21_RETURN_CODE_OK) {
      s21_dec_set_sign(result, S21_SIGN_MINUS);
    } else {
      res_code = S21_RETURN_TOO_SML;
    }
  } else {
    s21_big_decimal big_value_1 = s21_dec_to_bigdec(value_1);
    s21_big_decimal big_value_2 = s21_dec_to_bigdec(value_2);
    s21_big_decimal big_result = {0};

    res_code = s21_big_dec_normalize(&big_value_1, &big_value_2);

    if (res_code == S21_RETURN_CODE_OK) {
      uint32_t scale = s21_big_dec_get_scale(big_value_1);
      s21_big_dec_set_scale(&big_result, scale);

      s21_big_mantiss_sub(big_value_1, big_value_2, &big_result);
      res_code = s21_bigdec_to_dec(big_result, result);
    }
  }

  s21_dec_truncate_trailing_zeros(result);

  return res_code;
}