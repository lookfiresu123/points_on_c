#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30

void test_practice_3(){
	char checksum = -1;
	char str[MAX];
	int i;
	gets(str);//会把换行符'\n'给丢弃，因此需要在最后对checksum加上'\n'
	int len = strlen(str);
	if(len <= MAX){
		for(i=0;i<len;i++)
			checksum += str[i];
		puts(str);
		printf("%d\n",checksum+'\n');
	}
	else
		exit(EXIT_FAILURE);
}
