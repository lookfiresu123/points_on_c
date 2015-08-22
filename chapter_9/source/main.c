/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月19日 16时03分42秒
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
#include "../header/problem.h"
#include "../header/practice.h"

#define DO_PROBLEM 0
#define DO_PRACTICE 1

int main (void) {
#if DO_PROBLEM
    test_problem();
#endif
#if DO_PRACTICE
    test_practice();
#endif
    return 0;
}


