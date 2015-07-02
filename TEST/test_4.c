#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
//#include"test.h"
#include"test_a.h"

/*
 *     当函数原型为int *func();时，既可以看做是旧式风格的申明（之给出func函数的返回类型，无法知道函数的参数类型，默认都合法），
 * 也可以看做是新式风格（给出返回类型和参数类型），它究竟是哪一种呢？这个声明必须被解释为旧式风格，目的是保持与ANSI标准之前的程序的兼容性，
 * 一个不带参数的函数原型应被写成int *func(void);。
 * */
int test_20(void){
    /*
     *     函数func在test.h中的函数原型为int func();，它被看做是旧式风格的声明，只给出了func函数的返回类型，编译器无法知道参数所要求的类型，
     * 因此所有的参数都被默认为合法，因此编译器不会报错
     * */
	//printf("%d\n",func(1));
    /*
     *    函数func在test.h中的函数原型为int func1(void);，它被看做是新式风格的声明，既给出了func1函数的返回类型，有声明了该函数不带任何参数，
     * 因此当用参数1调用func1函数时，编译器知道该调用违法，因此会报错。
     * */
	//printf("%d\n",func1(1));
	return 0;
}

/*
 *    头文件中的函数原型在预编译的时候被引入源文件，之后编译器检查源文件中函数的调用和引入的函数原型在返回类型、参数类型上是否一致，其他不管。
 * 这就造成这样一种现象(假设同时编译test.o,test_a.o,test_4.o并将这三个文件链接在一起（错误发生在链接的过程中）)：
 *    在test_a.h和test.h头文件中分别定义了static void func1(void);和void func1(void);而在test_4.c中只include了test_a.h头文件，
 * 编译器将源文件中的func1()函数调用和test_a.h中的函数原型匹配，发现一致，之后函数正常调用，但问题在于test_a.h中的函数原型是static内链属性，
 * 源文件无法调用它，而在test.h中有外链属性的func1函数，尽管没有include该头文件，但程序依然错误的执行test.h中的func1函数（若test.o没有被链接，则该程序找不到test.h中的func1函数），会造成严重的后果。
 *    由此可以发现，include的头文件只负责检查函数调用和函数原型的返回类型和参数类型是否合法，不负责检查函数调用是不是执行了正确的函数原型（检查和执行不一定一致）。
 * 因此要尽量确保函数名的唯一性。
 * */
int test_21(void){
    //printf("%d\n",func1());
    return 0;
}

/*
 * 奇偶校验函数，若返回值为1，则表示符合偶校验；若返回值为0，则表示符合奇校验
 */
int test_22(int value,int n_bits){//value是要校验的数，n_bits是value的有效位
    int parity = 0;//记录value中1的个数
    while(n_bits > 0){
        parity += value & 1;//比较value最后1位是否为1，若是，则parity+1；否则，parity不变
        value >>= 1;//value右移一位
        n_bits --;//value的总位数-1
    }
    return (parity % 2)==0;
}

/*
 * 参数在栈中为副本，副本在函数结束后会被释放，且实际改变的是副本的值，原理是原本和副本在栈中的位置不一样
 * 例如：原本：x的位置：0x7fffffffffffde38，y的位置：0x7fffffffffffde3c
 *       副本：x的位置：0x7fffffffffffde0c，y的位置：0x7fffffffffffde38
 */
void test_23(int x,int y){
    //printf("test_23: &x = %p, &y = %p\n",&x,&y);
    int temp;
    temp = x;
    x = y;
    y = temp;
}

/*
 * 参数在栈中为原本的地址（位置），原本在函数结束后不会被释放，因此实际改变的就是原本的值
 */
void test_24(int *x,int *y){
    //printf("test_24: &(*x) = %p, &(*y) = %p\n",x,y);
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/*
 * 利用递归函数将整型值转化为字符并打印
 */
void test_25(unsigned int value){
    printf("%u -> %p\n",value,&value);
    int temp = value % 10;
    if((value /= 10) != 0)
        test_25(value);
    printf("%c",temp+'0');
}

void test_26(){
    int i = 1;
    //i = (++i) + (++i) + (++i) + (++i);
    //i = (++i) + (++i);
    i = (++i) + (++i) + (++i) + (++i) + (++i);
    /*
     * 观察反汇编代码后发现上述表达式类似于：
     * ++i;
     * ++i;
     * sum = i + i;
     * while(n-2>0){ //n表示表达式右值中i的个数
     *      ++i;
     *      sum = sum + i;
     *      n--;
     * }
     * i = sum;
     */
    //printf("%d\n",i);
}

/*
 * 计算输入参数的平均值
 */
float test_27(int n_value, ...){
    float sum = 0;
    va_list var_arg;
    int count;
    
    //初始化要访问的参数
    va_start(var_arg,n_value);
    //顺序访问参数
    for(count = 0;count < n_value;count++){
        sum += va_arg(var_arg,int);
    }
    //结束访问参数
    va_end(var_arg);

    return sum/n_value;
}

int main(void){
#if 0
    int x=1,y=2;
    //printf("main: &x = %p, &y = %p\n",&x,&y);
    test_23(x,y);
    test_24(&x,&y);
    unsigned int value = 9876;
    test_25(value);
#endif
    //test_26();
    int n_value = 5;
    int args[5] = {1,2,3,4,5};
    test_27(n_value,args[0],args[1],args[2],args[3],args[4]);
    return 0;
}

