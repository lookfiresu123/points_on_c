/*
 * =====================================================================================
 *
 *       Filename:  test2.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月25日 18时22分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "test1.h"

#ifndef _TEST2_H
#define _TEST2_H 1
typedef struct YEAR_TIME Year_Time;

struct YEAR_TIME {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    Day_Time day_time;
};
#endif
