/*
 * =====================================================================================
 *
 *       Filename:  test_8.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月02日 21时03分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <sys/resource.h>

int main (void) {
//    struct rlimit rl;
//    int result = getrlimit(RLIMIT_STACK, &rl);
#if 0
    int i = 0;
    int j = 0;
    int x = i++ + ++i;
    int y = ++j + ++j;
#endif
    return 0;
}

