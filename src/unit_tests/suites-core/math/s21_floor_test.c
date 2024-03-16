#include "suites-core/s21_decimal_core_test.h"

static void convert_and_test(char *src_str) {
  s21_decimal in = {0};
  s21_decimal res = {0};

  long double ld_expected = strtold(src_str, NULL);
  s21_str_to_dec(src_str, &in);

  int status_code = s21_floor(in, &res);
  ld_expected = floorl(ld_expected);
  long double ld_res = s21_dec_to_ld(&res);

  ck_assert_uint_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_ldouble_eq_tol(ld_res, ld_expected, 1e-6);
}

/* NORMAL */

static char *normal_vals[] = {
    "123.45",
    "-123.45",
    "123.0",
    "-123.0",
    "123.000000",
    "-123.000000",
    "10.11111",
    "0.21",
    "-0.21",
    "0.5356",
    "-0.5356",
    "1.5",
    "-1.5",
    "100.5",
    "-100.5",
    "100.4",
    "-100.4",
    "100.75",
    "-100.75",
    "100.66",
    "-100.66",
    "100.15",
    "-100.15",
    "1",
    "-1",
    "12354235423646.4",
    "-12354235423646.4",
    "12354235423646.6",
    "-12354235423646.6",
    "12354235423646.8",
    "-12354235423646.8",
};

START_TEST(normal_vals_test) {
  char *src_str = normal_vals[_i];
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_01) {
  char *src_str = "-412345665.98565656565";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_02) {
  char *src_str = "412345665.98565656565";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_03) {
  char *src_str = "-0.21";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_04) {
  char *src_str = "0.000000042";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_05) {
  char *src_str = "123";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_06) {
  char *src_str = "-123";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_07) {
  char *src_str = "123.0000000";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_08) {
  char *src_str = "-123.0000000";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_09) {
  char *src_str = "123456789012345678";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_10) {
  char *src_str = "-123456789012345678";
  convert_and_test(src_str);
}
END_TEST

START_TEST(normal_11) {
  char *src_str = "0";
  convert_and_test(src_str);
}
END_TEST

/* EDGE */

// MAX: 79228162514264337593543950335

static char *edge_vals[] = {
    // 79228162514264337593543950335
    "+0",
    "-0",
    "0.000000000000",
    "-0.00000000000",
    "1.000000000000",
    "-1.00000000000",
    "1.000000000001",
    "-1.00000000001",
    "1.000000000006",
    "-1.00000000006",
    "1.0000000000000000000000005",
    "1.6000000000000000000000005",
    "-1.600000000000000000000005",
    "1.1000000000000000000000005",
    "-1.100000000000000000000005",
    "1.5000000000000000000000005",
    "-1.500000000000000000000005",
    "11111112345.444444449012345",
    "-11111112345.444444489012345",
    "0.7777777777777777777777777",
    "-0.7777777777777777777777777",
    "0.00000000000000000000000001",
    "-0.00000000000000000000000001",
    "12345678964425243243242343.1",
    "-12345678964425243243242343.1",
    "12345678964425243243242343.5",
    "-12345678964425243243242343.5",
    "12345678964425243243242343.7",
    "-12345678964425243243242343.7",
    "1234567896442524.32432423437",
    "-123456789644252.432432423437",
    "1234.56789644252432432423437",
    "-1234.56789644252432432423437",
    "123456789644252432432.423437",
    "-123456789644252432432.423437",
    "123.0000005000000",
    "-123.0000005000000",
    "123.123456789",
    "-123.123456789",
    "123.987654431234",
    "-123.987654431234",
    "123.611111111111111",
    "-123.611111111111111",
    "-123.677777777777777",
    "123.677777777777777",
    "0.000000042",
    "-0.000000042",
    "412345665.98565656565",
    "-412345665.98565656565",
    "0.0000000000001",
    "-0.0000000000001",
    "53453453462213",
    "-555.665623267",
};

START_TEST(edge_vals_test) {
  char *src_str = edge_vals[_i];
  convert_and_test(src_str);
}
END_TEST

START_TEST(edge_0_test) {
  char *actual_str = "-1.000000000000000000000005";
  char *expected_str = "-2";

  s21_decimal actual_dec = {0};
  s21_decimal expected_dec = {0};

  s21_str_to_dec(actual_str, &actual_dec);
  s21_str_to_dec(expected_str, &expected_dec);

  int status_code = s21_floor(actual_dec, &actual_dec);

  ck_assert_uint_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert(s21_is_equal(actual_dec, expected_dec));
}
END_TEST

START_TEST(max_up_test) {
  //               79228162514264337593543950335
  char *src_str = "7922816251426433759354395033.5";
  convert_and_test(src_str);
}
END_TEST

START_TEST(max_down_test) {
  //               79228162514264337593543950335
  char *src_str = "7922816251426433759354395033.4";
  convert_and_test(src_str);
}
END_TEST

START_TEST(min_up_test) {
  //               79228162514264337593543950335
  char *src_str = "-7922816251426433759354395033.4";
  convert_and_test(src_str);
}
END_TEST

START_TEST(min_down_test) {
  //               79228162514264337593543950335
  char *src_str = "-7922816251426433759354395033.5";
  convert_and_test(src_str);
}
END_TEST

/* ANOMALY */

START_TEST(null_test) {
  s21_decimal val = {0};
  ck_assert_int_eq(s21_floor(val, NULL), S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(bad_dec_test) {
  s21_decimal dec = {.bits[3] = 111};
  s21_decimal val = {0};

  ck_assert_int_eq(s21_floor(dec, &val), S21_RETURN_CODE_ERR);
}
END_TEST

Suite *suite_s21_floor() {
  Suite *suite = suite_create("suite_s21_floor");

  TCase *normal_cases = tcase_create("normal_cases");
  const size_t normal_vals_elems = GET_SIZE_ARRAY(normal_vals);
  tcase_add_loop_test(normal_cases, normal_vals_test, 0, normal_vals_elems);
  tcase_add_test(normal_cases, normal_01);
  tcase_add_test(normal_cases, normal_02);
  tcase_add_test(normal_cases, normal_03);
  tcase_add_test(normal_cases, normal_04);
  tcase_add_test(normal_cases, normal_05);
  tcase_add_test(normal_cases, normal_06);
  tcase_add_test(normal_cases, normal_07);
  tcase_add_test(normal_cases, normal_08);
  tcase_add_test(normal_cases, normal_09);
  tcase_add_test(normal_cases, normal_10);
  tcase_add_test(normal_cases, normal_11);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  const size_t edge_vals_elems = GET_SIZE_ARRAY(edge_vals);
  tcase_add_loop_test(edge_cases, edge_vals_test, 0, edge_vals_elems);
  tcase_add_test(edge_cases, edge_0_test);
  tcase_add_test(edge_cases, max_up_test);
  tcase_add_test(edge_cases, max_down_test);
  tcase_add_test(edge_cases, min_up_test);
  tcase_add_test(edge_cases, min_down_test);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, null_test);
  tcase_add_test(anomaly_cases, bad_dec_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}