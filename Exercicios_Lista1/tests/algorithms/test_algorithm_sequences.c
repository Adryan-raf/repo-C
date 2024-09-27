#include <stdbool.h>
#include <stdlib.h>
#include "../minunit.h"
#include "../../src/algorithms/sequences.h"


void test_setup_algorithm_sequences(void) {
}

void test_teardown_algorithm_sequences(void) {
}


MU_TEST(test_algorithm_sequences_1){
    int size = 5;
    int pushed[5] = {1, 2, 3, 4, 5};
    int popped[5] = {5, 4, 3, 2, 1};
    bool expected = true;
    bool actual = Algorithm_Sequences_IsValid(pushed, popped, size);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_algorithm_sequences_2){
    int size = 5;
    int pushed[5] = {1, 2, 3, 4, 5};
    int popped[5] = {1, 2, 3, 4, 5};
    bool expected = true;
    bool actual = Algorithm_Sequences_IsValid(pushed, popped, size);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_algorithm_sequences_3){
    int size = 5;
    int pushed[5] = {1, 2, 3, 4, 5};
    int popped[5] = {4, 5, 3, 2, 1};
    bool expected = true;
    bool actual = Algorithm_Sequences_IsValid(pushed, popped, size);
    mu_assert_int_eq(expected, actual);
}


MU_TEST(test_algorithm_sequences_4){
    int size = 5;
    int pushed[5] = {1, 2, 3, 4, 5};
    int popped[5] = {4, 3, 5, 1, 2};
    bool expected = false;
    bool actual = Algorithm_Sequences_IsValid(pushed, popped, size);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_algorithm_sequences_5){
    int size = 5;
    int pushed[5] = {1, 2, 3, 4, 5};
    int popped[5] = {1, 2, 4, 3, 5};
    bool expected = true;
    bool actual = Algorithm_Sequences_IsValid(pushed, popped, size);
    mu_assert_int_eq(expected, actual);
}




MU_TEST_SUITE(test_suite_algorithm_sequences) {
	MU_SUITE_CONFIGURE(&test_setup_algorithm_sequences, &test_teardown_algorithm_sequences);
    MU_RUN_TEST(test_algorithm_sequences_1);
    MU_RUN_TEST(test_algorithm_sequences_2);
    MU_RUN_TEST(test_algorithm_sequences_3);
    MU_RUN_TEST(test_algorithm_sequences_4);
    MU_RUN_TEST(test_algorithm_sequences_5);
   
	
}
