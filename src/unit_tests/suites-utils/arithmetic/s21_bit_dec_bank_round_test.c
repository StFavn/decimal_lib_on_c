#include "suites-utils/s21_decimal_utils_test.h"

#define LD_EPS 1E-6

static void cycle_cases_dec_to_int(char *str) {
  s21_decimal tmp = {0};
  s21_str_to_dec(str, &tmp);
  s21_big_decimal a = s21_dec_to_bigdec(tmp);

  char *endptr = NULL;
  long double expected = strtold(str, &endptr);
  ;

  int status_code = s21_big_dec_bank_round(&a, 1);
  int sign = (s21_big_dec_get_sign(a)) ? -1 : 1;

  long double result = (long double)(a.bits[0]) * sign;

  ck_assert_uint_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_ldouble_eq_tol(result, rintl(expected), LD_EPS);
}

START_TEST(normal_test_01) {
  long double delta = 1;
  for (long double num = 0.5; num < 10; ++num) {
    char buff[50] = {0};
    num += delta;
    sprintf(buff, "%.1Lf", num);
    cycle_cases_dec_to_int(buff);
  }
}
END_TEST

START_TEST(normal_test_02) {
  long double delta = 0.5;
  for (long double num = 0; num >= -10; --num) {
    char buff[50] = {0};
    num += delta;
    sprintf(buff, "%.1Lf", num);
    cycle_cases_dec_to_int(buff);
  }
}
END_TEST

START_TEST(normal_test_03) {
  s21_big_decimal a = {0};
  int init_scale = 28;
  int shift_scale = 24;
  a.bits[0] = 102;
  s21_big_left_shift(&a, 96);
  s21_big_dec_set_scale(&a, init_scale);
  // 808.1272*576454962434541482934272
  long double ld_expected = 808.1273;
  int status_code = s21_big_dec_bank_round(&a, shift_scale);
  long double ld_result =
      (long double)(a.bits[0]) / powl(10, s21_big_dec_get_scale(a));

  ck_assert_uint_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq((init_scale - shift_scale), s21_big_dec_get_scale(a));
  ck_assert_int_eq(s21_big_dec_is_valid(a), true);
  ck_assert_ldouble_eq_tol(ld_result, ld_expected, LD_EPS);
}
END_TEST

START_TEST(normal_test_04) {
  s21_big_decimal a = {0};
  int init_scale = 28;
  int shift_scale = 23;
  a.bits[0] = 102;
  s21_big_left_shift(&a, 96);
  s21_big_dec_set_scale(&a, init_scale);
  // 808.12725*76454962434541482934272
  long double ld_expected = 808.12726;
  int status_code = s21_big_dec_bank_round(&a, shift_scale);
  long double ld_result =
      (long double)(a.bits[0]) / powl(10, s21_big_dec_get_scale(a));

  ck_assert_uint_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq((init_scale - shift_scale), s21_big_dec_get_scale(a));
  ck_assert_int_eq(s21_big_dec_is_valid(a), true);
  ck_assert_ldouble_eq_tol(ld_result, ld_expected, LD_EPS);
}
END_TEST

START_TEST(normal_test_05) {
  s21_big_decimal a = {0};
  s21_decimal tmp = {0};
  char *str_tmp = "0.5356";
  s21_str_to_dec(str_tmp, &tmp);
  a = s21_dec_to_bigdec(tmp);
  int init_scale = 4;
  int shift_scale = 4;

  long double ld_expected = 1.0;
  int status_code = s21_big_dec_bank_round(&a, shift_scale);
  long double ld_result =
      (long double)(a.bits[0]) / powl(10, s21_big_dec_get_scale(a));

  ck_assert_uint_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq((init_scale - shift_scale), s21_big_dec_get_scale(a));
  ck_assert_int_eq(s21_big_dec_is_valid(a), true);
  ck_assert_ldouble_eq_tol(ld_result, ld_expected, LD_EPS);
}
END_TEST

START_TEST(zero_five_test) {
  s21_big_decimal a = {0};
  s21_decimal tmp = {0};
  char *str_tmp = "0.5";

  s21_str_to_dec(str_tmp, &tmp);
  a = s21_dec_to_bigdec(tmp);

  int init_scale = 1;
  int shift_scale = 1;

  long double ld_expected = 0.0;
  int status_code = s21_big_dec_bank_round(&a, shift_scale);
  long double ld_result =
      (long double)(a.bits[0]) / powl(10, s21_big_dec_get_scale(a));

  ck_assert_uint_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq((init_scale - shift_scale), s21_big_dec_get_scale(a));
  ck_assert_int_eq(s21_big_dec_is_valid(a), true);
  ck_assert_ldouble_eq_tol(ld_result, ld_expected, LD_EPS);
}
END_TEST

/* ANOMALY */

START_TEST(null_test) {
  ck_assert_uint_eq(s21_big_dec_bank_round(NULL, 10), S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(pos_below_zero_test) {
  s21_big_decimal a = {0};
  a.bits[5] = 123;
  ck_assert_uint_eq(s21_big_dec_bank_round(&a, -10), S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(too_big_shif_test) {
  s21_big_decimal a = {0};
  a.bits[5] = 123;
  s21_big_dec_set_scale(&a, 5);
  ck_assert_uint_eq(s21_big_dec_bank_round(&a, 6), S21_RETURN_CODE_ERR);
}
END_TEST

// Убрано, т.к. функция используется для s21_big_decimal
// со scale > 28 (s21_bigdec_to_dec)
// START_TEST(bad_dec_test) {
//   s21_big_decimal a = {0};
//   a.bits[7] = 123;
//   a.bits[3] = 123;
//   ck_assert_uint_eq(s21_big_dec_bank_round(&a, 0), S21_RETURN_CODE_ERR);
// }

Suite *suite_s21_big_dec_bank_round() {
  Suite *suite = suite_create("suite_s21_big_dec_bank_round");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, normal_test_02);
  tcase_add_test(normal_cases, normal_test_03);
  tcase_add_test(normal_cases, normal_test_04);
  tcase_add_test(normal_cases, normal_test_05);
  tcase_add_test(normal_cases, zero_five_test);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, null_test);
  tcase_add_test(anomaly_cases, pos_below_zero_test);
  tcase_add_test(anomaly_cases, too_big_shif_test);
  // tcase_add_test(anomaly_cases, bad_dec_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
