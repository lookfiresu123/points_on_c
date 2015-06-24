#include<stdio.h>
#include<stdlib.h>

#define microsoft cp

int test_15(){
    int *a;//此时地址a = <_start>
    *a = 12;//程序在执行的时候会出现segmentation fault，表示程序试图访问一个未被分配给程序的内存位置
    return 0;
}

int test_16(){
    int *a = NULL;//此时地址a = 0x0
    char ch = 'a';//开辟了一个内存（地址为&ch，且在栈中），用于存储ch的值，且该值被初始化为'a'
    // char *cp;//cp = <_start>
    // *cp = 'a';//code segment can not be rewriten
    //&ch = &ch;
    // char *microsoft;//开辟了一个内存（地址为&microsoft，且在栈中），用于存储microsoft的值，但该值并未被初始化
    // microsoft = &ch;
    if(*a != 0)//can not access memory 0x0
    	;
    return 0;
}

int test_17(){
	char **strings;//在&strings的位置上定义strings（为赋值），&string处于内存的栈中
	char *string1 = "hello world";
	char *string2 = "you are welcome";
	char *string3 = "thank you";
	strings = &string3;//给strings赋值，这里不能用*strings = strings3，因为strings还没有明确的地址，编译器不知道到哪里去找*strings，赋值后strings处于内存栈中，与&strings相邻
	char **p = strings;
	*++strings = string1;
	*++strings = string2;
	strings = p;
	return 0;
}

int test_18(){
	
	char **strings = {	"sina",\
						"google",\
						"apple"	};//不能这样初始化，会造成excess elements in scalar initializer错误，strings中只有字符串"sina"，因为strings对应且只能对应一个地址，而该地址刚开始为"sina"地址，而"sina"地址处于常量区中，之后的"google"和"apple"都不能修改常量区中的值，故只能是"sina"
	return 0;
}

int test_19(){
    char a[10] = {'0','1','2','3','4','5','6','7','8','9'};//声明一块10字节大小的栈空间给a数组，并从低地址到高地址一次将0~9赋值到该块栈空间中，数值上a=&a
    char b[10];//声明一块10字节大小的栈空间给b数组，数值上b=&b
    char *p;//申明一块1字节大小的栈空间（空间地址为&p），用于存放地址p的值，&p!=p
    p = b;//将数组b的首地址b赋值给p
    return 0;
}



int main(){
    //test_15();
    //test_16();
    //test_17();
    //test_18();
    test_19();
    return 0;
}
