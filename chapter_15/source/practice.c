/*
 * =====================================================================================
 *
 *       Filename:  practice.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月25日 21时09分02秒
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

#define DO_PRACTICE_1 0
#define DO_PRACTICE_2 0
#define DO_PRACTICE_4 1

#define CHECK_OPEN_STREAM(x)        \
    {                               \
        if (x == NULL) {            \
            perror("fopen");        \
            exit(EXIT_FAILURE);     \
        }                           \
    }

#define CHECK_CLOSE_STREAM(x)       \
    {                               \
        if (x == 0) {               \
            perror("fclose");       \
            exit(EXIT_FAILURE);     \
        }                           \
    }

#define FFLUSH_OTHER                \
    {                               \
        fflush(stdout);             \
        fflush(stderr);             \
    }


int practice_1 (void) {
    int readchar;
    while ((readchar = fgetc(stdin)) != EOF) {
        fputc(readchar, stdout);
        fflush(stdout);
    }
    return 0;
}

#define BUF_SIZE 82
int practice_2 (void) {
    char buffer[BUF_SIZE];
    while (fgets(buffer, BUF_SIZE, stdin) != NULL) {
        fputs(buffer, stdout);
        fflush(stdout);
    }
    return 0;
}

// use fgets,fputs instead of gets,puts to do the practice_3

#ifdef BUF_SIZE
#undef BUF_SIZE
#endif
#define BUF_SIZE 100

int practice_4 (void) {
    char input_filename[FILENAME_MAX];
    char output_filename[FILENAME_MAX];
    char buffer[BUF_SIZE];
    printf("input two filename\n");
    if (fgets(input_filename, FILENAME_MAX, stdin) == NULL)
        ferror(stdin);
    if (fgets(output_filename, FILENAME_MAX, stdin) == NULL)
        ferror(stdin);

    FILE *input, *output;
    input = fopen("data", "r");
    CHECK_OPEN_STREAM(input)
    output = fopen("buffer", "w");
    CHECK_OPEN_STREAM(output)

    while (fgets(buffer, BUF_SIZE, input) != NULL) {
        fputs(buffer, output);
        fflush(output);
    }

    fclose(input);
    CHECK_CLOSE_STREAM(input)
    fclose(output);
    CHECK_CLOSE_STREAM(output)
    return 0;
}

int test_practice (void) {
#if DO_PRACTICE_1
    practice_1();
#endif
#if DO_PRACTICE_2
    practice_2();
#endif
#if DO_PRACTICE_4
    practice_4();
#endif
    return 0;
}

