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
#include <assert.h>
#include "stack_dynamic.h"

bool is_empty (int top_element) {
    return top_element == -1 ? true : false;
}

bool is_full (Stack *self, int top_element) {
    return top_element == self->buffer_size - 1 ? true : false;
}

void push (Stack *self, STACK_TYPE value) {
    if (! (self->_is_full)(self, self->top_element))
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

void create_stack (Stack *self, int _buffer_size) {
    if (_buffer_size == 0)
        perror("buffer_size can not be zero");
    else {
        self->buffer_size = _buffer_size;
        self->buffer = (STACK_TYPE*)malloc(_buffer_size * sizeof(Stack));
        assert(self->buffer != NULL);
    }
}

void destroy_stack (Stack *self) {
    if (self->top_element != -1)
        perror("stack is not empty");
    else {
        self->buffer_size = 0;
        free(self->buffer);
        self->buffer = NULL;
    }
}

int test_stack_dynamic (void) {
    Stack stack_example = {
        .buffer_size = 20,
        .top_element = -1,
        ._is_full = is_full,
        ._is_empty = is_empty,
        ._pop = pop,
        ._push = push,
        ._top = top,
        ._create_stack = create_stack,
        ._destroy_stack = destroy_stack
    };
    stack_example._create_stack(&stack_example, stack_example.buffer_size);
    int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int i;
    for (i = 0 ; i < 10 ; i++)
        stack_example._push(&stack_example, array[i]);
    for (i = 0 ; i < 10 ; i++)
        stack_example._pop(&stack_example);
    stack_example._destroy_stack(&stack_example);
    return 0;
}
