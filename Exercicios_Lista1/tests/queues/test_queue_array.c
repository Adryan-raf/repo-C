#include <stdbool.h>
#include <stdlib.h>
#include "../minunit.h"
#include "../../src/queues/queue.h"

static Queue * queue;

void test_setup_queue_array(void) {
    queue = Queue_Create();
}

void test_teardown_queue_array(void) {
    Queue_Destroy(queue);
}

MU_TEST(test_IsEmpty_IsTrue_WhenCreated_queue_array) {
	mu_check(Queue_IsEmpty(queue));
}

MU_TEST(test_IsEmpty_IsFalse_WhenOneValueWasEnqueued_queue_array) {
    Queue_Enqueue(queue, 1);
	mu_check(!Queue_IsEmpty(queue));
}

MU_TEST(test_Dequeue_ReturnsFirstEnqueuedValue_WhenOneValueWasEnqueued_queue_array){
	int first = rand();
	Queue_Enqueue(queue, first);
	int actual = Queue_Dequeue(queue);
	int expected = first;
	mu_assert_int_eq(expected, actual);
}

MU_TEST(test_Dequeue_ReturnsFirstEnqueuedValue_WhenTwoValuesWereEnqueued_queue_array){
	int first = rand();
	int second = rand();
	Queue_Enqueue(queue, first);
	Queue_Enqueue(queue, second);
	int actual = Queue_Dequeue(queue);
	int expected = first;
	mu_assert_int_eq(expected, actual);
}

MU_TEST(test_Dequeue_RerturnsFirstEnqueuedValue_WhenTwoValuesWereEnqueuedAndOneValueWasDenqueued_queue_array){
	int first = rand();
	int second = rand();
	Queue_Enqueue(queue, first);
	Queue_Enqueue(queue, second);
	Queue_Dequeue(queue);
	int actual = Queue_Dequeue(queue);
	int expected = second;
	mu_assert_int_eq(expected, actual);
	
}

MU_TEST(test_Dequeue_ReturnsSecondEnqueuedValued_AfterTwoEnqueuesAndOneDequeue_queue_array){
	int first = rand();
	int second = rand();
	int third = rand();
	Queue_Enqueue(queue, first);
	Queue_Enqueue(queue, second);
	Queue_Dequeue(queue);
	Queue_Enqueue(queue, third);
	int actual = Queue_Dequeue(queue);
	int expected = second;
	mu_assert_int_eq(expected, actual);
}

MU_TEST_SUITE(test_suite_queue_array) {
	MU_SUITE_CONFIGURE(&test_setup_queue_array, &test_teardown_queue_array);
	MU_RUN_TEST(test_IsEmpty_IsTrue_WhenCreated_queue_array);
	MU_RUN_TEST(test_IsEmpty_IsFalse_WhenOneValueWasEnqueued_queue_array);
	MU_RUN_TEST(test_Dequeue_ReturnsFirstEnqueuedValue_WhenOneValueWasEnqueued_queue_array);
	MU_RUN_TEST(test_Dequeue_ReturnsFirstEnqueuedValue_WhenTwoValuesWereEnqueued_queue_array);
	MU_RUN_TEST(test_Dequeue_RerturnsFirstEnqueuedValue_WhenTwoValuesWereEnqueuedAndOneValueWasDenqueued_queue_array);
	MU_RUN_TEST(test_Dequeue_ReturnsSecondEnqueuedValued_AfterTwoEnqueuesAndOneDequeue_queue_array);
	
}

