/*
 * =====================================================================================
 *
 *       Filename:  practice.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月19日 16时07分57秒
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
#include <assert.h>
#include <stddef.h>

#define DO_PRACTICE_1 0
#define DO_PRACTICE_2 0
#define DO_PRACTICE_3 0
#define DO_PRACTICE_4 0
#define DO_PRACTICE_5 0
#define DO_PRACTICE_6 0
#define DO_PRACTICE_7 0
#define DO_PRACTICE_8 0
#define DO_PRACTICE_9 0
#define DO_PRACTICE_10 0
#define DO_PRACTICE_11 1
#define DO_PRACTICE_12 0
#define DO_PRACTICE_13 0
#define DO_PRACTICE_14 0
#define DO_PRACTICE_15 0
#define DO_PRACTICE_16 0
#define DO_PRACTICE_17 0

typedef struct Count {
    unsigned int count_cntrl;
    unsigned int count_space;
    unsigned int count_digit;
    unsigned int count_lower;
    unsigned int count_upper;
    unsigned int count_punct;
    unsigned int count_unprint;
    unsigned int count_print;
    unsigned int count_sum;
} Array_Count;

typedef struct Rate {
    float rate_cntrl;
    float rate_space;
    float rate_digit;
    float rate_lower;
    float rate_upper;
    float rate_punct;
    float rate_unprint;
    float rate_print;
    float rate_sum;
} Array_Rate;

void practice_1 (void) {
    Array_Count count = {
        .count_cntrl = 0,
        .count_space = 0,
        .count_digit = 0,
        .count_lower = 0,
        .count_upper = 0,
        .count_punct = 0,
        .count_unprint = 0,
        .count_print = 0,
        .count_sum = 0
    };
    Array_Rate rate = {
        .rate_cntrl = 0,
        .rate_space = 0,
        .rate_digit = 0,
        .rate_lower = 0,
        .rate_upper = 0,
        .rate_punct = 0,
        .rate_unprint = 0,
        .rate_print = 0,
        .rate_sum = 0
    };
    char buffer[30];
    char *str = buffer;
    printf("print a string please !\n");
    gets(str);
    while(*str != '\0') {
        if (iscntrl(*str))
            count.count_cntrl++;
        if (isspace(*str))
            count.count_space++;
        if (isdigit(*str))
            count.count_digit++;
        if (islower(*str))
            count.count_lower++;
        if (isupper(*str))
            count.count_upper++;
        if (ispunct(*str))
            count.count_punct++;
        if (isprint(*str))
            count.count_print++;
        count.count_sum++;
        str++;
    }
    count.count_sum++;
    count.count_unprint = count.count_sum - count.count_print;

    rate.rate_sum = 1;
    rate.rate_cntrl = (float) count.count_cntrl / (float) count.count_sum;
    rate.rate_space = (float) count.count_space / (float) count.count_sum;
    rate.rate_digit = (float) count.count_digit / (float) count.count_sum;
    rate.rate_lower = (float) count.count_lower / (float) count.count_sum;
    rate.rate_upper = (float) count.count_upper / (float) count.count_sum;
    rate.rate_punct = (float) count.count_punct / (float) count.count_sum;
    rate.rate_print = (float) count.count_print / (float) count.count_sum;
    rate.rate_unprint = (float) count.count_unprint / (float) count.count_sum;

    assert(rate.rate_print + rate.rate_unprint == rate.rate_sum);
}

size_t my_strlen (char *str, unsigned int size) {
    size_t length;
    for (length = 0 ; length < (size_t) size ; length++)
        if (*(str + length) == '\0')
            break;
    return length;
}

void practice_2 (void) {
    unsigned int size = 10;
    char str1[10];
    char *str2 = "hello world";
    size_t length;
    strncpy(str1, str2, size);
    length = my_strlen(str1, size);
}

char *my_strcpy (char *dest, char *src, unsigned int size) {
    unsigned int length;
    if (length = strlen(src) < size)
        return memcpy(dest, src, length+1);
    else {
        memcpy(dest, src, size-1);
        dest[size-1] = '\0';
        return dest;
    }
}

void practice_3 (void) {
    char dest[10];
    char *src = "hello world";
    unsigned int size = 10;
    my_strcpy(dest, src, size);
}

char *my_strcat (char *dest, char *src, unsigned int size) {
    unsigned int length_dest = strlen(dest);
    unsigned int length_src = strlen(src);
    unsigned int length = length_dest + length_src + 1;
    if (length <= size) {
        memcpy(dest + length_dest, src, length_src + 1);
        return dest;
    }
    else {
        memcpy(dest + length_dest, src, size - length_dest - 1);
        dest[size-1] = '\0';
        return dest;
    }
}

void practice_4 (void) {
    char dest[10];
    char *str1 = "hello";
    strcpy(dest, str1);
    char *str2 = "world";
    unsigned int size = 10;
    my_strcat(dest, str2, size);
}

void my_strncat (char *dest, char *src, int dest_len) {
    assert(dest_len > 0);
    size_t length_dest = strlen(dest);
    size_t length_src = strlen(src);
    assert(length_dest + length_src <= (size_t) dest_len - 1);
    memcpy(dest + length_dest, src, length_src + 1);
}

void practice_5 (void) {
    char dest[10];
    char *str1 = "hello";
    strcpy(dest, str1);
    char *str2 = "hi";
    int dest_len = 10;
    my_strncat(dest, str2, dest_len);
}

char *my_strcpy_end (char *dest, char *src) {
    char *current = dest;
    memcpy(dest, src, strlen(src) + 1);
    current = dest + strlen(dest) + 1;
    return current;
}

void practice_6 (void) {
    char dest[10];
    char *src = "hello";
    char *current = dest;
    current = my_strcpy_end(dest, src);
}

char *my_strrchr (char const *str, int ch) {
    char *last = NULL;
    while (*str != '\0') {
        if (*str == (char) ch)
            last = str;
        str++;
    }
    return last;
}

void practice_7 (void) {
    char const *str = "hello world";
    char ch = 'l';
    char *result;
    result = my_strrchr(str, (int) ch);
}

char *my_strnchr (char const *str, int ch, int which) {
    char *result = NULL;
    int count;
    while (*str != '\0') {
        if (*str == (char) ch)
            count++;
        if (count == which) {
            result = str;
            break;
        }
        str++;
    }
    return result;
}

void practice_8 (void) {
    char const *str = "hello world";
    char ch = 'l';
    int which = 2;
    char *result;
    result = my_strnchr(str, (int) ch, which);
}

int count_chars (char const *str, char const *chars) {
    int count = 0;
    //char *gap;
    while (*str != '\0') {
        if (str = strpbrk(str, chars)) {
            //str = gap;
            count++;
            str++;
        }
        else
            break;
    }
    return count;
}

void practice_9 (void) {
    char const *str = "hello world";
    char const *chars = "else";
    int count;
    count = count_chars(str, chars);
}

int palindrome (char *string) {
    /* delete unalpha character */
    char *temp = (char *)malloc((strlen(string) + 1) * sizeof(char));
    char *current = temp;
    while (*string != '\0') {
        if (isalpha(*string))
            *current++ = *string;
        string++;
    }
    *current = '\0';
    current = temp;
    /* change lower to upper */
    while (*current != '\0') {
        if (islower(*current))
            *current = toupper(*current);
        current++;
    }
    current = temp;
    char *first = temp;
    char *last = temp + strlen(temp) - 1;
    while (first <= last) {
        if (*first != *last)
            return 0;
        else {
            first++;
            last--;
        }
    }
    return 1;
}

void practice_10 (void) {
    char *string = "ab98iA,A.7iBA";
    if(palindrome(string))
        printf("true\n");
    else
        printf("false\n");
}

int practice_11 (void) {
    char str1[100];
    printf("input a sentence !\n");
    gets(str1);
    char *str2 = "the";
    int count = 0;
    char *token = NULL;
    char *current = str1;
    while (token = strtok(current, " ")) {
        if (strcmp(token, str2) == 0)
            count++;
        current = current + strlen(token) + 1;
    }
    return count;
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
#if DO_PRACTICE_4
    practice_4();
#endif
#if DO_PRACTICE_5
    practice_5();
#endif
#if DO_PRACTICE_6
    practice_6();
#endif
#if DO_PRACTICE_7
    practice_7();
#endif
#if DO_PRACTICE_8
    practice_8();
#endif
#if DO_PRACTICE_9
    practice_9();
#endif
#if DO_PRACTICE_10
    practice_10();
#endif
#if DO_PRACTICE_11
    practice_11();
#endif
#if DO_PRACTICE_12
    practice_12();
#endif
#if DO_PRACTICE_13
    practice_13();
#endif
#if DO_PRACTICE_14
    practice_14();
#endif
#if DO_PRACTICE_15
    practice_15();
#endif
#if DO_PRACTICE_16
    practice_16();
#endif
#if DO_PRACTICE_17
    practice_17();
#endif
}
