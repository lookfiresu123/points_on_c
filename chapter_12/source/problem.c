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
#include <assert.h>
#include "../header/problem.h"

#define DO_PROBLEM_1 1
#define DO_PROBLEM_2 0
#define DO_PROBLEM_3 0
#define DO_PROBLEM_4 0
#define DO_PROBLEM_5 0

#define FALSE 0
#define TRUE 1

int sll_insert (Node **root, Node *current, int new_value) {
    Node *prev;
    Node *new;

    if (current->value >= new_value && current != *root) {
        printf("can not find the correct position where the new node should be inserted\n");
        return FALSE;
    }

    if (current->value >= new_value && current == *root) {
        new = malloc(sizeof(*new));
        *root = new;
        new->value = new_value;
        new->next = current;
        return TRUE;
    }

    /* find the correct position to insert into, the list is from least to largest */
    while (current != NULL && current->value < new_value) {
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

int sll_insert_advanced (Node **root, int new_value) {
    Node *current, *prev, *new;
    /* get the pointer point to the first node */
    current = *root;
    prev = NULL;    // used to check whether the new node should be the first node

    /* find the correct position to insert into, the list is from least to largest */
    while (current != NULL && current->value < new_value) {
        prev = current;
        current = current->next;
    }

    /* malloc memory for the new node, and initialize it */
    new = malloc(sizeof(*new));
    if (new == NULL)
        return FALSE;
    new->value = new_value;

    /* insert the correct position */
    if (prev == NULL)
        *root = new;
    else
        prev->next = new;
    new->next = current;
    return TRUE;
}

int sll_insert_final (register Node **linkp, int new_value) {
    register Node *current;
    register Node *new;

    /* find the correct position to insert the new node */
    while ((current = *linkp) != NULL &&
            current->value < new_value)
        linkp = &current->next;

    /* malloc memory for the new node, and initialize it */
    new = malloc(sizeof(*new));
    if (new == NULL)
        return FALSE;
    new->value = new_value;

    /* insert the new node */
    new->next = current;
    *linkp = new;
    return TRUE;
}

Node *create_list (int *point_array, int length_array) {
    Node *root, *current, *new;
    if (length_array == 0)
        return NULL;
    int i;
    for (i = 0 ; i < length_array ; i++) {
        /* melloc memory for the new node */
        new = malloc(sizeof(*new));
        assert(new);
        new->value = point_array[i];
        new->next = NULL;
        if (i == 0) {
            root = new;
            current = root;
        }
        else {
            current->next = new;
            current = new;
        }
    }
    return root;
}

void problem_1 (void) {
    int array[10] = { 2, 4, 7, 1, 9, 0, 3, 5, 8, 6 };
    int length_array = 10;
    int new_value = 12;
    Node *root = create_list(array, length_array);
    Node *current = root;
    enum METHOD { DO_SLL_INSERT, DO_SLL_INSERT_ADVANCED, DO_SLL_INSERT_FINAL } method;
    method = DO_SLL_INSERT_FINAL;
    switch (method) {
    case DO_SLL_INSERT:
        sll_insert(&root, current, new_value);
        break;
    case DO_SLL_INSERT_ADVANCED:
        sll_insert_advanced(&root, new_value);
        break;
    case DO_SLL_INSERT_FINAL:
        sll_insert_final(&root, new_value);
        break;
    }
}

void test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
}

