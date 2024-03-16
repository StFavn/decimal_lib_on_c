#include "suites-utils/s21_decimal_utils_test.h"

/* NORMAL */

START_TEST(big_dec_is_zero) {
  s21_big_decimal big_dec = {0};
  bool expect = true;

  bool actual = s21_big_dec_is_zero(big_dec);

  ck_assert(actual == expect);
}

START_TEST(big_dec_is_not_zero_0_bits) {
  s21_big_decimal big_dec = {0};
  big_dec.bits[0] = 1;
  bool expect = false;

  bool actual = s21_big_dec_is_zero(big_dec);

  ck_assert(actual == expect);
}

START_TEST(big_dec_is_not_zero_1_bits) {
  s21_big_decimal big_dec = {0};
  big_dec.bits[1] = 1;
  bool expect = false;

  bool actual = s21_big_dec_is_zero(big_dec);

  ck_assert(actual == expect);
}

START_TEST(big_dec_is_not_zero_2_bits) {
  s21_big_decimal big_dec = {0};
  big_dec.bits[2] = 1;
  bool expect = false;

  bool actual = s21_big_dec_is_zero(big_dec);

  ck_assert(actual == expect);
}

START_TEST(big_dec_is_not_zero_3_bits) {
  s21_big_decimal big_dec = {0};
  big_dec.bits[3] = 1;
  bool expect = false;

  bool actual = s21_big_dec_is_zero(big_dec);

  ck_assert(actual == expect);
}

START_TEST(big_dec_is_not_zero_4_bits) {
  s21_big_decimal big_dec = {0};
  big_dec.bits[4] = 1;
  bool expect = false;

  bool actual = s21_big_dec_is_zero(big_dec);

  ck_assert(actual == expect);
}

START_TEST(big_dec_is_not_zero_5_bits) {
  s21_big_decimal big_dec = {0};
  big_dec.bits[5] = 1;
  bool expect = false;

  bool actual = s21_big_dec_is_zero(big_dec);

  ck_assert(actual == expect);
}

START_TEST(big_dec_is_not_zero_6_bits) {
  s21_big_decimal big_dec = {0};
  big_dec.bits[6] = 1;
  bool expect = false;

  bool actual = s21_big_dec_is_zero(big_dec);

  ck_assert(actual == expect);
}

/* SUITES */

Suite *suite_s21_big_dec_is_zero() {
  Suite *suite = suite_create("suite_s21_big_dec_is_zero");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, big_dec_is_zero);
  tcase_add_test(normal_cases, big_dec_is_not_zero_0_bits);
  tcase_add_test(normal_cases, big_dec_is_not_zero_1_bits);
  tcase_add_test(normal_cases, big_dec_is_not_zero_2_bits);
  tcase_add_test(normal_cases, big_dec_is_not_zero_3_bits);
  tcase_add_test(normal_cases, big_dec_is_not_zero_4_bits);
  tcase_add_test(normal_cases, big_dec_is_not_zero_5_bits);
  tcase_add_test(normal_cases, big_dec_is_not_zero_6_bits);
  suite_add_tcase(suite, normal_cases);

  return suite;
}