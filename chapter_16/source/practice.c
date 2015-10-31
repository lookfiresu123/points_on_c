/*
 * =====================================================================================
 *
 *       Filename:  practice.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/28/2015 04:50:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123
 *        Company:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DO_PRACTICE_1 0
#define DO_PRACTICE_2 0
#define DO_PRACTICE_3 1

int practice_1 (void) {
    int old;
    int x;
    printf("input a number\n");
    scanf("%d",&old);
    /* store old into array */
    int array[10];
    int temp = old;
    int i = 0;
    int sum = 0;
    while (array[i++] = temp % 10, temp /= 10, temp != 0)
        ;
    int count = i;
    if (old == 29)
        return 10;
    else if (old > 29) {
        for (x = 11 ; x <= 36 ; x++) {
            for (i = count-1 ; i >=0 ; i--)
                sum = sum * x + array[i];
            if (sum <= 29)
                break;
        }
    }
    else
        x = 9;
    printf("%d\n",x);
    return x;
}

int practice_2 (void) {
    // regard 0~5 to 1~6
    srand((unsigned int)time(NULL));
    int i;
    for (i = 0 ; i < 12 ; i++)
        printf("%d ", rand()%6 + 1);
    return 0;
}

int practice_3 (void) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int x, y, temp;
    x = (temp = local->tm_hour % 12) == 0 ? 12 : temp;
    y = local->tm_min;
    printf("时针在%d上面，分针在%d上面\n", x, y);
    return 0;
}

int test_practice (void) {
#if DO_PRACTICE_1
    practice_1();
#endif
#if DO_PRACTICE_2
    practice_2();
#endif
#if DO_PRACTICE_3
    practice_3();
#endif
    return 0;
}
