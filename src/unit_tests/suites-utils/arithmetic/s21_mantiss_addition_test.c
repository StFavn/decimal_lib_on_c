#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(s21_mantiss_add_test) {
  // Базовые проверки
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res = {0};

  // 0 + 0
  ck_assert_uint_eq(s21_mantiss_addition(a, b, &res), 0);
  ck_assert_uint_eq(s21_dec_to_uint128_test(res), 0);

  // 42 + 21
  memset(&res, 0, sizeof(s21_decimal));
  a.bits[0] = 42;
  b.bits[0] = 21;
  ck_assert_uint_eq(s21_mantiss_addition(a, b, &res), 0);
  ck_assert_uint_eq(s21_dec_to_uint128_test(res), 63);

  // Сложение с переносом бита в страший блок
  memset(&a, 0, sizeof(s21_decimal));
  memset(&b, 0, sizeof(s21_decimal));
  memset(&res, 0, sizeof(s21_decimal));

  a.bits[0] = ~0U;
  b.bits[0] = 1;

  ck_assert_uint_eq(s21_mantiss_addition(a, b, &res), 0);
  ck_assert_uint_eq(s21_dec_to_uint128_test(res), 4294967296ULL);

  memset(&a, 0, sizeof(s21_decimal));
  memset(&b, 0, sizeof(s21_decimal));
  memset(&res, 0, sizeof(s21_decimal));

  a.bits[0] = ~0U;
  a.bits[1] = ~0U;
  b.bits[0] = 1;

  ck_assert_uint_eq(s21_mantiss_addition(a, b, &res), 0);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 1);

  // Переполнение
  memset(&a, 0, sizeof(s21_decimal));
  memset(&b, 0, sizeof(s21_decimal));
  memset(&res, 0, sizeof(s21_decimal));

  a.bits[0] = ~0U;
  a.bits[1] = ~0U;
  a.bits[2] = ~0U;
  b.bits[0] = 1;

  ck_assert_uint_eq(s21_mantiss_addition(a, b, &res), 1);
  // При переполнении в данном случае мантисса обнуляется
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
}
END_TEST

START_TEST(s21_big_mantiss_add_test) {
  // Базовые проверки
  s21_big_decimal a = {0};
  s21_big_decimal b = {0};
  s21_big_decimal res = {0};

  // 0 + 0
  ck_assert_uint_eq(s21_big_mantiss_addition(a, b, &res), 0);
  ck_assert_uint_eq(s21_big_dec_to_uint128_test(res), 0);

  // 42 + 21
  memset(&res, 0, sizeof(s21_big_decimal));
  a.bits[0] = 42;
  b.bits[0] = 21;
  ck_assert_uint_eq(s21_big_mantiss_addition(a, b, &res), 0);
  ck_assert_uint_eq(s21_big_dec_to_uint128_test(res), 63);

  // Сложение с переносом бита в страший блок
  memset(&a, 0, sizeof(s21_big_decimal));
  memset(&b, 0, sizeof(s21_big_decimal));
  memset(&res, 0, sizeof(s21_big_decimal));

  a.bits[0] = ~0U;
  b.bits[0] = 1;

  ck_assert_uint_eq(s21_big_mantiss_addition(a, b, &res), 0);
  ck_assert_uint_eq(s21_big_dec_to_uint128_test(res), 4294967296ULL);

  memset(&a, 0, sizeof(s21_big_decimal));
  memset(&b, 0, sizeof(s21_big_decimal));
  memset(&res, 0, sizeof(s21_big_decimal));

  a.bits[0] = ~0U;
  a.bits[1] = ~0U;
  b.bits[0] = 1;

  ck_assert_uint_eq(s21_big_mantiss_addition(a, b, &res), 0);
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 1);

  // Переполнение
  memset(&a, 0, sizeof(s21_big_decimal));
  memset(&b, 0, sizeof(s21_big_decimal));
  memset(&res, 0, sizeof(s21_big_decimal));

  a.bits[0] = ~0U;
  a.bits[1] = ~0U;
  a.bits[2] = ~0U;
  a.bits[3] = ~0U;
  a.bits[4] = ~0U;
  a.bits[5] = ~0U;
  a.bits[6] = ~0U;
  b.bits[0] = 1;

  ck_assert_uint_eq(s21_big_mantiss_addition(a, b, &res), 1);
  // При переполнении в данном случае мантисса обнуляется
  ck_assert_uint_eq(res.bits[0], 0);
  ck_assert_uint_eq(res.bits[1], 0);
  ck_assert_uint_eq(res.bits[2], 0);
  ck_assert_uint_eq(res.bits[3], 0);
  ck_assert_uint_eq(res.bits[4], 0);
  ck_assert_uint_eq(res.bits[5], 0);
  ck_assert_uint_eq(res.bits[6], 0);
}
END_TEST

Suite *suite_s21_mantiss_add() {
  Suite *suite = suite_create("suite_s21_mantiss_add");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, s21_mantiss_add_test);
  tcase_add_test(normal_cases, s21_big_mantiss_add_test);
  suite_add_tcase(suite, normal_cases);

  return suite;
}
