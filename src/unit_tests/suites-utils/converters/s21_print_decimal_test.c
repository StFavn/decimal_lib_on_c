#include "suites-utils/s21_decimal_utils_test.h"

START_TEST(s21_print_uint32_test) {
  const uint32_t even_number = 120;
  // Перенаправить stdout в файл
  freopen("./s21_print_uint32_test.txt", "w", stdout);
  s21_print_uint32(even_number);
  freopen("/dev/tty", "w", stdout);
  remove("./s21_print_uint32_test.txt");
}
END_TEST

START_TEST(s21_print_decimal_test) {
  s21_decimal dec = {0};
  // Перенаправить stdout в файл
  freopen("./s21_print_decimal_test.txt", "w", stdout);
  s21_print_decimal(&dec);
  freopen("/dev/tty", "w", stdout);
  remove("./s21_print_decimal_test.txt");
}
END_TEST

START_TEST(s21_print_big_decimal_test) {
  s21_big_decimal dec = {0};
  // Перенаправить stdout в файл
  char *o_fname = "./s21_print_big_decimal_test.txt";
  freopen(o_fname, "w", stdout);
  s21_print_big_decimal(&dec);
  freopen("/dev/tty", "w", stdout);
  remove(o_fname);
}
END_TEST

Suite *suite_s21_print_decimal() {
  Suite *suite = suite_create("suite_s21_print_decimal");

  TCase *normal_cases = tcase_create("normal_cases");
  tcase_add_test(normal_cases, s21_print_uint32_test);
  tcase_add_test(normal_cases, s21_print_decimal_test);
  tcase_add_test(normal_cases, s21_print_big_decimal_test);
  suite_add_tcase(suite, normal_cases);

  return suite;
}
