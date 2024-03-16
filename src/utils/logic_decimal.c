#include "utils/logic_decimal.h"

#include "utils/arithmetic_decimal.h"
#include "utils/bits_decimal.h"
#include "utils/converters_decimal.h"
#include "utils/types_decimal.h"

/**
 * @brief сравнение мантисс двух `s21_decimal`
 * Контроль входных данных не осуществляется.
 * @param val_1 Первый операнд сравнения `s21_decimal`
 * @param val_2 Второй операнд сравнения `s21_decimal`
 * @return
 * `1` (первое значение больше второго);
 * `0`  (оба значения равны);
 * `-1` (первое значение меньше второго);
 */
int s21_mantiss_compare(s21_decimal val_1, s21_decimal val_2) {
  int compare_result = 0;

  if (s21_dec_is_zero(val_1) && s21_dec_is_zero(val_2)) return compare_result;

  for (int i = S21_DEC_MANT_BITS - 1, is_found = 0; (i >= 0) && (!is_found);
       --i) {
    bool bit_value_1 = s21_dec_get_bit(val_1, i);
    bool bit_value_2 = s21_dec_get_bit(val_2, i);

    if (bit_value_1 ^ bit_value_2) {
      compare_result = (bit_value_1) ? 1 : -1;
      is_found = 1;
    }
  }

  return compare_result;
}

/**
 * @brief сравнение мантисс двух `s21_big_decimal`
 * Контроль входных данных не осуществляется.
 * @param val_1 Первый операнд сравнения `s21_big_decimal`
 * @param val_2 Второй операнд сравнения `s21_big_decimal`
 * @return
 * `1` (первое значение больше второго);
 * `0`  (оба значения равны);
 * `-1` (первое значение меньше второго);
 */
int s21_big_mantiss_compare(s21_big_decimal val_1, s21_big_decimal val_2) {
  int compare_result = 0;

  if (s21_big_dec_is_zero(val_1) && s21_big_dec_is_zero(val_2))
    return compare_result;

  for (int i = S21_BIG_DEC_MANT_BITS - 1, is_found = 0; (i >= 0) && (!is_found);
       --i) {
    bool bit_value_1 = s21_big_dec_get_bit(val_1, i);
    bool bit_value_2 = s21_big_dec_get_bit(val_2, i);

    if (bit_value_1 ^ bit_value_2) {
      compare_result = (bit_value_1) ? 1 : -1;
      is_found = 1;
    }
  }

  return compare_result;
}

/**
 * @brief сравнение двух `s21_decimal`
 * Контроль входных данных не осуществляется.
 * @param value_1 Первый операнд сравнения `s21_decimal`
 * @param value_2 Второй операнд сравнения `s21_decimal`
 * @return`1` (первое значение больше второго);
 * @return`0`  (оба значения равны);
 * @return`-1` (первое значение меньше второго);
 */
int s21_compare(s21_decimal value_1, s21_decimal value_2) {
  if (s21_is_equal(value_1, value_2)) {
    return 0;
  }

  int res = 0;
  bool is_found = false;

  bool sign_minus_1 = s21_dec_get_sign(value_1);
  bool sign_minus_2 = s21_dec_get_sign(value_2);
  bool common_minus = (sign_minus_1 && sign_minus_2);

  if (sign_minus_1 != sign_minus_2) {
    res = (sign_minus_1 ? -1 : 1);
    is_found = true;
  }

  if (!is_found) {
    if (s21_dec_is_zero(value_1) && !s21_dec_is_zero(value_2)) {
      res = -1;
      is_found = true;
    } else if (!s21_dec_is_zero(value_1) && s21_dec_is_zero(value_2)) {
      res = 1;
      is_found = true;
    }
  }

  if (!is_found) {
    s21_big_decimal big_value_1 = s21_dec_to_bigdec(value_1);
    s21_big_decimal big_value_2 = s21_dec_to_bigdec(value_2);
    int err = s21_big_dec_normalize(&big_value_1, &big_value_2);

    if (err != S21_RETURN_CODE_ERR) {
      for (int i = S21_BIG_DEC_MANT_PARTS; (!is_found) && (i >= 0); i--) {
        uint32_t bits_1 = big_value_1.bits[i];
        uint32_t bits_2 = big_value_2.bits[i];

        if (bits_1 != bits_2) {
          res = (common_minus ? (bits_1 > bits_2 ? -1 : 1)
                              : (bits_1 < bits_2 ? -1 : 1));
          is_found = true;
        }
      }
    }
  }

  return res;
}

/**
 * @brief сравнение двух `s21_big_decimal`
 * Контроль входных данных не осуществляется.
 * Контроль переполнения не осуществяется.
 * @param s21_big_decimal val_1 Первый операнд сравнения `s21_big_decimal`
 * @param s21_big_decimal val_2 Второй операнд сравнения `s21_big_decimal`
 * @return
 * `1` (первое значение больше второго);
 * `0`  (оба значения равны);
 * `-1` (первое значение меньше второго);
 */
int s21_big_dec_compare(s21_big_decimal val_1, s21_big_decimal val_2) {
  if (s21_big_dec_is_equal(val_1, val_2)) return 0;

  int res = 0;

  int sign_1 = s21_big_dec_get_sign(val_1);
  int sign_2 = s21_big_dec_get_sign(val_2);
  bool is_minus_signs =
      ((sign_1 == S21_SIGN_MINUS) && (sign_2 == S21_SIGN_MINUS));

  if (sign_1 != sign_2) {
    res = (sign_1 ? -1 : 1);
  } else if (s21_big_dec_is_zero(val_1) && !s21_big_dec_is_zero(val_2)) {
    res = (sign_2 == S21_SIGN_MINUS) ? 1 : -1;
  } else if (!s21_big_dec_is_zero(val_1) && s21_big_dec_is_zero(val_2)) {
    res = (sign_1 == S21_SIGN_MINUS) ? -1 : 1;
  } else {
    int err = s21_big_dec_normalize(&val_1, &val_2);

    if (err != S21_RETURN_CODE_ERR) {
      bool is_found = false;
      for (int i = S21_BIG_DEC_MANT_PARTS; (!is_found) && (i >= 0); i--) {
        uint32_t bits_1 = val_1.bits[i];
        uint32_t bits_2 = val_2.bits[i];

        if (bits_1 != bits_2) {
          res = (is_minus_signs ? (bits_1 > bits_2 ? -1 : 1)
                                : (bits_1 < bits_2 ? -1 : 1));
          is_found = true;
        }
      }
    }
  }

  return res;
}

/**
 * @brief осуществялется проверка равенства двух big_decimal значений.
 * Контроль входных данных не осуществляется.
 * @param s21_big_decimal первое значенме к сравнению
 * @param s21_big_decimal второе значенме к сравнению
 * @return
 * true - если каждый бит, включая экспаненту двух значений равны между собой
 * false - если хотя бы один бит одного значения отличается от другого
 */
bool s21_big_dec_is_equal(s21_big_decimal val_1, s21_big_decimal val_2) {
  if (s21_big_dec_is_zero(val_1) && s21_big_dec_is_zero(val_2)) {
    return true;
  }

  bool res = false;
  int err = s21_big_dec_normalize(&val_1, &val_2);

  if (err != S21_RETURN_CODE_ERR) {
    res =
        (val_1.bits[0] == val_2.bits[0]) && (val_1.bits[1] == val_2.bits[1]) &&
        (val_1.bits[2] == val_2.bits[2]) && (val_1.bits[3] == val_2.bits[3]) &&
        (val_1.bits[4] == val_2.bits[4]) && (val_1.bits[5] == val_2.bits[5]) &&
        (val_1.bits[6] == val_2.bits[6]) && (val_1.bits[7] == val_2.bits[7]);
  }

  return res;
}

/* S21_DECIMAL: decimal is zero */

/**
 * @brief осуществялется проверка на наличие положительных значений
 * в мантиссе состоящей из первых трех битов s21_decimal
 * Контроль входных данных не осуществляется.
 * @param s21_decimal значенме к сравнению
 * @return
 * true - если все биты мантиссы s21_decimal равны нулю
 * false - если хотя бы один бит мантиссы s21_decimal не равен нулю
 */
bool s21_dec_is_zero(s21_decimal dec) {
  return ((dec.bits[0] == 0) && (dec.bits[1] == 0) && (dec.bits[2] == 0));
}

/**
 * @brief осуществялется проверка на наличие положительных значений
 * в мантиссе, состоящей из первых шести битов s21_big_decimal
 * Контроль входных данных не осуществляется.
 * @param s21_dig_decimal значенме к сравнению
 * @return
 * true - если все биты мантиссы s21_big_decimal равны нулю
 * false - если хотя бы один бит мантиссы s21_big_decimal не равен нулю
 */
bool s21_big_dec_is_zero(s21_big_decimal dec) {
  bool low_mantiss = (!dec.bits[0] && !dec.bits[1]) && !dec.bits[2];
  bool middle_mantiss = (!dec.bits[3] && !dec.bits[4]) && !dec.bits[5];
  bool high_mantiss = !dec.bits[6];
  return (low_mantiss && middle_mantiss && high_mantiss);
}