/*
 * =====================================================================================
 *
 *       Filename:  problem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月23日 21时24分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "../header/types.h"

#define DO_PROBLEM_1 1

Ex problem_1 (void) {
    Ex x = {
        .a = 10,
        .b = { 'H', 'i', '\0' },
        .c.a = 5,
        .c.b = { -1, 25 },
        .d = 0x0
    };
    return x;
}

void test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
}

