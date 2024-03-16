#ifndef SRC_UTILS_S21_BITS_H_
#define SRC_UTILS_S21_BITS_H_

#include <stdbool.h>
#include <stdint.h>

#define S21_UINT32_BITS (sizeof(uint32_t) * 8)

bool s21_get_bit(uint32_t x, int bit_position);
void s21_set_bit_on(uint32_t *x, int bit_position);
void s21_set_bit_off(uint32_t *x, int bit_position);
void s21_set_bit_inverse(uint32_t *x, int bit_position);
bool s21_is_even(uint32_t x);

int s21_add_bits(int bit_1, int bit_2, int carry_bit);
bool s21_is_have_bits_on(int bits, int start, int end);

#endif  // !SRC_UTILS_S21_BITS_H_