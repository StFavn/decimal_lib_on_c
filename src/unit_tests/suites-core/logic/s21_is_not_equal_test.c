#include "suites-core/s21_decimal_core_test.h"

/* NORMAL */

static char *normal_vals[] = {
    "123.45",           // 1
    "10",               // 2
    "0.5356",           // 3
    "0.0000000000001",  // 4
    "53453453462213",   // 5
    "0",                // 6
    "-555"              // 7
};

START_TEST(equal_normal_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  char *val = normal_vals[_i];

  s21_str_to_dec(val, &dec_0);
  s21_str_to_dec(val, &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1) == false);
}
END_TEST

START_TEST(not_equal_normal_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  char *val = normal_vals[_i];

  s21_str_to_dec(val, &dec_0);
  s21_str_to_dec("8888.8888", &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1));
}
END_TEST

START_TEST(not_equal_same_nums_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_str_to_dec("12345", &dec_0);
  s21_str_to_dec("123.45", &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1));
}
END_TEST

START_TEST(not_equal_same_nums_sign_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_str_to_dec("-12345", &dec_0);
  s21_str_to_dec("12345", &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1));
}
END_TEST

/* EDGE */

static char *edge_vals[] = {
    // 79228162514264337593543950335
    "123.45000",                     // 1
    "+0.5356",                       // 2
    "0.5356",                        // 3
    "5345345346221353453453462214",  // 4
    "0.00000000000000000000000001",  // 5
    "+0",                            // 6
    "-0",                            // 7
    "0.000000000",                   // 8
    "1.100000000",                   // 9
};

START_TEST(equal_edge_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  char *val = edge_vals[_i];

  s21_str_to_dec(val, &dec_0);
  s21_str_to_dec(val, &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1) == false);
}
END_TEST

START_TEST(not_equal_edge_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  char *val = edge_vals[_i];

  s21_str_to_dec(val, &dec_0);
  s21_str_to_dec("8888.8888", &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1));
}
END_TEST

START_TEST(equal_max_vals_test) {
  s21_decimal dec_0 = s21_dec_get_max();
  s21_decimal dec_1 = s21_dec_get_max();

  ck_assert(s21_is_not_equal(dec_0, dec_1) == false);
}
END_TEST

START_TEST(equal_min_vals_test) {
  s21_decimal dec_0 = s21_dec_get_min();
  s21_decimal dec_1 = s21_dec_get_min();

  ck_assert(s21_is_not_equal(dec_0, dec_1) == false);
}
END_TEST

START_TEST(not_equal_max_min_vals_test) {
  s21_decimal dec_0 = s21_dec_get_max();
  s21_decimal dec_1 = s21_dec_get_min();

  ck_assert(s21_is_not_equal(dec_0, dec_1));
}
END_TEST

START_TEST(edge_scale_overflow_test) {
  s21_decimal dec_1 = s21_dec_init("7922816251426433759354395033.5");
  s21_decimal dec_2 = s21_dec_init("792281625142643375935439503.35");

  ck_assert(s21_is_not_equal(dec_1, dec_2) == 1);
}
END_TEST

/* ANOMALY */

START_TEST(equal_additional_zeros_0_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_str_to_dec("123.4500000", &dec_0);
  s21_str_to_dec("123.45", &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1) == false);
}
END_TEST

START_TEST(equal_additional_zeros_1_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_str_to_dec("123.00000", &dec_0);
  s21_str_to_dec("123", &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1) == false);
}
END_TEST

START_TEST(not_equal_additional_zeros_2_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_str_to_dec("123.0000", &dec_0);
  s21_str_to_dec("0.1230000", &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1));
}
END_TEST

START_TEST(equal_additional_zeros_3_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_dec_set_scale(&dec_0, 4);  // "0.0000"
  s21_dec_set_scale(&dec_1, 1);  // "0.0"

  ck_assert(s21_is_not_equal(dec_0, dec_1) == false);
}
END_TEST

START_TEST(equal_plus_minus_zeros_test) {
  s21_decimal dec_0 = {0};
  s21_decimal dec_1 = {0};

  s21_str_to_dec("-0", &dec_0);
  s21_str_to_dec("+0", &dec_1);

  ck_assert(s21_is_not_equal(dec_0, dec_1) == false);
}
END_TEST

START_TEST(not_equal_bad_dec_test) {
  s21_decimal dec_0 = {.bits[0] = 1};
  s21_decimal dec_1 = {.bits[0] = 1};

  dec_0.bits[3] = 111;
  dec_1.bits[3] = 112;

  ck_assert(s21_is_not_equal(dec_0, dec_1));
}
END_TEST

Suite *suite_s21_is_not_equal() {
  Suite *suite = suite_create("suite_s21_is_not_equal");

  TCase *normal_cases = tcase_create("normal_cases");
  const size_t normal_vals_elems = GET_SIZE_ARRAY(normal_vals);
  tcase_add_loop_test(normal_cases, equal_normal_test, 0, normal_vals_elems);
  tcase_add_loop_test(normal_cases, not_equal_normal_test, 0,
                      normal_vals_elems);
  tcase_add_test(normal_cases, not_equal_same_nums_test);
  tcase_add_test(normal_cases, not_equal_same_nums_sign_test);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  const size_t edge_vals_elems = GET_SIZE_ARRAY(edge_vals);
  tcase_add_loop_test(edge_cases, equal_edge_test, 0, edge_vals_elems);
  tcase_add_loop_test(edge_cases, not_equal_edge_test, 0, edge_vals_elems);
  tcase_add_test(edge_cases, equal_max_vals_test);
  tcase_add_test(edge_cases, equal_min_vals_test);
  tcase_add_test(edge_cases, not_equal_max_min_vals_test);
  tcase_add_test(edge_cases, edge_scale_overflow_test);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, equal_additional_zeros_0_test);
  tcase_add_test(anomaly_cases, equal_additional_zeros_1_test);
  tcase_add_test(anomaly_cases, not_equal_additional_zeros_2_test);
  tcase_add_test(anomaly_cases, equal_additional_zeros_3_test);
  tcase_add_test(anomaly_cases, equal_plus_minus_zeros_test);
  tcase_add_test(anomaly_cases, not_equal_bad_dec_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}