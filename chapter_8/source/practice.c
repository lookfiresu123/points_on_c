/*
 * created by lookfiresu123 @ 2015/8/4
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"../header/practice.h"

#define DO_PRACTICE_1 0
#define DO_PRACTICE_2 0
#define DO_PRACTICE_3 0
#define DO_PRACTICE_4 1
#define DO_PRACTICE_5 0
#define DO_PRACTICE_6 0
#define DO_PRACTICE_7 0
#define DO_PRACTICE_8 0

int practice_1(void) {
    char char_value[3][6][4][5] = {
        {},//0xxx
        {//1xxx
            {},//10xx
            {//11xx
                {},//110x
                {//111x
                    '\0',' '
                }
                //112x,113x
            },
            {//12xx
                {},//120x
                {},//121x
                {//122x
                    '\0','\0','\0','A'
                },
                {//123x
                    '\0','\0','\0','\0','x'
                }
            },
            {//13xx
                {},//130x
                {},//131x
                {//132x
                    '\0','\0',0xf3
                }
                //133x
            },
            {//14xx
                {},//140x
                {},//141x
                {//142x
                    '\0','\0','\0','\n'
                }
                //143x
            }
            //15xx
        },
        {//2xxx
            {},//20xx
            {//21xx
                {},//210x
                {//211x
                    '\0','\0',0320
                }
                //212x,213x
            },
            {//22xx
                {},//220x
                {//221x
                    '\0','0'
                },
                {//222x
                    '\0','\0','\''
                },
                {//223x
                    '\0','\121'
                }
            },
            {},//23xx
            {//24xx
                {},//240x
                {},//241x
                {},//242x
                {//243x
                   '\0','\0','3',3
                }
            },
            {//25xx
                {},//250x
                {},//251x
                {},//252x
                {//253x
                    '\0','\0','\0','\0',125
                }
            }
        }
    };
    return 0;
}

float single_tax(float income) {
    float salary[5] = { 0,23350,56550,117950,256500 };
    float rate[5] = { 0.15,0.28,0.31,0.36,0.396 };
    float base[5] = { 0,3502.50,12798.50,31832.50,81710.50 };
    int i = 0;
    float tax;
    while(i < 4) {
        if(income > salary[i] && income < salary[i+1]) {
            tax = base[i] + rate[i] * (income - salary[i]);
            return tax;
        }
        i++;
    }
    tax = base[i] + rate[i] * (income - salary[i]);
    return tax;
}

float practice_2(void) {
    float income = 56580;
    float tax = single_tax(income);
    return tax;
}

bool identity_matrix(int matrix[][10]) {
    int i,j;
    for(i = 0 ; i < 10 ; i++) {
        for(j = 0 ; j < 10 ; j++) {
            if(i == j && matrix[i][j] != 1)
                return false;
            else if(i != j && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool practice_3(void) {
    int matrix[10][10] = {
        {1,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,1}
    };
    bool result = identity_matrix(matrix);
    return result;
}

bool identity_matrix_extern(int *pos,struct MATRIX matrix_size) {
    int i,j;
    if(matrix_size.length_x != matrix_size.length_y)
        return false;
    for(i = 0 ; i < matrix_size.length_x ; i++) {
        for(j = 0 ; j < matrix_size.length_y ; j++) {
           if(i == j && *(pos + i * matrix_size.length_y + j) != 1)
               return false;
           else if(i != j && *(pos + i * matrix_size.length_y + j) != 0)
               return false;
        }
    }
    return true;
}

bool practice_4(void) {
    struct MATRIX matrix_size = {
        .length_x = 5,
        .length_y = 5
    };
    int matrix[5][5] = {
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1}
    };
    bool result = identity_matrix_extern(&matrix[0][0],matrix_size);
    return result;
}

int practice_5(void) {
    return 0;
}
int practice_6(void) {
    return 0;
}
int practice_7(void) {
    return 0;
}
int practice_8(void) {
    return 0;
}

int test_practice(void) {
#if DO_PRACTICE_1
    practice_1();
#endif
#if DO_PRACTICE_2
    practice_2();
#endif
#if DO_PRACTICE_3
    practice_3();
#endif
#if DO_PRACTICE_4
    practice_4();
#endif
#if DO_PRACTICE_5
    practice_5();
#endif
#if DO_PRACTICE_6
    practice_6();
#endif
#if DO_PRACTICE_7
    practice_7();
#endif
#if DO_PRACTICE_8
    practice_8();
#endif
    return 0;
}

