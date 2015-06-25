#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"../header/practice.h"

int practice_6(void){
    enum coin RMB = PENNY, dollor = NICKEL;
    return 0;
}

int practice_7(void){
    enum Liquid  jar;
    jar = QUART;
    printf("%s\n",jar); //此时，实际上jar在堆栈中是0x20(int)，不能用%s输出
    jar += PINT;
    printf("%s\n",jar); //此时，实际上jar在堆栈中是0x30(int)，不能用%s输出
    return 0;
}

int practice_12(void){
    const int a = 16;
    const int b;
//    b = 32;
    return 1;
}

int practice_14(void){ //查看汇编代码，发现共4个局部变量入栈，第一个a位于栈顶
    int a = 1;
    {
        int b = a;
        int a = 2;
        int c = a;
    }
    return 0;
}

int test_practice(void){
#if 0
    practice_6();
    practice_7();
    practice_12();
#endif
    practice_14();
    return 0;
}
