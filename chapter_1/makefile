objects = main.o 1-1.o

vpath %.c source
vpath %.h header
#VPATH = source:header

# 指令后面要有tab键，clean用于在命令行中输入make clean，.o文件自动推到同名的.c文件及cc命令
main : $(objects)
	cc -o main $(objects)
main.o : 1-1.h
1-1.o : 
 
.PHONY : clean
clean :
	rm  main $(objects)