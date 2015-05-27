#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//#define lol "lol"

/* external function */
static int practice_problem_225(){
    unsigned length = -1;
    printf("%u\n",length);
    return 0;
}

/* external function */
int practice_problem_226(){
    size_t a = 1,b = 2;
    a = a - b;
//    printf("%d\n",size_of(size_t));
    b = sizeof(size_t);
    return 0;
}

/* external function */
int practice_problem_const(){
    const char *s = "hello";
    s = "world";
    printf("%s\n",s);//if have not this code, you will see "set but not used for s, [-Wunused-but-set-variable]"
    return 0;
}

/* external function */
int test_test(){
    practice_problem_225();
    practice_problem_226();
    practice_problem_const();
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









