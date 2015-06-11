objects = main.o practice.o problem.o

vpath %.c source
vpath %.h header
#VPATH = source:header

# 指令后面要有tab键，clean用于在命令行中输入make clean，.o文件自动推到同名的.c文件及cc命令
main : $(objects)
	cc -g -Wall $(objects) -o main
main.o : practice.h problem.h
	cc -c -g -Wall source/main.c -o main.o
practice.o :
	cc -c -g -Wall source/practice.c -o practice.o
problem.o :
	cc -c -g -Wall source/problem.c -o problem.o
.PHONY : clean
clean :
	rm  main $(objects)