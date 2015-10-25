/*
 * =====================================================================================
 *
 *       Filename:  problem.c
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

#define DO_PROBLEM_1 1

#define CHECK_OPEN_STREAM(x)        \
    {                               \
        if (x == NULL) {            \
            perror(x);              \
            exit(EXIT_FAILURE);     \
        }                           \
    }

#define CHECK_CLOSE_STREAM(x)        \
    {                               \
        if (x == 0) {            \
            perror("fclose");              \
            exit(EXIT_FAILURE);     \
        }                           \
    }

int problem_1 (void) {
    FILE *input;
    input = fopen("data","r");      // 再可执行文件main的当前目录中找data
    CHECK_OPEN_STREAM("data")
    // 重新打开流input
    input = freopen("data","w",input);
    CHECK_OPEN_STREAM("data")
    int result = fclose(input);
    CHECK_CLOSE_STREAM(input)
    return 0;
}

int test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
    return 0;
}
