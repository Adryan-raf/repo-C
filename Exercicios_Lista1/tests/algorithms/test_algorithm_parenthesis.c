#include <stdbool.h>
#include <stdlib.h>
#include "../minunit.h"
#include "../../src/stacks/stack.h"
#include "../../src/algorithms/parenthesis.h"


void test_setup_algorithm_parenthesis(void) {
}

void test_teardown_algorithm_parenthesis(void) {
}


MU_TEST(test_algorithm_parenthesis_0){
    char * expression = "\0";
    bool expected = true;
    bool actual = Algorithm_Parenthesis_IsValid(expression);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_algorithm_parenthesis_1){
    char * expression = "(\0";
    bool expected = false;
    bool actual = Algorithm_Parenthesis_IsValid(expression);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_algorithm_parenthesis_2){
    char * expression = ")\0";
    bool expected = false;
    bool actual = Algorithm_Parenthesis_IsValid(expression);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_algorithm_parenthesis_3){
    char * expression = "()\0";
    bool expected = true;
    bool actual = Algorithm_Parenthesis_IsValid(expression);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_algorithm_parenthesis_4){
    char * expression = "([{}])\0";
    bool expected = true;
    bool actual = Algorithm_Parenthesis_IsValid(expression);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_algorithm_parenthesis_5){
    char * expression = "()[]{}\0";
    bool expected = true;
    bool actual = Algorithm_Parenthesis_IsValid(expression);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(test_algorithm_parenthesis_6){
    char * expression = "([]){\0";
    bool expected = false;
    bool actual = Algorithm_Parenthesis_IsValid(expression);
    mu_assert_int_eq(expected, actual);
}



MU_TEST_SUITE(test_suite_algorithm_parenthesis) {
	MU_SUITE_CONFIGURE(&test_setup_algorithm_parenthesis, &test_teardown_algorithm_parenthesis);
    MU_RUN_TEST(test_algorithm_parenthesis_0);
    MU_RUN_TEST(test_algorithm_parenthesis_1);
    MU_RUN_TEST(test_algorithm_parenthesis_2);
    MU_RUN_TEST(test_algorithm_parenthesis_3);
    MU_RUN_TEST(test_algorithm_parenthesis_4);
    MU_RUN_TEST(test_algorithm_parenthesis_5);
    MU_RUN_TEST(test_algorithm_parenthesis_6);
	
}
