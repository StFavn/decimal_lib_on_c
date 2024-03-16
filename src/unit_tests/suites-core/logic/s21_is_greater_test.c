#include "suites-core/s21_decimal_core_test.h"

/* NORMAL */

static char *normal_vals_is_greater_1[] = {
    "20",         // 0
    "10",         //
    "10",         //
    "0",          //
    "1.0",        //
    "1.0",        // 5
    "0.1",        //
    "1.9999",     //
    "0.0000001",  //
    "-10",        //
    "-1.9999",    // 10
    "0"           //
};

static char *normal_vals_is_greater_2[] = {
    "10",          // 0
    "0",           //
    "-10",         //
    "-100",        //
    "-0,00001",    //
    "0.999999",    // 5
    "0.099999",    //
    "1.9998",      //
    "-0.0000001",  //
    "-11",         //
    "-2.01",       // 10
    "-1.0"         //
};

START_TEST(normal_is_greater) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1 = normal_vals_is_greater_1[_i];
  char *val_2 = normal_vals_is_greater_2[_i];

  s21_str_to_dec(val_1, &dec_1);
  s21_str_to_dec(val_2, &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2));
}
END_TEST

static char *normal_vals_equal_1[] = {
    "20",         // 0
    "10",         //
    "10",         //
    "0",          //
    "1.0",        //
    "1.0",        // 5
    "0.1",        //
    "1.9999",     //
    "0.0000001",  //
    "-10",        //
    "-1.9999",    // 10
    "0"           //
};

static char *normal_vals_equal_2[] = {
    "20",         // 0
    "10",         //
    "10",         //
    "0",          //
    "1.0",        //
    "1.0",        // 5
    "0.1",        //
    "1.9999",     //
    "0.0000001",  //
    "-10",        //
    "-1.9999",    // 10
    "0"           //
};

START_TEST(normal_equal) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1 = normal_vals_equal_1[_i];
  char *val_2 = normal_vals_equal_2[_i];

  s21_str_to_dec(val_1, &dec_1);
  s21_str_to_dec(val_2, &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

static char *normal_vals_is_not_greater_1[] = {
    "19",          // 0
    "9",           //
    "-1",          //
    "-100",        //
    "0",           //
    "0.999999",    // 5
    "0.099999",    //
    "1.99998",     //
    "-0.0000001",  //
    "-11",         //
    "-2.01",       // 10
    "-1.0"         //
};

static char *normal_vals_is_not_greater_2[] = {
    "20",         // 0
    "10",         //
    "100",        //
    "0",          //
    "1.0",        //
    "1.0",        // 5
    "0.1",        //
    "1.99999",    //
    "0.0000001",  //
    "-10",        //
    "-1.9999",    // 10
    "0"           //
};

START_TEST(normal_is_not_greater) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1 = normal_vals_is_not_greater_1[_i];
  char *val_2 = normal_vals_is_not_greater_2[_i];

  s21_str_to_dec(val_1, &dec_1);
  s21_str_to_dec(val_2, &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

/* EDGE */

static char *edge_vals_is_greater_1[] = {
    // 79228162514264337593543950335
    "+0.7777",                        // 0
    "+0.7777",                        //
    "+0.7777",                        //
    "+0.7777",                        //
    "+0.7777",                        //
    "123.4500001",                    // 5
    "123.4500000",                    //
    "5342213534002214242424242423",   //
    "5342213534002214242424242423",   //
    "5342213534002214242424242423",   //
    "0.000000000000000000000000010",  // 10
    "0.000000000000000000000000002",  //
    "0.000000000000000000000000001",  //
    "0.000000000000000000000000001"   //
};

static char *edge_vals_is_greater_2[] = {
    // 79228162514264337593543950335
    "+0.5222",                         // 0
    "+0.0",                            //
    "0",                               //
    "-0",                              //
    "-1",                              //
    "123.45",                          // 5
    "-1",                              //
    "4345345346221353453453462214",    //
    "0",                               //
    "-53453453462213534534534622142",  //
    "0.000000000000000000000000001",   // 10
    "0.000000000000000000000000001",   //
    "0.000000000000000000000000000",   //
    "-0.000000000000000000000000001"   //
};

START_TEST(edge_is_greater) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1 = edge_vals_is_greater_1[_i];
  char *val_2 = edge_vals_is_greater_2[_i];

  s21_str_to_dec(val_1, &dec_1);
  s21_str_to_dec(val_2, &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2));
}
END_TEST

static char *edge_vals_is_not_greater_1[] = {
    // 79228162514264337593543950335
    "+0.5222",                         // 0
    "+0.0",                            //
    "0",                               //
    "-0",                              //
    "-1",                              //
    "123.4500001",                     // 5
    "-1",                              //
    "434534534622135345345346221",     //
    "0",                               //
    "-53453453462213534534534622142",  //
    "0.0000000000000000000000000001",  // 10
    "0.0000000000000000000000000001",  //
    "0.0000000000000000000000000000",  //
    "-0.000000000000000000000000001"   //
};

static char *edge_vals_is_not_greater_2[] = {
    // 79228162514264337593543950335
    "+0.7777",                       // 0
    "+0.7777",                       //
    "+0.7777",                       //
    "+0.7777",                       //
    "+0.7777",                       //
    "123.4500001",                   // 5
    "123.4500000",                   //
    "7340022135342214242424242423",  //
    "7340022135342214242424242423",  //
    "7340022135342214242424242423",  //
    "0.00000000000000000000000010",  // 10
    "0.00000000000000000000000002",  //
    "0.00000000000000000000000001",  //
    "0.00000000000000000000000001"   //
};

START_TEST(edge_is_not_greater) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1 = edge_vals_is_not_greater_1[_i];
  char *val_2 = edge_vals_is_not_greater_2[_i];

  s21_str_to_dec(val_1, &dec_1);
  s21_str_to_dec(val_2, &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

static char *edge_vals_equal_not_greater_1[] = {
    // 79228162514264337593543950335
    "+0.5222",                         // 0
    "+0.0",                            //
    "0",                               //
    "-0",                              //
    "-1",                              //
    "123.4500001",                     // 5
    "-1",                              //
    "43453453462213534534534622142",   //
    "0",                               //
    "-53453453462213534534534622142",  //
    "0.000000000000000000000000001",   // 10
    "0.000000000000000000000000001",   //
    "0.000000000000000000000000000",   //
    "-0.00000000000000000000000001"    //
};

static char *edge_vals_equal_not_greater_2[] = {
    // 79228162514264337593543950335
    "+0.5222",                         // 0
    "+0.0",                            //
    "0",                               //
    "-0",                              //
    "-1",                              //
    "123.4500001",                     // 5
    "-1",                              //
    "43453453462213534534534622142",   //
    "0",                               //
    "-53453453462213534534534622142",  //
    "0.000000000000000000000000001",   // 10
    "0.000000000000000000000000001",   //
    "0.000000000000000000000000000",   //
    "-0.00000000000000000000000001"    //
};

START_TEST(edge_equal_not_greater) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};

  char *val_1 = edge_vals_equal_not_greater_1[_i];
  char *val_2 = edge_vals_equal_not_greater_2[_i];

  s21_str_to_dec(val_1, &dec_1);
  s21_str_to_dec(val_2, &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(edge_max_1_greater_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = {};

  s21_str_to_dec("1", &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2));
}
END_TEST

START_TEST(edge_max_0_greater_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = {};

  s21_str_to_dec("0", &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2));
}
END_TEST

START_TEST(edge_max_m1_greater_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = {};

  s21_str_to_dec("-1", &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2));
}
END_TEST

START_TEST(edge_max_min_greater_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = s21_dec_get_min();

  ck_assert(s21_is_greater(dec_1, dec_2));
}
END_TEST

START_TEST(edge_max_max_equal_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = s21_dec_get_max();

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(edge_min_min_equal_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = s21_dec_get_min();

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(edge_min_m1_not_greater_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = {};

  s21_str_to_dec("-1", &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(edge_min_0_not_greater_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = {};

  s21_str_to_dec("0", &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(edge_min_1_not_greater_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = {};

  s21_str_to_dec("1", &dec_2);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(edge_min_max_not_greater_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = s21_dec_get_max();

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(edge_scale_overflow_test) {
  s21_decimal dec_1 = s21_dec_init("7922816251426433759354395033.5");
  s21_decimal dec_2 = s21_dec_init("792281625142643375935439503.35");

  ck_assert(s21_is_greater(dec_1, dec_2) == 1);
}
END_TEST

START_TEST(test_is_greater_ok5432) {
  // -1.22
  s21_decimal decimal1 = {{0x7A, 0x0, 0x0, 0x80020000}};
  // -0.0000000000000000000000000000
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  ck_assert(s21_is_greater(decimal1, decimal2) == check);
}

/* ANOMALY */

START_TEST(anomaly_set_scl_test) {
  s21_decimal dec_1 = {.bits[0] = 1};
  s21_decimal dec_2 = {.bits[0] = 1};

  s21_dec_set_scale(&dec_2, 2);

  ck_assert(s21_is_greater(dec_1, dec_2));
}
END_TEST

START_TEST(anomaly_set_scl_equal_test) {
  s21_decimal dec_1 = {.bits[0] = 1};
  s21_decimal dec_2 = {.bits[0] = 1};

  s21_dec_set_scale(&dec_1, 10);
  s21_dec_set_scale(&dec_2, 10);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(anomaly_set_scl_not_test) {
  s21_decimal dec_1 = {.bits[0] = 1};
  s21_decimal dec_2 = {.bits[0] = 1};

  s21_dec_set_scale(&dec_1, 2);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(anomaly_bad_dec_test) {
  s21_decimal dec_1 = {.bits[0] = 1};
  s21_decimal dec_2 = {.bits[0] = 1};

  dec_2.bits[3] = pow(2, 17);

  ck_assert(s21_is_greater(dec_1, dec_2));
}
END_TEST

START_TEST(anomaly_bad_dec_equal_test) {
  s21_decimal dec_1 = {.bits[0] = 10};
  s21_decimal dec_2 = {.bits[0] = 10};

  dec_1.bits[3] = pow(2, 19);
  dec_2.bits[3] = pow(2, 19);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(anomaly_bad_dec_dif_scl_equal_test) {
  s21_decimal dec_1 = {.bits[0] = 10};
  s21_decimal dec_2 = {.bits[0] = 1};

  dec_1.bits[3] = pow(2, 16);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

START_TEST(anomaly_bad_dec_not_greater_test) {
  s21_decimal dec_1 = {.bits[0] = 1};
  s21_decimal dec_2 = {.bits[0] = 1};

  dec_1.bits[3] = pow(2, 17);

  ck_assert(s21_is_greater(dec_1, dec_2) == 0);
}
END_TEST

Suite *suite_s21_is_greater() {
  Suite *suite = suite_create("suite_s21_is_greater");

  TCase *normal_cases = tcase_create("normal_cases");
  const size_t normal_greater_elems = GET_SIZE_ARRAY(normal_vals_is_greater_1);
  const size_t normal_not_greater_elems =
      GET_SIZE_ARRAY(normal_vals_is_not_greater_1);
  const size_t normal_equal_elems = GET_SIZE_ARRAY(normal_vals_equal_1);
  tcase_add_loop_test(normal_cases, normal_is_greater, 0, normal_greater_elems);
  tcase_add_loop_test(normal_cases, normal_is_not_greater, 0,
                      normal_not_greater_elems);
  tcase_add_loop_test(normal_cases, normal_equal, 0, normal_equal_elems);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  const size_t edge_greater_elems = GET_SIZE_ARRAY(edge_vals_is_greater_1);
  const size_t edge_not_greater_elems =
      GET_SIZE_ARRAY(edge_vals_is_not_greater_1);
  const size_t edge_equal_elems = GET_SIZE_ARRAY(edge_vals_equal_not_greater_1);
  tcase_add_loop_test(edge_cases, edge_is_greater, 0, edge_greater_elems);
  tcase_add_loop_test(edge_cases, edge_is_not_greater, 0,
                      edge_not_greater_elems);
  tcase_add_loop_test(edge_cases, edge_equal_not_greater, 0, edge_equal_elems);
  tcase_add_test(edge_cases, edge_max_1_greater_test);
  tcase_add_test(edge_cases, edge_max_0_greater_test);
  tcase_add_test(edge_cases, edge_max_m1_greater_test);
  tcase_add_test(edge_cases, edge_max_min_greater_test);
  tcase_add_test(edge_cases, edge_max_max_equal_test);
  tcase_add_test(edge_cases, edge_min_min_equal_test);
  tcase_add_test(edge_cases, edge_min_m1_not_greater_test);
  tcase_add_test(edge_cases, edge_min_0_not_greater_test);
  tcase_add_test(edge_cases, edge_min_1_not_greater_test);
  tcase_add_test(edge_cases, edge_min_max_not_greater_test);
  tcase_add_test(edge_cases, edge_scale_overflow_test);
  tcase_add_test(edge_cases, test_is_greater_ok5432);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, anomaly_set_scl_test);
  tcase_add_test(anomaly_cases, anomaly_set_scl_equal_test);
  tcase_add_test(anomaly_cases, anomaly_set_scl_not_test);
  tcase_add_test(anomaly_cases, anomaly_bad_dec_test);
  tcase_add_test(anomaly_cases, anomaly_bad_dec_equal_test);
  tcase_add_test(anomaly_cases, anomaly_bad_dec_dif_scl_equal_test);
  tcase_add_test(anomaly_cases, anomaly_bad_dec_not_greater_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}