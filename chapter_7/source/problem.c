#include<stdio.h>
#include<stdlib.h>

static int count = 0;

int Fibonacci(int i){
    count++;
    if( i>2 )
        return Fibonacci(i-1) + Fibonacci(i-2);
    else{
        count++;
        return 1;
    }
}

void problem_10(int i){
    Fibonacci(i);
    printf("%d\n",count);
}

void test_problem(void){
    int i;
    printf("input i\n");
    scanf("%d",&i);
    problem_10(i);
}
