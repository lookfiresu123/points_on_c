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

#define DO_STACK_STATIC 0
#define DO_STACK_DYNAMIC 0
#define DO_STACK_LIST 1

#if DO_STACK_STATIC
#include "./stack_static/stack_static.h"
#endif

#if DO_STACK_DYNAMIC
#include "./stack_dynamic/stack_dynamic.h"
#endif

#if DO_STACK_LIST
#include "./stack_list/stack_list.h"
#endif

int main (void) {
#if DO_STACK_STATIC
    test_stack_static();
#endif
#if DO_STACK_DYNAMIC
    test_stack_dynamic();
#endif
#if DO_STACK_LIST
    test_stack_list();
#endif
    return 0;
}
