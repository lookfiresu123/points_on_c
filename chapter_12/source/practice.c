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
#define DO_PRACTICE_3 0
#define DO_PRACTICE_4 0
#define DO_PRACTICE_5 0
#define DO_PRACTICE_6 1
#define DO_PRACTICE_7 0

#define NODE_SIZE 10000
#define TRUE 1
#define FALSE 0

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
        //current = current->next;
    }

    new = malloc(sizeof(*new));
    new->value = value;

    // either the current is NULL or not, it should be the next node of the new one
    new->next = current;
    // either the prev is NULL or not, it should be the previous node of the new one
    new->prev = prev;

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
    register Node_two_way **first_ptr = &list->next;
    register Node_two_way **last_ptr = &list->prev;
    // if (*last_ptr) {
    //     while ((*last_ptr)->next)
    //         last_ptr = &(*last_ptr)->next;      // change the *last_ptr will change the pointer of *(&(*last_ptr)->next)
    // }
    dll_insert_practice(first_ptr, last_ptr, 6);
}

Node *sll_reverse (Node *first) {
    if (! first)
        return NULL;

    Node *new_first;
    Node *current = first;
    int count = 0;      // because first is not NULL, so count is 1 at least.

    // define a enough large array to store the (Node *) pointer
    Node *node_ptrs[NODE_SIZE];
    //node_ptrs[0] = first;       // initialize the node_ptrs

    while (current) {
        node_ptrs[count] = current;
        count ++;
        current = current->next;
    }

    // reverse the list by array
    int i;
    for (i = count - 1 ; i > 0 ; i--)
        node_ptrs[i]->next = node_ptrs[i-1];
    node_ptrs[i]->next = NULL;

    // assign the new_first pointer by array
    new_first = node_ptrs[count-1];

    return new_first;
}

void practice_4 (void) {
    int array[] = { 1, 2, 3, 4, 5 };
    int length_array = 5;
    Node *first = create_list(array, length_array);
    first = sll_reverse(first);
}

/*
 * @rootp: the pointer which points to (Node *)root
 * @none: the node which to be removed
 * */
int sll_remove (Node **rootp, Node *node) {
    Node *current = *rootp;
    Node *prev = NULL;          // the previous node of the "node"
    // find the "node" in the list
    while (current) {
        if (current == node)
            break;
        prev = current;
        current = current->next;
    }

    // there is no "node" in the list
    if (! current)
        return FALSE;

    // otherwise, remove it
    if ( current == *rootp && current->next) {        // if the "node" is the head of the list but not the tail
        *rootp = current->next;
        free(current);
    }

    else if (! current->next && current != *rootp) {          // if the "node" is the tail of the list but not the head
        prev->next = NULL;
        free(current);
    }

    else if (current->next && current == *rootp) {      // if the "node" is either the head or the tail
        free(current);
        *rootp = NULL;
    }

    else {          // if the "node" is at middle of the list
        prev->next = current->next;
        free(current);
    }

    return TRUE;
}

void practice_5 (void) {
    int array[] = { 1, 2, 3, 4, 5 };
    int length_array = 5;
    Node *first = create_list(array, length_array);
    sll_remove(&first, first->next);
}

int dll_remove (Node_two_way *rootp, Node_two_way *node) {
    // find the head and tail of the list
    Node_two_way *head = rootp->next;
    Node_two_way *tail = rootp->prev;

    Node_two_way *current = head;
    // search for the "node" in the list
    while (current) {
        if (current == node)
            break;
        current = current->next;
    }

    if (! current)      // if there is no "none" in the list
        return FALSE;

    // if the "node" exist, remove it
    if (current == head && current != tail) {
        // if the "node" is the head but not the tail of the list
        rootp->next = current->next;
        current->next->prev = NULL;
    }
    else if (current == tail && current != head) {
        // if the "node" is the tail but not the head of the list
        rootp->prev = current->prev;
        current->prev->next = NULL;
    }
    else if (current == tail && current == head) {
        // if the "node" is either the head or the tail of the list
        rootp->prev = current->prev;
        rootp->next = current->next;
        current->prev->next = NULL;
        current->next->prev = NULL;
    }
    else {
        // if the "node" is at middle in the list
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
    rootp->value --;
    return TRUE;
}

void practice_6 (void) {
    int array[] = { 1, 2, 3, 4, 5 };
    int length_array = 5;
    int *array_ptr = array;
    Node_two_way *rootp = create_list_two_way (array_ptr, length_array);
    dll_remove(rootp, rootp->next);
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


