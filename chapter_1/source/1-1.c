#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000

/*
 * 读取列标号，如果超出规定范围则不予理会
 * */
int read_column_numbers(int column[], int max){
    int num = 0;
    int ch;

    /* 取得列标号，如果所读取的数小于0则停止，结束时column数组中包含-1 num也包含-1的个数 */
    while(num < max && scanf("%d",&column[num]) == 1 && column[num] >= 0)
        num += 1;
    /* 确认已经读取的标号为偶数个，因为他们是以对的形式出现的 */
    if(num % 2 != 0){
        puts("Last column numbers is not paired");
        exit(EXIT_FAILURE);
    }
    /* 丢弃column[num]=-1 */
    while((ch = getchar()) != EOF && ch != '\n')
        ;
    return num;//不包含-1的列标号个数
}

/* 处理输入行，将指定的字符连接在一起，输出行以NUL结尾  */
void rearrange(char *output,char const *input,int n_columns,int const columns[]){
    int col;
    int output_col;
    int len;
    len = strlen(input);//可能大于MAX_INPUT
    output_col = 0;
    /* 处理每对列标号 --> col += 2 */
    for(col = 0;col < n_columns;col += 2){
        int nchars = columns[col + 1] - columns[col] + 1;
        /* 如果输入行结束或输出行数组已满，则任务结束 */
        if(columns[col] >= len || output_col == MAX_INPUT - 1){
            break;
        }
        /* 如果输出行超出最大值，则值输出未超出的部分  */
        if(output_col + nchars > MAX_INPUT -1)
            nchars = MAX_INPUT - output_col - 1;
        strncpy(output + output_col, input + columns[col],nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';//最后以NUL结尾
}

int test_1_1(void){
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns =  read_column_numbers(columns,MAX_COLS);
    while(gets(input) != NULL){
        printf("Original input: %s\n",input);
        rearrange(output,input,n_columns,columns);
        printf("rearrange lines: %s\n",output);
    }
    return EXIT_SUCCESS;
}
