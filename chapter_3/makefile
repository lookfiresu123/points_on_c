objects = main.o test_1.o test.o practice.o 

vpath %.c source
vpath %.h header
#VPATH = source:header

# 指令后面要有tab键，clean用于在命令行中输入make clean，.o文件自动推到同名的.c文件及cc命令
main : $(objects)
	cc -g -Wall $(objects) -o main
main.o : test_1.h test.h
	cc -c -g -Wall source/main.c -o main.o
test_1.o :
	cc -c -g -Wall source/test_1.c -o test_1.o
test.o : test.h
	cc -c -g -Wall source/test.c -o test.o
practice.o : practice.h
	cc -c -g -Wall source/practice.c -o practice.o
 
.PHONY : clean
clean :
	rm  main $(objects)
