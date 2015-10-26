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

#define DO_PROBLEM_1 0
#define DO_PROBLEM_2 0
#define DO_PROBLEM_3 0
#define DO_PROBLEM_4 1

#define CHECK_OPEN_STREAM(x)        \
    {                               \
        if (x == NULL) {            \
            perror(x);              \
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

/*
 * fgets和gets的区别：fgets以换行符'\n'结尾，再末尾加上'\0'；而gets用'\0'替换'\n'
 * fputs和puts的区别：fgets以'\0'结尾，逐字写入；而puts用'\n'替换'\0'
 * */
#define MAX_LINE_LENGTH 10
int problem_2 (void) {
    FILE *input, *output;
    input = fopen("data","r");
    CHECK_OPEN_STREAM("data")
    output = fopen("buffer","w");
    CHECK_OPEN_STREAM("buffer")
    //  FILE数据结构中有IO_read_base,IO_read_ptr,IO_read_end,IO_write_base,IO_write_ptr,IO_write_end
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, input) != NULL)       // fgets读到文件末尾（即EOF字符）时，返回NULL；文件结尾不用加'\n'，系统会自动帮你加'\n'
        fputs(buffer, output);                                  // buffer采用覆盖而不是清空
    fclose(input);
    fclose(output);
    CHECK_CLOSE_STREAM(input)
    CHECK_CLOSE_STREAM(output)
    fflush(output);
    FFLUSH_OTHER
    return 0;
}

#define BUFFER_SIZE 100
int problem_3 (void) {
    FILE *input;
    input = fopen("data","r");
    CHECK_OPEN_STREAM("data")
    int a, b, c, d, e;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
        // 先读取一行
        if (sscanf(buffer, "%d %d %d %d %d", &a, &b, &c, &d, &e) != 4) {
            fprintf(stderr, "Bad input skipped: %s", buffer);
            continue;
        }
    }
    fclose(input);
    CHECK_CLOSE_STREAM(input)
    FFLUSH_OTHER
    return 0;
}

long problem_4 (void) {
    FILE *input;
    input = fopen("data","r");
    long offset = 4;                // 偏移量
    int from = SEEK_SET;            // 流的起始位置
    fseek(input, offset, from);     // 重定位一个流到距起始位置offset字节的地方
    long result = ftell(input);
    return result;
}

int test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
#if DO_PROBLEM_2
    problem_2();
#endif
#if DO_PROBLEM_3
    problem_3();
#endif
#if DO_PROBLEM_4
    problem_4();
#endif
    return 0;
}
