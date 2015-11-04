/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.h
 *
 *    Description:  Description of object binary tree
 *
 *        Version:  1.0
 *        Created:  11/04/2015 06:38:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123@gmail.com
 *        Company:
 *
 * =====================================================================================
 */
#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H 1

#define VALUE_TYPE int
typedef struct BINARY_TREE Binary_tree;
typedef struct OBJECT_TREE Object_tree;

void insert_node (Object_tree **self, VALUE_TYPE value, Object_tree *parent);/* insert node */
void print_tree (Object_tree *self);/* print tree */
void free_tree (Object_tree *self);/* free tree */
void delete_tree (Object_tree *self);/* delete node in binary search tree */

struct OBJECT_TREE {
    int value;
    Object_tree *left;
    Object_tree *right;
    Object_tree *parent;
};

struct BINARY_TREE {
    Object_tree *root;
    void (*_insert_node) (Object_tree **_self, VALUE_TYPE _value, Object_tree *parent);
    void (*_print_tree) (Object_tree *_self);
    void (*_free_tree) (Object_tree *self);
    void (*_delete_tree) (Object_tree *self);
};

int test_binary_tree (void);

#endif
