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
#include "stack_list.h"

bool is_empty (Stack_node *list) {
    return list == NULL ? true : false;
}

bool is_full (Stack_node *list) {
    return false;       // never full because of list data structure
}

void push (Stack *self, STACK_TYPE value) {
    if (! (self->_is_full)(self->list)) {
        // add a node at the head of list
        Stack_node *new = (Stack_node *)malloc(sizeof(Stack_node));
        new->value = value;
        new->next = self->list;
        self->list = new;
    }
    else
        perror("stack is full");
}

STACK_TYPE pop (Stack *self) {
    if (! (self->_is_empty)(self->list)) {
        STACK_TYPE value_pop;
        // delete a node at the head of list
        Stack_node *current = self->list;
        self->list = current->next;
        value_pop = current->value;
        free(current);
        return value_pop;
    }
    else {
        perror("stack is empty");
        return (STACK_TYPE)0;
    }
}

STACK_TYPE top (Stack *self) {
    if (! (self->_is_empty)(self->list))
        return self->list->value;
    else
        return (STACK_TYPE)0;
}

void distroy (Stack *self) {
    while (self->list)
        pop(self);
}

int test_stack_list (void) {
    Stack stack_example = {
        .list = NULL,
        ._is_full = is_full,
        ._is_empty = is_empty,
        ._pop = pop,
        ._push = push,
        ._top = top,
        ._distroy = distroy
    };
    int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int i;
    for (i = 0 ; i < 10 ; i++)
        stack_example._push(&stack_example, array[i]);
    distroy(&stack_example);
    return 0;
}
