#include "suites-core/s21_decimal_core_test.h"

void fail_assert_cases(s21_decimal *dec, float f_x) {
  s21_decimal expected = {0};
  int res = s21_from_float_to_decimal(f_x, dec);

  ck_assert_uint_eq(res, S21_RETURN_CODE_ERR);
  ck_assert_int_eq(s21_is_equal(*dec, expected), true);
}

void normal_assert_cases(s21_decimal *dec, float f_x, __uint128_t expected_res,
                         int expected_scale, bool expected_sign) {
  int res = s21_from_float_to_decimal(f_x, dec);
  ck_assert_uint_eq(res, S21_RETURN_CODE_OK);
  ck_assert_uint_eq(s21_dec_to_uint128_test(*dec), expected_res);
  ck_assert_uint_eq(s21_dec_get_scale(*dec), expected_scale);
  ck_assert_uint_eq(s21_dec_get_sign(*dec), expected_sign);
}

// POSITIVE NUMBER NORMAL
START_TEST(pos_num_test_01) {
  s21_decimal dec = {0};
  float f_x = 1230.450;
  __uint128_t expected_res = 123045ULL;
  int expected_scale = 2;
  bool expected_sign = false;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

START_TEST(pos_num_test_02) {
  s21_decimal dec = {0};
  float f_x = 0.0000001;
  ;
  __uint128_t expected_res = 1ULL;
  int expected_scale = 7;
  bool expected_sign = false;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

START_TEST(pos_num_test_03) {
  s21_decimal dec = {0};
  float f_x = 1234560000000;
  __uint128_t expected_res = 1234560000000ULL;
  int expected_scale = 0;
  bool expected_sign = false;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

START_TEST(pos_num_test_04) {
  s21_decimal dec = {0};
  float f_x = 0.0;
  __uint128_t expected_res = 0ULL;
  int expected_scale = 0;
  bool expected_sign = false;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

START_TEST(pos_num_test_05) {
  s21_decimal dec = {0};
  float f_x = S21_DEC_MIN_FLOAT + 1e-28;
  __uint128_t expected_res = 2ULL;
  int expected_scale = 28;
  bool expected_sign = false;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

START_TEST(normal_test_01) {
  s21_decimal dec = {0};
  float f_x = 2.75726864E-23;
  __uint128_t expected_res = 275727ULL;
  int expected_scale = 28;
  bool expected_sign = false;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

// NEGATIVE NUMBER NORMAL

START_TEST(neg_num_test_01) {
  s21_decimal dec = {0};
  float f_x = -1230.450;
  __uint128_t expected_res = 123045ULL;
  int expected_scale = 2;
  bool expected_sign = true;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

START_TEST(neg_num_test_02) {
  s21_decimal dec = {0};
  float f_x = -0.0000001;
  ;
  __uint128_t expected_res = 1ULL;
  int expected_scale = 7;
  bool expected_sign = true;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

START_TEST(neg_num_test_03) {
  s21_decimal dec = {0};
  float f_x = -1234560000000;
  __uint128_t expected_res = 1234560000000ULL;
  int expected_scale = 0;
  bool expected_sign = true;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

START_TEST(neg_num_test_04) {
  s21_decimal dec = {0};
  float f_x = -0.0;
  __uint128_t expected_res = 0ULL;
  int expected_scale = 0;
  bool expected_sign = true;

  normal_assert_cases(&dec, f_x, expected_res, expected_scale, expected_sign);
}
END_TEST

// FAIL TESTS

// Сценарий исключен, т.к. мы теперь не проверяем корректность
// переданного s21_decimal и принудительно зануляем его
// START_TEST(fail_test_01) {
//   s21_decimal dec = {0};
//   float f_x = 21.42;
//   s21_dec_set_bit(&dec, 122, true);

//   fail_assert_cases(&dec, f_x);
// }
// END_TEST

START_TEST(fail_test_02) {
  s21_decimal dec = {0};
  float f_x = FLT_MAX;
  s21_dec_set_bit(&dec, 122, true);

  fail_assert_cases(&dec, f_x);
}
END_TEST

START_TEST(fail_test_03) {
  s21_decimal dec = {0};
  float f_x = FLT_MIN;
  s21_dec_set_bit(&dec, 122, true);

  fail_assert_cases(&dec, f_x);
}
END_TEST

START_TEST(fail_test_04) {
  s21_decimal dec = {0};
  // Т.к. анализируем только 6 значащих цифр
  // S21DMAX_FLOAT + 1 не даст превышения максимального значения
  float f_x = S21_DEC_MAX_FLOAT + 1e+22;
  s21_dec_set_bit(&dec, 122, true);

  fail_assert_cases(&dec, f_x);
}
END_TEST

// Сценарий исключен, т.к. мы теперь не проверяем корректность
// переданного s21_decimal и принудительно зануляем его
// START_TEST(fail_test_05) {
//   s21_decimal dec = {0};
//   float f_x = S21_DEC_MIN_FLOAT;
//   s21_dec_set_bit(&dec, 122, true);

//   fail_assert_cases(&dec, f_x);
// }
// END_TEST

START_TEST(fail_test_06) {
  s21_decimal dec = {0};
  float f_x = INFINITY;
  fail_assert_cases(&dec, f_x);
}
END_TEST

START_TEST(fail_test_07) {
  s21_decimal dec = {0};
  float f_x = -INFINITY;
  fail_assert_cases(&dec, f_x);
}
END_TEST

START_TEST(fail_test_08) {
  s21_decimal dec = {0};
  float f_x = NAN;
  fail_assert_cases(&dec, f_x);
}
END_TEST

static const float fails_big[] = {
    340282346638528859811704183484516925440.f,
    340282326356119256160033759537265639424.f,
    340282306073709652508363335590014353408.f,
    170141173319264429905852091742258462720.f,
    226854897759019239874469455656344616960.f,
    283568632339978851668922031544056414208.f,
    85070586659632214952926045871129231360.f,
    85070591730234615865843651857942052864.f,
    5316911666227013434557877866945576960.f,
    2658455991569831745807614120560689152.f,
    20769186196199271228741710417756160.f,
    10384593717069655257060992658440192.f,
    158456325028528675187087900672.0f,
    158456315583795709447797473280.0f,
    158456306139062743708507045888.0f,
    316912631167591418895594946560.f,
    158456325028528675187087900672.f,
    79228190848463234811415232512.f,
    79228181403730269072124805120.f,
    79228171958997303332834377728.f,
    79228162514264337593543950336.f,
    79228162514264337593543950335.f,
};

static const float fails_small[] = {
    0.00000000000000000000000000009999999429857660888699309391359540480357727713304344f,
    0.00000000000000000000000000009999998828004553267688105311366433422567940670147579f,
    0.00000000000000000000000000009999998226151445646676901231373326364778153626990814f,
    0.00000000000000000000000000009000000028539691658739462124217382784332763280814999f,
    0.00000000000000000000000000005000000015855384254855256735676323769073757378230555f,
    0.00000000000000000000000000004999999714928830444349654695679770240178863856652172f,
    4.999999414002276633844052655683216711283970335073789659219301029224880039691925048828125E-29f,
    1.2621774483536188886587657044524579674771302961744368076324462890625E-29f,
    1.0000000031710768509710513471352647538147514756461109453056224083411507308483123779296875E-29f,
    7.7037193183714626222678539700519994217126886949453196668630670929101000865557580254971981E-34f,
    4.8148245739821641389174087312824996385704304343408247917894169330688125540973487659357488E-35f,
    1.1754943508222875079687365372222456778186655567720875215087517062784172594547271728515625E-38f,
    1.4012984643248170709237295832899161312802619418765157717570682838897910826858606014866381E-45f,
};

START_TEST(fail_test_09) {
  float f_x = fails_small[_i];
  s21_decimal dec;
  fail_assert_cases(&dec, f_x);
}
END_TEST

START_TEST(fail_test_10) {
  float f_x = -fails_small[_i];
  s21_decimal dec;
  fail_assert_cases(&dec, f_x);
}
END_TEST

START_TEST(fail_test_11) {
  float f_x = fails_big[_i];
  s21_decimal dec;
  fail_assert_cases(&dec, f_x);
}
END_TEST

START_TEST(fail_test_12) {
  float f_x = -fails_big[_i];
  s21_decimal dec;
  fail_assert_cases(&dec, f_x);
}
END_TEST

Suite *suite_s21_float_to_dec() {
  Suite *suite = suite_create("suite_s21_float_to_dec");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, pos_num_test_01);
  tcase_add_test(normal_cases, pos_num_test_02);
  tcase_add_test(normal_cases, pos_num_test_03);
  tcase_add_test(normal_cases, pos_num_test_04);
  tcase_add_test(normal_cases, pos_num_test_05);

  tcase_add_test(normal_cases, neg_num_test_01);
  tcase_add_test(normal_cases, neg_num_test_02);
  tcase_add_test(normal_cases, neg_num_test_03);
  tcase_add_test(normal_cases, neg_num_test_04);

  tcase_add_test(normal_cases, normal_test_01);
  suite_add_tcase(suite, normal_cases);

  TCase *anomaly_cases = tcase_create("anomaly_cases");
  // tcase_add_test(anomaly_cases, fail_test_01);
  tcase_add_test(anomaly_cases, fail_test_02);
  tcase_add_test(anomaly_cases, fail_test_03);
  tcase_add_test(anomaly_cases, fail_test_04);
  // tcase_add_test(anomaly_cases, fail_test_05);
  tcase_add_test(anomaly_cases, fail_test_06);
  tcase_add_test(anomaly_cases, fail_test_07);
  tcase_add_test(anomaly_cases, fail_test_08);
  tcase_add_loop_test(normal_cases, fail_test_09, 0,
                      GET_SIZE_ARRAY(fails_small));
  tcase_add_loop_test(normal_cases, fail_test_10, 0,
                      GET_SIZE_ARRAY(fails_small));
  tcase_add_loop_test(normal_cases, fail_test_11, 0, GET_SIZE_ARRAY(fails_big));
  tcase_add_loop_test(normal_cases, fail_test_12, 0, GET_SIZE_ARRAY(fails_big));
  suite_add_tcase(suite, anomaly_cases);

  return suite;
}
