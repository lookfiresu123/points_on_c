/*
 * =====================================================================================
 *
 *       Filename:  problem.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月11日 20时16分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

typedef struct NODE {
    int value;
    struct NODE *next;
} Node;


int sll_insert (Node **root, Node *current, int new_value);
int sll_insert_advanced (Node **root, int new_value);
int sll_insert_final (register Node **linkp, int new_value);
Node *create_list (int *point_array, int length_array);
void problem_1 (void);

void test_problem (void);
