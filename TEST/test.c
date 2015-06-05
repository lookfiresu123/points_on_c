#include<stdio.h>

int test_3(){ //每个函数的开始都要创建栈，结束都要消除栈
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
    char *p;//什么都不做
    char *q;
#endif
    //int a = sizeof(float);
    //int b = sizeof(double);
    return 1;
}

int test_4(){ //每个函数的开始都要创建栈，结束都要消除栈
#if 0
    if(1)  //在汇编语言中，不比较，直接执行return 1后结束函数，因为表达式 1 是必然事件
        return 1;
    else
        return 0;
#endif
#if 0
    int i = 0;
    if(i != 0) //在汇编语言中，比较，若!=0，跳转到return 1，之后跳转到结束；否则跳转到return 0，之后跳转到结束
        return 1;
    else
        return 0;
#endif
#if 0
    int i = 0;
    while(1) //必然事件，不用判断
        i++;
#endif
#if 0
    int i = 1;
    while(i < 10) //非必然事件，需要判断比较，汇编中有cmpl,jle,jmp等
        i++;
    return 0;
#endif
#if 0
    int i,a;
    for(i=0;;i++) //可以将其改写成等价的while语句，以便于理解汇编语言
        a = i;
#endif
#if 0
    int i,a;
    for(i=0;i<10;i++){  //汇编中，cmpl操作的次数比addl操作的次数多1
        a = i;
        if(i < 5)
            ;            //break; //nop --> no operation 无操作
            //continue;
        a--;
    }
#endif
#if 0
    int i = 0;
    do{
        i++;
    }while(1); //while这一行最后要有;（分号）
#endif
#if 0
    int i = 0;
    do{
        i++;
    }while(i<10);
#endif
#if 0
    int i = 0;
    //cmp 2,je,cmp 3,je,cmp 1,jne --> i+=1,i+=2,i+=3,i+=4（执行顺序）
    switch(i){
    case 1: //除default外（default不比较，直接执行），最后一个比较的
        i += 1;
    case 2: //第一个比较
        i += 2;
    case 3: //第二个比较
        i += 3;
    default: //最后一项，default字符本身不对应代码，直接执行i+=4（汇编）
        i += 4;
    }
#endif
#if 0
    int i = 0;
    //cmp 2,je,cmp 3,je,cmp 1,jne --> i+=1,i+=2,i+=3,i+=4（执行顺序）
    switch(i){
    case 1: //除default外（default不比较，直接执行），最后一个比较的
        i += 1;
        break;  //相当于jmp到return 0
    case 2: //第一个比较
        i += 2;
        break;
    case 3: //第二个比较
        i += 3;
        break;
    default: //最后一项，default字符本身不对应代码，直接执行i+=4（汇编）
        i += 4;
        break;
    }
#endif
#if 0
    int i = 0;
    switch(i){
    case 1:
    case 2:
    case 3: //直接和3比（分别和min、max比）
        i += 3;
        break;
    default: 
        i += 4;
        break;
    }
#endif
    int i,j,k,a; //查看汇编代码
    i = j = k = a = 0;
    while(i<5){
        while(j<7){
            while(k<9){
                a++;
                if(a == 100)
                    goto exit;
                k++;
            }
            j++;
        }
        i++;
    }
exit:
    return 0;
}

void test_5(){
    // char *a = "abc";
    // char *b = "abc";
}

int practice_5(){
    char *input[20];
    char *buf[20];
    int i,k,j;
    for(i=0;i<20;i++)
        buf[i] = (char *)malloc(100*sizeof(char));
    gets(buf[0]);
    input[0] = buf[0];
    i = k = 1;
    while(gets(buf[i]) && *buf[i] != '\0'){   
        if(buf[i] != buf[i-1]){
            input[k] = buf[i];
            k++;
        }
        //free(buf[i]);
        i++;
    }
    //free(buf[i]);
    for(j=0;j<k;j++)
        puts(input[j]);
    return 0;
}

int main(){
#if 0
    test_3();
    test_4();
    test_5();
#endif
    // char *ch = malloc(10);
    // gets(ch);
    // free(ch);
    practice_5();

    return 0;
}
