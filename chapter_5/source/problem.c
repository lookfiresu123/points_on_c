#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


int func(void){
	static int counter = 1;//存储于静态存储区
	//printf("&counter = %p, counter = %d\n",&counter,counter);
	return ++counter;
}

int problem_2(void){
	int answer;
	answer = func() - func() * func();//func函数从左到右以此执行，然后将三个结果按表达式计算，每个func函数的counter都指向同一个静态存储区的同一位置，调用完后更新(update)回去。
	printf("%d\n",answer);
	return 0;
}

int if_else(void){
	int a = 0, b =0, c = 0, i;
	if(a > 3)
		i = b + 1;
	else
		i = c * 5;
	return 0;
}

int expression(void){
	int a = 0, b =0, c = 0, i;
	i = a>3 ? b+1 : c*5;
	return 0;
}

int problem_4(void){
	if_else();
	expression();
	return 0;
}

bool problem_5(int year){
	bool leap_year;
	leap_year = ((year%4==0 && year%100!=0) || year%400==0) ? true : false;
	return leap_year;
}

int f1(int x){
	return 100-x; 
}

int f2(int x){
	return 100-2*x;
}

int f3(int x,int y){
	return x+y;
}

int problem_8(int x){
#if 0
	int a = f1(x);
	int b = f2(x+a);
	int c;
	for(c = f3(a,b);c>0;c = f3(a,b)){
		a = f1(++x);
		b = f2(x+a);
	}
#endif
	int a,c,y = x-1;
	while(a=f1(++y),c=f3(a,f2(y+a)),c>0)
		;
	printf("%d\n",c);
	return c;
}

int problem_9(int array[],int array_size){
	int non_zero = 0,i = 0;
	while(non_zero ^= array[i++],i < array_size)
		;
	if (!non_zero)
		puts("values are all zero");//fputs("values are all zero\n",stdout);
	else
		puts("there are nonzero values");//fputs("there are nonzero values\n",stdout);
	return 0;
}




int test_problem(void){
	//problem_2();
	//problem_4();
	//problem_5(2014);
	//problem_8(20);
	// int array[10] = {0,0,0,0,0,0,0,0,8,0}, array_size = 10;
	// problem_9(array,array_size);
	return 0;
}
