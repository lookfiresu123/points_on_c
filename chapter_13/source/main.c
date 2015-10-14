/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月08日 13时57分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#define DO_PRACTICE 1
#define DO_PROBLEM 0

#if DO_PRACTICE
#include "../header/practice.h"
#endif

#if DO_PROBLEM
#include "../header/node.h"
#include "../header/problem.h"
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
