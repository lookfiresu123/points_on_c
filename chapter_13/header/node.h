/*
 * =====================================================================================
 *
 *       Filename:  node.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年10月08日 14时39分09秒
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
