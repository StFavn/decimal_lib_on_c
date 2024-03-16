#include "suites-core/s21_decimal_core_test.h"

#define LD_EPS 1E-6

static long double get_real_ld(const s21_decimal *dec) {
  return s21_dec_to_ld(dec) / powl(10, s21_dec_get_scale(*dec));
}

static void cycle_cases(char *str_v1, char *str_v2) {
  s21_decimal value_1 = s21_dec_init(str_v1);
  s21_decimal value_2 = s21_dec_init(str_v2);
  long double ld_value_1 = get_real_ld(&value_1);
  long double ld_value_2 = get_real_ld(&value_2);
  long double expected = ld_value_1 + ld_value_2;

  s21_decimal result = {0};

  int status_code = s21_add(value_1, value_2, &result);
  long double ld_result = get_real_ld(&result);

  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_double_eq_tol(expected, ld_result, LD_EPS);
}

/* NORMAL */

static char *str_normal_values_1[] = {
    "0.000121",  // 0
    "0.000012",   "121", "0.000121", "0.000012",
    "0.01",  // 5
    "0",          "10",  "0",        "125",
    "40256898655"  // 10
};
static char *str_normal_values_2[] = {
    "0.000012",  // 0
    "0.121",      "12", "0.00000000012",
    "0.121",
    "0.02",  // 5
    "10",         "0",  "0",
    "125",
    "45665655998"  // 10
};

START_TEST(normal_values_test) {
  char *v1 = str_normal_values_1[_i];
  char *v2 = str_normal_values_2[_i];

  cycle_cases(v1, v2);
}
END_TEST

START_TEST(two_frac_test_0) {
  s21_decimal dec_0 = s21_dec_init("123.45");
  s21_decimal dec_1 = s21_dec_init("123.55");
  s21_decimal expected = s21_dec_init("247");
  s21_decimal result = {0};

  ck_assert_int_eq(s21_add(dec_0, dec_1, &result), S21_RETURN_CODE_OK);
  ck_assert(s21_is_equal(expected, result));
}
END_TEST

START_TEST(two_frac_test_1) {
  s21_decimal dec_0 = s21_dec_init("49704001422.391670881925172831");
  s21_decimal dec_1 = s21_dec_init("26409387.498605864508043122005");
  s21_decimal expected = s21_dec_init("49730410809.890276746433215953");
  s21_decimal result = {0};

  ck_assert_int_eq(s21_add(dec_0, dec_1, &result), S21_RETURN_CODE_OK);
  ck_assert(s21_is_equal(expected, result));
}

/* EDGE */

static char *str_edge_values_1[] = {"0.1", "0.1", "1",
                                    "0.1538461538461538461538461538"};
static char *str_edge_values_2[] = {
    // 7.9228162514264337593543950335
    "0.3545454545454545454545454545", "7.9228162514264337593543950335 ",
    "0.9999999999999999999999999999", "6.9228162514264337593543950335"};

START_TEST(edge_values_test) {
  char *v1 = str_edge_values_1[_i];
  char *v2 = str_edge_values_2[_i];

  cycle_cases(v1, v2);
}
END_TEST

/* ANOMALY */

START_TEST(null_test) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};

  s21_str_to_dec("2", &val_1);
  s21_str_to_dec("1", &val_2);

  ck_assert_uint_eq(s21_add(val_1, val_2, NULL), S21_RETURN_CODE_ERR);
}
END_TEST

Suite *suite_s21_add() {
  Suite *suite = suite_create("suite_s21_add");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_loop_test(normal_cases, normal_values_test, 0,
                      GET_SIZE_ARRAY(str_normal_values_1));
  tcase_add_test(normal_cases, two_frac_test_0);
  tcase_add_test(normal_cases, two_frac_test_1);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  tcase_add_loop_test(normal_cases, edge_values_test, 0,
                      GET_SIZE_ARRAY(str_edge_values_1));
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, null_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
