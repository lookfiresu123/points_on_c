/*
 * created by lookfiresu123 @ 2015/8/4
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 50
#define PROBLEM_4 0
#define PROBLEM_18 1

bool problem_4(void) {
    char buffer[SIZE] = {'a','b','c','d','e','f','g','f','e','d','c','b','a','\0'};
    int front,rear;

    front = 0;
    rear = strlen(buffer) - 1;

    while(front < rear) {
        if(*(buffer + front) != *(buffer + rear))
            break;
        front++;
        rear--;
    }

    if(front >= rear)
        return true;
    return false;
}

void problem_18(void) {
    int (*array)[5][2];
    array++;
}

int test_problem(void) {
#if PROBLEM_4
    bool result_problem_1 = problem_4();
#endif
#if PROBLEM_18
    problem_18();
#endif
    return 0;
}

