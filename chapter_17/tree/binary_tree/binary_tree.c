/*
 * =====================================================================================
 *
 *       Filename:  binary_tree.c
 *
 *    Description:  Description of object binary tree
 *
 *        Version:  1.0
 *        Created:  11/04/2015 06:37:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123@gmail.com
 *        Company:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

void insert_node (Object_tree **self, VALUE_TYPE value, Object_tree *parent) {
    if (*self == NULL) {
        Object_tree *new = (Object_tree *)malloc(sizeof(Object_tree));
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        new->parent = parent;
        *self = new;
    }
    else {
        if (value < (*self)->value)
            insert_node(&((*self)->left), value, *self);
        else if (value > (*self)->value)
            insert_node(&((*self)->right), value, *self);
        else
            perror("the value has exist in the tree");
    }
}

void print_tree (Object_tree *self) {
    if (self == NULL)
        printf(" [%c] ", '*');
    else {
        printf(" [%d] ", self->value);
        print_tree(self->left);
        print_tree(self->right);
    }
}

void free_tree (Object_tree *self) {
    if (self != NULL) {
        free_tree(self->left);
        free_tree(self->right);
        free(self);
    }
}

void delete_tree (Object_tree *self) {
    if (self != NULL) {
        // 如果该节点是叶子节点，则直接删除
        if (self->left == NULL && self->right == NULL) {
            // 若该节点同时也为根节点
            if (self->parent == NULL)
                free(self);
            // 否则，还要令父节点的左/右子树为空
            else {
                if (self->parent->left == self)
                    self->parent->left = NULL;
                else
                    self->parent->right = NULL;
                free(self);
            }
        }
        // 如果该节点只有一个孩子，则只需要将孩子接点变为父节点的孩子即可
        else if (self->left == NULL && self->right != NULL) {
            if (self->parent == NULL) {
                VALUE_TYPE store = self->right->value;
                free(self->right);
                self->value = store;
            }
            else {
                if (self->parent->left == self) {
                    self->parent->left = self->right;
                    self->right->parent = self->parent;
                }
                else {
                    self->parent->right = self->right;
                    self->right->parent = self->parent;
                }
                free(self);
            }
        }
        else if (self->left != NULL && self->right == NULL) {
            if (self->parent == NULL) {
                VALUE_TYPE store = self->left->value;
                free(self->left);
                self->value = store;
            }
            else {
                if (self->parent->left == self) {
                    self->parent->left = self->left;
                    self->left->parent = self->parent;
                }
                else {
                    self->parent->right = self->left;
                    self->left->parent = self->parent;
                }
                free(self);
            }
        }
        // 如果该节点的两个孩子都不为空，则删除它左子树中最大的那个节点，并把那个节点的值代替self节点的值
        else {
            // 递归self节点左子树的右子树，直到self->right == NULL
            Object_tree *temp = self->left;
            while (temp->right != NULL)
                temp = temp->right;
            VALUE_TYPE store = temp->value;
            delete_tree(temp);
            self->value = store;
        }
    }
}

int test_binary_tree (void) {
    Binary_tree tree_example = {
        .root = NULL,
        ._insert_node = insert_node,
        ._print_tree = print_tree,
        ._free_tree = free_tree,
        ._delete_tree = delete_tree
    };
    VALUE_TYPE array[10] = { 1, 0, 2, 9, 4, 6, 8, 7, 5, 3 };
    int i;
    for (i = 0 ; i < 10 ; i++)
        tree_example._insert_node(&(tree_example.root), array[i], NULL);
    tree_example._print_tree(tree_example.root);
    printf("\n");
    tree_example._delete_tree(tree_example.root);
    tree_example._print_tree(tree_example.root);
    printf("\n");
    tree_example._free_tree(tree_example.root);
    return 0;
}

