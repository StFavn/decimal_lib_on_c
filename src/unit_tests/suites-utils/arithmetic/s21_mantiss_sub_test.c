#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(dec_mantiss_sub_zeroes) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};

  s21_mantiss_sub(a, b, &res);
  ck_assert_uint_eq(s21_dec_to_uint128_test(res), 0ULL);
}
END_TEST

START_TEST(dec_mantiss_sub_zero) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};

  char *a_ = "30000000000000090001";
  s21_str_to_dec(a_, &a);
  s21_mantiss_sub(a, b, &res);
  ck_assert_uint_eq(s21_dec_to_uint128_test(res), s21_dec_to_uint128_test(a));
}
END_TEST

START_TEST(dec_mantiss_sub_small_nums) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};

  a.bits[0] = 42;
  b.bits[0] = 21;
  s21_mantiss_sub(a, b, &res);
  ck_assert_uint_eq(s21_dec_to_uint128_test(res), 21ULL);
}
END_TEST

START_TEST(dec_mantiss_sub_huge_nums) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};

  char *a_ = "30000000000000090001";
  char *b_ = "29999999999999990000";
  s21_str_to_dec(a_, &a);
  s21_str_to_dec(b_, &b);
  s21_mantiss_sub(a, b, &res);

  ck_assert_uint_eq(s21_dec_to_uint128_test(res), 100001ULL);
}
END_TEST

// BIG

START_TEST(big_dec_mantiss_sub_zeroes) {
  s21_big_decimal a = {0};
  s21_big_decimal b = {0};
  s21_big_decimal res = {0};

  s21_big_mantiss_sub(a, b, &res);
  ck_assert_uint_eq(s21_big_dec_to_uint128_test(res), 0ULL);
}
END_TEST

START_TEST(big_dec_mantiss_sub_zero) {
  s21_big_decimal a = {0};
  s21_big_decimal b = {0};
  s21_big_decimal res = {0};

  a.bits[6] = 1;
  s21_big_mantiss_sub(a, b, &res);
  ck_assert_uint_eq(a.bits[6], res.bits[6]);
}
END_TEST

START_TEST(big_dec_mantiss_sub_small_nums) {
  s21_big_decimal a = {0};
  s21_big_decimal b = {0};
  s21_big_decimal res = {0};

  a.bits[0] = 42;
  b.bits[0] = 21;
  s21_big_mantiss_sub(a, b, &res);
  ck_assert_uint_eq(s21_big_dec_to_uint128_test(res), 21ULL);
}
END_TEST

START_TEST(big_dec_mantiss_sub_huge_nums) {
  s21_big_decimal a = {0};
  s21_big_decimal b = {0};
  s21_big_decimal res = {0};

  a.bits[0] = 42;
  b.bits[0] = 21;
  int shift_amount = 100;

  s21_big_left_shift(&a, shift_amount);
  s21_big_left_shift(&b, shift_amount);

  s21_big_mantiss_sub(a, b, &res);

  for (int i = 0; i < 7; ++i) {
    ck_assert_uint_eq(b.bits[i], res.bits[i]);
  }
}
END_TEST

Suite *suite_s21_mantiss_sub() {
  Suite *suite = suite_create("ssuite_s21_mantiss_sub");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, dec_mantiss_sub_zeroes);
  tcase_add_test(normal_cases, dec_mantiss_sub_zero);
  tcase_add_test(normal_cases, dec_mantiss_sub_small_nums);
  tcase_add_test(normal_cases, dec_mantiss_sub_huge_nums);

  tcase_add_test(normal_cases, big_dec_mantiss_sub_zeroes);
  tcase_add_test(normal_cases, big_dec_mantiss_sub_zero);
  tcase_add_test(normal_cases, big_dec_mantiss_sub_small_nums);
  tcase_add_test(normal_cases, big_dec_mantiss_sub_huge_nums);
  suite_add_tcase(suite, normal_cases);

  // TCase *anomaly_cases =
  //   tcase_create("anomaly_cases");
  // tcase_add_test(anomaly_cases, fail_test);
  // suite_add_tcase(suite, anomaly_cases);

  return suite;
}
