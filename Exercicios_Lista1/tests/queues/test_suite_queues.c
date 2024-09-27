#include "../minunit.h"
#include "test_queue_array.c"
#include "test_priorityQueue_array.c"


void test_suite_queues() {
    MU_RUN_SUITE(test_suite_queue_array);
    MU_RUN_SUITE(test_suite_priorityQueue_array);
}