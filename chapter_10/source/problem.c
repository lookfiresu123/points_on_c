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
#include <time.h>
#include "../header/types.h"

#define DO_PROBLEM_1 0
#define DO_PROBLEM_2 0
#define DO_PROBLEM_3 1

Ex3 problem_1 (void) {
    Ex y = {
        .a = 10,
        .b = { 'H', 'i', '\0' },
        .c.a = 5,
        .c.b = { -1, 25 },
        .d = 0x0
    };
    char s = 'b';
    Ex3 x = {
    	.b = -1,
    	.c = 1,
    	.d = -1,
    	.a = 'a'
    };
    return x;
}

void problem_2 (void) {
    int count = 10;
    int result[10];
    while(count-- > 0) {
    /* linux system use Linear congruential algorithm to generate random numbers
     * Linear congruential:
     * use the old random number to be the random seed of the new one.
     * for example:
     *  {
     *      for (i = 0 ; i < n ; i++) {
                random[i] = (p * seed + q) mod m;
                seed = random[i];
            }
     *  }
     * the same seed may generate different random numbers in different operating system (because p,q,m is different)
     */
        result[count] = rand();
    }
}

void problem_3 (void) {
    /* the value of enum should suit with integer , integer contains long, int, short, char and unsigned ... */
    enum X {A = -0xffffffff, B = 0xffffffffffffffff} x;
    //enum X {A = -0xffffffff, B = 0x10000000000000000} x;
    //enum X {A = -0.1, B = 0xffffffffffffffff} x;
    x = A;
}

void test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
#if DO_PROBLEM_2
    problem_2();
#endif
#if DO_PROBLEM_3
    problem_3();
#endif
}

