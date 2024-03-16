#include "suites-utils/s21_decimal_utils_test.h"

/* NORMAL */

static char *normal_vals[] = {
    "123.45",           // 0
    "10",               //
    "0.5356",           //
    "0.0000000000001",  //
    "53453453462213",   //
    "0",                // 5
    "-555"              //
};

START_TEST(big_equal_normal_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = normal_vals[_i];
  char *val_2_str = normal_vals[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = true;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(not_big_equal_normal_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = normal_vals[_i];
  char *val_2_str = "1";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = false;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(not_big_equal_same_nums_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = "12345";
  char *val_2_str = "123.45";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = false;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(not_big_equal_same_nums_sign_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = "-12345";
  char *val_2_str = "12345";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = false;

  ck_assert(actual == expect);
}
END_TEST

/* EDGE */

static char *edge_vals[] = {
    "123.45000",                                 // 0
    "+0.5356",                                   //
    "0.5356",                                    //
    "5345345346221353453453462142233245245252",  //
    "0.0000000000000000000000000001",            // 4
    "+0",                                        //
    "-0",                                        //
    "0.000000000",                               //
    "1.100000000",                               //
};

START_TEST(big_equal_edge_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = edge_vals[_i];
  char *val_2_str = edge_vals[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = true;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(not_big_equal_edge_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = edge_vals[_i];
  char *val_2_str = "1";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = false;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(big_equal_max_max_vals_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_max();
  s21_big_decimal big_dec_2 = s21_big_dec_get_max();

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = true;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(big_equal_min_min_vals_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_min();
  s21_big_decimal big_dec_2 = s21_big_dec_get_min();

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = true;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(not_big_equal_max_min_vals_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_max();
  s21_big_decimal big_dec_2 = s21_big_dec_get_min();

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = false;

  ck_assert(actual == expect);
}
END_TEST

/* ANOMALY */

START_TEST(big_equal_additional_zeros_0_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = "123.4500000";
  char *val_2_str = "123.45";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = true;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(big_equal_additional_zeros_1_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = "123.0000000";
  char *val_2_str = "123";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = true;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(not_big_equal_additional_zeros_2_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = "123.0000000";
  char *val_2_str = "0.1230000";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = false;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(big_equal_additional_zeros_3_test) {
  s21_big_decimal big_dec_1 = {0};
  s21_big_decimal big_dec_2 = {0};

  s21_big_dec_set_scale(&big_dec_1, 4);
  s21_big_dec_set_scale(&big_dec_2, 1);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = true;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(big_equal_plus_minus_zeros_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = "+0";
  char *val_2_str = "-0";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = true;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(not_big_equal_bad_dec_test) {
  s21_big_decimal big_dec_1 = {.bits[0] = 1};
  s21_big_decimal big_dec_2 = {.bits[0] = 1};

  big_dec_1.bits[7] = 111;
  big_dec_2.bits[7] = 112;

  bool actual = s21_big_dec_is_equal(big_dec_1, big_dec_2);
  bool expect = false;

  ck_assert(actual == expect);
}
END_TEST

Suite *suite_s21_big_dec_is_equal() {
  Suite *suite = suite_create("suite_s21_big_dec_is_equal");

  TCase *normal_cases = tcase_create("normal_cases");
  const size_t normal_vals_elems = GET_SIZE_ARRAY(normal_vals);
  tcase_add_loop_test(normal_cases, big_equal_normal_test, 0,
                      normal_vals_elems);
  tcase_add_loop_test(normal_cases, not_big_equal_normal_test, 0,
                      normal_vals_elems);
  tcase_add_test(normal_cases, not_big_equal_same_nums_test);
  tcase_add_test(normal_cases, not_big_equal_same_nums_sign_test);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  const size_t edge_vals_elems = GET_SIZE_ARRAY(edge_vals);
  tcase_add_loop_test(edge_cases, big_equal_edge_test, 0, edge_vals_elems);
  tcase_add_loop_test(edge_cases, not_big_equal_edge_test, 0, edge_vals_elems);
  tcase_add_test(edge_cases, big_equal_max_max_vals_test);
  tcase_add_test(edge_cases, big_equal_min_min_vals_test);
  tcase_add_test(edge_cases, not_big_equal_max_min_vals_test);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, big_equal_additional_zeros_0_test);
  tcase_add_test(anomaly_cases, big_equal_additional_zeros_1_test);
  tcase_add_test(anomaly_cases, not_big_equal_additional_zeros_2_test);
  tcase_add_test(anomaly_cases, big_equal_additional_zeros_3_test);
  tcase_add_test(anomaly_cases, big_equal_plus_minus_zeros_test);
  tcase_add_test(anomaly_cases, not_big_equal_bad_dec_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}