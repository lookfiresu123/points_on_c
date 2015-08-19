/*
 * =====================================================================================
 *
 *       Filename:  problem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月19日 15时36分12秒
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

#define DO_IMPLEMENT_STRSTR 0
#define DO_IMPLEMENT_STRRSTR 0
#define DO_IMPLEMENT_STRRPBRK 1

char *implement_strstr (const char *s1, const char *s2) {
    char *pointer_s1 = s1;
    char *pointer_s2;
    if (!s2)
        return pointer_s1;
    int length_s1 = strlen(s1);
    int length_s2 = strlen(s2);
    if (length_s1 < length_s2)
        return NULL;
    char start_s2 = *s2;
    char *store_s1 = pointer_s1;
    /*
     * find the occurrence of start_s2 in string s1
     */
    while (*pointer_s1 != '\0') {
        pointer_s2 = s2;
        pointer_s1 = strchr(store_s1+1, start_s2);
        if (pointer_s1) {
            store_s1 = pointer_s1;
            while (*pointer_s1++ == *pointer_s2++ && *pointer_s2 != '\0' && *pointer_s1 != '\0')
                ;
            if (*pointer_s2 == '\0')
                return store_s1;
            else if (*pointer_s1 == '\0')
                return NULL;
        }
    }
}

char *implement_strrstr (const char *s1, const char *s2) {
    char *current;
    char *last;
    current = strstr(s1, s2);
    while (current) {
        last = current;
        current = strstr(last+1, s2);
    }
    return last;
}

char *implement_strrpbrk (const char *s1, const char *s2) {
    char *current;
    char *last;
    current = strpbrk(s1, s2);
    while (current) {
        last = current;
        current = strpbrk(last+1, s2);
    }
    return last;
}

void test_problem (void) {
    const char *s1 = "hello world";
    const char *s2 = "how";
#if DO_IMPLEMENT_STRSTR
    char *p = implement_strstr(s1, s2);
#endif
#if DO_IMPLEMENT_STRRSTR
    char *p = implement_strrstr(s1, s2);
#endif
#if DO_IMPLEMENT_STRRPBRK
    char *p = implement_strrpbrk(s1, s2);
#endif
}

