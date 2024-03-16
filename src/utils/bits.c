#include "utils/bits.h"

bool s21_get_bit(uint32_t x, int bit_position) {
  uint32_t mask = 1U << bit_position;
  return x & mask;
}

void s21_set_bit_on(uint32_t *x, int bit_position) {
  uint32_t mask = 1U << bit_position;
  *x |= mask;
}

void s21_set_bit_off(uint32_t *x, int bit_position) {
  uint32_t mask = ~(1U << bit_position);
  *x &= mask;
}

void s21_set_bit_inverse(uint32_t *x, int bit_position) {
  uint32_t mask = 1U << bit_position;
  *x ^= mask;
}

bool s21_is_even(uint32_t x) {
  // Младший бит четного числа всегда равен 0;
  return (s21_get_bit(x, 0) == 0);
}

int s21_add_bits(int bit_1, int bit_2, int carry_bit) {
  return (bit_1 ^ carry_bit) ^ bit_2;
}

bool s21_is_have_bits_on(int bits, int start, int end) {
  while (start <= end) {
    if (s21_get_bit(bits, start) == 1) return true;
    start++;
  }

  return false;
}