/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月25日 21时09分02秒
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
#include <setjmp.h>
#include "../header/problem.h"
#include "../header/practice.h"

#define DO_PROBLEM 1
#define DO_PRACTICE 0

int main (void) {
    jmp_buf restart_main;
    setjmp(restart_main);           // save the current state of registers into restart_main
#if DO_PROBLEM
    test_problem();
#endif
#if DO_PRACTICE
    test_practice();
#endif
    return 0;
}
