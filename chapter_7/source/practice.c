#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

/*
 * 厄密多项式的计算函数
 */
int hermite(int n,int x){
    if(n <= 0)
        return 1;
    else if(n == 1)
        return 2*x;
    else
        return 2*x*hermite(n-1,x) - 2*(n-1)*hermite(n-2,x);
}

int practice_1(void){
    int n = 3,x = 2;
    int result = hermite(n,x);
    return result;
}

/*
 * 求最大公约数
 */
int gcd(int m,int n){
    int r = m % n;
    if(r == 0)
        return n;
    else
        return gcd(n,r);
}

int practice_2(void){
    int m = 100,n = 30;
    int result = gcd(m,n);
    return result;
}

/*
 * 将字符数字转换为整型
 */
int ascii_to_integer(char *string){
    char *p = string;
    int result = 0;
    while(*p != '\0'){
        if(*p <= '9' && *p >= '0')
            result = result*10 + (*p-'0');
        else
            return 0;
        p++;
    }
    return result;
}

int practice_3(void){
    char *string = (char*)malloc(100*sizeof(char));
    printf("input a string\n");
    gets(string);
    int result = ascii_to_integer(string);
    free(string);
    return result;
}

int max_list(int first,...){
    int max = first;
    int temp;
    va_list var_arg;
    //初始化
    va_start(var_arg,first);
    while(temp = va_arg(var_arg,int),temp >= 0){
        if(temp > max)
            max = temp;
    }
    return max;
}

int practice_4(void){
    int max = max_list(5,7,1,3,9,-1);
    return max;
}

void print_integer(int integer){
    int temp;
    if((temp = integer/10) != 0)
        print_integer(temp);
    putchar('0'+integer%10);
}

int practice_5(void){
    int a = 1234;
    print_integer(a);
    return 0 ;
}


void test_practice(void){
#if 0
    practice_1();
    practice_2();
    practice_3();
    practice_4();
#endif
    practice_5();
}
