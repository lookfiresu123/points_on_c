/*
 * =====================================================================================
 *
 *       Filename:  problem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月11日 20时16分01秒
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
#include <assert.h>
#include <string.h>
#include "../header/problem.h"

#define DO_PROBLEM_1 0
#define DO_PROBLEM_2 0
#define DO_PROBLEM_3 1

#define FALSE 0
#define TRUE 1

int sll_insert (Node **root, Node *current, int new_value) {
    Node *prev;
    Node *new;

    if (current->value >= new_value && current != *root) {
        printf("can not find the correct position where the new node should be inserted\n");
        return FALSE;
    }

    if (current->value >= new_value && current == *root) {
        new = malloc(sizeof(*new));
        *root = new;
        new->value = new_value;
        new->next = current;
        return TRUE;
    }

    /* find the correct position to insert into, the list is from least to largest */
    while (current != NULL && current->value < new_value) {
        prev = current;
        current = current->next;
    }

    /* malloc memory for the new node, and initialize it, return FALSE if failed */
    new = malloc(sizeof(*new));
    if (new == NULL)
        return FALSE;
    new->value = new_value;
    prev->next = new;
    new->next = current;
    return TRUE;
}

int sll_insert_advanced (Node **root, int new_value) {
    Node *current, *prev, *new;
    /* get the pointer point to the first node */
    current = *root;
    prev = NULL;    // used to check whether the new node should be the first node

    /* find the correct position to insert into, the list is from least to largest */
    while (current != NULL && current->value < new_value) {
        prev = current;
        current = current->next;
    }

    /* malloc memory for the new node, and initialize it */
    new = malloc(sizeof(*new));
    if (new == NULL)
        return FALSE;
    new->value = new_value;

    /* insert the correct position */
    if (prev == NULL)
        *root = new;
    else
        prev->next = new;
    new->next = current;
    return TRUE;
}

int sll_insert_final (register Node **linkp, int new_value) {
    register Node *current;
    register Node *new;

    /* find the correct position to insert the new node */
    while ((current = *linkp) != NULL &&
            current->value < new_value)
        linkp = &current->next;

    /* malloc memory for the new node, and initialize it */
    new = malloc(sizeof(*new));
    if (new == NULL)
        return FALSE;
    new->value = new_value;

    /* insert the new node */
    new->next = current;
    *linkp = new;
    return TRUE;
}

/* two-way list insert normal code */
int dll_insert (Node_two_way *root, int value) {
    Node_two_way *current, *next, *new;

    /* check whether there is already a node with this value in the list
     * if yes, then return FALSE; else, malloc memory for the new node,
     * initialize it, and the current node should be the previous node of
     * the new node, and the next node should be the next node of the new
     * node. */
    for (current = root ; (next = current->next) != NULL ; current = next) {
        if (next->value == value)
            return FALSE;
        else if (next->value > value)
            break;
    }

    /* the current node is the correct position to insert into */

    new = malloc(sizeof(*new));
    if (new == NULL)
        return FALSE;
    new->value = value;

    /* insert the new node to the list */
    if (next != NULL) {
        /*
         * situation 1: the correct position is not the tail of list
         */
        /* situation 1.1: the correct position is not the head of list, in other words, the current is not the root */
        if (current != root) {
            // none is NULL
            current->next = new;
            new->prev = current;
            new->next = next;
            next->prev = new;
        }
        /* situation 1.2: the correct position is the head of list, in other words, the current is not the root */
        else {
            // make the prev NULL
             root->next = new;
             new->prev = NULL;
             new->next = next;
             next->prev = new;
        }
    }
    else {
        /*
         * situation 2: the correct position is the tail of list
         */
        /* situation 2.1: the correct position is not the head of list, in other words, the current is not the root. */
        if (current != root) {
            // make the next NULL
            current->next = new;
            new->prev = current;
            new->next = NULL;
            root->prev = new;
        }
        /* situation 2.2: the correct position is the head of list, in other words, the current is not the root. */
        else {
            // both make the prev and next NULL
            new->next = NULL;
            new->prev = NULL;
            root->next = new;
            root->prev = new;
        }
    }
    root->value ++;
    return TRUE;
}

/* two-way list insert advanced and reduced code */
int dll_insert_advanced (Node_two_way *root, int value) {
    Node_two_way *current, *next, *new;

    /* check whether there is already a node with this value in the list
     * if yes, then return FALSE; else, malloc memory for the new node,
     * initialize it, and the current node should be the previous node of
     * the new node, and the next node should be the next node of the new
     * node. */
    for (current = root ; (next = current->next) != NULL ; current = next) {
        if (next->value == value)
            return FALSE;
        else if (next->value > value)
            break;
    }

    /* the current node is the correct position to insert into */

    new = malloc(sizeof(*new));
    if (new == NULL)
        return FALSE;
    new->value = value;

    /* insert the new node to the list */
    if (next != NULL) {
        /*
         * situation 1: the correct position is not the tail of list
         */
        /* situation 1.1: the correct position is not the head of list, in other words, the current is not the root */
        if (current != root) {
            // none is NULL
            current->next = new;
            new->prev = current;
        }
        /* situation 1.2: the correct position is the head of list, in other words, the current is not the root */
        else {
            // make the prev NULL
             root->next = new;
             new->prev = NULL;
        }
        new->next = next;
        next->prev = new;
    }
    else {
        /*
         * situation 2: the correct position is the tail of list
         */
        /* situation 2.1: the correct position is not the head of list, in other words, the current is not the root. */
        if (current != root) {
            // make the next NULL
            current->next = new;
            new->prev = current;
        }
        /* situation 2.2: the correct position is the head of list, in other words, the current is not the root. */
        else {
            // both make the prev and next NULL
            new->prev = NULL;
            root->next = new;
        }
        new->next = NULL;
        root->prev = new;
    }
    root->value ++;
    return TRUE;
}

/* two-way list insert final and most-reduced code */
int dll_insert_final (Node_two_way *root, int value) {
    register Node_two_way *current, *next, *new;

    /* check whether there is already a node with this value in the list
     * if yes, then return FALSE; else, malloc memory for the new node,
     * initialize it, and the current node should be the previous node of
     * the new node, and the next node should be the next node of the new
     * node. */
    for (current = root ; (next = current->next) != NULL ; current = next) {
        if (next->value == value)
            return FALSE;
        else if (next->value > value)
            break;
    }

    /* the current node is the correct position to insert into */

    new = malloc(sizeof(*new));
    if (new == NULL)
        return FALSE;
    new->value = value;

    /* insert the new node to the list */
    new->next = next;
    current->next = new;

    if (current != root)
        new->prev = current;
    else
        new->prev = NULL;

    if (next != NULL)
        next->prev = new;
    else
        root->prev = new;


    root->value ++;
    return TRUE;
}

Node *create_list (int *point_array, int length_array) {
    Node *root, *current, *new;
    if (length_array == 0)
        return NULL;
    int i;
    for (i = 0 ; i < length_array ; i++) {
        /* malloc memory for the new node */
        new = malloc(sizeof(*new));
        assert(new);
        new->value = point_array[i];
        new->next = NULL;
        if (i == 0) {
            root = new;
            current = root;
        }
        else {
            current->next = new;
            current = new;
        }
    }
    return root;
}

Node_two_way *create_list_two_way (int *point_array, int length_array) {
    Node_two_way *root, *current, *new;
    /* malloc memory for the root node, and initialize it */
    root = malloc(sizeof(*root));
    root->prev = NULL;
    root->next = NULL;
    root->value = length_array;
    current = root;

    int i;
    for (i = 0 ; i < length_array ; i++) {
        /* malloc memory for the new node, and initialize it */
        new = malloc(sizeof(*new));
        new->value = point_array[i];
        /* the operation for initializing the first node */
        if (i == 0) {
            new->prev = NULL;
            root->next = new;
        }
        /* the operation for initializing the node which is not the first node */
        else {
            current->next = new;
            new->prev = current;
        }
        current = new;
    }

    /* the operation for initializing the last node */
    new->next = NULL;
    root->prev = new;

    return root;
}

void problem_1 (void) {
    int array[10] = { 2, 4, 7, 1, 9, 0, 3, 5, 8, 6 };
    int length_array = 10;
    int new_value = 12;
    Node *root = create_list(array, length_array);
    Node *current = root;
    enum METHOD { DO_SLL_INSERT, DO_SLL_INSERT_ADVANCED, DO_SLL_INSERT_FINAL } method;
    method = DO_SLL_INSERT_FINAL;
    switch (method) {
    case DO_SLL_INSERT:
        sll_insert(&root, current, new_value);
        break;
    case DO_SLL_INSERT_ADVANCED:
        sll_insert_advanced(&root, new_value);
        break;
    case DO_SLL_INSERT_FINAL:
        sll_insert_final(&root, new_value);
        break;
    }
}

void problem_2 (void) {
    int array[10] = { 2, 4, 7, 1, 9, 0, 3, 5, 8, 6 };
    int length_array = 10;
    int new_value = 12;
    Node_two_way *root = create_list_two_way(array, length_array);
    Node_two_way *current;
    for (current = root->next ; current != NULL ; current = current->next) {
        printf("%d ", current->value);
    }
    printf("\n");
    enum METHOD { DO_DLL_INSERT, DO_DLL_INSERT_ADVANCED, DO_DLL_INSERT_FINAL } method;
    method = DO_DLL_INSERT_FINAL;
    switch(method) {
    case DO_DLL_INSERT:
        dll_insert(root, new_value);
        break;
    case DO_DLL_INSERT_ADVANCED:
        dll_insert_advanced(root, new_value);
        break;
    case DO_DLL_INSERT_FINAL:
    dll_insert_final(root, new_value);
        break;
    }
    //dll_insert(root, new_value);
    for (current = root->next ; current != NULL ; current = current->next) {
        printf("%d ", current->value);
    }
}

void Init_index_table (Node_char **table) {
    int i;
    for (i = 0 ; i < 26 ; i++) {
        *table = malloc(sizeof(**table));
        (*table)->index = 'a' + i;
        (*table)->list = NULL;
        table = &(*table)->next;
    }
    *table = NULL;
}

static int EXISTED = 0;
static int SUCCESS = 1;

/*
 * insert a string to a correct position in the index table
 * */
// @table: index table which store strings
// @string: the string which to be inserted
int Insert_string (Node_char *table, char *string) {
    // find the list that match the first character of string
    Node_char *pos_node_char = table;
    while (pos_node_char) {
        if (pos_node_char->index == *string)
            break;
        pos_node_char = pos_node_char->next;
    }

    // find the correct position to insert into
    Node_string **pos_node_string = &pos_node_char->list;
    int temp = 1;
    while( *pos_node_string && (temp = strcmp((*pos_node_string)->string, string)) < 0)
        pos_node_string = &(*pos_node_string)->next;

    if (temp == 0)
        return EXISTED;
    else {
        // insert into there
        Node_string *new = malloc(sizeof(*new));
        new->string = string;
        new->next = *pos_node_string; // maybe NULL
        *pos_node_string = new;
        return SUCCESS;
    }
}

void problem_3 (void) {
    Node_char *table;
    Init_index_table(&table);
    char *string[10] = { "tencent" , "google", "sina", "baidu", "apple", 
                         "htc", "sansung", "yahoo", "ebay", "microsoft" };
    int i;
    for (i = 0 ; i < 10 ; i++)
        Insert_string(table, string[i]);

    // display table
    Node_char *p = table;
    Node_string *q;
    while (p) {
        printf("%c: ", p->index);
        q = p->list;
        while (q) {
            printf("%s ", q->string);
            q = q->next;
        }
        printf("\n");
        p = p->next;
    }

}

void test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
#if DO_PROBLEM_2
    problem_2();
#endif
#if DO_PROBLEM_3
    problem_3();
#endif
}

