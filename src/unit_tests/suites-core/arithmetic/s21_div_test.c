#include "suites-core/s21_decimal_core_test.h"

static void cycle_cases(char *str_v1, char *str_v2, char *str_exp,
                        bool str_conv_fix) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal expected = {0};
  s21_decimal result = {0};

  s21_str_to_dec(str_v1, &value_1);
  s21_str_to_dec(str_v2, &value_2);
  s21_str_to_dec(str_exp, &expected);

  if (str_conv_fix) {
    // Для строк вида "0.3333...." функция s21_str_to_dec
    // определяет scale на 1 больше , считая 0 значимой цифрой
    s21_dec_set_scale(&expected, 28);
  }

  int status_code = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_is_equal(result, expected), true);
}

/* NORMAL */

static char *str_eq_values_1[] = {"-10", "10", "-10", "10"};
static char *str_eq_values_2[] = {"10", "-10", "-10", "10"};
static char *str_eq_expeceted[] = {"-1", "-1", "1", "1"};

START_TEST(normal_equal_values) {
  char *v1 = str_eq_values_1[_i];
  char *v2 = str_eq_values_2[_i];
  char *e = str_eq_expeceted[_i];

  cycle_cases(v1, v2, e, false);
}
END_TEST

static char *str_one_values_1[] = {"-10", "10", "10", "-10", "0"};
static char *str_one_values_2[] = {"1", "-1", "1", "-1", "120"};
static char *str_one_expeceted[] = {"-10", "-10", "10", "10", "0"};

START_TEST(normal_value_2_is_one) {
  char *v1 = str_one_values_1[_i];
  char *v2 = str_one_values_2[_i];
  char *e = str_one_expeceted[_i];

  cycle_cases(v1, v2, e, false);
}
END_TEST

static char *str_inf_frac_values_1[] = {"1", "2", "5", "1", "2", "3", "5"};
static char *str_inf_frac_values_2[] = {"3", "3", "6", "7", "7", "7", "7"};
static char *str_inf_frac_expeceted[] = {
    "0.3333333333333333333333333333",
    "0.6666666666666666666666666667",  // Округление
    "0.8333333333333333333333333333",
    "0.1428571428571428571428571429",  // Округление
    "0.2857142857142857142857142857",
    "0.4285714285714285714285714286",  // Округление
    "0.7142857142857142857142857143",  // Округление
};

START_TEST(normal_inf_fractions) {
  char *v1 = str_inf_frac_values_1[_i];
  char *v2 = str_inf_frac_values_2[_i];
  char *e = str_inf_frac_expeceted[_i];

  cycle_cases(v1, v2, e, false);
}
END_TEST

static char *str_inf02_frac_values_1[] = {"1",     "10",     "100",    "1000",
                                          "10000", "100000", "1000000"};
static char *str_inf02_frac_values_2[] = {"3", "3", "3", "3", "3", "3", "3"};
static char *str_inf02_frac_expeceted[] = {
    "0.3333333333333333333333333333", "3.3333333333333333333333333333",
    "33.333333333333333333333333333", "333.33333333333333333333333333",
    "3333.3333333333333333333333333", "33333.333333333333333333333333",
    "333333.33333333333333333333333",
};

START_TEST(normal_inf_fractions_02) {
  char *v1 = str_inf02_frac_values_1[_i];
  char *v2 = str_inf02_frac_values_2[_i];
  char *e = str_inf02_frac_expeceted[_i];

  cycle_cases(v1, v2, e, false);
}
END_TEST

/* EDGE */

START_TEST(edge_test_01) {
  s21_decimal a = s21_dec_init("0.0000000000000000000000000163");
  s21_decimal b = s21_dec_init("100");
  s21_decimal expected = s21_dec_init("0.0000000000000000000000000002");
  s21_decimal res = {0};

  int status_code = s21_div(a, b, &res);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), true);
}
END_TEST

/* ANOMALY */

START_TEST(too_small_test) {
  s21_decimal a = s21_dec_init("0.000000000000000000000000001");
  s21_decimal b = s21_dec_init("100");
  s21_decimal res = {0};

  int status_code = s21_div(a, b, &res);
  ck_assert_int_eq(status_code, S21_RETURN_TOO_SML);
}
END_TEST

START_TEST(too_small_test_01) {
  s21_decimal a = s21_dec_init("79228162514264337593543950335");
  s21_decimal b = s21_dec_init("-0.5");
  s21_decimal res = {0};

  int status_code = s21_div(a, b, &res);
  ck_assert_int_eq(status_code, S21_RETURN_TOO_SML);
}
END_TEST

START_TEST(too_small_test_02) {
  s21_decimal a = s21_dec_init("0.0000000000000000000000000001");
  s21_decimal b = s21_dec_init("-79228162514264337593543950335");
  s21_decimal res = {0};

  int status_code = s21_div(a, b, &res);
  ck_assert_int_eq(status_code, S21_RETURN_TOO_SML);
}
END_TEST

START_TEST(is_one_test) {
  s21_decimal a = s21_dec_init("0.000000000000000000000000001");
  s21_decimal b = s21_dec_init("0.000000000000000000000000001");
  s21_decimal expected = s21_dec_init("1");
  s21_decimal res = {0};

  int status_code = s21_div(a, b, &res);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), true);
}
END_TEST

START_TEST(null_test) {
  s21_decimal a = s21_dec_init("4");
  s21_decimal b = s21_dec_init("2");

  int status_code = s21_div(a, b, NULL);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(bad_dec_test_01) {
  s21_decimal a = {.bits[3] = 111};
  s21_decimal b = s21_dec_init("2");
  s21_decimal res = {0};

  int status_code = s21_div(a, b, &res);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(bad_dec_test_02) {
  s21_decimal a = s21_dec_init("2");
  s21_decimal b = {.bits[3] = 111};
  s21_decimal res = {0};

  int status_code = s21_div(a, b, &res);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(div_by_zero_test) {
  s21_decimal a = s21_dec_init("2");
  s21_decimal b = s21_dec_init("0");
  s21_decimal res = {0};

  int status_code = s21_div(a, b, &res);
  ck_assert_int_eq(status_code, S21_RETURN_DIV_BY_ZERO);
}
END_TEST

Suite *suite_s21_div() {
  Suite *suite = suite_create("suite_s21_div");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_loop_test(normal_cases, normal_equal_values, 0,
                      GET_SIZE_ARRAY(str_eq_values_1));
  tcase_add_loop_test(normal_cases, normal_value_2_is_one, 0,
                      GET_SIZE_ARRAY(str_one_values_1));
  tcase_add_loop_test(normal_cases, normal_inf_fractions, 0,
                      GET_SIZE_ARRAY(str_inf_frac_values_1));
  tcase_add_loop_test(normal_cases, normal_inf_fractions_02, 0,
                      GET_SIZE_ARRAY(str_inf02_frac_values_1));
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  tcase_add_test(edge_cases, edge_test_01);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, too_small_test);
  tcase_add_test(anomaly_cases, too_small_test_01);
  tcase_add_test(anomaly_cases, too_small_test_02);
  tcase_add_test(anomaly_cases, is_one_test);
  tcase_add_test(anomaly_cases, null_test);
  tcase_add_test(anomaly_cases, bad_dec_test_01);
  tcase_add_test(anomaly_cases, bad_dec_test_02);
  tcase_add_test(anomaly_cases, div_by_zero_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}