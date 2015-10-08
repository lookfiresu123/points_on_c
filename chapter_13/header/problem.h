/*
 * =====================================================================================
 *
 *       Filename:  problem.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月08日 13时58分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

double calculator (int op, double x, double y);
void problem_1 (void);

Node *search_list ( Node *node, void const *value, int compare (void const * , void const *));
int compare_ints (void const *x , void const *y);
void problem_2 (void);

void test_problem (void);
