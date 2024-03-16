#include "suites-utils/s21_decimal_utils_test.h"

/* NORMAL */

START_TEST(simple_normalize_0_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_str_to_dec("123.0000", &dec_0);
  s21_str_to_dec("123.0", &dec_1);

  ck_assert_uint_ne(s21_dec_get_scale(dec_0), s21_dec_get_scale(dec_1));

  ck_assert_uint_eq(s21_dec_normalize(&dec_0, &dec_1), S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_get_scale(dec_0), s21_dec_get_scale(dec_1));
}
END_TEST

START_TEST(simple_normalize_1_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_str_to_dec("123.0000", &dec_0);
  s21_str_to_dec("0.1230000", &dec_1);

  ck_assert_uint_ne(s21_dec_get_scale(dec_0), s21_dec_get_scale(dec_1));

  ck_assert_uint_eq(s21_dec_normalize(&dec_0, &dec_1), S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_get_scale(dec_0), s21_dec_get_scale(dec_1));
}
END_TEST

/* EDGE */

START_TEST(same_scale_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_str_to_dec("123.0000", &dec_0);
  s21_str_to_dec("123.0000", &dec_1);

  ck_assert_uint_eq(s21_dec_get_scale(dec_0), s21_dec_get_scale(dec_1));

  ck_assert_uint_eq(s21_dec_normalize(&dec_0, &dec_1), S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_get_scale(dec_0), s21_dec_get_scale(dec_1));
}
END_TEST

Suite *suite_s21_dec_normalize() {
  Suite *suite = suite_create("suite_s21_dec_normalize");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, simple_normalize_0_test);
  tcase_add_test(normal_cases, simple_normalize_1_test);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  tcase_add_test(edge_cases, same_scale_test);
  suite_add_tcase(suite, edge_cases);

  return suite;
}
