/*
 * =====================================================================================
 *
 *       Filename:  problem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月15日 20时05分04秒
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
#include "../header/test1.h"
#include "../header/test2.h"

#define DO_PROBLEM_1 0
#define DO_PROBLEM_2 1

#define FACTORIAL(rst, n)   \
        int i;              \
        for (i = 1 ; i <= n ; i++)  \
            rst *= i                \

#define PRINT(format, variable, value)	\
        printf(#variable" = "format, value);

int problem_1 (void) {
    int num = 9;
    int result = 0;
    FACTORIAL(result, num);
    PRINT("%d\n", result, result);
    return result;
}

int problem_2 (void) {
    Year_Time year_time = {
        .year = 2015,
        .month = 10,
        .day = 25,
        .day_time.hour = 18,
        .day_time.minute = 24,
        .day_time.seconds = 59
    };
    int a[10];
    int *p = NULL;
    return 0;
}

void test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
#if DO_PROBLEM_2
    problem_2();
#endif
}
