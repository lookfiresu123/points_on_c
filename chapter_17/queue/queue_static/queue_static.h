/*
 * =====================================================================================
 *
 *       Filename:  queue_static.h
 *
 *    Description:  build queue data structure with array
 *
 *        Version:  1.0
 *        Created:  11/02/2015 10:09:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123@gmail.com,
 *        Company:
 *
 * =====================================================================================
 */
#ifndef _QUEUE_STATIC_H
#define _QUEUE_STATIC_H 1

#include <stdbool.h>

#define QUEUE_TYPE int          // 队列元素的类型
#define QUEUE_SIZE 100          // 队列中元素的最大数量
#define ARRAY_SIZE (QUEUE_SIZE + 1)         // 数组的长度 = 元素最大数量 + 1

typedef struct QUEUE Queue;

void insert_queue (Queue *self, QUEUE_TYPE value);
QUEUE_TYPE delete_queue (Queue *self);
QUEUE_TYPE first (Queue *self);
bool is_empty (Queue *self);
bool is_full (Queue *self);


struct QUEUE {
    QUEUE_TYPE queue_array[ARRAY_SIZE];
    size_t front;
    size_t rear;
    void (*_insert_queue) (Queue *_self, QUEUE_TYPE _value);
    QUEUE_TYPE (*_delete_queue) (Queue *_self);
    QUEUE_TYPE (*_first) (Queue *_self);
    bool (*_is_empty) (Queue *_self);
    bool (*_is_full) (Queue *_self);
};

int test_queue_static(void);

#endif
