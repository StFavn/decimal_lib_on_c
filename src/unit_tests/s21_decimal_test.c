#include "suites-core-generic/s21_decimal_core_generic_test.h"
#include "suites-core/s21_decimal_core_test.h"
#include "suites-utils/s21_decimal_utils_test.h"
#include "suites_runner.h"

test_results_t run_core_tests() {
  test_results_t core_res_tests = {0};

  Suite *suites_arithmetic[] = {suite_s21_add(), suite_s21_div(),
                                suite_s21_mul(), suite_s21_sub(), NULL};
  run_test_module("Arithmetic func's unit-tests:", suites_arithmetic,
                  &core_res_tests);

  Suite *suites_logic[] = {suite_s21_is_equal(),
                           suite_s21_is_not_equal(),
                           suite_s21_compare(),
                           suite_s21_is_greater(),
                           suite_s21_is_greater_or_equal(),
                           suite_s21_is_less(),
                           suite_s21_is_less_or_equal(),
                           NULL};
  run_test_module("Logic func's unit-tests:", suites_logic, &core_res_tests);

  Suite *suites_converters[] = {
      suite_s21_float_to_dec(), suite_s21_dec_to_float(),
      suite_s21_int_to_dec(), suite_s21_dec_to_int(), NULL};
  run_test_module("Converters func's unit-tests:", suites_converters,
                  &core_res_tests);

  Suite *suites_math[] = {suite_s21_negate(), suite_s21_truncate(),
                          suite_s21_floor(), suite_s21_round(), NULL};
  run_test_module("Math func's unit-tests:", suites_math, &core_res_tests);

  printf(DIVIDER_TEXT);

  return core_res_tests;
}

test_results_t run_core_generic_tests() {
  test_results_t core_generic_res_tests = {0};

  Suite *suites_arithmetic[] = {all_arithmetic_functions_cases(), NULL};
  run_test_module("Arithmetic func's generic unit-tests:", suites_arithmetic,
                  &core_generic_res_tests);

  printf(DIVIDER_TEXT);

  return core_generic_res_tests;
}

test_results_t run_utils_tests() {
  test_results_t utils_res_tests = {0};

  Suite *suites_bits[] = {suite_s21_bits(),
                          suite_s21_bits_decimal(),
                          suite_s21_bits_big_decimal(),
                          suite_s21_dec_scale_increase(),
                          suite_s21_big_dec_scale_increase(),
                          suite_s21_left_shift(),
                          suite_s21_right_shift(),
                          NULL};
  run_test_module("Bits utils unit-tests:", suites_bits, &utils_res_tests);

  Suite *suites_arithmetic[] = {suite_s21_mantiss_add(),
                                suite_s21_mantiss_sub(),
                                suite_s21_dec_normalize(),
                                suite_s21_big_dec_normalize(),
                                suite_s21_mantiss_div(),
                                suite_s21_big_mantiss_div(),
                                suite_s21_big_dec_mult10(),
                                suite_s21_big_dec_bank_round(),
                                suite_s21_truncate_trailing_zeros(),
                                suite_s21_big_dec_mantiss_mult(),
                                suite_s21_big_dec_mult(),
                                NULL};

  run_test_module("Arithmetic utils unit-tests:", suites_arithmetic,
                  &utils_res_tests);

  Suite *suites_convert[] = {suite_s21_bd_converters(), suite_s21_str_to_dec(),
                             suite_s21_print_decimal(),
                             suite_s21_convert_bd_to_dec(), NULL};
  run_test_module("Converters utils unit-tests:", suites_convert,
                  &utils_res_tests);

  Suite *suites_logic[] = {
      suite_s21_compare(),          suite_s21_big_dec_compare(),
      suite_s21_big_dec_is_equal(), suite_s21_dec_is_zero(),
      suite_s21_big_dec_is_zero(),  NULL};
  run_test_module("Logic utils unit-tests:", suites_logic, &utils_res_tests);

  printf(DIVIDER_TEXT);

  return utils_res_tests;
}

int main() {
  test_results_t total_res_tests = {0};

  printf(MARINE_TEXT "\t---Decimal Core tests---" RESET_TEXT);
  test_results_t core_res_tests = run_core_tests();

  print_tests_results(core_res_tests, "Core");

  total_res_tests.all += core_res_tests.all;
  total_res_tests.failed += core_res_tests.failed;

  printf("\n\n");

  printf(MARINE_TEXT "\t---Decimal GENERIC Core tests---" RESET_TEXT);
  test_results_t core_generic_res_tests = run_core_generic_tests();

  print_tests_results(core_generic_res_tests, "Core GENERIC");

  total_res_tests.all += core_generic_res_tests.all;
  total_res_tests.failed += core_generic_res_tests.failed;

  printf("\n\n");

  printf(MARINE_TEXT "\t---Decimal Utils tests---" RESET_TEXT);
  test_results_t utils_res_tests = run_utils_tests();

  print_tests_results(utils_res_tests, "Utils");

  total_res_tests.all += utils_res_tests.all;
  total_res_tests.failed += utils_res_tests.failed;

  printf(MARINE_TEXT
         "\n===================Total===================\n" RESET_TEXT);
  print_tests_results(total_res_tests, "All");

  return 0;
}
