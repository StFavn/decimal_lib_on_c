#include "suites-utils/s21_decimal_utils_test.h"

/* NORMAL */

static char *normal_vals_1[] = {
    "1",    // 0
    "1",    //
    "1",    //
    "1.0",  //
    "0.1",  // 4
};

static char *normal_vals_2[] = {
    "1.0",     // 0
    "1.00",    //
    "0.01",    //
    "1.0000",  //
    "1000",    // 4
};

START_TEST(normal_normal_vals_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = normal_vals_1[_i];
  char *val_2_str = normal_vals_2[_i];
  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);
  uint32_t scale_1 = s21_big_dec_get_scale(big_dec_1);
  uint32_t scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_ne(scale_1, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

START_TEST(normal_big_val_test) {
  s21_big_decimal big_dec_1 = {0};
  s21_big_decimal big_dec_2 = {0};
  big_dec_1.bits[5] = 1;
  big_dec_2.bits[5] = 1;

  uint32_t scale_1 = 10;
  uint32_t scale_2 = 9;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

START_TEST(normal_big_scale_test) {
  s21_big_decimal big_dec_1 = {0};
  s21_big_decimal big_dec_2 = {0};
  big_dec_1.bits[3] = 1;
  big_dec_2.bits[3] = 1;

  uint32_t scale_1 = 26;
  uint32_t scale_2 = 25;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

/* EDGE */

START_TEST(edge_equal_scale_test) {
  s21_big_decimal big_dec_1 = {0};
  s21_big_decimal big_dec_2 = {0};
  big_dec_1.bits[3] = 1;
  big_dec_2.bits[3] = 1;

  uint32_t scale_1 = 25;
  uint32_t scale_2 = 25;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

START_TEST(edge_max_val_equal_scale_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_max();
  s21_big_decimal big_dec_2 = s21_big_dec_get_max();

  uint32_t scale_1 = 1;
  uint32_t scale_2 = 1;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

START_TEST(edge_max_normalize_start_0_bits_test) {
  s21_big_decimal big_dec_1 = {0};
  s21_big_decimal big_dec_2 = {0};
  big_dec_1.bits[0] = 1;
  big_dec_2.bits[3] = 1;

  uint32_t scale_1 = 0;
  uint32_t scale_2 = 27;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

START_TEST(edge_max_normalize_start_1_bits_test) {
  s21_big_decimal big_dec_1 = {0};
  s21_big_decimal big_dec_2 = {0};
  big_dec_1.bits[1] = 1;
  big_dec_2.bits[3] = 1;

  uint32_t scale_1 = 0;
  uint32_t scale_2 = 27;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

START_TEST(edge_max_normalize_start_2_bits_test) {
  s21_big_decimal big_dec_1 = {0};
  s21_big_decimal big_dec_2 = {0};
  big_dec_1.bits[2] = 1;
  big_dec_2.bits[3] = 1;

  uint32_t scale_1 = 0;
  uint32_t scale_2 = 27;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

START_TEST(edge_max_normalize_start_3_bits_test) {
  s21_big_decimal big_dec_1 = {0};
  s21_big_decimal big_dec_2 = {0};
  big_dec_1.bits[3] = 1;
  big_dec_2.bits[3] = 1;

  uint32_t scale_1 = 0;
  uint32_t scale_2 = 27;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

START_TEST(edge_max_normalize_start_4_bits_test) {
  s21_big_decimal big_dec_1 = {0};
  s21_big_decimal big_dec_2 = {0};
  big_dec_1.bits[4] = 1;
  big_dec_2.bits[3] = 1;

  uint32_t scale_1 = 0;
  uint32_t scale_2 = 27;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_OK;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_eq(scale_1, scale_2);
}
END_TEST

/* ANOMALY */

START_TEST(anomaly_overflow_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_max();
  s21_big_decimal big_dec_2 = {0};
  big_dec_2.bits[0] = 1;

  uint32_t scale_1 = 0;
  uint32_t scale_2 = 1;
  s21_big_dec_set_scale(&big_dec_1, scale_1);
  s21_big_dec_set_scale(&big_dec_2, scale_2);

  int actual_code = s21_big_dec_normalize(&big_dec_1, &big_dec_2);
  int expect_code = S21_RETURN_CODE_ERR;
  scale_1 = s21_big_dec_get_scale(big_dec_1);
  scale_2 = s21_big_dec_get_scale(big_dec_2);

  ck_assert_uint_eq(actual_code, expect_code);
  ck_assert_uint_ne(scale_1, scale_2);
}
END_TEST

Suite *suite_s21_big_dec_normalize() {
  Suite *suite = suite_create("suite_s21_big_dec_normalize");

  TCase *normal_cases = tcase_create("normal_cases");
  const size_t normal_elems = GET_SIZE_ARRAY(normal_vals_1);
  tcase_add_loop_test(normal_cases, normal_normal_vals_test, 0, normal_elems);
  tcase_add_test(normal_cases, normal_big_val_test);
  tcase_add_test(normal_cases, normal_big_scale_test);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  tcase_add_test(edge_cases, edge_equal_scale_test);
  tcase_add_test(edge_cases, edge_max_val_equal_scale_test);
  tcase_add_test(edge_cases, edge_max_normalize_start_0_bits_test);
  tcase_add_test(edge_cases, edge_max_normalize_start_1_bits_test);
  tcase_add_test(edge_cases, edge_max_normalize_start_2_bits_test);
  tcase_add_test(edge_cases, edge_max_normalize_start_3_bits_test);
  tcase_add_test(edge_cases, edge_max_normalize_start_4_bits_test);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, anomaly_overflow_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}