/*
 * =====================================================================================
 *
 *       Filename:  practice.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月08日 13时57分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include "../header/practice.h"

#define DO_PRACTICE_1 1

static int (*compare[7]) (int) = {
    iscntrl, isspace, isdigit, islower, isupper, ispunct, isprint
};

void practice_1 (void) {
    // store the input stream
    char *str = NULL;
    size_t n = 0;
    size_t len_str;
    assert((len_str = getline(&str, &n, stdin)) != -1);

    // initialize Type_Cnt instance
    Type_Cnt count_info = {
        .count_cntrl = 0,
        .count_space = 0,
        .count_digit = 0,
        .count_lower = 0,
        .count_upper = 0,
        .count_punct = 0,
        .count_print = 0
    };

    int a[7] = { 0, 0, 0, 0, 0, 0, 0 };
    // calculate all kinds of characters
    int i = 0;
    for (i = 0 ; i < len_str ; i++) {
        int j = 0;
        while (compare[j](str[i]) == 0)
            j++;
        a[j]++;
    }
    count_info.count_cntrl = a[0];
    count_info.count_space = a[1];
    count_info.count_digit = a[2];
    count_info.count_lower = a[3];
    count_info.count_upper = a[4];
    count_info.count_punct = a[5];
    count_info.count_print = a[6];

    // calculate rates
    int sum = 0;
    for (i = 0 ; i < 7 ; i++)
        sum += a[i];
    Type_Rate rate_info;
    rate_info.rate_cntrl = (double) count_info.count_cntrl / sum;
    rate_info.rate_space = (double) count_info.count_space / sum;
    rate_info.rate_digit = (double) count_info.count_digit / sum;
    rate_info.rate_lower = (double) count_info.count_lower / sum;
    rate_info.rate_upper = (double) count_info.count_upper / sum;
    rate_info.rate_punct = (double) count_info.count_punct / sum;
    rate_info.rate_print = (double) count_info.count_print / sum;

    // print the information
    printf("cntrl = %lf, space = %lf, digit = %lf, lower = %lf, upper = %lf, punct = %lf, print = %lf\n",
            rate_info.rate_cntrl,
            rate_info.rate_space,
            rate_info.rate_digit,
            rate_info.rate_lower,
            rate_info.rate_upper,
            rate_info.rate_punct,
            rate_info.rate_print );
}

void test_practice (void) {
#if DO_PRACTICE_1
    practice_1();
#endif
}

