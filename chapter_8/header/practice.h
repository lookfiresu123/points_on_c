/*
 * created by lookfiresu123 @ 2015/8/4
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct MATRIX {
    int length_x;//row
    int length_y;//column
};

int practice_1(void);

float single_tax(float income);
float practice_2(void);

bool identity_matrix(int matrix[][10]);
bool practice_3(void);

bool identity_matrix_extern(int *pos,struct MATRIX matrix_size);
bool practice_4(void);

void matrix_mutiply(int *m1,int *m2,int *r,int x,int y,int z);
int practice_5(void);

int practice_6(void);

int practice_7(void);

int practice_8(void);

int test_practice(void);
