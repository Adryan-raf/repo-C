#include "stacks/test_suite_stacks.c"
#include "queues/test_suite_queues.c"
#include "algorithms/test_suite_algorithms.c"

#include "minunit.h"

void test_suite() {
    MU_RUN_SUITE(test_suite_stacks);
    MU_RUN_SUITE(test_suite_queues);
	MU_RUN_SUITE(test_suite_algorithms);
	
}

int main() {
	test_suite();
	MU_REPORT();
	return MU_EXIT_CODE;
}