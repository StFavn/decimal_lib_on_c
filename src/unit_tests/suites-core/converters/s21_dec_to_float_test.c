#include "suites-core/s21_decimal_core_test.h"

union float_binary {
  float num_float;
  uint32_t num_int;
};

bool get_float_sign(const float num) {
  union float_binary f_bin = {0};
  f_bin.num_float = num;
  return s21_get_bit(f_bin.num_int, 31);
}

static void cycle_conversion_cases(float *in) {
  float out = 0;
  s21_decimal dec = {0};
  s21_from_float_to_decimal(*in, &dec);
  int status = s21_from_decimal_to_float(dec, &out);

  ck_assert_int_eq(status, 0);
  ck_assert_float_eq_tol(*in, out, 1e-7);
}

// POSITIVE NUMBER NORMAL
START_TEST(pos_num_test_01) {
  float in = 21.42;
  cycle_conversion_cases(&in);
}
END_TEST

START_TEST(pos_num_test_02) {
  float in = 0.00000011234;
  cycle_conversion_cases(&in);
}
END_TEST

START_TEST(pos_num_test_03) {
  float in = 1234560000000;
  cycle_conversion_cases(&in);
}
END_TEST

START_TEST(pos_num_test_04) {
  float in = 0.0;
  cycle_conversion_cases(&in);
}
END_TEST

START_TEST(pos_num_test_05) {
  float in = S21_DEC_MIN_FLOAT + 1e-28;
  cycle_conversion_cases(&in);
}
END_TEST

START_TEST(pos_num_test_06) {
  float in = S21_DEC_MAX_FLOAT;
  cycle_conversion_cases(&in);

  in = S21_DEC_MAX_FLOAT - 1;
  cycle_conversion_cases(&in);
}
END_TEST

// NEGATIVE NUMBER NORMAL

START_TEST(neg_num_test_01) {
  float in = -21.42;
  cycle_conversion_cases(&in);
}
END_TEST

START_TEST(neg_num_test_02) {
  float in = 0.00000011234;
  cycle_conversion_cases(&in);
}
END_TEST

START_TEST(neg_num_test_03) {
  float in = -1234560000000;
  cycle_conversion_cases(&in);
}
END_TEST

START_TEST(neg_num_test_04) {
  float in = -0.0;
  float out = 0;

  s21_decimal dec = {0};
  s21_from_float_to_decimal(in, &dec);
  int status = s21_from_decimal_to_float(dec, &out);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(get_float_sign(out), true);
}
END_TEST

// FAIL TESTS

START_TEST(fail_test_01) {
  s21_decimal dec = {0};
  dec.bits[0] = 123456;
  float out = 0;
  s21_dec_set_bit(&dec, 122, true);

  int status = s21_from_decimal_to_float(dec, &out);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(fail_test_02) {
  s21_decimal dec = {0};
  dec.bits[0] = 123456;
  float *out = NULL;

  int status = s21_from_decimal_to_float(dec, out);
  ck_assert_int_eq(status, 1);
}
END_TEST

Suite *suite_s21_dec_to_float() {
  Suite *suite = suite_create("suite_s21_dec_to_float");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, pos_num_test_01);
  tcase_add_test(normal_cases, pos_num_test_02);
  tcase_add_test(normal_cases, pos_num_test_03);
  tcase_add_test(normal_cases, pos_num_test_04);
  tcase_add_test(normal_cases, pos_num_test_05);
  tcase_add_test(normal_cases, pos_num_test_06);

  tcase_add_test(normal_cases, neg_num_test_01);
  tcase_add_test(normal_cases, neg_num_test_02);
  tcase_add_test(normal_cases, neg_num_test_03);
  tcase_add_test(normal_cases, neg_num_test_04);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, fail_test_01);
  tcase_add_test(anomaly_cases, fail_test_02);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
