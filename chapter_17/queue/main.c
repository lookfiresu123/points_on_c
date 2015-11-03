/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/31/2015 05:19:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#define DO_QUEUE_STATIC 1
#define DO_QUEUE_DYNAMIC 0
#define DO_QUEUE_LIST 0

#if DO_QUEUE_STATIC
#include "./queue_static/queue_static.h"
#endif

int main (void) {
#if DO_QUEUE_STATIC
    test_queue_static();
#endif
    return 0;
}
