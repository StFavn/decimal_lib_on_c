#include "suites-utils/s21_decimal_utils_test.h"

#define LD_EPS 1E-6

static long double get_real_ld(const s21_decimal *dec) {
  return s21_dec_to_ld(dec) / powl(10, s21_dec_get_scale(*dec));
}

static void cycle_cases_normal(char *str_v1, char *str_v2) {
  s21_decimal value_1 = s21_dec_init(str_v1);
  s21_decimal value_2 = s21_dec_init(str_v2);
  long double ld_value_1 = get_real_ld(&value_1);
  long double ld_value_2 = get_real_ld(&value_2);
  long double expected = ld_value_1 * ld_value_2;

  s21_decimal result = {0};

  int status_code = s21_mul(value_1, value_2, &result);
  long double ld_result = get_real_ld(&result);

  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_double_eq_tol(expected, ld_result, LD_EPS);
}

static char *str_eq_values_1[] = {"0", "10", "0", "1", "123", "1"};
static char *str_eq_values_2[] = {"10", "0", "0", "123", "1", "1"};

START_TEST(normal_test_zero_one) {
  char *v1 = str_eq_values_1[_i];
  char *v2 = str_eq_values_2[_i];

  cycle_cases_normal(v1, v2);
}
END_TEST

static char *str_eq02_values_1[] = {
    "0.01", "15",      "123.25",       "78.3256",   "-0.02",
    "-12",  "-568.25", "-1.123456789", "0.0000123", "-0.0000123"};
static char *str_eq02_values_2[] = {"0.02",     "23",    "6.326",  "89.1235",
                                    "7.123",    "56.23", "35.266", "1.112",
                                    "0.000502", "0.025"};

START_TEST(normal_test_small_numbers) {
  char *v1 = str_eq02_values_1[_i];
  char *v2 = str_eq02_values_2[_i];

  cycle_cases_normal(v1, v2);
}
END_TEST

// generate int number, py: random.getrandbits(96)
// decimal parameter: decimal.getcontext().prec=29
static char *str_eq03_values_1[] = {
    "815.2666800543878376877190074",  // 0
    "255.68728819464312070882225417", "66.34845812959974241448260434",
    "628.00282808293542677109848449", "532.51668111440327389091254387",
    "-52.10036273809646572543482981",  // 5
    "373.15034531230776389820004528", "696.69641600708707293896571815",
    "662.98261023162585511938232681", "44.89732808460487510408142029",
    "781.96772587737690399327848685",  // 10
};
static char *str_eq03_values_2[] = {
    "56.865588382483744631730516005",  // 0
    "40.154899583355739877021142551",  "46.85661761398373824621888764",
    "-63.561990111989290717112308967", "61.020138084824896005429835698",
    "43.267714142659397477276384974",  // 5
    "59.730322682058029210290029455",  "3.982723359492798834629664324",
    "19.107850886041394476846566173",  "76.989136776481415850522526649",
    "1.182296860102236972388726127",  // 10
};
static char *str_eq03_res[] = {
    "46360.619449926889030841925994",  // 0
    "10267.097382196434035042737176", "3108.8643318560658428984484935",
    "-39917.109548908852052418851804", "32494.241414073553657161180268",
    "-2254.2636016808211399833002536",  // 5
    "22288.390534425522423591283918", "2774.7490905063383768399118701",
    "12668.172856344408579272306271", "3456.6065328042051146905606808",
    // Переполнение; результат питона:
    // 924.51798700610947142717495959
    "924.5179870061094714271749596",  // 10
};

START_TEST(normal_test_dec_numbers) {
  s21_decimal value_1 = s21_dec_init(str_eq03_values_1[_i]);
  s21_decimal value_2 = s21_dec_init(str_eq03_values_2[_i]);
  s21_decimal expected = s21_dec_init(str_eq03_res[_i]);
  s21_decimal result = {0};

  int status_code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_is_equal(result, expected), true);
}
END_TEST

static char ten_powers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
static char *multupler[] = {"10",         "100",        "1000",     "10000",
                            "100000",     "1000000",    "10000000", "100000000",
                            "1000000000", "10000000000"};

START_TEST(normal_test_ten_crosscheck) {
  s21_decimal value_1 = s21_dec_init("123.50032142");
  s21_decimal ten = s21_dec_init(multupler[_i]);
  s21_decimal result = {0};
  s21_decimal mult_by_ten_res = value_1;

  int status_code = s21_mul(value_1, ten, &result);
  s21_dec_mult_by_ten(&mult_by_ten_res, ten_powers[_i]);
  s21_dec_truncate_trailing_zeros(&mult_by_ten_res);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_is_equal(result, mult_by_ten_res), true);
}
END_TEST

START_TEST(normal_test_big_by_one) {
  s21_decimal value_1 = s21_dec_init("79228162514264337593543950335");
  s21_decimal value_2 = s21_dec_init("1");
  s21_decimal result = {0};

  int status_code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_OK);
  ck_assert_int_eq(s21_is_equal(result, value_1), true);
}
END_TEST

/* ANOMALY */

START_TEST(too_big_test) {
  s21_decimal value_1 = s21_dec_init("79228162514264337593543950335");
  s21_decimal value_2 = s21_dec_init("2");
  s21_decimal result = {0};

  int status_code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(status_code, S21_RETURN_TOO_BIG);
}
END_TEST

START_TEST(too_small_test) {
  s21_decimal value_1 = s21_dec_init("0.000000000000000000000000001");
  s21_decimal value_2 = s21_dec_init("0.001");
  s21_decimal result = {0};

  int status_code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(status_code, S21_RETURN_TOO_SML);
}
END_TEST

START_TEST(null_test) {
  s21_decimal value_1 = s21_dec_init("123.56");
  s21_decimal value_2 = s21_dec_init("0.001");

  int status_code = s21_mul(value_1, value_2, NULL);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(bad_dec_test_01) {
  s21_decimal value_1 = {0};
  value_1.bits[3] = 21;
  s21_decimal value_2 = s21_dec_init("0.001");
  s21_decimal result = {0};

  int status_code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

START_TEST(bad_dec_test_02) {
  s21_decimal value_2 = {0};
  value_2.bits[3] = 21;
  s21_decimal value_1 = s21_dec_init("0.001");
  s21_decimal result = {0};

  int status_code = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(status_code, S21_RETURN_CODE_ERR);
}
END_TEST

Suite *suite_s21_mul() {
  Suite *suite = suite_create("suite_s21_mul");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_loop_test(normal_cases, normal_test_zero_one, 0,
                      GET_SIZE_ARRAY(str_eq_values_1));
  tcase_add_loop_test(normal_cases, normal_test_small_numbers, 0,
                      GET_SIZE_ARRAY(str_eq02_values_1));
  tcase_add_loop_test(normal_cases, normal_test_dec_numbers, 0,
                      GET_SIZE_ARRAY(str_eq03_values_1));
  tcase_add_loop_test(normal_cases, normal_test_ten_crosscheck, 0,
                      GET_SIZE_ARRAY(ten_powers));
  tcase_add_test(normal_cases, normal_test_big_by_one);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  tcase_add_test(anomaly_cases, too_big_test);
  tcase_add_test(anomaly_cases, too_small_test);
  tcase_add_test(anomaly_cases, null_test);
  tcase_add_test(anomaly_cases, bad_dec_test_01);
  tcase_add_test(anomaly_cases, bad_dec_test_02);
  // tcase_add_test(anomaly_cases, div_by_zero_test);
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
