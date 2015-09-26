/*
 * =====================================================================================
 *
 *       Filename:  practice.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月11日 20时15分18秒
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
#include <string.h>
#include "../header/problem.h"

#define DO_PRACTICE_1 0
#define DO_PRACTICE_2 0
#define DO_PRACTICE_3 1
#define DO_PRACTICE_4 0
#define DO_PRACTICE_5 0
#define DO_PRACTICE_6 0
#define DO_PRACTICE_7 0

int Count_nodes (Node *root) {
    int count = 0;
    while (root) {
        count ++;
        root = root->next;
    }
    return count;
}

/* insert a node to the tail */
Node **tail_insert_node (Node **pos_tail, int value) {
    *pos_tail = malloc(sizeof(**pos_tail));
    (*pos_tail)->value = value;
    (*pos_tail)->next = NULL;
    pos_tail = &(*pos_tail)->next;
    return pos_tail;
}

void practice_1 (void) {
    Node *root;
    Node **pos_tail = &root;
    int count;
    pos_tail = tail_insert_node(pos_tail, 1);
    pos_tail = tail_insert_node(pos_tail, 2);
    pos_tail = tail_insert_node(pos_tail, 3);
    pos_tail = tail_insert_node(pos_tail, 4);
    pos_tail = tail_insert_node(pos_tail, 5);
    count = Count_nodes(root);
    printf("%d\n",count);
}

Node *search_for_value (Node *root, int value) {
    Node *current = root;
    while (current && current->value != value)
        current = current->next;
    return current;
}

void practice_2 (void) {
    Node *result;
    Node *root;
    Node **pos_tail = &root;
    pos_tail = tail_insert_node(pos_tail, 3);
    pos_tail = tail_insert_node(pos_tail, 2);
    pos_tail = tail_insert_node(pos_tail, 5);
    pos_tail = tail_insert_node(pos_tail, 1);
    pos_tail = tail_insert_node(pos_tail, 4);
    int value = 1;
    result = search_for_value(root, value);
    printf("%p\n",result);
}

/*
 * for sometimes, we should change the first pointer and the last one,
 * so we use "register Node **" type to change *first_ptr and *last_ptr.
 * @start_ptr: first_ptr -> first -> the first node
 * @last_ptr: last_ptr -> last -> the last node
 */
int dll_insert_practice (register Node_two_way **first_ptr, register Node_two_way **last_ptr, int value) {

    /* check if value has existed in the list
     * if true, then return ;
     * if false, then create a node to for the value
     * */
    register Node_two_way *current;
    register Node_two_way *prev = NULL;
    register Node_two_way *new;
    for (current = *first_ptr ; current != NULL ; current = current->next) {
        if (current->value == value)   // if existed
            return 0;
        if (current->value > value)    // find the first node whose value larger than the given one
            break;
        prev = current;
        current = current->next;
    }

    new = malloc(sizeof(*new));
    new->value = value;

    // either the current is NULL or not, it should be the next node of the new one
    new->next = current;
    if (current)            // the new node should not be inserted into the last position
        current->prev = new;
    else                    // the new node should be inserted into the last position
        *last_ptr = new;

    if (prev)       // the new node should not be inserted into the first position
        prev->next = new;
    else
        *first_ptr = new;

    return 1;
}

void practice_3 (void) {
    int array[5] = { 1, 2, 3, 4, 5 };
    int length_array = 5;
    Node_two_way *list = create_list_two_way(array, length_array);
    register Node_two_way **first_ptr = &list;
    register Node_two_way **last_ptr = first_ptr;
    if (*last_ptr) {
        while ((*last_ptr)->next)
            last_ptr = &(*last_ptr)->next;
    }
    dll_insert_practice(first_ptr, last_ptr, 6);
}


void test_practice (void) {
#if DO_PRACTICE_1
    practice_1();
#endif
#if DO_PRACTICE_2
    practice_2();
#endif
#if DO_PRACTICE_3
    practice_3();
#endif
#if DO_PRACTICE_4
    practice_4();
#endif
#if DO_PRACTICE_5
    practice_5();
#endif
#if DO_PRACTICE_6
    practice_6();
#endif
#if DO_PRACTICE_7
    practice_7();
#endif
}


