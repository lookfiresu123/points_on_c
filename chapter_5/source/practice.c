#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define byte_size 8
#define bit_size 10
#define bit_16 16

#define int_size 32

#define encode(x) \
		if(x>='a'&&x<='z') \
			x = 'a'+(x-'a'+13)%26; \
		else if(x>='A'&&x<='Z') \
			x = 'A'+(x-'A'+13)%26; \

#define swap(x,y) \
		int temp; \
		temp = x; \
		x = y; \
		y = temp; \


int practice_1(void){
	char str[100];
	fgets(str,100,stdin);
	//int length = strlen(str);
	int i,temp = 'A'-'a';
	for (i = 0; str[i]!='\0'; i++){
		if(str[i]<='Z' && str[i]>='A')
			str[i] -= temp;
	}
	//printf("%d",strlen(str));
	fputs(str,stdout);
	return 0;
}

int practice_2(void){
	char str[100];
	fgets(str,100,stdin);
	int i=0;
	while(str[i]!='\0'){
		encode(str[i])
		i++;
	}
	return 0;
}

unsigned int reverse_bits(unsigned int value_D,unsigned int value_B[]){
	int i=0;
	unsigned int temp[int_size];
	while(temp[i++]=value_D%2, value_D/=2, value_D>0)
		;
	int length = i;
	i = 0;
	while(value_B[int_size-1-i]=temp[i++],i<length)
		;
	for(i=0;i<int_size/2;i++){
		swap(value_B[i],value_B[int_size-1-i])
	}
	return 0;
}

unsigned int *practice_3(unsigned int value){
	unsigned int value_B[int_size];
	int i;
	for(i=0;i<int_size;i++)
		value_B[i] = 0;
	reverse_bits(value,value_B);
	return value_B;
}

void set_bit(char bit_array[],unsigned bit_number){
	if(bit_number <= bit_size)
		bit_array[bit_number] = '1';
	else
		printf("bit_number is overflow\n");
}

void clear_bit(char bit_array[],unsigned bit_number){
	if(bit_number <= bit_size)
		bit_array[bit_number] = '0';
	else
		printf("bit_number is overflow\n");
}

void assign_bit(char bit_array[],unsigned bit_number,int value){
	if(bit_number <= bit_size){
		if(value == 0)
			bit_array[bit_number] = '0';
		else
			bit_array[bit_number] = '1';
	}
	else
		printf("bit_number is overflow\n");
}

bool test_bit(char bit_array[],unsigned bit_number){
	if(bit_number <= bit_size){
		if(bit_array[bit_number] != '0')
			return true;
		else
			return false;
	}
	else{
		printf("bit_number is overflow\n");
		return false;
	}
}


int practice_4(void){
	char bit_array[bit_size] = {'a','b','c','d','e','f','g','h','i','j'};
	unsigned bit_number = 8;
	int value = 1;
	set_bit(bit_array,bit_number);
	clear_bit(bit_array,bit_number);
	assign_bit(bit_array,bit_number,value);
	test_bit(bit_array,bit_number);
	return 0;
}

unsigned int Switch(unsigned int value_D,unsigned int value_B[]){
	int i=0;
	unsigned int temp[int_size];
	while(temp[i++]=value_D%2, value_D/=2, value_D>0)
		;
	int length = i;
	i = 0;
	while(value_B[int_size-1-i]=temp[i++],i<length)
		;
	return 0;
}

void left_move(unsigned int value[],int step){
	int i,j;
	for(i=0;i<step;i++){
		for(j=0;j<int_size-1;j++)
			value[j] = value[j+1];
		value[int_size-1] = 0;
	}
}

int store_bit_field(int original_value,int value_to_store,unsigned starting_bit,unsigned ending_bit){
	int value_stored_int;
	unsigned int value_stored = 0;
	unsigned int value_D_original,value_D_store;
	unsigned int value_B_original[int_size],value_B_store[int_size];
	unsigned int mask_oppsite[int_size],mask[int_size];
	int i;
	for(i=0;i<int_size;i++){
		value_B_original[i] = 0;
		value_B_store[i] = 0;
		mask_oppsite[i] = 1;
		mask[i] = 0;
	}
	value_D_original = (unsigned) original_value;
	value_D_store = (unsigned) value_to_store;
	Switch(value_D_original,value_B_original);
	Switch(value_D_store,value_B_store);
	for(i=starting_bit;i>=ending_bit;i--){
		mask_oppsite[int_size-1-i] = 0;
		mask[int_size-1-i] = 1;
	}
	for(i=0;i<int_size;i++)
		value_B_original[i] &= mask_oppsite[i];

	left_move(value_B_store,ending_bit);//left move
	i=0;
	while(value_B_store[i] &= mask[i],i++,i<int_size)
		;
	i=0;
	while(value_B_store[i] |= value_B_original[i],i++,i<int_size)
		;
	unsigned int mid_result;
	int j;
	for(i=0;i<int_size;i++){
		mid_result = 1;
		for(j=i;j<int_size-1;j++)
			mid_result *= 2;
		value_stored += value_B_store[i] * mid_result;
	}
	value_stored_int = (int) value_stored;
	return value_stored_int;
}

int practice_5(void){
	int original_value,value_to_store;
	int result;
	unsigned starting_bit,ending_bit;
	printf("input original_value\n");
	scanf("%x",&original_value);
	printf("input value_to_store\n");
	scanf("%x",&value_to_store);
	printf("input starting_bit\n");
	scanf("%u",&starting_bit);
	printf("input ending_bit\n");
	scanf("%u",&ending_bit);
	result = store_bit_field(original_value,value_to_store,starting_bit,ending_bit);
	printf("%x\n",result);
	return result;
}

int test_practice(void){
	//practice_1();
	//practice_2();
	//practice_3(25);
	//practice_4();
	practice_5();
	return 0;
}