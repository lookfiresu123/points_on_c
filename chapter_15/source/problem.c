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

int problem_1 (void) {
    FILE *input;
    input = fopen("data","r");      // 再可执行文件main的当前目录中找data
    if (input == NULL) {
        perror("data");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
    return 0;
}
