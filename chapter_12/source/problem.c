/*
 * =====================================================================================
 *
 *       Filename:  problem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月11日 20时16分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "../header/problem.h"

#define DO_PROBLEM_1 1
#define DO_PROBLEM_2 0
#define DO_PROBLEM_3 0
#define DO_PROBLEM_4 0
#define DO_PROBLEM_5 0

#define FALSE 0
#define TRUE 1

int sll_insert (Node *root, Node *current, int new_value) {
    Node *prev;
    Node *new;

    if (current->value >= new_value && current != root) {
        printf("can not find the correct position where the new node should be inserted\n");
        return FALSE;
    }

    if (current->value >= new_value && current == root) {
        new = malloc(sizeof(*new));
        root = new;
        new->value = new_value;
        new->next = current;
        return TRUE;
    }

    /* find the correct position to insert into, the list is from least to largest */
    while (current->value < new_value) {
        prev = current;
        current = current->next;
    }

    /* malloc memory for the new node, and initialize it, return FALSE if failed */
    new = malloc(sizeof(*new));
    if (new == NULL)
        return FALSE;
    new->value = new_value;
    prev->next = new;
    new->next = current;
    return TRUE;
}

void problem_1 (void) {
    sll_insert(root, current, 12);
}

void test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
}

