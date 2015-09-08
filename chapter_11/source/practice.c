/*
 * =====================================================================================
 *
 *       Filename:  practice.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月01日 21时40分04秒
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

#define DO_PRACTICE_1 0
#define DO_PRACTICE_2 0
#define DO_PRACTICE_3 1

#define calloc(x, y) malloc(x * sizeof(y))

int *practice_1 (void) {
    size_t size = 10;
    int *mem = calloc(size, int);
    return mem;
}

void practice_2 (void) {
    size_t size = 10;
    int *array = malloc(size * sizeof(*array));
    int count = 0;
    int temp;
    while (scanf("%d",&temp) != EOF) {
        array[++count] = temp;
        if (count == size - 1) {
            size *= 2;
            realloc(array, size);
        }
    }
    array[0] = count;
}

char *practice_3 (void) {
    char ctr;
    size_t size = 10;
    int count = 0;
    char *str = malloc(size * sizeof(*str));
    while ((ctr = getchar()) != '\n') {
        str[count++] = ctr;
        if (count == size) {
            size *= 2;
            realloc(str, size);
        }
    }
    str[count] = '\0';
    return str;
}

void test_practice (void) {
#if DO_PRACTICE_1
    practice_1();
#endif
#if DO_PRACTICE_2
    practice_2();
#endif
#if DO_PRACTICE_3
    practice_3();
#endif
}
