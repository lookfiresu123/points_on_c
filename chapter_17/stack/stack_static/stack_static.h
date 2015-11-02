/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/31/2015 05:18:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */
#ifndef _STACK_STATIC_H
#define _STACK_STATIC_H 1
#include <stdbool.h>

#define STACK_TYPE int
#define BUFFER_SIZE 100

typedef struct STACK Stack;

void push (Stack *self, STACK_TYPE value);
STACK_TYPE pop (Stack *self);
STACK_TYPE top(Stack *self);
bool is_empty (int top_element);
bool is_full (int top_element);

struct STACK {
    STACK_TYPE buffer[BUFFER_SIZE];
    int top_element;        // empty: top_element = -1, full: top_element = BUFFER_SIZE-1
    void (*_push) (Stack *_self, STACK_TYPE _value);
    STACK_TYPE (*_pop) (Stack *_self);
    STACK_TYPE (* _top) (Stack *_self);
    bool (*_is_empty) (int _top_element);
    bool (*_is_full) (int _top_element);
};

int test_stack_static (void);
#endif
