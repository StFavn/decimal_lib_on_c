#include "utils/arithmetic_decimal.h"

#include <string.h>

#include "../utils/all_decimal.h"
#include "all_decimal.h"
#include "s21_big_decimal.h"
#include "s21_decimal.h"
#include "utils/bits_decimal.h"
#include "utils/logic_decimal.h"
#include "utils/types_decimal.h"

/**
 * @brief Осуществить сложение целочисленных мантисс s21_decimal
 * При переполнении осуществляется потеря старшего бита мантиссы.
 * @param value_1 Первое слагаемое
 * @param value_2 Второе слагаемое
 * @param result Указатель на результат выполнения операции
 * @return Успешное выполнение: 0 OK; Переполнение: 1 ERROR
 */
int s21_mantiss_addition(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal *result) {
  bool carry_bit = 0;

  for (size_t i = 0; i < S21_DEC_MANT_BITS; ++i) {
    bool value_1_bit = s21_dec_get_bit(value_1, i);
    bool value_2_bit = s21_dec_get_bit(value_2, i);
    bool add_bits_result = s21_add_bits(value_1_bit, value_2_bit, carry_bit);

    s21_dec_set_bit(result, i, add_bits_result);
    // (b1 & b2) | ((b1 | b2) & cb)
    carry_bit =
        (value_1_bit & value_2_bit) | ((value_1_bit | value_2_bit) & carry_bit);
  }

  // Если после завершения цикла остался перенос разряда -> Переполнение
  return (carry_bit) ? S21_RETURN_CODE_ERR : S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить сложение целочисленных мантисс s21_big_decimal
 * При переполнении осуществляется потеря старшего бита мантиссы.
 * @param value_1 Первое слагаемое
 * @param value_2 Второе слагаемое
 * @param result Указатель на результат выполнения операции
 * @return Успешное выполнение: 0 OK; Переполнение: 1 ERROR
 */
int s21_big_mantiss_addition(s21_big_decimal value_1, s21_big_decimal value_2,
                             s21_big_decimal *result) {
  bool carry_bit = 0;

  for (size_t i = 0; i < S21_BIG_DEC_MANT_BITS; ++i) {
    bool value_1_bit = s21_big_dec_get_bit(value_1, i);
    bool value_2_bit = s21_big_dec_get_bit(value_2, i);
    bool add_bits_result = s21_add_bits(value_1_bit, value_2_bit, carry_bit);

    s21_big_dec_set_bit(result, i, add_bits_result);
    // (b1 & b2) | ((b1 | b2) & cb)
    carry_bit =
        (value_1_bit & value_2_bit) | ((value_1_bit | value_2_bit) & carry_bit);
  }

  // Если после завершения цикла остался перенос разряда -> Переполнение
  return (carry_bit) ? S21_RETURN_CODE_ERR : S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить умножение s21_decimal на 10 в заданной степени
 * по формуле: res = (dec << 3) + (dec << 1)
 * При переполнении вернуть ошибку; умножаемое не менять.
 * @param dec Указательн на умножаемое
 * @param ten_power Степень 10
 * @return Успешное выполнение: 0 OK; Переполнение: 1 ERROR
 */
int s21_dec_mult_by_ten(s21_decimal *dec, int ten_power) {
  if (dec == NULL || !s21_dec_is_valid(*dec)) return S21_RETURN_CODE_ERR;
  if (ten_power < 0) return S21_RETURN_CODE_ERR;
  if (ten_power == 0) return S21_RETURN_CODE_OK;

  s21_decimal tmp = *dec;
  int is_overflow = 0;

  for (int i = 0; (i < ten_power) && !is_overflow; ++i) {
    s21_decimal ten_mult_tmp = tmp;

    is_overflow = s21_left_shift(&ten_mult_tmp, 3);
    if (!is_overflow) {
      s21_left_shift(&tmp, 1);
      is_overflow = s21_mantiss_addition(tmp, ten_mult_tmp, &tmp);
    }
  }

  if (!is_overflow) {
    *dec = tmp;
  }

  return (is_overflow) ? S21_RETURN_CODE_ERR : S21_RETURN_CODE_OK;
}

void s21_big_dec_mult_by_ten(s21_big_decimal *dec, int ten_power) {
  // res = (dec << 3) + (dec << 1)
  for (int i = 0; i < ten_power; ++i) {
    s21_big_decimal dec_tmp = *dec;

    s21_big_left_shift(&dec_tmp, 3);
    s21_big_left_shift(dec, 1);
    s21_big_mantiss_addition(*dec, dec_tmp, dec);
  }
}

/**
 * @brief Осуществить вычитание мантисс s21_decimal
 * Контроль входных данных не осуществляется
 * Уменьшаемое должно быть больше вычитаемого (по модулю)
 * @param value_1 Уменьшаемое (большее число)
 * @param value_2 Вычитаемое (меньшее число)
 * @param result Указатель на результат выполнения операции
 * @return Успешное выполнение: 0 OK; Ошибка: 1 ERROR
 */
int s21_mantiss_sub(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  if (s21_dec_is_zero(value_2)) {
    *result = value_1;
    return S21_RETURN_CODE_OK;
  }

  bool carry_bit = 0;

  for (size_t i = 0; i < S21_DEC_MANT_BITS; ++i) {
    bool value_1_bit = s21_dec_get_bit(value_1, i);
    bool value_2_bit = s21_dec_get_bit(value_2, i);
    bool add_bits_result = s21_add_bits(value_1_bit, value_2_bit, carry_bit);

    s21_dec_set_bit(result, i, add_bits_result);
    // (!b1 & b2) | ((!b1 | b2) & cb)
    carry_bit = (!value_1_bit & value_2_bit) |
                ((!value_1_bit | value_2_bit) & carry_bit);
  }

  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить вычитание мантисс s21_big_decimal
 * Контроль входных данных не осуществляется
 * Уменьшаемое должно быть больше вычитаемого
 * @param value_1 Уменьшаемое (большее число)
 * @param value_2 Вычитаемое (меньшее число)
 * @param result Указатель на результат выполнения операции
 * @return Успешное выполнение: 0 OK; Ошибка: 1 ERROR
 */
int s21_big_mantiss_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  if (s21_big_dec_is_zero(value_2)) {
    *result = value_1;
    return S21_RETURN_CODE_OK;
  }

  bool carry_bit = 0;

  for (size_t i = 0; i < S21_BIG_DEC_MANT_BITS; ++i) {
    bool value_1_bit = s21_big_dec_get_bit(value_1, i);
    bool value_2_bit = s21_big_dec_get_bit(value_2, i);
    bool add_bits_result = s21_add_bits(value_1_bit, value_2_bit, carry_bit);

    s21_big_dec_set_bit(result, i, add_bits_result);
    // (!b1 & b2) | ((!b1 | b2) & cb)
    carry_bit = (!value_1_bit & value_2_bit) |
                ((!value_1_bit | value_2_bit) & carry_bit);
  }

  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить приведение s21_decimal аргументов к единой степени 10
 * (scale) Контроль входных данных не осуществляется
 * @param value_1 Первый s21_decimal аргумент
 * @param value_2 Второй s21_decimal аргумент
 * @return Успешное выполнение: 0 OK; Переполнение: 1 ERROR
 */
int s21_dec_normalize(s21_decimal *value_1, s21_decimal *value_2) {
  int err = S21_RETURN_CODE_OK;

  int scale_val_1 = s21_dec_get_scale(*value_1);
  int scale_val_2 = s21_dec_get_scale(*value_2);

  if (scale_val_1 < scale_val_2) {
    err = s21_dec_scale_increase(value_1, scale_val_2 - scale_val_1);
  } else if (scale_val_1 > scale_val_2) {
    err = s21_dec_scale_increase(value_2, scale_val_1 - scale_val_2);
  }

  return err;
}

int s21_big_dec_normalize(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int err = S21_RETURN_CODE_OK;

  int scale_val_1 = s21_big_dec_get_scale(*value_1);
  int scale_val_2 = s21_big_dec_get_scale(*value_2);

  if (scale_val_1 < scale_val_2) {
    err = s21_big_dec_scale_increase(value_1, scale_val_2 - scale_val_1);
  } else if (scale_val_1 > scale_val_2) {
    err = s21_big_dec_scale_increase(value_2, scale_val_1 - scale_val_2);
  }

  return err;
}
/**
 * @brief Осуществить сокращение конечных нулей s21_decimal
 * мантисы и экспоненты (1200/100 -> 12/1);
 * Контроль входных данных не осуществляется
 * @param dec Первый аргумент
 * @return Успешное выполнение: 0 OK; Ошибка: 1 ERROR
 */
int s21_dec_truncate_trailing_zeros(s21_decimal *dec) {
  if (dec == NULL || !s21_dec_is_valid(*dec)) return S21_RETURN_CODE_ERR;
  if (s21_dec_is_zero(*dec)) {
    s21_dec_set_scale(dec, 0);
    return S21_RETURN_CODE_OK;
  }

  uint32_t dec_scale = s21_dec_get_scale(*dec);
  if (dec_scale == 0) return S21_RETURN_CODE_OK;

  s21_decimal ten = {0};
  ten.bits[0] = 10;

  s21_decimal rem = {0};
  s21_decimal tmp = *dec;

  // #NOTE: Save sign, because mantis_div() work with only |x| and remove sign
  // of args.
  bool sign = s21_dec_get_sign(*dec);

  while (true) {
    s21_mantiss_div(tmp, ten, &tmp, &rem);
    if ((dec_scale == 0) || (!s21_dec_is_zero(rem))) {
      break;
    }
    *dec = tmp;
    --dec_scale;
  }

  s21_dec_set_scale(dec, dec_scale);
  if (sign) s21_dec_set_sign(dec, sign);
  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить целочисленное деление мантисс с получением остатка
 * двух модулей s21_decimal
 * @param value_1 Делимое
 * @param value_2 Делитель
 * @param res Указатель на результат деления
 * @param rem Указатель на остаток
 * @return Успешное выполнение: 0 OK; Ошибка: код ошибки
 */
int s21_mantiss_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *res,
                    s21_decimal *rem) {
  if (res == NULL || rem == NULL) return S21_RETURN_CODE_ERR;
  if (s21_dec_is_zero(value_2)) return S21_RETURN_DIV_BY_ZERO;

  memset(res, 0, sizeof(s21_decimal));
  memset(rem, 0, sizeof(s21_decimal));

  if (s21_dec_is_zero(value_1)) return S21_RETURN_CODE_OK;

  value_1 = s21_dec_mod(value_1);
  value_2 = s21_dec_mod(value_2);

  if (s21_mantiss_compare(value_2, value_1) == 1) {
    *rem = s21_dec_mod(value_1);
    return S21_RETURN_CODE_OK;
  }

  s21_decimal one = {0};
  one.bits[0] = 1;

  if (s21_is_equal(value_1, value_2)) {
    *res = one;
    return S21_RETURN_CODE_OK;
  }

  if (s21_is_equal(one, value_2)) {
    *res = value_1;
    return S21_RETURN_CODE_OK;
  }

  // Получить старший бит делимого
  uint32_t divident_h_bit = s21_dec_get_high_bit(value_1);

  // Выполнить деление
  for (int i = divident_h_bit; i > 0; --i) {
    s21_left_shift(rem, 1);

    // mask = ((a >> (i - 1)) & 1);
    s21_decimal mask = value_1;
    s21_right_shift(&mask, i - 1);
    s21_dec_and(mask, one, &mask);

    // *rem |= mask;
    s21_dec_or(*rem, mask, rem);

    if (s21_mantiss_compare(*rem, value_2) >= 0) {
      s21_mantiss_sub(*rem, value_2, rem);
      s21_decimal mask = one;
      s21_left_shift(&mask, (i - 1));
      s21_dec_or(*res, mask, res);
    }
  }

  return s21_dec_is_zero(*res) ? S21_RETURN_TOO_SML : S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить целочисленное деление мантисс с получением остатка
 * двух s21_big_decimal
 * Функция не является безопасной, проверки на корректность параметров
 * необходимо осуществлять до её вызова.
 * @param value_1 Делимое
 * @param value_2 Делитель
 * @param res Указатель на результат деления
 * @param rem Указатель на остаток
 * @return Успешное выполнение: 0 OK; Ошибка: код ошибки
 */
int s21_big_mantiss_div(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *res, s21_big_decimal *rem) {
  if (res == NULL || rem == NULL) return S21_RETURN_CODE_ERR;
  if (s21_big_dec_is_zero(value_2)) return S21_RETURN_DIV_BY_ZERO;

  memset(res, 0, sizeof(s21_big_decimal));
  memset(rem, 0, sizeof(s21_big_decimal));

  if (s21_big_dec_is_zero(value_1)) return S21_RETURN_CODE_OK;

  s21_big_decimal one = {0};
  one.bits[0] = 1;

  uint32_t divident_h_bit = s21_big_dec_get_high_bit(value_1);

  // Выполнить деление
  for (int i = divident_h_bit; i > 0; --i) {
    s21_big_left_shift(rem, 1);

    // mask = ((a >> (i - 1)) & 1);
    s21_big_decimal mask = value_1;
    s21_big_right_shift(&mask, i - 1);
    s21_big_dec_and(mask, one, &mask);

    // *rem |= mask;
    s21_big_dec_or(*rem, mask, rem);

    // if (s21_is_greater_or_equal(*rem, value_2))
    if (s21_big_mantiss_compare(*rem, value_2) >= 0) {
      s21_big_mantiss_sub(*rem, value_2, rem);
      s21_big_decimal mask = one;
      s21_big_left_shift(&mask, (i - 1));
      s21_big_dec_or(*res, mask, res);
    }
  }

  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить банковское округление к ближайшему чётному
 * мантиссы s21_big_decimal на заданное число позиций после запятой.
 * @param dec Значение s21_big_decimal
 * @param position На сколько необходимо сократить дробную часть
 * @return Успешное выполнение: 0 OK; Ошибка: 1 (превышение scale,
 * некорректные данные)
 */
int s21_big_dec_bank_round(s21_big_decimal *dec, int position) {
  if (dec == NULL || position < 0) return S21_RETURN_CODE_ERR;
  // Проверка избыточна, т.к. имеем дело со степенями больше 28
  // if (!s21_big_dec_is_valid(*dec)) return S21_RETURN_CODE_ERR;
  int scale = s21_big_dec_get_scale(*dec) - position;
  if (scale < 0) return S21_RETURN_CODE_ERR;

  bool is_sign = s21_big_dec_get_sign(*dec);
  s21_big_decimal tmp = *dec;
  s21_big_decimal res = {0};
  s21_big_decimal rem = {0};

  s21_big_decimal ten = {0};
  ten.bits[0] = 1;

  s21_big_dec_mult_by_ten(&ten, position);
  s21_big_mantiss_div(tmp, ten, &res, &rem);

  // s21_print_big_decimal(&rem);

  // Сравнение остатка:
  s21_big_decimal half_one = {0};
  half_one.bits[0] = 5;
  if (position) {
    s21_big_dec_mult_by_ten(&half_one, position - 1);
  }

  bool chek_rem = (s21_big_mantiss_compare(rem, half_one) > 0);

  bool check_half = (((res.bits[0] & 1U) != 0) &&
                     (s21_big_mantiss_compare(rem, half_one) == 0));
  if (check_half || chek_rem) {
    s21_big_decimal one = {0};
    one.bits[0] = 1;
    s21_big_mantiss_addition(res, one, &res);
  }

  s21_big_dec_set_scale(&res, scale);
  if (is_sign) {
    s21_big_dec_set_sign(&res, is_sign);
  }
  *dec = res;

  return S21_RETURN_CODE_OK;
}

s21_decimal s21_dec_mod(s21_decimal dec) {
  if (s21_dec_get_sign(dec) == S21_SIGN_MINUS) {
    s21_dec_set_sign(&dec, S21_SIGN_PLUS);
  }
  return dec;
}

/**
 * @brief Осуществить сокращение конечных нулей s21_big_decimal
 * мантисы и экспоненты (1200/100 -> 12/1);
 * Контроль входных данных не осуществляется
 * @param big_dec Первый аргумент
 * @return Успешное выполнение: 0 OK; Ошибка: 1 ERROR
 */
int s21_big_dec_truncate_trailing_zeros(s21_big_decimal *big_dec) {
  if (big_dec == NULL) return S21_RETURN_CODE_ERR;
  if (s21_big_dec_is_zero(*big_dec)) {
    s21_big_dec_set_scale(big_dec, 0);
    return S21_RETURN_CODE_OK;
  }

  int big_dec_scale = s21_big_dec_get_scale(*big_dec);
  if (big_dec_scale == 0) return S21_RETURN_CODE_OK;

  s21_big_decimal ten = {0};
  ten.bits[0] = 10;

  s21_big_decimal rem = {0};
  s21_big_decimal tmp = *big_dec;

  // #NOTE: Save sign, because mantis_div() work with only |x| and remove sign
  // of args.
  bool sign = s21_big_dec_get_sign(*big_dec);

  while (true) {
    s21_big_mantiss_div(tmp, ten, &tmp, &rem);
    if ((big_dec_scale == 0) || (!s21_big_dec_is_zero(rem))) {
      break;
    }
    *big_dec = tmp;
    --big_dec_scale;
  }

  s21_big_dec_set_scale(big_dec, big_dec_scale);
  if (sign) s21_big_dec_set_sign(big_dec, sign);

  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить умножение мантисс двух s21_big_decimal
 * @param left_mult Первый множитель
 * @param right_mult Второй множитель
 * @return Успешное выполнение: 0 OK; проверки на ошибки отсутсвуют
 */

int s21_big_mantiss_mult(s21_big_decimal left_mult, s21_big_decimal right_mult,
                         s21_big_decimal *result) {
  memset(result, 0, sizeof(s21_big_decimal));

  // Задача сводится к сумме степеней двоек, размещённых на
  // битах right_mult

  for (int i = S21_BIG_DEC_MANT_BITS - 1; i >= 0; --i) {
    if (s21_big_dec_get_bit(right_mult, i)) {
      s21_big_decimal shifted_left_mult = left_mult;
      s21_big_left_shift(&shifted_left_mult, i);
      s21_big_mantiss_addition(*result, shifted_left_mult, result);
    }
  }

  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить умножение двух s21_big_decimal
 * @param left_mult Первый множитель
 * @param right_mult Второй множитель
 * @return Успешное выполнение: 0 OK; проверки на ошибки отсутсвуют
 * Контроль переполнения не требуется (избыточен)
 */
int s21_big_dec_mult(s21_big_decimal left_mult, s21_big_decimal right_mult,
                     s21_big_decimal *result) {
  memset(result, 0, sizeof(s21_big_decimal));
  if (s21_big_dec_is_zero(left_mult) || s21_big_dec_is_zero(right_mult))
    return S21_RETURN_CODE_OK;

  uint32_t result_scale =
      s21_big_dec_get_scale(left_mult) + s21_big_dec_get_scale(right_mult);

  s21_big_mantiss_mult(left_mult, right_mult, result);

  s21_big_dec_set_scale(result, result_scale);
  if (s21_big_dec_get_sign(left_mult) ^ s21_big_dec_get_sign(right_mult)) {
    s21_big_dec_set_sign(result, S21_SIGN_MINUS);
  }

  return S21_RETURN_CODE_OK;
}

int s21_big_dec_div(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal *result) {
  bool sign_value_1 = s21_big_dec_get_sign(value_1);
  bool sign_value_2 = s21_big_dec_get_sign(value_2);
  bool res_sign =
      (sign_value_1 ^ sign_value_2) ? S21_SIGN_MINUS : S21_SIGN_PLUS;

  uint32_t scale_value_1 = s21_big_dec_get_scale(value_1);
  uint32_t scale_value_2 = s21_big_dec_get_scale(value_2);
  int result_scale = scale_value_1 - scale_value_2;

  if (result_scale < 0) {
    // Домножить делимое на 10 в степени (result_scale * -1)
    result_scale = -result_scale;
    s21_big_dec_mult_by_ten(&value_1, result_scale);
    result_scale = 0;
  }

  s21_big_decimal tmp = {0};
  s21_big_decimal rem = {0};

  bool is_scale_overflow = false;

  s21_big_mantiss_div(value_1, value_2, &tmp, &rem);

  while ((!s21_big_dec_is_zero(rem) &&
          (s21_big_mantiss_compare(rem, value_2) <= 0)) &&
         !is_scale_overflow) {
    // Если остаток меньше делителя - домножить остаток,
    // в результат записать ноль
    while ((s21_big_mantiss_compare(rem, value_2) < 0) && !is_scale_overflow) {
      is_scale_overflow = (result_scale > 32);
      if (!is_scale_overflow) {
        s21_big_dec_mult_by_ten(&rem, 1);
        s21_big_dec_mult_by_ten(&tmp, 1);
        ++result_scale;
      }
    }

    s21_big_decimal digit = {0};
    s21_big_mantiss_div(rem, value_2, &digit, &rem);
    s21_big_mantiss_addition(tmp, digit, &tmp);
  }

  s21_big_dec_set_scale(&tmp, result_scale);
  s21_big_dec_set_sign(&tmp, res_sign);
  *result = tmp;

  return S21_RETURN_CODE_OK;
}