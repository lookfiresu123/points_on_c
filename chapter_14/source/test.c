/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月25日 18时21分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "test1.h"
#include "test2.h"

int main (void) {
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
