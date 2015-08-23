/*
 * =====================================================================================
 *
 *       Filename:  types.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月23日 21时30分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

typedef struct {
    int a;
    short b[2];
} Ex2;

typedef struct Ex {
    int a;
    char b[3];
    Ex2 c;
    struct Ex *d;
} Ex;
