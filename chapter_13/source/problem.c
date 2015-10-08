/*
 * =====================================================================================
 *
 *       Filename:  problem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月08日 13时57分42秒
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
#include "../header/function.h"
#include "../header/node.h"

#define DO_PROBLEM_1 0
#define DO_PROBLEM_2 1

// transfer table
double calculator (int op, double x, double y) {
    double (*func_oper[]) (double, double) = {
        _add, _sub, _mul, _div
    };
    double result = func_oper[op](x, y);
    return result;
}

void problem_1 (void) {
    double x = 4;
    double y = 5;
    enum OPER { ADD, SUB, MUL, DIV } oper;
    oper = ADD;
    double result = calculator(oper, x, y);
    printf("%lf\n", result);
}

// callback function
Node *search_list ( Node *node, void const *value,
        int (*compare) (void const *, void const *) ) {
    while (node) {
        if (compare(&node->value, value) == 0)
            break;
        node = node->next;
    }
    return node;
}

int compare_ints (void const *x , void const *y) {
    if (*(int *)x == *(int *)y)
        return 0;
    else
        return 1;
}

void problem_2 (void) {
    // create node list
    int count_nodes = 5;
    int i = 0;
    int data[5] = { 1, 2, 3, 4, 5 };
    Node *root, *current, *new;
    while (i < count_nodes) {
        new = malloc(sizeof(*new));
        new->value = data[i];
        if (i == 0) {
            root = new;
            current = root;
        }
        else {
            current->next = new;
            current = current->next;
        }
        i++;
    }
    current->next = NULL;

    // compare
    int value = 4;
    Node *result = search_list(root, &value, compare_ints);
    printf("%p\n",result);
}

void test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
#if DO_PROBLEM_2
    problem_2();
#endif
}
