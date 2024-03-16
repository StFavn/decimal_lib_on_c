#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(normal_test_01) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_decimal rem = {0};

  b.bits[0] = 42;

  int return_code = s21_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_is_zero(res), true);
  ck_assert_uint_eq(s21_dec_is_zero(rem), true);
  ck_assert_uint_eq(s21_dec_is_valid(res), true);
  ck_assert_uint_eq(s21_dec_is_valid(rem), true);
}
END_TEST

START_TEST(normal_test_02) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_decimal rem = {0};

  a.bits[0] = 42;
  b.bits[0] = 2;

  int return_code = s21_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(res.bits[0], 21);
  ck_assert_uint_eq(s21_dec_is_zero(rem), true);
  ck_assert_uint_eq(s21_dec_is_valid(res), true);
  ck_assert_uint_eq(s21_dec_is_valid(rem), true);
}
END_TEST

START_TEST(normal_test_03) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_decimal rem = {0};

  a.bits[0] = 10;
  b.bits[0] = 3;

  int return_code = s21_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(res.bits[0], 3);
  ck_assert_uint_eq(rem.bits[0], 1);
  ck_assert_uint_eq(s21_dec_is_valid(res), true);
  ck_assert_uint_eq(s21_dec_is_valid(rem), true);
}
END_TEST

START_TEST(normal_test_04) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal buff_rem = {0};
  s21_decimal res = {0};
  s21_decimal rem = {0};

  a.bits[1] = 10;
  b.bits[1] = 3;

  char *str_buff_rem = "4294967296";
  s21_str_to_dec(str_buff_rem, &buff_rem);

  int return_code = s21_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(res.bits[0], 3);
  ck_assert_uint_eq(s21_is_equal(rem, buff_rem), true);
  ck_assert_uint_eq(s21_dec_is_valid(res), true);
  ck_assert_uint_eq(s21_dec_is_valid(rem), true);
}
END_TEST

START_TEST(normal_test_05) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal buff = {0};
  s21_decimal res = {0};
  s21_decimal rem = {0};

  char *a_str = "400000000000000000000";
  char *buff_str = "200000000000000000000";
  s21_str_to_dec(a_str, &a);
  s21_str_to_dec(buff_str, &buff);
  b.bits[0] = 2;

  int return_code = s21_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_is_equal(res, buff), true);
  ck_assert_uint_eq(s21_dec_is_zero(rem), true);
  ck_assert_uint_eq(s21_dec_is_valid(res), true);
  ck_assert_uint_eq(s21_dec_is_valid(rem), true);
}
END_TEST

START_TEST(normal_test_06) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_decimal rem = {0};

  b.bits[0] = 1024;

  int return_code = s21_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_is_zero(res), true);
  ck_assert_uint_eq(s21_dec_is_zero(rem), true);
}
END_TEST

START_TEST(normal_test_07) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_decimal rem = {0};
  s21_decimal one = {0};

  b.bits[1] = 1024;
  a.bits[1] = 1024;
  one.bits[0] = 1;

  int return_code = s21_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_is_equal(res, one), true);
  ck_assert_uint_eq(s21_dec_is_zero(rem), true);
}
END_TEST

START_TEST(normal_test_08) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_decimal rem = {0};

  a.bits[0] = 2;
  b.bits[0] = 4;

  int return_code = s21_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_is_equal(a, rem), true);
}
END_TEST

START_TEST(fail_test_01) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};
  s21_decimal rem = {0};

  int return_code = s21_mantiss_div(a, b, &res, &rem);
  ck_assert_uint_eq(return_code, S21_RETURN_DIV_BY_ZERO);
}
END_TEST

START_TEST(fail_test_02) {
  s21_decimal a = {0};
  s21_decimal b = {0};

  int return_code = s21_mantiss_div(a, b, NULL, NULL);
  ck_assert_uint_eq(return_code, S21_RETURN_CODE_ERR);
}
END_TEST

Suite *suite_s21_mantiss_div() {
  Suite *suite = suite_create("suite_s21_mantiss_div");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_test_01);
  tcase_add_test(normal_cases, normal_test_02);
  tcase_add_test(normal_cases, normal_test_03);
  tcase_add_test(normal_cases, normal_test_04);
  tcase_add_test(normal_cases, normal_test_05);
  tcase_add_test(normal_cases, normal_test_06);
  tcase_add_test(normal_cases, normal_test_07);
  tcase_add_test(normal_cases, normal_test_08);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, fail_test_01);
  tcase_add_test(anomaly_cases, fail_test_02);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
