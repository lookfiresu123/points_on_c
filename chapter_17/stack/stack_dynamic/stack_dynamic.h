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
#ifndef _STACK_DYNAMIC_H
#define _STACK_DYNAMIC_H 1
#include <stdbool.h>

#define STACK_TYPE int

typedef struct STACK Stack;

void push (Stack *self, STACK_TYPE value);
STACK_TYPE pop (Stack *self);
STACK_TYPE top(Stack *self);
bool is_empty (int top_element);
bool is_full (Stack *self, int top_element);
void create_stack (Stack *self, int _buffer_size);
void destroy_stack (Stack *self);

struct STACK {
    STACK_TYPE *buffer;
    int buffer_size;
    int top_element;        // empty: top_element = -1, full: top_element = BUFFER_SIZE-1
    void (*_push) (Stack *_self, STACK_TYPE _value);
    STACK_TYPE (*_pop) (Stack *_self);
    STACK_TYPE (* _top) (Stack *_self);
    bool (*_is_empty) (int _top_element);
    bool (*_is_full) (Stack *_self, int _top_element);
    void (*_create_stack) (Stack *_self, int _buffer_size);
    void (*_destroy_stack) (Stack *_self);
};

int test_stack_dynamic (void);
#endif
