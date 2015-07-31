/*
 * this test file is prepared for charpter 8
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define faster_array 1
#define faster_point -1
#define same_fast 0
#define SIZE 10000

#define DO_COMPARE_ARRAY_POINT 0
#define DO_DISASEMBLE_SWITCH 0
#define DO_DOUBLE_ARRAY 1

int compare_array_point(int x[],int y[],int numSize){
    int result;
    int *p_x = x;
    int *p_y = y;
    int i;
    clock_t start_array,end_array,time_array;
    clock_t start_point,end_point,time_point;
    start_array = clock();
    for(i = 0 ; i < numSize ; i++)
        x[i] = y[i];//lea 0x0(,%rax,4) : 0x0 + %rax * 4
    end_array = clock();
    time_array = end_array - start_array;
    start_point = clock();
    for(i = 0 ; i < numSize ; i++)
        *p_x++ = *p_y++;//lea 0x4(%rax),%rdx ; mov %rdx %rax
    end_point = clock();
    time_point = end_point - start_point;
    if(time_array < time_point)
        result = faster_array;
    else if(time_array > time_point)
        result = faster_point;
    else
        result = same_fast;
    return result;
}

/* have no "break"
   0x0000000000400639 <+0>:	push   %rbp
   0x000000000040063a <+1>:	mov    %rsp,%rbp
   0x000000000040063d <+4>:	movl   $0x1,-0x4(%rbp)
   0x0000000000400644 <+11>:	mov    -0x4(%rbp),%eax
   0x0000000000400647 <+14>:	test   %eax,%eax
   0x0000000000400649 <+16>:	je     0x400652 <disasemble_switch+25>
   0x000000000040064b <+18>:	cmp    $0x1,%eax
   0x000000000040064e <+21>:	je     0x400656 <disasemble_switch+29>
   0x0000000000400650 <+23>:	jmp    0x40065a <disasemble_switch+33>
   0x0000000000400652 <+25>:	addl   $0x1,-0x4(%rbp)
   0x0000000000400656 <+29>:	addl   $0x2,-0x4(%rbp)
   0x000000000040065a <+33>:	addl   $0x3,-0x4(%rbp)
   0x000000000040065e <+37>:	pop    %rbp
   0x000000000040065f <+38>:	retq
*/

/* have "break"
   0x0000000000400639 <+0>:	push   %rbp
   0x000000000040063a <+1>:	mov    %rsp,%rbp
   0x000000000040063d <+4>:	movl   $0x1,-0x4(%rbp)
   0x0000000000400644 <+11>:	mov    -0x4(%rbp),%eax
   0x0000000000400647 <+14>:	test   %eax,%eax
   0x0000000000400649 <+16>:	je     0x400652 <disasemble_switch+25>
   0x000000000040064b <+18>:	cmp    $0x1,%eax
   0x000000000040064e <+21>:	je     0x400658 <disasemble_switch+31>
   0x0000000000400650 <+23>:	jmp    0x40065e <disasemble_switch+37>
   0x0000000000400652 <+25>:	addl   $0x1,-0x4(%rbp)
   0x0000000000400656 <+29>:	jmp    0x400663 <disasemble_switch+42>
   0x0000000000400658 <+31>:	addl   $0x2,-0x4(%rbp)
   0x000000000040065c <+35>:	jmp    0x400663 <disasemble_switch+42>
   0x000000000040065e <+37>:	addl   $0x3,-0x4(%rbp)
   0x0000000000400662 <+41>:	nop
   0x0000000000400663 <+42>:	pop    %rbp
   0x0000000000400664 <+43>:	retq
*/

/* "case" looks like "goto" this line */
void disasemble_switch(void){
    int n = 1;
    switch(n){
    case 0:
        n++;
        break;
    case 1:
        n += 2;
        break;
    default:
        n += 3;
        break;
    }
}

void double_array(){
    char test[2][3][4];
    int i,j,k;
    //for(i = 0 ; i < 2 ; i++)
      //  for(j = 0 ; j < 5 ; j++)
        //    test[i][j] = 'a';// *(i * 5 + j + test) = 'a'
    for(i = 0 ; i < 2 ; i++)
        for(j = 0 ; j < 3 ; j++)
            for(k = 0 ; k < 4 ; k++)
                test[i][j][k] = 'a';// *((i * 3 + j) * 4 + k + test) = 'a'
    //the same as *((i * length_j + j) * length_k + k + address_of_test) = 'a'
    i = 1;
    j = 1;
    k = 1;
    test[i][j][k] = 'b';
}

int main(void){
#if DO_COMPARE_ARRAY_POINT
    int x[SIZE],y[SIZE];
    int i;
    int j = 0;
    for(i = 0 ; i < SIZE ; i++)
        x[i] = i;
    for(i = SIZE-1 ; i >= 0 ; i--)
        y[i] = j++;
    int numSize = SIZE;
    compare_array_point(x,y,numSize);//the answer is that point is faster than array
#endif
#if DO_DISASEMBLE_SWITCH
    disasemble_switch();
#endif
#if DO_DOUBLE_ARRAY
    double_array();
#endif
    return 0;
}

