#include<stdio.h>

int main(){
#if 0
    printf("%d\n",1);  //将字符值0x1赋值到esi寄存器中
#define f 4  //无任何汇编代码
#define g "abc"  //只有为"abc"分配内存（文字常量区）的代码
    printf("%p,%p\n",&g,g);
    int a = 1;  //讲0x1、0x2、0x5压栈
    int b = 2;
    int c = 5;
    c = a;  //a对应的栈中内容赋值到c对应的栈中
    printf("%d\n",7);
    printf("%d\n",c);
#endif
#if 0
    char *p = "abc";//创建栈，并为p、q压栈
    char *q = "edf";
#endif
#if 0
    char *p;//创建栈，但不为p、q压栈
    char *q;
#endif
    int a = sizeof(float);
    int b = sizeof(double);
    return 1;
}
