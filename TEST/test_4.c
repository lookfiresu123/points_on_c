#include<stdio.h>
#include<stdlib.h>
//#include"test.h"
#include"test_a.h"

/*
 *     当函数原型为int *func();时，既可以看做是旧式风格的申明（之给出func函数的返回类型，无法知道函数的参数类型，默认都合法），
 * 也可以看做是新式风格（给出返回类型和参数类型），它究竟是哪一种呢？这个声明必须被解释为旧式风格，目的是保持与ANSI标准之前的程序的兼容性，
 * 一个不带参数的函数原型应被写成int *func(void);。
 * */
int test_20(void){
    /*
     *     函数func在test.h中的函数原型为int *func();，它被看做是旧式风格的声明，只给出了func函数的返回类型，编译器无法知道参数所要求的类型，
     * 因此所有的参数都被默认为合法，因此编译器不会报错
     * */
	//printf("%d\n",func(1));
    /*
     *    函数func在test.h中的函数原型为int *func1(void);，它被看做是新式风格的声明，既给出了func1函数的返回类型，有声明了该函数不带任何参数，
     * 因此当用参数1调用func1函数时，编译器知道该调用违法，因此会报错。
     * */
	//printf("%d\n",func1(1));
	return 0;
}

/*
 *    头文件中的函数原型在预编译的时候被引入源文件，之后编译器检查源文件中函数的调用和引入的函数原型在返回类型、参数类型上是否一致，其他不管。
 * 这就造成这样一种现象：
 *    在test_a.h和test.h头文件中分别定义了static void func1(void);和void func1(void);而在test_4.c中只include了test_a.h头文件，
 * 编译器将源文件中的func1()函数调用和test_a.h中的函数原型匹配，发现一致，之后函数正常调用，但问题在于test_a.h中的函数原型是static内链属性，
 * 源文件无法调用它，而在test.h中有外链属性的func1函数，尽管没有include该头文件，但程序依然错误的执行test.h中的func1函数，会造成严重的后果。
 *    由此可以发现，include的头文件只负责检查函数调用和函数原型的返回类型和参数类型是否合法，不负责检查函数调用是不是执行了正确的函数原型（检查和执行不一定一致）。
 * 因此要尽量确保函数名的唯一性。
 * */
int test_21(void){
    printf("%d\n",func1());
    return 0;
}

int main(void){
	//test_20();
    test_21();
	return 0;
}
