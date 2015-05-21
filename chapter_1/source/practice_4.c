#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
#define NUM 10

void test_practice_4(){
	char str[NUM][MAX];
	int result;
	int i=0;
	int len_previous = 0;
	int len_after;
	while(gets(str[i])!=NULL && *(str[i]) != NULL){
		len_after = strlen(str[i]);
		//printf("%d\n",len_after);
		if(len_after > len_previous){
			len_previous = len_after;
			result = i;
			//printf("%d\n",result);
		}
		i++;
	}
	printf("%s\n",str[result]);
}