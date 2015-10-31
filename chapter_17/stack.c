/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/31/2015 05:18:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

bool is_empty (int top_element) {
    return top_element == -1 ? true : false;
}

bool is_full (int top_element) {
    return top_element == BUFFER_SIZE - 1 ? true : false;
}

void push (Stack *self, STACK_TYPE value) {
    if (! (self->_is_full)(self->top_element))
        self->buffer[++(self->top_element)] = value;
    else
        perror("stack is full");
}

STACK_TYPE pop (Stack *self) {
    if (! (self->_is_empty)(self->top_element))
        return self->buffer[(self->top_element)--];
    else {
        perror("stack is empty");
        return (STACK_TYPE)0;
    }
}

STACK_TYPE top (Stack *self) {
    if (! (self->_is_empty)(self->top_element))
        return self->buffer[self->top_element];
    else
        return (STACK_TYPE)0;
}

int test_stack (void) {
    Stack stack_example = {
        .top_element = -1,
        ._is_full = is_full,
        ._is_empty = is_empty,
        ._pop = pop,
        ._push = push,
        ._top = top
    };
    int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int i;
    for (i = 0 ; i < 10 ; i++)
        stack_example._push(&stack_example, array[i]);
    return 0;
}
