#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"../header/practice.h"

#define length_dst 10
// #define length_src 20

int practice_1(){
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

int practice_2(){
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

int practice_3(){
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
	int length_src;
	i = 0;
	while(src[i] != '\0')
		i++;
	length_src = i+1;
	if(n <= length_src){
		for(i=0;i<n;i++)
			dst[i] = src[i];
	}
	else{
		for(i=0;i<length_src;i++)
			dst[i] = src[i];
		while(i < n){
			dst[i] = 0;
			i++;
		}
	}
}

int practice_4(){
	char src[] = "Hello China";
	char dst[length_dst];
	copy_n(dst,src,length_dst);
	return 0;
}

int practice_5(){
    char *input[20];
    char *buf[20];
    int i,k,j;
    for(i=0;i<20;i++)
        buf[i] = (char *)malloc(100*sizeof(char));
    /* 指针变量存放在堆栈中，需要使用malloc函数为该堆栈中的指针变量制定一块文字常量区的地址，并将输入的字符串
     * 放到该区域中，并将该区域的地址存放在该变量所对应的堆栈位置里，free函数用于将该指针指向的文字常量区域中
     * 的字符串清空，但指针变量的值（即该文字常量区域的地址或相应堆栈中的值）不变。*/
    gets(buf[0]);
    input[0] = buf[0];
    i = k = 1;
    while(gets(buf[i]) && *buf[i] != '\0'){   
        if(strcmp(buf[i],buf[i-1])){
            input[k] = buf[i];
            k++;
        }
        //free(buf[i]);
        i++;
    }
    //free(buf[i]);
    for(j=0;j<k;j++)
        puts(input[j]);
    return 0;
}

void test_practice(){
#if 0
	practice_1();
	practice_2();
	practice_3();
	practice_4();
#endif
	practice_5();
}
