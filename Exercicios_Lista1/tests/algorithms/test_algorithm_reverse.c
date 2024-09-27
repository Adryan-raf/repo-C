#include <stdbool.h>
#include <stdlib.h>
#include "../minunit.h"
#include "../../src/queues/queue.h"
#include "../../src/stacks/stack.h"
#include "../../src/algorithms/reverse.h"

static Queue * queue;
static Stack * stack;



void test_setup_algorithm_reverse(void) {
    queue = Queue_Create();
    stack = Stack_Create();
}

void test_teardown_algorithm_reverse(void) {
    Queue_Destroy(queue);
    Stack_Destroy(stack);
}

MU_TEST(test_algorithm_reverse){
    int size = 10;
    for(int i = 0 ; i < size; i++){
        Queue_Enqueue(queue, i);
    }
    Algorithm_Reverse_Queue_Using_Stack(queue, stack);
    for(int i = 0; i < size;i++){
        int expected = size - i - 1;
        int actual = Queue_Dequeue(queue);
        mu_assert_int_eq(expected, actual);
    }
}


MU_TEST_SUITE(test_suite_algorithm_reverse) {
	MU_SUITE_CONFIGURE(&test_setup_algorithm_reverse, &test_teardown_algorithm_reverse);
	MU_RUN_TEST(test_algorithm_reverse);
	
}
