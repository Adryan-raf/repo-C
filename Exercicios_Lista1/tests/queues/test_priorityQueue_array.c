#include <stdbool.h>
#include <stdlib.h>
#include "../minunit.h"
#include "../../src/queues/priorityQueue.h"

static PriorityQueue * prioriryQueue;

#define SIZE_5 5

void testCase(PriorityQueue * prioriryQueue, int * values, int * expected, int size);

void test_setup_priorityQueue_array(void) {
    prioriryQueue = PriorityQueue_Create();
}

void test_teardown_priorityQueue_array(void) {
    PriorityQueue_Destroy(prioriryQueue);
}


MU_TEST(test_priorityQueue_01){
	int size = SIZE_5;
	int values[SIZE_5] = {1, 2, 3, 4, 5};
	int expected[SIZE_5] = {1, 2, 3, 4, 5};
	testCase(prioriryQueue, values, expected, size);
}

MU_TEST(test_priorityQueue_02){
	int size = SIZE_5;
	int values[SIZE_5] = {5,4, 3, 2, 1};
	int expected[SIZE_5] = {1, 2, 3, 4, 5};
	testCase(prioriryQueue, values, expected, size);
}

void testCase(PriorityQueue * prioriryQueue, int * values, int * expected, int size){
	for(int i = 0; i < size; i++){
		PriorityQueue_Enqueue(prioriryQueue, *(values + i));
	}
	int * actual = (int *) malloc(sizeof(int) * size);
	for(int i = 0; i < size; i++){
		*(actual + i) = PriorityQueue_Dequeue(prioriryQueue);
	}
	for(int i = 0; i < size; i++){
		mu_assert_int_eq(*(expected + i), *(actual + i));
	}
	free(actual);
}

MU_TEST_SUITE(test_suite_priorityQueue_array) {
	MU_SUITE_CONFIGURE(&test_setup_priorityQueue_array, &test_teardown_priorityQueue_array);
	MU_RUN_TEST(test_priorityQueue_01);
	MU_RUN_TEST(test_priorityQueue_02);
	
}

