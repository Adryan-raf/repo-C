#include <stdbool.h>
#include <stdlib.h>
#include "../minunit.h"
#include "../../src/stacks/stack.h"

static Stack * stack;

void test_setup_stack_array(void) {
    stack = Stack_Create();
}

void test_teardown_stack_array(void) {
    Stack_Destroy(stack);
}

MU_TEST(test_IsEmpty_IsTrue_WhenCreated_stack_array) {
	mu_check(Stack_IsEmpty(stack));
}

MU_TEST(test_IsEmpty_IsFalse_WhenOneValueWasPushed_stack_array) {
    Stack_Push(stack, 1);
	mu_check(!Stack_IsEmpty(stack));
}

MU_TEST(test_Pop_ReturnsFirstPushedValue_WhenOneValueWasPushed_stack_array){
	int first = rand();
	Stack_Push(stack, first);
	int actual = Stack_Pop(stack);
	int expected = first;
	mu_assert_int_eq(expected, actual);
}

MU_TEST(test_Pop_ReturnsSecondPushedValue_WhenTwoValuesWerePushed_stack_array){
	int first = rand();
	int second = rand();
	Stack_Push(stack, first);
	Stack_Push(stack, second);
	int actual = Stack_Pop(stack);
	int expected = second;
	mu_assert_int_eq(expected, actual);
}

MU_TEST(test_Pop_ReturnsFirstPushedValue_WhenTwoValuesWerePushedAndOneValueWasPopped_stack_array){
	int first = rand();
	int second = rand();
	Stack_Push(stack, first);
	Stack_Push(stack, second);
	Stack_Pop(stack);
	int actual = Stack_Pop(stack);
	int expected = first;
	mu_assert_int_eq(expected, actual);
}


MU_TEST_SUITE(test_suite_stack_array) {
	MU_SUITE_CONFIGURE(&test_setup_stack_array, &test_teardown_stack_array);
	MU_RUN_TEST(test_IsEmpty_IsTrue_WhenCreated_stack_array);
    MU_RUN_TEST(test_IsEmpty_IsFalse_WhenOneValueWasPushed_stack_array);
	MU_RUN_TEST(test_Pop_ReturnsFirstPushedValue_WhenOneValueWasPushed_stack_array);
	MU_RUN_TEST(test_Pop_ReturnsSecondPushedValue_WhenTwoValuesWerePushed_stack_array);
	MU_RUN_TEST(test_Pop_ReturnsFirstPushedValue_WhenTwoValuesWerePushedAndOneValueWasPopped_stack_array);
}