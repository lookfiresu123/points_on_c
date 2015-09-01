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
#define DO_PROBLEM_3 0
#define DO_PROBLEM_4 0
#define DO_PROBLEM_5 1

struct {
    int a:2;
} x;

union {
    int a;
    float b;
    char c;
} y;

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
    /* the value stored in the memory will be expanded to 4 bytes or 8 bytes, it depends to the value you input */
    enum X {A = (short)0x1, B = (long int)0xffffffffffffffff} x;
    //enum X {A = -0xffffffff, B = 0xffffffffffffffff} x;
    //enum X {A = -0xffffffff, B = 0x10000000000000000} x;
    //enum X {A = -0.1, B = 0xffffffffffffffff} x;
    x = A;
}

void problem_4 (void) {
    /* binary:
     * x = 0 --> x = 01 --> x = 10 (-2 for decimal)
     */
    x.a = 1;
    x.a += 1;
    printf("%d\n",x.a);
}

void problem_5 (void) {
    y.a = 25;       // occupy 4 bytes, change: 0x00 0x00 0x00 0x00 --> 0x19 0x00 0x00 0x00
    y.b = 3.14;     // occupy 4 bytes, change: 0x19 0x00 0x00 0x00 --> 0xc3 0xf5 0x48 0x40
    y.c = 'x';      // occupy 1 byte,  change: 0xc3 0xf5 0x48 0x40 --> 0x78 0xf5 0x48 0x40
    printf("%d, %g, %c\n", y.a, y.b, y.c);      // output: y.a != (25||3.14||'x') , y.b != (25||3.14||'x') , y.c = 'x'
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
#if DO_PROBLEM_4
    problem_4();
#endif
#if DO_PROBLEM_5
    problem_5();
#endif
}

