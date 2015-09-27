/*
 * =====================================================================================
 *
 *       Filename:  practice.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月11日 20时16分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include "../header/problem.h"

int Count_nodes (Node *root);
Node **tail_insert_node (Node **pos_tail, int value);
void practice_1 (void);


Node *search_for_value (Node *root, int value);
void practice_2 (void);


int dll_insert_practice (register Node_two_way **first_ptr, register Node_two_way **last_ptr, int value);
void practice_3 (void);

int sll_remove (Node **rootp, Node *node);
void practice_5 (void);

int sll_remove (Node **rootp, Node *node);
void practice_5 (void);
void test_practice (void);
