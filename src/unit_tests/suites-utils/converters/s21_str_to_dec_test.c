#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(pos_num_test) {
  s21_decimal dec = {0};
  __uint128_t expected_res = 12345ULL;
  int expected_scale = 2;

  char *str = "123.45";
  int res = s21_str_to_dec(str, &dec);
  ck_assert_uint_eq(res, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_to_uint128_test(dec), expected_res);
  ck_assert_uint_eq(s21_dec_get_scale(dec), expected_scale);
  ck_assert_uint_eq(s21_dec_get_sign(dec), false);

  memset(&dec, 0, sizeof(s21_decimal));
  str = "123.40";
  expected_res = 12340ULL;  // Последний ноль не обрезается!
  res = s21_str_to_dec(str, &dec);
  ck_assert_uint_eq(res, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_to_uint128_test(dec), expected_res);
  ck_assert_uint_eq(s21_dec_get_scale(dec), expected_scale);
  ck_assert_uint_eq(s21_dec_get_sign(dec), false);
}
END_TEST

START_TEST(neg_num_test) {
  s21_decimal dec = {0};
  __uint128_t expected_res = 15ULL;
  int expected_scale = 7;

  char *str = "-.0000015";
  int res = s21_str_to_dec(str, &dec);
  ck_assert_uint_eq(res, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_to_uint128_test(dec), expected_res);
  ck_assert_uint_eq(s21_dec_get_scale(dec), expected_scale);
  ck_assert_uint_eq(s21_dec_get_sign(dec), true);
}
END_TEST

START_TEST(big_num_test) {
  s21_decimal dec = {0};
  __uint128_t expected_res = UINT64_MAX << 3;
  int expected_scale = 0;

  char *str = "147573952589676412920";
  int res = s21_str_to_dec(str, &dec);
  ck_assert_uint_eq(res, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_to_uint128_test(dec), expected_res);
  ck_assert_uint_eq(s21_dec_get_scale(dec), expected_scale);
  ck_assert_uint_eq(s21_dec_get_sign(dec), false);
}
END_TEST

START_TEST(fail_test) {
  s21_decimal dec = {0};

  char *str = "-.000A0015";
  int res = s21_str_to_dec(str, &dec);
  ck_assert_uint_eq(res, S21_RETURN_CODE_ERR);
}
END_TEST

Suite *suite_s21_str_to_dec() {
  Suite *suite = suite_create("suite_s21_str_to_dec");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, pos_num_test);
  tcase_add_test(normal_cases, neg_num_test);
  tcase_add_test(normal_cases, big_num_test);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, fail_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
