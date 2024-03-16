#include "suites-utils/s21_decimal_utils_test.h"

/* NORMAL */
START_TEST(normal_zero) {
  s21_big_decimal src = {0};
  s21_decimal target = {0};

  int status_code = s21_bigdec_to_dec(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_dec_is_valid(target), true);
  ck_assert_int_eq(s21_dec_is_zero(target), true);
}
END_TEST

static char *dec_init_str[] = {
    "79228162514264337593543950335",
    "-79228162514264337593543950335",
    "-10",
    "10",
    "0.023656598985556",
    "123",
    "-0.002659881",
    "789.236",
};

START_TEST(normal_dec_size) {
  s21_decimal max_dec = s21_dec_init(dec_init_str[_i]);
  s21_big_decimal src = s21_dec_to_bigdec(max_dec);
  s21_decimal target = {0};

  int status_code = s21_bigdec_to_dec(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_dec_is_valid(target), true);
  ck_assert_int_eq(s21_is_equal(target, max_dec), true);
}
END_TEST

START_TEST(normal_dec_size_02) {
  s21_decimal dec = s21_dec_init("1230000000");
  s21_dec_set_scale(&dec, 7);
  s21_decimal expected = s21_dec_init("123");
  s21_big_decimal src = s21_dec_to_bigdec(dec);
  s21_decimal target = {0};

  int status_code = s21_bigdec_to_dec(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_dec_is_valid(target), true);
  ck_assert_int_eq(s21_is_equal(target, expected), true);
}
END_TEST

START_TEST(normal_over_scale) {
  s21_big_decimal src = {0};
  s21_decimal target = {0};
  s21_decimal expected = s21_dec_init("0.0000000000368934881474191032");

  src.bits[2] = 2;
  s21_big_dec_set_scale(&src, 30);

  int status_code = s21_bigdec_to_dec(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_dec_is_valid(target), true);
  ck_assert_int_eq(s21_is_equal(target, expected), true);
}
END_TEST

START_TEST(normal_over_scale_02) {
  s21_big_decimal src = {0};
  s21_decimal target = {0};
  s21_decimal expected = s21_dec_init("-0.0000000000368934881474191032");

  src.bits[2] = 2;
  s21_big_dec_set_scale(&src, 30);
  s21_big_dec_set_sign(&src, S21_SIGN_MINUS);

  int status_code = s21_bigdec_to_dec(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_dec_is_valid(target), true);
  ck_assert_int_eq(s21_is_equal(target, expected), true);
}
END_TEST

START_TEST(normal_over_mantissa) {
  s21_big_decimal src = {0};
  s21_decimal target = {0};
  s21_decimal expected = s21_dec_init("1584563250.2852867518708790067");

  src.bits[3] = 2;
  s21_big_dec_set_scale(&src, 20);

  int status_code = s21_bigdec_to_dec(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_dec_is_valid(target), true);
  ck_assert_int_eq(s21_is_equal(target, expected), true);
}
END_TEST

START_TEST(normal_over_mantissa_02) {
  s21_big_decimal src = {0};
  s21_decimal target = {0};
  s21_decimal expected = s21_dec_init("-1584563250.2852867518708790067");

  src.bits[3] = 2;
  s21_big_dec_set_scale(&src, 20);
  s21_big_dec_set_sign(&src, S21_SIGN_MINUS);

  int status_code = s21_bigdec_to_dec(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_dec_is_valid(target), true);
  ck_assert_int_eq(s21_is_equal(target, expected), true);
}
END_TEST

/* ANOMALY */

START_TEST(null_test) {
  s21_big_decimal src = {0};
  int status_code = s21_bigdec_to_dec(src, NULL);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(too_small_test) {
  s21_big_decimal src = {0};
  src.bits[0] = 2;
  s21_decimal target = {0};

  s21_big_dec_set_scale(&src, 30);
  int status_code = s21_bigdec_to_dec(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_TOO_SML);
  ;
}
END_TEST

START_TEST(too_big_test) {
  s21_big_decimal src = {0};
  src.bits[4] = 2;
  s21_decimal target = {0};

  s21_big_dec_set_scale(&src, 2);
  int status_code = s21_bigdec_to_dec(src, &target);
  ck_assert_int_eq(status_code, S21_RETURN_TOO_BIG);
}
END_TEST

// dec->bits[7] = scale << S21_DEC_LOW_SCALE_SHIFT;

Suite *suite_s21_convert_bd_to_dec() {
  Suite *suite = suite_create("suite_s21_convert_bd_to_dec");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, normal_zero);
  tcase_add_loop_test(normal_cases, normal_dec_size, 0,
                      GET_SIZE_ARRAY(dec_init_str));
  tcase_add_test(normal_cases, normal_dec_size_02);
  tcase_add_test(normal_cases, normal_over_scale);
  tcase_add_test(normal_cases, normal_over_scale_02);
  tcase_add_test(normal_cases, normal_over_mantissa);
  tcase_add_test(normal_cases, normal_over_mantissa_02);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, null_test);
  tcase_add_test(anomaly_cases, too_small_test);
  tcase_add_test(anomaly_cases, too_big_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
