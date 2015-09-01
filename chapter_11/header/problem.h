/*
 * =====================================================================================
 *
 *       Filename:  problem.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月01日 21时40分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#define malloc          never call malloc directly
#define MALLOC(num, type)       (type *)alloc((num) * sizeof(type))

void problem_1 (void);

void *alloc (size_t size);

void problem_2 (void);

void test_problem (void);
