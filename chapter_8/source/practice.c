/*
 * created by lookfiresu123 @ 2015/8/4
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdarg.h>
#include"../header/practice.h"

#define DO_PRACTICE_1 0
#define DO_PRACTICE_2 0
#define DO_PRACTICE_3 0
#define DO_PRACTICE_4 0
#define DO_PRACTICE_5 0
#define DO_PRACTICE_6 0
#define DO_PRACTICE_7 0
#define DO_PRACTICE_8 1

//#define NUMS_QUEEN 8

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

void matrix_mutiply(int *m1,int *m2,int *r,int x,int y,int z) {
    int i,j,k;
    int temp;
    for(i = 0 ; i < x ; i++) {
        for(k = 0 ; k < z ; k++) {
            temp = 0;
            for(j = 0 ; j < y ; j++) {
                temp += *(m1 + i * y + j) * *(m2 + j * z + k);
            }
            *(r + i * z + k) = temp;
        }
    }
}

int practice_5(void) {
    struct MATRIX matrix_A_size = {
        .length_x = 3,
        .length_y = 2
    };
    struct MATRIX matrix_B_size = {
        .length_x = 2,
        .length_y = 4
    };
    struct MATRIX matrix_C_size = {
        .length_x = matrix_A_size.length_x,
        .length_y = matrix_B_size.length_y
    };
    int matrix_A[3][2] = {
        {2,-6},
        {3,5},
        {1,-1}
    };
    int matrix_B[2][4] = {
        {4,-2,-4,-5},
        {-7,-3,6,7}
    };
    int matrix_C[3][4];
    matrix_mutiply(&matrix_A[0][0],&matrix_B[0][0],&matrix_C[0][0],
                matrix_A_size.length_x,matrix_B_size.length_x,matrix_B_size.length_y);
    return 0;
}
/*
 * @arrayinfo[]: contains nums, low and high
 * @...: the sum is the values of index
 */
int array_offset(int arrayinfo[], ...) {
    va_list var_arg;
    va_start(var_arg, arrayinfo);
    /* Determine an array dimension is between 1 and 10 */
    int dimension = arrayinfo[0];
    if(dimension > 10 || dimension < 1)
        return -1;
    else{
        /* store the index to low array and high array */
        int *low_index = (int *)malloc(dimension * sizeof(int));
        int *high_index = (int *)malloc(dimension * sizeof(int));
        int i,j;
        for(i = 0 , j = 1 ; i < dimension ; i++) {
            low_index[i] = arrayinfo[j++];
            high_index[i] = arrayinfo[j++];
        }
        int *index = (int *)malloc(dimension * sizeof(int));
        /* determine whether the index overflow  */
        for(i = 0 ; i < dimension ; i++) {
            index[i] = va_arg(var_arg, int);
            if(index[i] < low_index[i] || index[i] > high_index[i])
                return -1;
        }
        va_end(var_arg);
        /* calculate the loc */
        int loc = 0;
        for(i = 0 ; i < dimension ; i++) {
            loc = loc * (high_index[i] - low_index[i] + 1) + index[i] -low_index[i];
        }
        return loc;
    }
}

int practice_6(void) {
    int arrayinfo[] = {3,4,6,1,5,-3,3};
    int loc = array_offset(arrayinfo,6,3,1);
    return loc;
}

int array_offset2(int arrayinfo[], ...) {
    va_list var_arg;
    va_start(var_arg, arrayinfo);
    /* Determine an array dimension is between 1 and 10 */
    int dimension = arrayinfo[0];
    if(dimension > 10 || dimension < 1)
        return -1;
    else{
        /* store the index to low array and high array */
        int *low_index = (int *)malloc(dimension * sizeof(int));
        int *high_index = (int *)malloc(dimension * sizeof(int));
        int i,j;
        for(i = 0 , j = 1 ; i < dimension ; i++) {
            low_index[i] = arrayinfo[j++];
            high_index[i] = arrayinfo[j++];
        }
        int *index = (int *)malloc(dimension * sizeof(int));
        /* determine whether the index overflow  */
        for(i = 0 ; i < dimension ; i++) {
            index[i] = va_arg(var_arg, int);
            if(index[i] < low_index[i] || index[i] > high_index[i])
                return -1;
        }
        va_end(var_arg);
        /* calculate the loc */
        int loc = 0;
        for(i = dimension - 1 ; i >= 0 ; i--) {
            loc = loc * (high_index[i] - low_index[i] + 1) + index[i] -low_index[i];
        }
        return loc;
    }
}

int practice_7(void) {
    int arrayinfo[] = {3,4,6,1,5,-3,3};
    int loc = array_offset2(arrayinfo,6,5,3);
    return loc;
}

bool is_valid_row(int panic[][NUMS_QUEEN],int index_row,int index_column) {
    int i;
    for(i = 0 ; i < NUMS_QUEEN ; i++) {
        if(panic[index_row][i] == 1 && i != index_column)
            return false;
    }
    return true;
}

bool is_valid_column(int panic[][NUMS_QUEEN],int index_row,int index_column) {
    int i;
    for(i = 0 ; i < NUMS_QUEEN ; i++) {
        if(panic[i][index_column] == 1 && i != index_row)
            return false;
    }
    return true;
}

bool is_valid_oblique_left(int panic[][NUMS_QUEEN],int index_row,int index_column) {
    int current_index_row = index_row;
    int current_index_column = index_column;
    while(--current_index_row >= 0 && --current_index_column >= 0) {
        if(panic[current_index_row][current_index_column] == 1)
            return false;
    }
    current_index_row = index_row;
    current_index_column = index_column;
    while(++current_index_row < NUMS_QUEEN && ++current_index_column < NUMS_QUEEN) {
        if(panic[current_index_row][current_index_column] == 1)
            return false;
    }
    return true;
}

bool is_valid_oblique_right(int panic[][NUMS_QUEEN],int index_row,int index_column) {
    int current_index_row = index_row;
    int current_index_column = index_column;
    while(++current_index_row < NUMS_QUEEN && --current_index_column >= 0) {
        if(panic[current_index_row][current_index_column] == 1)
            return false;
    }
    current_index_row = index_row;
    current_index_column = index_column;
    while(--current_index_row >= 0 && ++current_index_column < NUMS_QUEEN) {
        if(panic[current_index_row][current_index_column] == 1)
            return false;
    }
    return true;
}

bool is_valid(int panic[][NUMS_QUEEN],int index_row,int index_column) {
    if( is_valid_row(panic,index_row,index_column) &&
        is_valid_column(panic,index_row,index_column) &&
        is_valid_oblique_left(panic,index_row,index_column) &&
        is_valid_oblique_right(panic,index_row,index_column) ) {
        int current_index_row;
        int current_index_column;
        if((current_index_row = index_row + 1) < NUMS_QUEEN) {
            current_index_column = 0;
            while(current_index_column < NUMS_QUEEN) {
                panic[current_index_row][current_index_column] = 1;
                if(is_valid(panic,current_index_row,current_index_column)) {
                    //panic[current_index_row][current_index_column] = 0;
                    return true;
                }
                else
                    panic[current_index_row][current_index_column] = 0;
                current_index_column++;
            }
            return false;
        }
        else
            return true;
    }
    return false;
}

void print_out(int panic[][NUMS_QUEEN]) {
    int i,j;
    for(i = 0 ; i < NUMS_QUEEN ; i++) {
        for(j = 0 ; j < NUMS_QUEEN ; j++) {
            printf("%d ", panic[i][j]);
        }
        printf("\n");
    }
}

void initialize(int panic[][NUMS_QUEEN]) {
    int i,j;
    for(i = 0 ; i < NUMS_QUEEN ; i++)
        for(j = 0 ; j < NUMS_QUEEN ; j++)
            panic[i][j] = 0;
}

/*
 * determine where one queen should be put
 */
void make_result(int panic[][NUMS_QUEEN],int index_row,int index_column) {
    int current_index_column = index_column;
    while(current_index_column < NUMS_QUEEN) {
        panic[index_row][current_index_column] = 1;
        if(is_valid(panic,index_row,current_index_column)) {
            print_out(panic);
            printf("<------------------------------------------->\n");
        }
        initialize(panic);
        current_index_column++;
    }
}

int practice_8(void) {
    int panic[NUMS_QUEEN][NUMS_QUEEN];
    int i,j;
    for(i = 0 ; i < NUMS_QUEEN ; i++)
        for(j = 0 ; j < NUMS_QUEEN ; j++)
            panic[i][j] = 0;
    int index_row = 0;
    int index_column = 0;
    make_result(panic,index_row,index_column);
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

