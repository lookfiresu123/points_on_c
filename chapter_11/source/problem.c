/*
 * =====================================================================================
 *
 *       Filename:  problem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月01日 21时40分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <assert.h>
#include "../header/problem.h"

#define DO_PROBLEM_1 0
#define DO_PROBLEM_2 1

void problem_1 (void) {
    int *new_memory = MALLOC(25, int);
    assert(new_memory);
}

/* cancel the last define of malloc */
#undef malloc

void *alloc (size_t size) {
    void *new_memory = malloc(size);
    assert(new_memory);
    return new_memory;
}

void problem_2 (void) {
    size_t size = 25;
    int *new_memory = alloc(size);
}

void test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
#if DO_PROBLEM_2
    problem_2();
#endif
}

