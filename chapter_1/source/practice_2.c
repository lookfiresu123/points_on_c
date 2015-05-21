#include<stdio.h>
#include<stdlib.h>

#define MAX 30
#define MAX_NUM 10

#if 1
void test_practice_2(){
    char input[MAX_NUM][MAX];
    //char output[MAX+2];
    int i = 0;
    while(i < MAX_NUM && gets(input[i]) != NULL && *input[i] != NULL){
        //puts(strcat(strcat((i+'0')," "),input));
        //printf("%d %s",i,input));
        i++;
    }
    int j = 0;
    for(j=0;j<i;j++)
        printf("%d %s\n",j,input[j]);
}
#endif
