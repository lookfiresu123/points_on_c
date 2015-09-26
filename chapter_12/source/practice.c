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

#define DO_PRACTICE_1 1

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
}

void test_practice (void) {
#if DO_PRACTICE_1
    practice_1();
#endif
}
