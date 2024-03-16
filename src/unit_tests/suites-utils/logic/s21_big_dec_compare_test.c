#include "suites-utils/s21_decimal_utils_test.h"

/* NORMAL */

static char *normal_vals_one_more_1[] = {
    "2",         // 0
    "1",         //
    "1",         //
    "0",         //
    "1.0",       //
    "1.0",       // 5
    "0.1",       //
    "1.999",     //
    "10000000",  //
    "-1",        //
    "-1.9999",   // 10
    "0"          //
};

static char *normal_vals_one_more_2[] = {
    "1",           // 0
    "0",           //
    "-1",          //
    "-1",          //
    "0",           //
    "0.9",         // 5
    "0.01",        //
    "-1",          //
    "-0.0000001",  //
    "-2",          //
    "-2",          // 10
    "-1.0"         //
};

START_TEST(compare_normal_one_more) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = normal_vals_one_more_1[_i];
  char *val_2_str = normal_vals_one_more_2[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 1;

  ck_assert(actual == expect);
}
END_TEST

static char *normal_vals_equal_1[] = {
    "0",     // 0
    "1",     //
    "-1",    //
    "0",     //
    "1111",  // 5
    "1.0",   //
    "1.1"    //
};

static char *normal_vals_equal_2[] = {
    "0",     // 0
    "1",     //
    "-1",    //
    "0",     //
    "1111",  // 5
    "1.0",   //
    "1.1"    //
};

START_TEST(compare_normal_equal) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = normal_vals_equal_1[_i];
  char *val_2_str = normal_vals_equal_2[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 0;

  ck_assert(actual == expect);
}
END_TEST

static char *normal_vals_two_more_1[] = {
    "1",           // 0
    "0",           //
    "-1",          //
    "-1",          //
    "0",           //
    "0.9",         // 5
    "0.01",        //
    "-1",          //
    "-0.0000001",  //
    "-2",          //
    "-2",          // 10
    "-1.0"         //
};

static char *normal_vals_two_more_2[] = {
    "2",         // 0
    "1",         //
    "1",         //
    "0",         //
    "1.0",       //
    "1.0",       // 5
    "0.1",       //
    "1.999",     //
    "10000000",  //
    "-1",        //
    "-1.9999",   // 10
    "0"          //
};

START_TEST(compare_normal_two_more) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = normal_vals_two_more_1[_i];
  char *val_2_str = normal_vals_two_more_2[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = -1;

  ck_assert(actual == expect);
}
END_TEST

/* EDGE */

static char *edge_vals_one_more_1[] = {
    "+0.5356",                         // 0
    "+0.5356",                         //
    "+0.5356",                         //
    "+0.5356",                         //
    "+0.5356",                         //
    "123.4500001",                     // 5
    "123.4500000",                     //
    "534534534622135345345346221424",  //
    "534534534622135345345346221424",  //
    "534534534622135345345346221424",  //
    "0.0000000000000000000000000010",  // 10
    "0.0000000000000000000000000002",  //
    "0.0000000000000000000000000001",  //
    "0.0000000000000000000000000001"   //
};

static char *edge_vals_one_more_2[] = {
    "+0.5355",                         // 0
    "+0.0",                            //
    "0",                               //
    "-0",                              //
    "-1",                              //
    "123.4500000",                     // 5
    "-1",                              //
    "534534534622135345345346221423",  //
    "0",                               //
    "-53453453462213534534534622142",  //
    "0.0000000000000000000000000001",  // 10
    "0.0000000000000000000000000001",  //
    "0.0000000000000000000000000000",  //
    "-0.0000000000000000000000000001"  //
};

START_TEST(compare_edge_one_more) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = edge_vals_one_more_1[_i];
  char *val_2_str = edge_vals_one_more_2[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 1;

  ck_assert(actual == expect);
}
END_TEST

static char *edge_vals_equal_1[] = {"+0",
                                    "-0",
                                    "-1.0000000000000000000000000000",
                                    "0.0000000000000000000000000000",
                                    "1.0000000000000000000000000000",
                                    "534534534622135345345346221424",
                                    "1.5345345346221353453453462214"};

static char *edge_vals_equal_2[] = {"-0",
                                    "+0",
                                    "-1.0000000000000000000000000000",
                                    "0.0000000000000000000000000000",
                                    "1.0000000000000000000000000000",
                                    "534534534622135345345346221424",
                                    "1.5345345346221353453453462214"};

START_TEST(compare_edge_equal) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = edge_vals_equal_1[_i];
  char *val_2_str = edge_vals_equal_2[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 0;

  ck_assert(actual == expect);
}
END_TEST

static char *edge_vals_two_more_1[] = {
    "+0.5355",                          // 0
    "+0.0",                             //
    "0",                                //
    "-0",                               //
    "-1",                               //
    "123.4500000",                      // 5
    "-1",                               //
    "534534534622135345345346221423",   //
    "0",                                //
    "-534534534622135345345346221424",  //
    "0.0000000000000000000000000001",   // 10
    "0.0000000000000000000000000000",   //
    "-0.0000000000000000000000000001"   //
};

static char *edge_vals_two_more_2[] = {
    "+0.5356",                         // 0
    "+0.5356",                         //
    "+0.5356",                         //
    "+0.5356",                         //
    "+0.5356",                         //
    "123.4500001",                     // 5
    "123.4500000",                     //
    "534534534622135345345346221424",  //
    "534534534622135345345346221424",  //
    "534534534622135345345346221424",  //
    "0.0000000000000000000000000002",  // 10
    "0.0000000000000000000000000001",  //
    "0.0000000000000000000000000001"   //
};

START_TEST(compare_edge_two_more) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1_str = edge_vals_two_more_1[_i];
  char *val_2_str = edge_vals_two_more_2[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);

  s21_big_decimal big_dec_1 = s21_dec_to_bigdec(dec_1);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = -1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_max_1_one_more_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_max();

  s21_decimal dec_2 = {0};
  char *val_2_str = "1";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_max_0_one_more_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_max();

  s21_decimal dec_2 = {0};
  char *val_2_str = "0";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_max_m1_one_more_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_max();

  s21_decimal dec_2 = {0};
  char *val_2_str = "-1";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_max_min_one_more_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_max();
  s21_big_decimal big_dec_2 = s21_big_dec_get_min();

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_max_max_equal_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_max();
  s21_big_decimal big_dec_2 = s21_big_dec_get_max();

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 0;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_min_min_equal_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_min();
  s21_big_decimal big_dec_2 = s21_big_dec_get_min();

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 0;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_min_m1_two_more_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_min();

  s21_decimal dec_2 = {0};
  char *val_2_str = "-1";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = -1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_min_0_two_more_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_min();

  s21_decimal dec_2 = {0};
  char *val_2_str = "0";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = -1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_min_1_two_more_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_min();

  s21_decimal dec_2 = {0};
  char *val_2_str = "1";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_big_decimal big_dec_2 = s21_dec_to_bigdec(dec_2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = -1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(edge_min_max_two_more_test) {
  s21_big_decimal big_dec_1 = s21_big_dec_get_min();
  s21_big_decimal big_dec_2 = s21_big_dec_get_max();

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = -1;

  ck_assert(actual == expect);
}
END_TEST

/* ANOMALY */

START_TEST(anomaly_set_scl_one_more_test) {
  s21_big_decimal big_dec_1 = {.bits[0] = 1};
  s21_big_decimal big_dec_2 = {.bits[0] = 1};

  s21_big_dec_set_scale(&big_dec_2, 2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(anomaly_set_scl_equal_test) {
  s21_big_decimal big_dec_1 = {.bits[0] = 1};
  s21_big_decimal big_dec_2 = {.bits[0] = 1};

  s21_big_dec_set_scale(&big_dec_1, 10);
  s21_big_dec_set_scale(&big_dec_2, 10);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 0;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(anomaly_set_scl_two_more_test) {
  s21_big_decimal big_dec_1 = {.bits[0] = 1};
  s21_big_decimal big_dec_2 = {.bits[0] = 1};

  s21_big_dec_set_scale(&big_dec_1, 2);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = -1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(anomaly_bad_dec_one_more_test) {
  s21_big_decimal big_dec_1 = {.bits[0] = 1};
  s21_big_decimal big_dec_2 = {.bits[0] = 1};

  big_dec_2.bits[7] = pow(2, 17);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 1;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(anomaly_bad_dec_equal_test) {
  s21_big_decimal big_dec_1 = {.bits[0] = 1};
  s21_big_decimal big_dec_2 = {.bits[0] = 1};

  big_dec_1.bits[7] = pow(2, 18);
  big_dec_2.bits[7] = pow(2, 18);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 0;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(anomaly_bad_dec_dif_scl_equal_test) {
  s21_big_decimal big_dec_1 = {.bits[0] = 10};
  s21_big_decimal big_dec_2 = {.bits[0] = 1};

  big_dec_1.bits[7] = pow(2, 16);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = 0;

  ck_assert(actual == expect);
}
END_TEST

START_TEST(anomaly_bad_dec_two_more_test) {
  s21_big_decimal big_dec_1 = {.bits[0] = 1};
  s21_big_decimal big_dec_2 = {.bits[0] = 1};

  big_dec_1.bits[7] = pow(2, 17);

  int actual = s21_big_dec_compare(big_dec_1, big_dec_2);
  int expect = -1;

  ck_assert(actual == expect);
}
END_TEST

Suite *suite_s21_big_dec_compare() {
  Suite *suite = suite_create("suite_s21_big_dec_compare");

  TCase *normal_cases = tcase_create("normal_cases");
  const size_t normal_one_more_elems = GET_SIZE_ARRAY(normal_vals_one_more_1);
  const size_t normal_equal_elems = GET_SIZE_ARRAY(normal_vals_equal_1);
  const size_t normal_two_more_elems = GET_SIZE_ARRAY(normal_vals_two_more_1);
  tcase_add_loop_test(normal_cases, compare_normal_one_more, 0,
                      normal_one_more_elems);
  tcase_add_loop_test(normal_cases, compare_normal_equal, 0,
                      normal_equal_elems);
  tcase_add_loop_test(normal_cases, compare_normal_two_more, 0,
                      normal_two_more_elems);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  const size_t edge_one_more_elems = GET_SIZE_ARRAY(edge_vals_one_more_1);
  const size_t edge_equal_elems = GET_SIZE_ARRAY(edge_vals_equal_1);
  const size_t edge_two_more_elems = GET_SIZE_ARRAY(edge_vals_two_more_1);
  tcase_add_loop_test(edge_cases, compare_edge_one_more, 0,
                      edge_one_more_elems);
  tcase_add_loop_test(edge_cases, compare_edge_equal, 0, edge_equal_elems);
  tcase_add_loop_test(edge_cases, compare_edge_two_more, 0,
                      edge_two_more_elems);
  tcase_add_test(edge_cases, edge_max_1_one_more_test);
  tcase_add_test(edge_cases, edge_max_0_one_more_test);
  tcase_add_test(edge_cases, edge_max_m1_one_more_test);
  tcase_add_test(edge_cases, edge_max_min_one_more_test);
  tcase_add_test(edge_cases, edge_max_max_equal_test);
  tcase_add_test(edge_cases, edge_min_min_equal_test);
  tcase_add_test(edge_cases, edge_min_m1_two_more_test);
  tcase_add_test(edge_cases, edge_min_0_two_more_test);
  tcase_add_test(edge_cases, edge_min_1_two_more_test);
  tcase_add_test(edge_cases, edge_min_max_two_more_test);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, anomaly_set_scl_one_more_test);
  tcase_add_test(anomaly_cases, anomaly_set_scl_equal_test);
  tcase_add_test(anomaly_cases, anomaly_set_scl_two_more_test);
  tcase_add_test(anomaly_cases, anomaly_bad_dec_one_more_test);
  tcase_add_test(anomaly_cases, anomaly_bad_dec_equal_test);
  tcase_add_test(anomaly_cases, anomaly_bad_dec_dif_scl_equal_test);
  tcase_add_test(anomaly_cases, anomaly_bad_dec_two_more_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}