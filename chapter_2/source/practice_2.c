#include<stdio.h>

void test_practice_2(){
	int ch;
	int braces = 0;
	while((ch = getchar()) != EOF){
		/*
         * '{'合法
         * */
        if(ch == '{')
			braces++;
        /* 
         * '}'当前面有'{'时合法，否则不合法
         * */
		else if(ch == '}'){
			if(braces == 0){
				printf("error\n");
				break;
			}
			else if(braces > 0)
				braces--;
		}
	}
	if(braces == 0)
		printf("success\n");
	else
		printf("failure\n");
}
