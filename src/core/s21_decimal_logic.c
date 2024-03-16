#include <stdbool.h>

#include "s21_big_decimal.h"
#include "s21_decimal.h"
#include "utils/arithmetic_decimal.h"
#include "utils/bits_decimal.h"
#include "utils/converters_decimal.h"
#include "utils/logic_decimal.h"
#include "utils/types_decimal.h"

/**
 * @brief Проверка на равенство двух `s21_decimal`
 * Контроль входных данных не осуществляется.
 * @param val_1 Первый операнд сравнения `s21_decimal`
 * @param val_2 Второй операнд сравнения `s21_decimal`
 * @return Результат: `1` TRUE (равны); `0` FALSE (не равны)
 */
int s21_is_equal(s21_decimal val_1, s21_decimal val_2) {
  s21_big_decimal bg_val_1 = s21_dec_to_bigdec(val_1);
  s21_big_decimal bg_val_2 = s21_dec_to_bigdec(val_2);

  return s21_big_dec_is_equal(bg_val_1, bg_val_2);
}

/**
 * @brief Проверка на НЕ равенство двух `s21_decimal`
 * Контроль входных данных не осуществляется.
 * @param val_1 Первый операнд сравнения `s21_decimal`
 * @param val_2 Второй операнд сравнения `s21_decimal`
 * @return Результат: `1` TRUE (не равны); `0` FALSE (равны)
 */
int s21_is_not_equal(s21_decimal val_1, s21_decimal val_2) {
  return !s21_is_equal(val_1, val_2);
}

int s21_is_greater(s21_decimal val_1, s21_decimal val_2) {
  s21_big_decimal bg_val_1 = s21_dec_to_bigdec(val_1);
  s21_big_decimal bg_val_2 = s21_dec_to_bigdec(val_2);

  return s21_big_dec_compare(bg_val_1, bg_val_2) == 1;
}

int s21_is_greater_or_equal(s21_decimal val_1, s21_decimal val_2) {
  s21_big_decimal bg_val_1 = s21_dec_to_bigdec(val_1);
  s21_big_decimal bg_val_2 = s21_dec_to_bigdec(val_2);

  return s21_big_dec_compare(bg_val_1, bg_val_2) >= 0;
}

int s21_is_less(s21_decimal val_1, s21_decimal val_2) {
  s21_big_decimal bg_val_1 = s21_dec_to_bigdec(val_1);
  s21_big_decimal bg_val_2 = s21_dec_to_bigdec(val_2);

  return s21_big_dec_compare(bg_val_1, bg_val_2) == -1;
}

int s21_is_less_or_equal(s21_decimal val_1, s21_decimal val_2) {
  s21_big_decimal bg_val_1 = s21_dec_to_bigdec(val_1);
  s21_big_decimal bg_val_2 = s21_dec_to_bigdec(val_2);

  return s21_big_dec_compare(bg_val_1, bg_val_2) <= 0;
}