#ifndef SRC_UNIT_TESTS_SUITES_RUNNER_H_
#define SRC_UNIT_TESTS_SUITES_RUNNER_H_

#include <check.h>
#include <stdbool.h>
#include <stdio.h>

#define BUFF_SIZE 512

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define BLUE_TEXT "\033[1;34m"
#define MARINE_TEXT "\033[1;36m"
#define RESET_TEXT "\033[0m"

#define BOLD_TEXT "\e[1m"
#define BOLD_OFF_TEXT "\e[m"

#define DIVIDER_TEXT "\n===========================================\n"

typedef struct test_results_t {
  int failed;
  int all;
} test_results_t;

bool have_failed_tests(test_results_t res_tests);
void print_tests_results(test_results_t res_tests, char *title);

void run_suite(Suite *suite, test_results_t *res_tests);
void run_suites_collection(Suite *suites[], test_results_t *res_tests);
void run_test_module(const char *label, Suite *suites[],
                     test_results_t *res_tests);

#endif  // !SRC_UNIT_TEST_SUITES_RUNNER_H_