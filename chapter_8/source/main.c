/*
 * created by lookfiresu123 @ 2015/8/4
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"../header/practice.h"
#include"../header/problem.h"

#define DO_TEST_PROBLEM 0
#define DO_TEST_PRACTICE 1

int main(void) {
#if DO_TEST_PROBLEM
    test_problem();
#endif
#if DO_TEST_PRACTICE
    test_practice();
#endif
    return 0;
}

