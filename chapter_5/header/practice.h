#include<stdio.h>
#include<stdlib.h>

int practice_1(void);

int practice_2(void);

unsigned int reverse_bits(unsigned int value_D,unsigned int value_B[]);
unsigned int *practice_3(unsigned int value);

void set_bit(char bit_array[],unsigned bit_number);
void clear_bit(char bit_array[],unsigned bit_number);
void assign_bit(char bit_array[],unsigned bit_number,int value);
bool test_bit(char bit_array[],unsigned bit_number);
int practice_4();

unsigned int Switch(unsigned int value_D,unsigned int value_B[]);
void left_move(unsigned int value[],int step);
int store_bit_field(int original_value,int value_to_store,unsigned starting_bit,unsigned ending_bit);
int practice_5(void);

int test_practice(void);