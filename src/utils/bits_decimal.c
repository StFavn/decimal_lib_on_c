#include "utils/bits_decimal.h"

#include <string.h>

#include "utils/arithmetic_decimal.h"
#include "utils/logic_decimal.h"
#include "utils/types_decimal.h"

// S21_DECIMAL: set bit

void s21_dec_set_bit(s21_decimal *dec, uint32_t shift, bool bit) {
  uint8_t bit_indx = 0;
  shift = s21_dec_get_shift(shift, &bit_indx, S21_DECIMAL_BITS);

  if (bit) {
    s21_set_bit_on(&dec->bits[bit_indx], shift);
  } else {
    s21_set_bit_off(&dec->bits[bit_indx], shift);
  }
}

void s21_big_dec_set_bit(s21_big_decimal *dec, uint32_t shift, bool bit) {
  uint8_t bit_indx = 0;
  shift = s21_dec_get_shift(shift, &bit_indx, S21_BIG_DECIMAL_BITS);

  if (bit) {
    s21_set_bit_on(&dec->bits[bit_indx], shift);
  } else {
    s21_set_bit_off(&dec->bits[bit_indx], shift);
  }
}

// S21_DECIMAL: get bit

bool s21_dec_get_bit(s21_decimal dec, uint32_t shift) {
  uint8_t bit_indx = 0;
  shift = s21_dec_get_shift(shift, &bit_indx, S21_DECIMAL_BITS);

  return s21_get_bit(dec.bits[bit_indx], shift);
}

bool s21_big_dec_get_bit(s21_big_decimal dec, uint32_t shift) {
  uint8_t bit_indx = 0;
  shift = s21_dec_get_shift(shift, &bit_indx, S21_BIG_DECIMAL_BITS);

  return s21_get_bit(dec.bits[bit_indx], shift);
}

// S21_DECIMAL: set sign

void s21_dec_set_sign(s21_decimal *dec, bool sign) {
  s21_dec_set_bit(dec, S21_DEC_SIGN_SHIFT, sign);
}

void s21_big_dec_set_sign(s21_big_decimal *dec, bool sign) {
  s21_big_dec_set_bit(dec, S21_BIG_DEC_SIGN_SHIFT, sign);
}

// S21_DECIMAL: get sign

bool s21_dec_get_sign(s21_decimal dec) {
  return s21_dec_get_bit(dec, S21_DEC_SIGN_SHIFT);
}

bool s21_big_dec_get_sign(s21_big_decimal dec) {
  return s21_big_dec_get_bit(dec, S21_BIG_DEC_SIGN_SHIFT);
}

// S21_DECIMAL: set scale

int s21_dec_set_scale(s21_decimal *dec, uint32_t scale) {
  if (scale > S21_DEC_MAX_SCALE) return S21_RETURN_CODE_ERR;

  bool is_sign = s21_dec_get_sign(*dec);
  dec->bits[3] = scale << S21_DEC_LOW_SCALE_SHIFT;
  if (is_sign) {
    s21_dec_set_sign(dec, is_sign);
  }

  return S21_RETURN_CODE_OK;
}

int s21_big_dec_set_scale(s21_big_decimal *dec, uint32_t scale) {
  // if (scale > S21_DEC_MAX_SCALE) return S21_RETURN_CODE_ERR;

  bool is_sign = s21_big_dec_get_sign(*dec);
  dec->bits[7] = scale << S21_DEC_LOW_SCALE_SHIFT;
  if (is_sign) {
    s21_big_dec_set_sign(dec, is_sign);
  }

  return S21_RETURN_CODE_OK;
}

// S21_DECIMAL: get scale

uint32_t s21_dec_get_scale(s21_decimal dec) {
  s21_dec_set_sign(&dec, false);
  return dec.bits[3] >> S21_DEC_LOW_SCALE_SHIFT;
}

uint32_t s21_big_dec_get_scale(s21_big_decimal big_dec) {
  s21_big_dec_set_sign(&big_dec, false);
  return big_dec.bits[7] >> S21_DEC_LOW_SCALE_SHIFT;
}

// Проверяет, что в запретных позициях scale_bits нет активных битов
// Запретные позиции: 0 ... 15; 24 ... 30
bool s21_scale_bits_is_valid(int scale_bits) {
  for (int i = 0; i <= 15; ++i) {
    if (s21_get_bit(scale_bits, i)) {
      return false;
    }
  }

  for (int i = 24; i <= 30; ++i) {
    if (s21_get_bit(scale_bits, i)) {
      return false;
    }
  }

  return true;
}

bool s21_scale_value_is_valid(int scale) {
  return ((scale < 0) || (scale > 28)) ? false : true;
}

bool s21_dec_is_valid(s21_decimal dec) {
  return (s21_scale_bits_is_valid(dec.bits[3]) &&
          s21_scale_value_is_valid(s21_dec_get_scale(dec)));
}

bool s21_big_dec_is_valid(s21_big_decimal dec) {
  return (s21_scale_bits_is_valid(dec.bits[7]) &&
          s21_scale_value_is_valid(s21_big_dec_get_scale(dec)));
}

/**
 * @brief Получить индекс bits s21_big_decimal/s21_decimal
 * и сдвиг в рамках полученного bits по заданному абсолютному
 * смещению.
 * Не обрабатывает избыточное смещение - в этом случае смещение
 * приравнивается к нулю.
 * @param shift Смещение по s21_big_decimal/s21_decimal
 * @param bits_indx Указатель, возвращающий индекс массива bits
 * @param max_bit Максимальное смещение
 * @return Сдвиг в рамках найденного bits (0 ... 31)
 */
uint32_t s21_dec_get_shift(uint32_t shift, uint8_t *bits_indx,
                           const uint32_t max_bit) {
  // TODO: нормализовать к диапазону max_bits?
  shift = (shift >= max_bit) ? 0 : shift;

  *bits_indx = shift / S21_UINT32_BITS;
  shift -= (S21_UINT32_BITS * (*bits_indx));
  return shift;
}

uint32_t s21_dec_get_high_bit(s21_decimal dec) {
  if (s21_dec_is_zero(dec)) return 1;
  uint32_t divident_h_bit = S21_DEC_MANT_BITS - 1;
  for (; !s21_dec_get_bit(dec, divident_h_bit); --divident_h_bit)
    ;
  ++divident_h_bit;
  return divident_h_bit;
}

uint32_t s21_big_dec_get_high_bit(s21_big_decimal dec) {
  if (s21_big_dec_is_zero(dec)) return 1;
  uint32_t divident_h_bit = S21_BIG_DEC_MANT_BITS - 1;
  for (; !s21_big_dec_get_bit(dec, divident_h_bit); --divident_h_bit)
    ;
  ++divident_h_bit;
  return divident_h_bit;
}

uint32_t s21_dec_get_low_bit(s21_decimal dec) {
  uint32_t low_bit = 0;
  for (; (low_bit < S21_DEC_MANT_BITS) && !s21_dec_get_bit(dec, low_bit);
       ++low_bit)
    ;
  ++low_bit;
  return low_bit;
}

s21_decimal s21_dec_get_whole(s21_decimal val) {
  s21_decimal whole_part = {0};
  s21_truncate(val, &whole_part);
  return whole_part;
}

s21_decimal s21_dec_get_frac(s21_decimal val) {
  s21_decimal whole_part = s21_dec_get_whole(val);
  s21_dec_normalize(&val, &whole_part);

  s21_mantiss_sub(val, whole_part, &val);

  return val;
}

/**
 * @brief Осуществить увеличение степени 10 делителя (множитель) s21_decimal
 * @param dec Указатель на значение
 * @param multiplier Увеличение степени 10 делителя (множитель)
 * @return Успешное выполнение: 0 OK; Переполнение: 1 ERROR
 */
int s21_dec_scale_increase(s21_decimal *dec, int multiplier) {
  // Проверить переданный множитель
  if (multiplier <= 0) return S21_RETURN_CODE_ERR;
  // Делитель не должен превышать максимальной степени
  if ((s21_dec_get_scale(*dec) + multiplier) > S21_DEC_MAX_SCALE) {
    return S21_RETURN_CODE_ERR;
  }

  // Контроль переполнения осуществляется в процессе нормализации
  // Для защиты переданного s21_decimal операции проводятся над его копией
  bool is_overflow = false;
  s21_decimal result = *dec;

  // Умножить мантиссу числа на 10 multiplier раз
  for (int i = 0; i < multiplier && !is_overflow; ++i) {
    // TODO: заменить на s21_multiple_by10
    s21_decimal tmp = {0};
    tmp = result;
    is_overflow = s21_left_shift(&tmp, 3);

    if (!is_overflow) {
      s21_left_shift(&result, 1);
      is_overflow = s21_mantiss_addition(result, tmp, &result);
    }
  }

  // Увеличить степень числа и присвоить результат переданному s21_decimal
  if (!is_overflow) {
    uint8_t new_scale = s21_dec_get_scale(*dec) + multiplier;
    s21_dec_set_scale(&result, new_scale);
    *dec = result;
  }

  return (is_overflow) ? S21_RETURN_CODE_ERR : S21_RETURN_CODE_OK;
}

int s21_big_dec_scale_increase(s21_big_decimal *big_dec, int multiplier) {
  // Проверить переданный множитель
  if (multiplier <= 0) return S21_RETURN_CODE_ERR;
  // Делитель не должен превышать максимальной степени
  if ((s21_big_dec_get_scale(*big_dec) + multiplier) > S21_DEC_MAX_SCALE) {
    return S21_RETURN_CODE_ERR;
  }

  // Контроль переполнения осуществляется в процессе нормализации
  // Для защиты переданного s21_decimal операции проводятся над его копией
  bool is_overflow = false;
  s21_big_decimal result = *big_dec;

  // Умножить мантиссу числа на 10 multiplier раз
  for (int i = 0; i < multiplier && !is_overflow; ++i) {
    // TODO: заменить на s21_multiple_by10
    s21_big_decimal tmp = {0};
    tmp = result;
    is_overflow = s21_big_left_shift(&tmp, 3);

    if (!is_overflow) {
      s21_big_left_shift(&result, 1);
      is_overflow = s21_big_mantiss_addition(result, tmp, &result);
    }
  }

  // Увеличить степень числа и присвоить результат переданному s21_decimal
  if (!is_overflow) {
    uint8_t new_scale = s21_big_dec_get_scale(*big_dec) + multiplier;
    s21_big_dec_set_scale(&result, new_scale);
    *big_dec = result;
  }

  return (is_overflow) ? S21_RETURN_CODE_ERR : S21_RETURN_CODE_OK;
}

bool s21_dec_is_mantiss_full(const s21_decimal dec, const int shift) {
  if (dec.bits[2] == 0) return false;

  uint8_t max_uint32_shift = S21_UINT32_BITS - 1;
  uint8_t high_bit = 0;
  for (int i = max_uint32_shift; i >= 0; --i) {
    if (s21_get_bit(dec.bits[2], i) == 1) {
      high_bit = i;
      break;
    }
  }

  return ((max_uint32_shift - high_bit) < shift) ? true : false;
}

/**
 * @brief Осуществить левый сдвиг s21_decimal на заданное число позиций.
 * Максимальный сдвиг ограничен размером мантиссы s21_decimal.
 * @param dec указатель на s21_decimal
 * @param shift_amount число позиций сдвига (max 95 dec == 1)
 * @return Код ошибки: 0 OK; Переполнение: 1 ERROR
 */
int s21_left_shift(s21_decimal *dec, uint32_t shift_amount) {
  if (dec == NULL) return S21_RETURN_CODE_ERR;
  if (shift_amount > (S21_DEC_MANT_BITS - 1)) return S21_RETURN_CODE_ERR;
  if (shift_amount == 0) return S21_RETURN_CODE_OK;

  const uint8_t max_uint32_shift = S21_UINT32_BITS - 1;

  // Получить число сдвигов
  uint8_t shifts_count = shift_amount / max_uint32_shift;
  // Размер последнего сдвига
  uint8_t last_shift_amount = shift_amount - (shifts_count * max_uint32_shift);

  uint32_t carry_bit = 0;
  bool is_mantiss_overflow = false;

  for (int shift_counter = shifts_count; shift_counter >= 0; --shift_counter) {
    uint32_t cycle_shift_amount = 0;
    if (shift_counter != 0) {
      cycle_shift_amount =
          (shift_amount > max_uint32_shift) ? max_uint32_shift : shift_amount;
    } else {
      cycle_shift_amount = last_shift_amount;
    }

    if (s21_dec_is_mantiss_full(*dec, cycle_shift_amount)) {
      is_mantiss_overflow = true;
      break;
    }

    // TODO Сделать нормально при нулевом cycle_shift_amount
    if (cycle_shift_amount != 0) {
      for (uint32_t i = 0; i < S21_DEC_MANT_PARTS; ++i) {
        uint32_t tmp = dec->bits[i];
        dec->bits[i] <<= cycle_shift_amount;
        dec->bits[i] |= carry_bit;
        carry_bit = tmp >> (S21_UINT32_BITS - cycle_shift_amount);
      }
    }
  }

  return (is_mantiss_overflow) ? S21_RETURN_CODE_ERR : S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить левый сдвиг s21_big_decimal на заданное число позиций.
 * Максимальный сдвиг ограничен размером мантиссы s21_big_decimal.
 * Контроль переполнения не осуществляется!
 * @param dec указатель на s21_big_decimal
 * @param shift_amount число позиций сдвига (max 223 для dec == 1)
 * @return Код ошибки: 0 OK; 1 ERROR
 */
int s21_big_left_shift(s21_big_decimal *dec, uint32_t shift_amount) {
  if (dec == NULL) return S21_RETURN_CODE_ERR;
  if (shift_amount > (S21_BIG_DEC_MANT_BITS - 1)) return S21_RETURN_CODE_ERR;
  if (shift_amount == 0) return S21_RETURN_CODE_OK;

  uint32_t carry_bit = 0;
  uint8_t shifts_count = 0;
  uint8_t last_shift_amount = 0;

  uint8_t max_uint32_shift = S21_UINT32_BITS - 1;

  // Получить число сдвигов
  shifts_count = shift_amount / max_uint32_shift;
  // Размер последнего сдвига
  last_shift_amount = shift_amount - (shifts_count * max_uint32_shift);

  for (int shift_counter = shifts_count; shift_counter >= 0; --shift_counter) {
    uint32_t cycle_shift_amount = 0;
    if (shift_counter) {
      cycle_shift_amount =
          (shift_amount > max_uint32_shift) ? max_uint32_shift : shift_amount;
    } else {
      cycle_shift_amount = last_shift_amount;
    }

    if (cycle_shift_amount != 0) {
      for (uint32_t i = 0; i < S21_BIG_DEC_MANT_PARTS; ++i) {
        uint32_t tmp = dec->bits[i];
        dec->bits[i] <<= cycle_shift_amount;
        dec->bits[i] |= carry_bit;
        carry_bit = tmp >> (S21_UINT32_BITS - cycle_shift_amount);
      }
    }
  }

  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить правый сдвиг s21_decimal на заданное число позиций.
 * @param dec указатель на s21_decimal
 * @param shift_amount число позиций сдвига
 * @return Код ошибки: 0 OK; Переполнение: 1 ERROR
 */
int s21_right_shift(s21_decimal *dec, uint32_t shift_amount) {
  if (dec == NULL) return S21_RETURN_CODE_ERR;
  if ((s21_dec_is_zero(*dec)) || (shift_amount == 0)) return S21_RETURN_CODE_OK;

  // Получить число сдвигов
  const uint8_t max_uint32_shift = S21_UINT32_BITS - 1;
  uint8_t shifts_count = shift_amount / max_uint32_shift;
  // Размер последнего сдвига
  uint8_t last_shift_amount = shift_amount - (shifts_count * max_uint32_shift);

  for (int shift_counter = shifts_count; shift_counter >= 0; --shift_counter) {
    uint32_t carry_bit = 0;
    uint32_t cycle_shift_amount = 0;
    if (shift_counter != 0) {
      cycle_shift_amount =
          (shift_amount > max_uint32_shift) ? max_uint32_shift : shift_amount;
    } else {
      cycle_shift_amount = last_shift_amount;
    }

    if (cycle_shift_amount != 0) {
      for (int i = S21_DEC_MANT_PARTS - 1; i >= 0; --i) {
        uint32_t tmp = dec->bits[i];
        dec->bits[i] >>= cycle_shift_amount;
        dec->bits[i] |= carry_bit;
        carry_bit = tmp << (S21_UINT32_BITS - cycle_shift_amount);
      }
    }
  }

  return S21_RETURN_CODE_OK;
}

/**
 * @brief Осуществить правый сдвиг s21_big_decimal на заданное число позиций.
 * @param dec указатель на s21_big_decimal
 * @param shift_amount число позиций сдвига
 * @return Код ошибки: 0 OK; Переполнение: 1 ERROR
 */
int s21_big_right_shift(s21_big_decimal *dec, uint32_t shift_amount) {
  if (dec == NULL) return S21_RETURN_CODE_ERR;
  if ((s21_big_dec_is_zero(*dec)) || (shift_amount == 0))
    return S21_RETURN_CODE_OK;

  // Получить число сдвигов
  const uint8_t max_uint32_shift = S21_UINT32_BITS - 1;
  uint8_t shifts_count = shift_amount / max_uint32_shift;
  // Размер последнего сдвига
  uint8_t last_shift_amount = shift_amount - (shifts_count * max_uint32_shift);

  for (int shift_counter = shifts_count; shift_counter >= 0; --shift_counter) {
    uint32_t carry_bit = 0;
    uint32_t cycle_shift_amount = 0;
    if (shift_counter != 0) {
      cycle_shift_amount =
          (shift_amount > max_uint32_shift) ? max_uint32_shift : shift_amount;
    } else {
      cycle_shift_amount = last_shift_amount;
    }

    if (cycle_shift_amount != 0) {
      for (int i = S21_BIG_DEC_MANT_PARTS - 1; i >= 0; --i) {
        uint32_t tmp = dec->bits[i];
        dec->bits[i] >>= cycle_shift_amount;
        dec->bits[i] |= carry_bit;
        carry_bit = tmp << (S21_UINT32_BITS - cycle_shift_amount);
      }
    }
  }

  return S21_RETURN_CODE_OK;
}

void s21_dec_and(s21_decimal value_1, s21_decimal value_2, s21_decimal *res) {
  for (uint32_t i = 0; i < S21_DEC_MANT_PARTS; ++i) {
    res->bits[i] = value_1.bits[i] & value_2.bits[i];
  }
}

void s21_big_dec_and(s21_big_decimal value_1, s21_big_decimal value_2,
                     s21_big_decimal *res) {
  for (uint32_t i = 0; i < S21_BIG_DEC_MANT_PARTS; ++i) {
    res->bits[i] = value_1.bits[i] & value_2.bits[i];
  }
}

void s21_dec_or(s21_decimal value_1, s21_decimal value_2, s21_decimal *res) {
  for (uint32_t i = 0; i < S21_DEC_MANT_PARTS; ++i) {
    res->bits[i] = value_1.bits[i] | value_2.bits[i];
  }
}

void s21_big_dec_or(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal *res) {
  for (uint32_t i = 0; i < S21_BIG_DEC_MANT_PARTS; ++i) {
    res->bits[i] = value_1.bits[i] | value_2.bits[i];
  }
}