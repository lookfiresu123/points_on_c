/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月11日 20时16分09秒
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

#define DO_PROBLEM 1
#define DO_PRACTICE 0

#if DO_PROBLEM
#include "../header/problem.h"
#endif

#if DO_PRACTICE
#include "../header/practice.h"
#endif

int main (void) {
#if DO_PROBLEM
    test_problem();
#endif
#if DO_PRACTICE
    test_practice();
#endif
   return 0;
}
