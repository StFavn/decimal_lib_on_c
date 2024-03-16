#include "suites_runner.h"

bool have_failed_tests(test_results_t res_tests) {
  return (res_tests.failed != 0);
}

void print_tests_results(test_results_t res_tests, char *title) {
  printf(BOLD_TEXT "%s tests total: %d\n" BOLD_OFF_TEXT, title, res_tests.all);

  char result_msg[BUFF_SIZE];
  sprintf(result_msg,
          BOLD_TEXT GREEN_TEXT "ALL TESTS PASSED" BOLD_OFF_TEXT RESET_TEXT);

  if (have_failed_tests(res_tests)) {
    sprintf(result_msg, RED_TEXT "FAILED TESTS: %d" RESET_TEXT,
            res_tests.failed);
  }

  printf("%s\n", result_msg);
}

void run_suite(Suite *suite, test_results_t *res_tests) {
  SRunner *sr = srunner_create(suite);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  res_tests->all += srunner_ntests_run(sr);
  res_tests->failed += srunner_ntests_failed(sr);

  srunner_free(sr);
}

void run_suites_collection(Suite *suites[], test_results_t *res_tests) {
  for (Suite **cur = suites; *cur != NULL; cur++) {
    run_suite(*cur, res_tests);
  }
}

void run_test_module(const char *label, Suite *suites[],
                     test_results_t *res_tests) {
  printf(DIVIDER_TEXT);
  printf(BLUE_TEXT "%s\n\n" RESET_TEXT, label);

  run_suites_collection(suites, res_tests);
}
