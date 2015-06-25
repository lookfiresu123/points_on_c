#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(char source_one,char const *chars);
char *find_char(char const *source, char const *chars);
int practice_1(void);

void delete(char *str, char const *substr,char *address);
int del_substr(char *str, char const *substr);
int practice_2(void);

void reserse_string(char *string);
int practice_3(void);

void Eratosthenes(char string[],char result[]);
int practice_4(void);

int practice_5(void);

int count_prime(int start, int end);
int practice_6(void);

int test_practice(void);