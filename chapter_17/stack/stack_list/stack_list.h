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
#ifndef _STACK_LIST_H
#define _STACK_LIST_H 1
#include <stdbool.h>

#define STACK_TYPE int
#define BUFFER_SIZE 100

typedef struct STACK Stack;
typedef struct STACK_NODE Stack_node;

void push (Stack *self, STACK_TYPE value);
STACK_TYPE pop (Stack *self);
STACK_TYPE top(Stack *self);
bool is_empty (Stack_node *list);
bool is_full (Stack_node *list);
void distroy (Stack *self);

struct STACK_NODE {
	STACK_TYPE value;
	Stack_node *next;
};

struct STACK {
    Stack_node *list;		// the top node of the stack
    void (*_push) (Stack *_self, STACK_TYPE _value);
    STACK_TYPE (*_pop) (Stack *_self);
    STACK_TYPE (* _top) (Stack *_self);
    bool (*_is_empty) (Stack_node *_list);
    bool (*_is_full) (Stack_node *_list);
    void (*_distroy) (Stack *_self);
};

int test_stack_list (void);
#endif
