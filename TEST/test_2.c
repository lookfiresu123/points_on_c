#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* 
 * 测试malloc函数和free函数在内存中的表现
 * */
int test_9(void){
	int *ptr1 = (int *)malloc(10 * sizeof(int));//malloc函数在堆空间中找到一个空闲的堆，并将该空闲堆的首地址赋值给ptr1，指针变量ptr1的值存储在栈中
	int *p = ptr1;
	int i;
	for(i=0;i<10;p++,i++)//对于指针变量p来说，p+=1、p++、p=p+1表示p=p+sizof(*p),disasambler:addq   $0x4,-0x10(%rbp)
		*p = i;
	free(ptr1);//只是将该块堆的struct mem_control_block->is_available赋值为1，表示该堆可用，指针变量ptr1的值不变，而该堆中原先的值可能改变，也可能不变。
	//int *ptr2 = ptr1;
	//ptr2 = (int *)malloc(10 * sizeof(int));
	//ptr1 = (int *)malloc(10 * sizeof(int));
	return 0;
}

int fx(int *a){
	*a = *a + 1;
	return 0;
}

int test_10(void){
	int a = 0;
	int array[10] = {0,0,0,0,0,0,0,0,0,0};
	array[fx(&a)] ++; // execute fx once
	array[fx(&a)] += 1; //execute fx once
	array[fx(&a)] = array[fx(&a)]+1; //execute fx twice
	//fx(&a) ++; //函数fx的返回值是一个整型常量，因此不能作为左操作数
	return 0;
}

int test_11(void){
#if 0
	int a = 1,b = 2;
	int c = a++; // a-->%eax, a++, %eax-->c <==> int c = a; a++
	int d = ++b; // b++, b-->%eax, %eax-->d <==> b++; int d = b;
#endif
	// int a = 0;
	// a++ = 10; //mistake, because a++ itself is not a variable
	// ++a = 10; //mistake, because ++a itself is not a variable
	return 0;
}

int test_12(void){
	int a = 1,b = 0,c;
	(a==1) ? (b++) : (b--);
	c = (b==0) ? (a+b) : (a-b);
	return 0;
}

int output(char str[],int length){
	int i=0;
	while(fputc(str[i],stdout),i++,i<length)//整个表达式的真假只由最后一个逗号右边的表达式的真假决定，但前面的所有表达式在程序中都被依次且正确的执行。（相当于do{...}while;）
		;
	printf("\n");
	return 0;
}

int test_13(void){
	char str[] = "hello world";
	int i=0;
	while(str[i++]!='\0' && fputc(str[i-1],stdout))//当'&&'符号左边为假时，不用计算右边的真假，直接判断整个表达式为假即可；符号'||'以此类推。
		;
	printf("\n\n");
	int length = strlen(str);
	while(output(str,length),length--,length>0)//整个表达式的真假只由最后一个逗号右边的表达式的真假决定，但前面的所有表达式在程序中都被依次且正确的执行。（相当于do{...}while;）
		;
	printf("\n");
	return 0;
}

int test_14(void){
#if 0
	char str1[100];
	char str2[100];
	fputs("hello world",stdout);//去掉'\0'，但后面不加换行符，之后输出
	puts("hello world");//将'\0'换成'\n'，之后输出
	fgets(str1,100,stdin);//对最后的'\0'不做任何操作
	gets(str2);//讲最后的'\n'换成'\0'
	str1[0] = '\0';
#endif
	char str3[] = "hello world\000you";
	int length_string = strlen(str3);//从字符串头字符开始，直到遇到第一个'\0'（即八进制'\000'）结束，计算这段子字符串的长度（不包括'\0'），即为该字符串的strlen长度（除了关心空间外，还关心内容）
	int length_sizeof = sizeof(str3);//从字符串头字符开始，直到遇到最后一个'\0'（即八进制'\000'）结束，计算这段字符串的长度（包括所有的'\0'），即为该字符串的空间大小（只关心空间，不关心内容）
	return 0;
}
