#include "suites-utils/s21_decimal_utils_test.h"

#define LD_EPS 1E-6

static long double get_real_ld(const s21_decimal *dec) {
  return s21_dec_to_ld(dec) / powl(10, s21_dec_get_scale(*dec));
}

static void cycle_cases_dec_size(char *str_v1, char *str_v2) {
  s21_decimal value_1 = s21_dec_init(str_v1);
  s21_decimal value_2 = s21_dec_init(str_v2);
  long double ld_value_1 = get_real_ld(&value_1);
  long double ld_value_2 = get_real_ld(&value_2);
  long double expected = ld_value_1 * ld_value_2;

  s21_decimal result_converted = {0};

  s21_big_decimal a = s21_dec_to_bigdec(value_1);
  s21_big_decimal b = s21_dec_to_bigdec(value_2);
  s21_big_decimal result = {0};

  int status_code = s21_big_dec_mult(a, b, &result);
  s21_bigdec_to_dec(result, &result_converted);
  long double ld_result_converted = get_real_ld(&result_converted);

  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_double_eq_tol(expected, ld_result_converted, LD_EPS);
}

static char *str_eq_values_1[] = {"-10", "10", "-10", "10", "0", "10"};
static char *str_eq_values_2[] = {"10", "-10", "-10", "10", "10", "0"};

START_TEST(normal_test_dec_size) {
  char *v1 = str_eq_values_1[_i];
  char *v2 = str_eq_values_2[_i];

  cycle_cases_dec_size(v1, v2);
}
END_TEST

static char *str_eq02_values_1[] = {"0.01",  "15",  "123.25",  "78.3256",
                                    "-0.02", "-12", "-568.25", "-1.123456789"};
static char *str_eq02_values_2[] = {"0.02",  "23",    "6.326",  "89.1235",
                                    "7.123", "56.23", "35.266", "1.112"};

START_TEST(normal_test_dec_size_02) {
  char *v1 = str_eq02_values_1[_i];
  char *v2 = str_eq02_values_2[_i];

  cycle_cases_dec_size(v1, v2);
}
END_TEST

START_TEST(normal_test_bigdec_size) {
  s21_big_decimal a = {0};
  s21_big_decimal b = {0};
  s21_big_decimal res = {0};

  uint32_t a_h_bit = 120;
  uint32_t b_h_bit = 96;
  uint32_t a_scale = 27;
  uint32_t b_scale = 8;

  s21_big_dec_set_bit(&a, a_h_bit, true);  // 2 ^ 120
  s21_big_dec_set_bit(&b, b_h_bit, true);  // 2 ^ 96
  s21_big_dec_set_scale(&a, 27);
  s21_big_dec_set_scale(&b, 8);

  // Мантиссы: 2 ^ 120 * 2 ^ 96 = 2 ^ 216
  int status_code = s21_big_dec_mult(a, b, &res);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq((s21_big_dec_get_high_bit(res) - 1), a_h_bit + b_h_bit);
  // Scale: 27 + 8 = 35
  ck_assert_uint_eq(s21_big_dec_get_scale(res), a_scale + b_scale);
}
END_TEST

Suite *suite_s21_big_dec_mult() {
  Suite *suite = suite_create("suite_s21_big_dec_mult");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_loop_test(normal_cases, normal_test_dec_size, 0,
                      GET_SIZE_ARRAY(str_eq_values_1));
  tcase_add_loop_test(normal_cases, normal_test_dec_size_02, 0,
                      GET_SIZE_ARRAY(str_eq02_values_1));
  tcase_add_test(normal_cases, normal_test_bigdec_size);
  // tcase_add_test(normal_cases, normal_test_02);
  suite_add_tcase(suite, normal_cases);

  return suite;
}
