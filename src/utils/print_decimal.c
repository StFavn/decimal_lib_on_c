#include <math.h>
#include <stdio.h>

#include "utils/all_decimal.h"

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define RESET_TEXT "\033[0m"

#define S21_BUFF_SIZE 1024

// Вывод на печать бинарного представления числа
// Для экспериментов
void s21_print_uint32(uint32_t x) {
  for (int i = 31; i >= 0; --i) {
    putchar(((x >> i) & 1U) ? '1' : '0');
  }
  putchar('\n');
}

void s21_print_decimal(const s21_decimal *dec) {
  const char *s21_decimal_structure_desc[] = {"sign & scale", "upper", "medium",
                                              "lower"};

  const int elements_count = 4;

  for (int i = 0; i < elements_count; ++i) {
    if (i == 0) {
      printf("%-13s: ", s21_decimal_structure_desc[i]);
      bool sign = s21_dec_get_sign(*dec);
      // Знак
      printf(GREEN_TEXT "%u" RESET_TEXT, sign);
      // Неиспользуемые биты 126 ... 120 (30 ... 24 bits[3])
      for (int k = 126; k >= 120; --k) {
        bool bit = s21_dec_get_bit(*dec, k);
        printf(RED_TEXT "%u" RESET_TEXT, bit);
      }
      // Степень
      for (int k = 119; k >= 112; --k) {
        bool bit = s21_dec_get_bit(*dec, k);
        printf("%u", bit);
      }
      // Неиспользуемые биты 111 ... 96 (15 ... 0 bits[3])
      for (int k = 111; k >= 96; --k) {
        bool bit = s21_dec_get_bit(*dec, k);
        printf(RED_TEXT "%u" RESET_TEXT, bit);
      }
      printf("\n");
    } else {
      printf("%-13s: ", s21_decimal_structure_desc[i]);
      s21_print_uint32(dec->bits[(elements_count - 1) - i]);
    }
  }

  printf("===============================================\n");
  s21_print_decimal_base(dec);
}

void s21_print_big_decimal(const s21_big_decimal *dec) {
  const char *s21_decimal_structure_desc[] = {
      "sign & scale", "high",    "upper_1",  "medium_1",
      "lower_1",      "upper_0", "medium_0", "lower_0"};

  const int elements_count = 8;

  for (int i = 0; i < elements_count; ++i) {
    if (i == 0) {
      printf("%-13s: ", s21_decimal_structure_desc[i]);
      bool sign = s21_big_dec_get_sign(*dec);
      // Знак
      printf(GREEN_TEXT "%u" RESET_TEXT, sign);
      // Неиспользуемые биты 254 ... 248 (30 ... 24 bits[7])
      for (int k = 254; k >= 248; --k) {
        bool bit = s21_big_dec_get_bit(*dec, k);
        printf(RED_TEXT "%u" RESET_TEXT, bit);
      }
      // Степень
      for (int k = 247; k >= 240; --k) {
        bool bit = s21_big_dec_get_bit(*dec, k);
        printf("%u", bit);
      }
      // Неиспользуемые биты 239 ... 224 (15 ... 0 bits[7])
      for (int k = 239; k >= 224; --k) {
        bool bit = s21_big_dec_get_bit(*dec, k);
        printf(RED_TEXT "%u" RESET_TEXT, bit);
      }
      printf("\n");
    } else {
      printf("%-13s: ", s21_decimal_structure_desc[i]);
      s21_print_uint32(dec->bits[(elements_count - 1) - i]);
    }
  }

  printf("===============================================\n");
  s21_print_big_decimal_base(dec);
}

void s21_print_decimal_base(const s21_decimal *dec) {
  int scale = s21_dec_get_scale(*dec);
  long double ld_mantissa = s21_dec_to_ld(dec);

  char print_format[S21_BUFF_SIZE] = {0};
  sprintf(print_format, "% .0Lf / 10 ** %d", ld_mantissa, scale);
  printf("%47s\n", print_format);
}

void s21_print_big_decimal_base(const s21_big_decimal *dec) {
  long double ld_mantissa = 0;
  int scale = s21_big_dec_get_scale(*dec);

  for (size_t i = 0; i < S21_BIG_DEC_MANT_BITS; ++i) {
    long double tmp = powl(2, i);
    bool mantissa_bit = s21_big_dec_get_bit(*dec, i);
    ld_mantissa += (long double)mantissa_bit * tmp;
  }

  if (s21_big_dec_get_sign(*dec)) {
    ld_mantissa *= -1;
  }

  char print_format[S21_BUFF_SIZE] = {0};
  sprintf(print_format, "% .0Lf / 10 ** %d", ld_mantissa, scale);
  printf("%47s\n", print_format);
}

/**
 * @brief Осуществить преобразование мантиссы в long double
 * Деление на scale не осуществляется.
 * @param dec Указатель на s21_decimal
 * @return мантисса long double
 */
long double s21_dec_to_ld(const s21_decimal *dec) {
  long double ld_mantissa = 0;
  for (size_t i = 0; i < S21_DEC_MANT_BITS; ++i) {
    long double tmp = powl(2, i);
    bool mantissa_bit = s21_dec_get_bit(*dec, i);
    ld_mantissa += (long double)mantissa_bit * tmp;
  }

  if (s21_dec_get_sign(*dec)) {
    ld_mantissa *= -1;
  }

  return ld_mantissa;
}