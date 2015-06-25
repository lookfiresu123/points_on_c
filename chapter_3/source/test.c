#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"../header/test.h"

//#define lol "lol"

/* external function */
static int practice_problem_225(void){
    unsigned length = -1;
    printf("%u\n",length);
    return 0;
}

/* external function */
int practice_problem_226(void){
    size_t a = 1,b = 2;
    a = a - b;
//    printf("%d\n",size_of(size_t));
    b = sizeof(size_t);
    return 0;
}

/* external function */
int practice_problem_const(void){
    const char *s = "hello";
    s = "world";
    printf("%s\n",s);//if have not this code, you will see "set but not used for s, [-Wunused-but-set-variable]"
    return 0;
}

static int sizeof_enum(void){
    enum Day yesterday,today,tomorrow; //光声明只能申请到栈，待函数结束后栈就自然被释放了
    int a = 1; //想要压入栈中必须给局部变量赋初值
    #if 0
    yesterday = Monday;
    today = Tuesday;
    tomorrow = Wednesday;
    int a = sizeof(yesterday);
    int b = sizeof(today);
    int c = sizeof(tomorrow);
    #endif
    return 0;
}

/* external function */
int test_test(void){
    #if 0
    practice_problem_225();
    practice_problem_226();
    practice_problem_const();
    #endif
    sizeof_enum();
    #if 0
    char a[] = "abcd";
    char *b = "abcd";
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 1;
    const char *c = "hell";
    const int d = 1;
    const int *e = ptr;
    #endif
    #if 0
    char input[20];
    int i = 0;
    while(gets(input) && (*input != NULL))
        i++;
    for(i=0;i<21;i++)
        input[i] = 'a'+ i;
    while(getchar()!=EOF)
        ;
    printf("end\n");
    #endif
    #if 0
    printf("%p,%p,%s\n",&a,a,a);
    printf("%p,%p,%s\n",&b,b,b);
    printf("const char * : %p,%p,%s\n",&c,c,c);
    printf("const int : %p,%d\n",&d,d);
    printf("const int * : %p,%p\n",&e,e);
    b = "defg";
    printf("%p,%p,%s\n",&b,b,b);
    #define lol 1
    printf("#define : %p,%d\n",&1,1);
    free(ptr);
    #endif

    return 0;
}









