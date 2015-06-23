#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SUCCESS 1
#define FAILURE 0
#define LEN 100
#define MAX 1000
#define TRUE 't'
#define FALSE 'f'

/*practice 1*/
int compare(char source_one,char const *chars){
	while(*chars != '\0'){
		if(source_one == *chars++)
			return SUCCESS;
	}
	return FAILURE;
}


char *find_char(char const *source, char const *chars){
	int result;
	if(source == NULL || chars == NULL)
		return NULL;
	else{
		while(*source != '\0'){
			result = compare(*source++,chars);
			if(result == SUCCESS)
				return --source;
		}
		return NULL;
	}
}


int practice_1(){
	char const *source = "hello world";
	char const *chars = "word";
	char *result;
	result = find_char(source,chars);
	printf("%p\n",result);
	return 0;
}

/*practice 2*/
int delete(char *str, char const *substr,char *address,char result[]){
    //不能直接在str中改，因为str存在常量区中，该区域只读，需要用数组（存储在栈中）充当容器存储删除后的字符串，并且该数组需为参数，否则在函数执行完之后，数组所在的栈将会被自动清除
	int len = strlen(substr);
	char *q = address + len;
	char *pos = str;
	char *point = result;
	while(pos < address)
		*point++ = *pos++;
	while(*q != '\0')
		*point++ = *q++;
	*point = '\0';
	return SUCCESS;
}

int del_substr(char *str, char const *substr){
	char *address = strstr(str,substr);
	if(!address)
		return FAILURE;
	else{
		char result[LEN];
		delete(str,substr,address,result);
		printf("%s\n",result);
		return SUCCESS;
	}
}

int practice_2(){
	char *str = "hello world";
	char *substr = "hello";
	del_substr(str,substr);
	return 0;
}

/*practice 3*/
void reserse_string(char *string){
	int len = strlen(string);//do not contain '\0' at the end
	char *first = string,*end = string+len-1;
	char temp;
	while(first <= end){
		temp = *end;
		*end = *first;
		*first = temp;
		*end--;
		*first++;
	}
}

int practice_3(){
	char string[] = "hello world";
	reserse_string(string);
	printf("%s\n",string);
	return 0;
}

/*practice 4*/
void Eratosthenes(char string[],int result[]){//筛选出MAX个质数
	char *p = string;
	int *q = result+1;
	int i = 0, j = 3;
	int m = (int)sqrt(MAX);
	while(j <= m){
		while(i<MAX){
			if(*(p+i) == TRUE && (3+2*i)%j == 0 && (3+2*i)/j != 1)
				*(p+i) = FALSE;
			i++;
		}
		j+=2;
	}
	i = 0;
	while(i<MAX){
		if(*(p+i) == TRUE)
			*q++ = 3+i*2;//奇数变全数
		i++;
	}
	*q = -1;
}


int practice_4(){
	char string[MAX];
	int result[MAX];
	char *p = string;
	int i = 0;
	for(i=0;i<MAX;i++)
		*(p+i) = TRUE;
	*result = 2;
	Eratosthenes(string,result);
	//i = 0;
	int *q = result;
	while(*q != -1)
		printf("%d, ",*q++);	
	printf("\n");
	return 0;
}

int test_practice(){
#if 0
	practice_1();
	practice_2();
	practice_3();
#endif
	practice_4();
	return 0;
}
