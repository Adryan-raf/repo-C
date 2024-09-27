#include "test_algorithm_reverse.c"
#include "test_algorithm_parenthesis.c"
#include "test_algorithm_sequences.c"
#include "../minunit.h"

void test_suite_algorithms() {
    MU_RUN_SUITE(test_suite_algorithm_reverse);
    MU_RUN_SUITE(test_suite_algorithm_parenthesis);
    MU_RUN_SUITE(test_suite_algorithm_sequences);
}

