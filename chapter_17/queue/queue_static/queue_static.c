/*
 * =====================================================================================
 *
 *       Filename:  queue_static.c
 *
 *    Description:  build queue data structure with array
 *
 *        Version:  1.0
 *        Created:  11/03/2015 02:18:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123@gmail.com
 *        Company:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queue_static.h"

/* insert an element : modify the rear and insert it behind the rear */
void insert_queue (Queue *self, QUEUE_TYPE value) {
    if ( (self->_is_full)(self) == true)
        perror("the queue is full");
    else {
        self->rear = (self->rear + 1) % ARRAY_SIZE;
        self->queue_array[self->rear] = value;
    }
}

/* delete an element : modify the front and return the element  */
QUEUE_TYPE delete_queue (Queue *self) {
    if ( (self->_is_empty)(self) == true) {
        perror("the queue is empty");
        return (QUEUE_TYPE)0;
    }
    else {
        QUEUE_TYPE ret = self->queue_array[self->front];
        self->front = (self->front + 1) % ARRAY_SIZE ;
        return ret;
    }
}

/* get the element at the front */
QUEUE_TYPE first (Queue *self) {
    if ( (self->_is_empty)(self) == true ) {
        perror("the queue is empty");
        return (QUEUE_TYPE)0;
    }
    else
        return self->queue_array[self->front];
}

bool is_empty (Queue *self) {
    return (self->rear + 1) % ARRAY_SIZE == self->front ? true : false;
}

bool is_full (Queue *self) {
    return (self->rear + 2) % ARRAY_SIZE == self->front ? true : false;
}

int test_queue_static(void) {
    Queue queue_example = {
        .front = 0,
        .rear = ARRAY_SIZE - 1,
        ._insert_queue = insert_queue,
        ._delete_queue = delete_queue,
        ._first = first,
        ._is_empty = is_empty,
        ._is_full = is_full
    };
    QUEUE_TYPE array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int i;
    for (i = 0 ; i < 10 ; i++)
        queue_example._insert_queue(&queue_example, array[i]);
    for (i = 0 ; i < 10 ; i++)
        queue_example._delete_queue(&queue_example);
    return 0;
}

