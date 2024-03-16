#include "suites-core/s21_decimal_core_test.h"

// (+a > +b  = +c)
// (+a > 0   = +a)
// (+a < +b  = -c)
// (+a == +a =  0)
// (0  == 0  =  0)
// (0  < +b  = -b)
// (-a == -a =  0)
// (-a > -b  = +c)
// (-a < -b  = -c)
// (+a > -b  = +c)
// (-a < +b  = -c)

/* NORMAL */

static char *normal_vals_1[] = {
    "2",   // 0
    "1",   //
    "1",   //
    "1",   //
    "0",   //
    "0",   // 5
    "-1",  //
    "-1",  //
    "-2",  //
           // "1",     //
           // "-1",    // 10

};

static char *normal_vals_2[] = {
    "1",   // 0
    "0",   //
    "2",   //
    "1",   //
    "0",   //
    "1",   // 5
    "-1",  //
    "-2",  //
    "-1",  //
           // "-1",      // 10
           // "1",       //
};

static char *normal_result[] = {
    "1",   // 0
    "1",   //
    "-1",  //
    "0",   //
    "0",   //
    "-1",  // 5
    "0",   //
    "1",   //
    "-1",  //
           // "2",     // 10
           // "-2",    //
};

START_TEST(normal_normal_vals) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  char *val_1_str = normal_vals_1[_i];
  char *val_2_str = normal_vals_2[_i];
  char *expect_str = normal_result[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);
  s21_str_to_dec(expect_str, &expect);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
}
END_TEST

static char *normal_float_vals_1[] = {
    "2.1",   // 0
    "1.1",   //
    "1.1",   //
    "1.1",   //
    "0",     //
    "0",     // 5
    "-1.1",  //
    "-1.1",  //
    "-2.1",  //
             // "-1.1",  //
             // "1.1",   // 10
};

static char *normal_float_vals_2[] = {
    "2.0",   // 0
    "1.1",   //
    "2.2",   //
    "1.05",  //
    "0.0",   //
    "1.1",   // 5
    "-1.1",  //
    "-2.1",  //
    "-1.1",  //
             // "1.1",   //
             // "-1.1",  // 10
};

static char *normal_float_result[] = {
    "0.1",   // 0
    "0",     //
    "-1.1",  //
    "0.05",  //
    "0",     //
    "-1.1",  // 5
    "0",     //
    "1",     //
    "-1",    //
             // "-2.2",  //
             // "0",     // 10
};

START_TEST(normal_float_vals) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  char *val_1_str = normal_float_vals_1[_i];
  char *val_2_str = normal_float_vals_2[_i];
  char *expect_str = normal_float_result[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);
  s21_str_to_dec(expect_str, &expect);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
}
END_TEST

/* EDGE */

static char *edge_vals_1[] = {
    "2.21",        // 0
    "1.11",        //
    "0.99000000",  //
    "1.110",       //
    "0.0000",      //
    "0.00",        // 5
    "-0.1000",     //
    "-1.121",      //
    "-2.1111",     //
                   // "1.5555",      //
                   // "-0.1111",     // 10
};

static char *edge_vals_2[] = {
    "1.11",      // 0
    "0",         //
    "1.0000",    //
    "1.110000",  //
    "0.0",       //
    "-1.1",      // 5
    "-0.1",      //
    "-1.221",    //
    "-1.0001",   //
                 // "-1.0555",   //
                 // "0.1119",    // 10
};

static char *edge_vals_result[] = {
    "1.1",     // 0
    "1.11",    //
    "-0.01",   //
    "0",       //
    "0",       //
    "1.1",     // 5
    "0",       //
    "0.1",     //
    "-1.111",  //
               // "2.611",     //
               // "-0.223",    // 10
};

START_TEST(edge_denormalise_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  char *val_1_str = edge_vals_1[_i];
  char *val_2_str = edge_vals_2[_i];
  char *expect_str = edge_vals_result[_i];

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);
  s21_str_to_dec(expect_str, &expect);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  uint32_t actual_scale = s21_dec_get_scale(actual);
  uint32_t expect_scale = s21_dec_get_scale(expect);

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert_uint_eq(actual_scale, expect_scale);
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_max_max_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = s21_dec_get_max();
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  uint32_t actual_scale = s21_dec_get_scale(actual);
  uint32_t expect_scale = s21_dec_get_scale(expect);

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert_uint_eq(actual_scale, expect_scale);
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_min_min_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = s21_dec_get_min();
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  uint32_t actual_scale = s21_dec_get_scale(actual);
  uint32_t expect_scale = s21_dec_get_scale(expect);

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert_uint_eq(actual_scale, expect_scale);
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_max_pluse_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = s21_dec_get_max();

  expect.bits[0] -= 1;
  char *val_2_str = "1";
  s21_str_to_dec(val_2_str, &dec_2);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  uint32_t actual_scale = s21_dec_get_scale(actual);
  uint32_t expect_scale = s21_dec_get_scale(expect);

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert_uint_eq(actual_scale, expect_scale);
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_max_0_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = s21_dec_get_max();

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  uint32_t actual_scale = s21_dec_get_scale(actual);
  uint32_t expect_scale = s21_dec_get_scale(expect);

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert_uint_eq(actual_scale, expect_scale);
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_max_minus_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  char *val_2_str = "-1";
  s21_str_to_dec(val_2_str, &dec_2);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_TOO_BIG;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_max_min_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = s21_dec_get_min();
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_TOO_BIG;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_min_max_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = s21_dec_get_max();
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_TOO_SML;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_min_pluse_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  char *val_2_str = "1";
  s21_str_to_dec(val_2_str, &dec_2);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_TOO_SML;

  uint32_t actual_scale = s21_dec_get_scale(actual);
  uint32_t expect_scale = s21_dec_get_scale(expect);

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert_uint_eq(actual_scale, expect_scale);
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_min_0_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = s21_dec_get_min();

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  uint32_t actual_scale = s21_dec_get_scale(actual);
  uint32_t expect_scale = s21_dec_get_scale(expect);

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert_uint_eq(actual_scale, expect_scale);
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_min_minus_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = s21_dec_get_min();

  expect.bits[0] -= 1;
  char *val_2_str = "-1";
  s21_str_to_dec(val_2_str, &dec_2);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(edge_max_scl_1_1d1_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  char *val_1_str = "11";
  char *val_2_str = "1";
  char *expect_str = "1";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);
  s21_str_to_dec(expect_str, &expect);

  s21_dec_set_scale(&dec_1, S21_DEC_MAX_SCALE);
  s21_dec_set_scale(&dec_2, S21_DEC_MAX_SCALE);
  s21_dec_set_scale(&expect, S21_DEC_MAX_SCALE - 1);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  uint32_t actual_scale = s21_dec_get_scale(actual);
  uint32_t expect_scale = s21_dec_get_scale(expect);

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert_uint_eq(actual_scale, expect_scale);
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

/* ANOMALY */

// слишком большое число
START_TEST(anomaly_overflow_value_more_max_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  char *val_2_str = "-1";
  s21_str_to_dec(val_2_str, &dec_2);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_TOO_BIG;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

// слишком маленькое число
START_TEST(anomaly_overflow_value_more_min_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  char *val_2_str = "1";
  s21_str_to_dec(val_2_str, &dec_2);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_TOO_SML;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

// 111...111 - 0.000...001 - округление
START_TEST(anomaly_overflow_scl_positive_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = s21_dec_get_max();

  char *val_2_str = "1";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_dec_set_scale(&dec_2, S21_DEC_MAX_SCALE);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

// -111...111 + 0.000...001 - округление
START_TEST(anomaly_overflow_scl_negative_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = s21_dec_get_min();

  char *val_2_str = "-1";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_dec_set_scale(&dec_2, S21_DEC_MAX_SCALE);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

START_TEST(anomaly_for_round_test) {
  s21_decimal dec_1 = {0};
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = {0};

  char *val_1_str = "79228162514264337593543950335";
  char *val_2_str = "0.6";
  char *expect_str = "79228162514264337593543950334";

  s21_str_to_dec(val_1_str, &dec_1);
  s21_str_to_dec(val_2_str, &dec_2);
  s21_str_to_dec(expect_str, &expect);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

// 111...111 + 0.000...001 - слишком большое число
START_TEST(anomaly_overflow_scl_value_more_max_test) {
  s21_decimal dec_1 = s21_dec_get_max();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = s21_dec_get_max();

  char *val_2_str = "-1";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_dec_set_scale(&dec_2, S21_DEC_MAX_SCALE);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
}
END_TEST

// -111...111 - 0.000...001 - слишком маленькое число
START_TEST(anomaly_overflow_scl_value_more_min_test) {
  s21_decimal dec_1 = s21_dec_get_min();
  s21_decimal dec_2 = {0};
  s21_decimal actual = {0};
  s21_decimal expect = s21_dec_get_min();

  char *val_2_str = "1";
  s21_str_to_dec(val_2_str, &dec_2);
  s21_dec_set_scale(&dec_2, S21_DEC_MAX_SCALE);

  int actual_code = s21_sub(dec_1, dec_2, &actual);
  int expect_code = S21_RETURN_CODE_OK;

  ck_assert_int_eq(actual_code, expect_code);
  ck_assert(s21_is_equal(actual, expect));
  ck_assert(s21_mantiss_compare(actual, expect) == 0);
}
END_TEST

Suite *suite_s21_sub() {
  Suite *suite = suite_create("suite_s21_sub");

  TCase *normal_cases = tcase_create("normal_cases");
  const size_t normal_vals_elems = GET_SIZE_ARRAY(normal_vals_1);
  const size_t normal_float_elems = GET_SIZE_ARRAY(normal_float_vals_1);
  tcase_add_loop_test(normal_cases, normal_normal_vals, 0, normal_vals_elems);
  tcase_add_loop_test(normal_cases, normal_float_vals, 0, normal_float_elems);
  suite_add_tcase(suite, normal_cases);

  TCase *edge_cases = tcase_create("edge_cases");
  const size_t edge_vals_elems = GET_SIZE_ARRAY(edge_vals_1);
  tcase_add_loop_test(edge_cases, edge_denormalise_test, 0, edge_vals_elems);
  tcase_add_test(edge_cases, edge_max_max_test);
  tcase_add_test(edge_cases, edge_min_min_test);
  tcase_add_test(edge_cases, edge_max_pluse_test);
  tcase_add_test(edge_cases, edge_max_0_test);
  tcase_add_test(edge_cases, edge_max_minus_test);
  tcase_add_test(edge_cases, edge_max_min_test);
  tcase_add_test(edge_cases, edge_min_max_test);
  tcase_add_test(edge_cases, edge_min_pluse_test);
  tcase_add_test(edge_cases, edge_min_0_test);
  tcase_add_test(edge_cases, edge_min_minus_test);
  tcase_add_test(edge_cases, edge_max_scl_1_1d1_test);
  suite_add_tcase(suite, edge_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, anomaly_overflow_value_more_max_test);
  tcase_add_test(anomaly_cases, anomaly_overflow_value_more_min_test);
  tcase_add_test(anomaly_cases, anomaly_overflow_scl_positive_test);
  tcase_add_test(anomaly_cases, anomaly_overflow_scl_negative_test);
  tcase_add_test(anomaly_cases, anomaly_overflow_scl_value_more_max_test);
  tcase_add_test(anomaly_cases, anomaly_overflow_scl_value_more_min_test);
  tcase_add_test(anomaly_cases, anomaly_for_round_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
