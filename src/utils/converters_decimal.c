#include "utils/converters_decimal.h"

#include "s21_decimal.h"
#include "utils/all_decimal.h"
#include "utils/arithmetic_decimal.h"
#include "utils/bits_decimal.h"
#include "utils/types_decimal.h"

/**
 * @brief Осуществить преобразование s21_decimal в s21_big_decimal
 * @param dec Преобразуемое значение
 * @return s21_big_decimal
 */
s21_big_decimal s21_dec_to_bigdec(const s21_decimal dec) {
  s21_big_decimal res = {0};
  // Копирование мантиссы
  for (uint8_t i = 0; i < S21_DEC_MANT_PARTS; ++i) {
    res.bits[i] = dec.bits[i];
  }
  // Копирование знака и степени
  res.bits[7] = dec.bits[3];
  return res;
}

static int get_digits_count(const char *str);
static int get_decimal_count(const char *str);
static bool get_str_sign(const char *str);
static bool is_num_str_valid(const char *str);

bool is_part_num_ch(char ch) { return (ch == '.' || ch == '-' || ch == '+'); }

/**
 * @brief Осуществить перевод числа из строки в s21_decimal
 * Контроль переполнения не осуществляется, научная нотация не поддерживается
 * @param str Строка, содержащая число
 * @param dec Указатель на инициализируемый s21_decimal
 * @return Успешное выполнение: 0 OK; Ошибка: 1 ERROR
 */
int s21_str_to_dec(char *str, s21_decimal *dec) {
  if (!is_num_str_valid(str)) return S21_RETURN_CODE_ERR;

  // Получить число разрядов до точки
  int digits_count = get_digits_count(str);
  // Получить число разрядов после точки
  int decimal_count = get_decimal_count(str);
  // Получить знак
  bool have_sign = (*str == '-' || *str == '+');
  bool sign = get_str_sign(str);

  // Получить позицию старшего разрядя (степень десятки)
  int ten_pow = --digits_count + decimal_count - have_sign;
  // Занулить переданный s21_decimal
  memset(dec, 0, sizeof(s21_decimal));

  // Осуществить преобразование
  while (*str != '\0') {
    if (!is_part_num_ch(*str)) {
      int digit = *str - '0';
      s21_decimal temp = {0};
      // Присвоить число в младший разряд s21_decimal
      temp.bits[0] = digit;
      // Переместить число на нужную позицию умножением на 10
      s21_dec_mult_by_ten(&temp, ten_pow);
      // Сложим мантиссы и уменьшим следующий разряд
      s21_mantiss_addition(*dec, temp, dec);
      --ten_pow;
    }
    ++str;
  }

  // Заполнить знак и степень
  if (decimal_count) {
    s21_dec_set_scale(dec, decimal_count);
  }

  if (sign) {
    s21_dec_set_sign(dec, sign);
  }

  return S21_RETURN_CODE_OK;
}

bool get_str_sign(const char *str) {
  return (*str == '-') ? S21_SIGN_MINUS : S21_SIGN_PLUS;
}

bool is_num_str_valid(const char *str) {
  bool is_valid = true;

  while (*str != '\0') {
    if (((*str < '0') || (*str > '9')) && !is_part_num_ch(*str)) {
      is_valid = false;
      break;
    }
    ++str;
  }

  return is_valid;
}

int get_digits_count(const char *str) {
  int counter = 0;
  while (*str != '\0' && *str != '.') {
    ++counter;
    ++str;
  }
  return counter;
}

int get_decimal_count(const char *str) {
  int counter = 0;
  char *decimal_point = strchr(str, '.');
  if (decimal_point == NULL) {
    return counter;
  }
  ++decimal_point;
  while (*decimal_point != '\0') {
    ++counter;
    ++decimal_point;
  }
  return counter;
}

/**
 * @brief Осуществить инициализацию s21_decimal строковым значением цисла
 * @param dec_str Строка, содержащая число
 * @return s21_decimal (нулевое значение в случае ошибки конвертации)
 */
s21_decimal s21_dec_init(char *dec_str) {
  s21_decimal result = {0};
  s21_str_to_dec(dec_str, &result);
  return result;
}

static void bigdec_to_dec_copy_digits(const s21_big_decimal big_dec,
                                      s21_decimal *dec);
static bool bigdec_to_dec_is_high_bits(const s21_big_decimal big_dec);
static int big_dec_round_count(s21_big_decimal big_dec);
/**
 * @brief Осуществить преобразование s21_big_decimal в s21_decimal
 * @param big_dec Преобразуемое значение
 * @param dec Указатель на результат преобразования
 * @return Успешное выполнение операции: 0; Код ошибки в ином случае (число
 * слишком большое, слишком малое)
 */
int s21_bigdec_to_dec(s21_big_decimal big_dec, s21_decimal *dec) {
  if (dec == NULL) return S21_RETURN_CODE_ERR;

  memset(dec, 0, sizeof(s21_decimal));

  if (s21_big_dec_is_zero(big_dec)) {
    return (s21_big_dec_get_scale(big_dec) == 0) ? S21_RETURN_CODE_OK
                                                 : S21_RETURN_TOO_SML;
  }

  s21_big_dec_truncate_trailing_zeros(&big_dec);
  int big_dec_scale = s21_big_dec_get_scale(big_dec);
  int big_dec_sign = s21_big_dec_get_sign(big_dec);

  if (bigdec_to_dec_is_high_bits(big_dec) && (big_dec_scale == 0)) {
    return (big_dec_sign == S21_SIGN_PLUS) ? S21_RETURN_TOO_BIG
                                           : S21_RETURN_TOO_SML;
  }

  // 36893488147419103232 / 10 ** 30 == 3.6893488147419106e-11
  if ((big_dec_scale > (int)S21_DEC_MAX_SCALE) ||
      ((bigdec_to_dec_is_high_bits(big_dec)) &&
       (big_dec_scale <= (int)S21_DEC_MAX_SCALE))) {
    // s21_print_big_decimal_base(&big_dec);
    uint32_t round_scale = big_dec_round_count(big_dec);
    big_dec_scale -= round_scale;

    if (big_dec_scale < 0) {
      return (big_dec_sign == S21_SIGN_PLUS) ? S21_RETURN_TOO_BIG
                                             : S21_RETURN_TOO_SML;
    }

    if (big_dec_scale > (int)S21_DEC_MAX_SCALE) {
      int delta = big_dec_scale - S21_DEC_MAX_SCALE;
      big_dec_scale = S21_DEC_MAX_SCALE;
      round_scale += delta;
    }

    s21_big_dec_bank_round(&big_dec, round_scale);

    if (s21_big_dec_is_zero(big_dec)) {
      return S21_RETURN_TOO_SML;
    } else {
      s21_big_dec_set_scale(&big_dec, (big_dec_scale));
      return s21_bigdec_to_dec(big_dec, dec);
    }
  }

  // Последний случай: в старших битах данных нет, scale меньше либо равен 28
  // Данные готовы к конвертации
  bigdec_to_dec_copy_digits(big_dec, dec);
  s21_dec_set_scale(dec, big_dec_scale);
  s21_dec_set_sign(dec, big_dec_sign);

  return S21_RETURN_CODE_OK;
}

void bigdec_to_dec_copy_digits(const s21_big_decimal big_dec,
                               s21_decimal *dec) {
  for (uint32_t i = 0; i < S21_DEC_MANT_PARTS; ++i) {
    dec->bits[i] = big_dec.bits[i];
  }
}

bool bigdec_to_dec_is_high_bits(const s21_big_decimal big_dec) {
  uint32_t bit_indx = s21_big_dec_get_high_bit(big_dec);
  return (bit_indx > S21_DEC_MANT_BITS);
}

int big_dec_round_count(s21_big_decimal big_dec) {
  int count = 0;
  s21_big_decimal rem = {0};
  s21_big_decimal ten = {0};
  ten.bits[0] = 10;
  while (bigdec_to_dec_is_high_bits(big_dec)) {
    s21_big_mantiss_div(big_dec, ten, &big_dec, &rem);
    ++count;
  }
  return count;
}