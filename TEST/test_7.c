/*
 * =====================================================================================
 *
 *       Filename:  test_7.c
 *
 *    Description:  test for some examples in chapter 8
 *
 *        Version:  1.0
 *        Created:  2015年08月18日 21时23分23秒
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
#include <string.h>

int compare_integers (void const *a, void const *b) {
	register int const *pa = a;
	register int const *pb = b;
	return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
}

int main(void) {
    // char *str1 = "hello world";
    // char *str2 = "hello word";
    // int a = strcmp(str1, str2);

    int const a = 1;
    int const b = 2;
    int result = compare_integers(&a, &b);		// int const * extension to void const *, and then void const * extension to register int const *
    return result;
}

