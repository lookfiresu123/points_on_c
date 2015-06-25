#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"../header/practice.h"

#define length_dst 10
#define length_src 10

int practice_1(void){
	double n,new,old;
	printf("input a num\n");
	scanf("%lf",&n);
	new = 1;
	do{
		old = new;
		new = (new + n/new)/2;
	}while(old != new);
	printf("%lf\n",new);
	return 0;
}

int Sqrt(int parameter){
	int i=1;
	while(i*i <= parameter)
		i++;
	return i-1;
}

int practice_2(void){
	int i,k,j;
	for(i=1;i<=100;i++){
		k = Sqrt(i);
		for(j=2;j<=k;j++){
			if(i%j == 0)
				goto out;
		}
		printf("%d ",i);
out:
		;
	}
	printf("\n");
	return 0;
}

int practice_3(void){
	int line[3];
	printf("input three num\n");
	int i;
	for(i=0;i<3;i++){
		scanf("%d",&line[i]);
	}
    //判断是否是三角形
    if(line[0]+line[1]>line[2] && line[0]+line[2]>line[1] && line[1]+line[2]>line[0] \
    && line[0]>0 && line[1]>0 && line[2]>0){
        //是三角形      
        if(line[0] != line[1] && line[0] != line[2] && line[1] != line[2] )
            printf("不等边三角形\n");
        else if(line[0] == line[1] && line[0] == line[2])
            printf("等边三角形\n");
        else
            printf("等腰三角形\n");
    }
    //不是三角形
    else	
    	printf("不是三角形\n");
	return 0;
}

void copy_n(char dst[],char src[],int n){
	int i = 0;
	int Length_src;
	i = 0;
	while(src[i] != '\0')
		i++;
    Length_src = i+1;
	if(n <= Length_src){
		for(i=0;i<n;i++)
			dst[i] = src[i];
	}
	else{
		for(i=0;i<Length_src;i++)
			dst[i] = src[i];
		while(i < n){
			dst[i] = 0;
			i++;
		}
	}
}

int practice_4(void){
	char src[] = "Hello China";
	char dst[length_dst];
	copy_n(dst,src,length_dst);
	return 0;
}

int practice_5(void){
    char *input[20];
    char *buf[20];
    int i,k,j;
    for(i=0;i<20;i++)
        buf[i] = (char *)malloc(100*sizeof(char));
    /* 指针变量存放在堆栈中，需要使用malloc函数为该堆栈中的指针变量制定一块文字常量区的地址，并将输入的字符串
     * 放到该区域中，并将该区域的地址存放在该变量所对应的堆栈位置里，free函数用于将该指针指向的文字常量区域中
     * 的字符串清空，但指针变量的值（即该文字常量区域的地址或相应堆栈中的值）不变。*/
    fgets(buf[0],sizeof(buf[0]),stdin);
    input[0] = buf[0];
    i = k = 1;
    while(fgets(buf[i],sizeof(buf[i]),stdin) && *buf[i] != '\0'){   
        if(strcmp(buf[i],buf[i-1])){
            input[k] = buf[i];
            k++;
        }
        //free(buf[i]);
        i++;
    }
    //free(buf[i]);
    for(j=0;j<k;j++)
        fputs(input[j],stdin);//fputs(input[j]) is also fine
    for(i=0;i<20;i++)
        free(buf[i]);
    return 0;
}

int substr(char dst[],char src[],int start,int len){
    int ret;
    if(start < 0 || len < 0 || start > length_src-1){
        dst[0] = '\0';
        ret = 0;
    }
    else{
        int i;
        for(i=0;i<len;i++)
            dst[i] = src[start+i]; 
        ret = len;
        dst[len] = '\0';
    }
    return ret;
}

int practice_6(void){
    char dst[length_dst],src[length_src];
    int start,len;
    int i=0;
#if 0
/*  the first method  */
    printf("input start\n");
    scanf("%d",&start);
    printf("\n");
    printf("input len\n");
    scanf("%d",&len);//输入一个阿拉伯数字后要用EOF（ctrl+d）结尾，不能用换行符或其他字符，因为在后面的scanf-->%c中会从len的stdin后扫描第一个匹配格式的字符，若不用EOF结尾，则该非EOF的结尾字符会成为后面的第一个%c
    printf("\n");
    printf("input src\n");
    while(i<10){
        scanf("%c",&src[i]);//scanf --> %c 要特别注意
        i++;
    }
    printf("\n");
    i=0;
    while(i<10){
        printf("%c",src[i]);
        i++;
    }
    printf("\n");
#endif
    printf("input src about %d numbers\n",length_src);
    while(i<length_src){
        scanf("%c",&src[i]);
        i++;
    }
    printf("input start\n");
    scanf("%d",&start);
    printf("input len\n");
    scanf("%d",&len);
    substr(dst,src,start,len);
    puts(dst);
    return 0;    
}

void delete(char string[],int pos){
    int i = pos;
    while(string[i] != '\0'){
        string[i] = string[i+1];
        i++;
    }
}

void deblank(char string[]){
    int i=0;
    while(string[i+1] != '\0'){
        if(string[i] == ' ' && string[i+1] == ' ')
            delete(string,i+1);
        i++;
    }
}

int practice_7(void){
    char string[] = "hello  world   !";
    deblank(string);
    return 0;
}

void test_practice(void){
#if 0
	practice_1();
	practice_2();
	practice_3();
	practice_4();
	practice_5();
    practice_6();
#endif
    practice_7();
}
