/*
 * =====================================================================================
 *
 *       Filename:  practice.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月08日 13时58分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

typedef struct Count_Character {
    int count_cntrl;
    int count_space;
    int count_digit;
    int count_lower;
    int count_upper;
    int count_punct;
    int count_print;
} Type_Cnt;

typedef struct Rate_Character {
    double rate_cntrl;
    double rate_space;
    double rate_digit;
    double rate_lower;
    double rate_upper;
    double rate_punct;
    double rate_print;
} Type_Rate;

void practice_1 (void);
void test_practice (void);
