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

typedef struct NODE_TWO_WAY {
    int value;
    struct NODE_TWO_WAY *prev;      // pointer to the previous node
    struct NODE_TWO_WAY *next;      // pointer to the next node
} Node_two_way;


int sll_insert (Node **root, Node *current, int new_value);
int sll_insert_advanced (Node **root, int new_value);
int sll_insert_final (register Node **linkp, int new_value);
Node *create_list (int *point_array, int length_array);
void problem_1 (void);

int dll_insert (Node_two_way *root, int value);
Node_two_way *create_list_two_way (int *point_array, int length_array);
void problem_2 (void);

void test_problem (void);
