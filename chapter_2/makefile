objects = main.o practice_2.o

vpath %.c source
vpath %.h header
#VPATH = source:header

# 指令后面要有tab键，clean用于在命令行中输入make clean，.o文件自动推到同名的.c文件及cc命令
main : $(objects)
	cc -o main $(objects)
main.o : practice_2.h
practice_2.o :
 
.PHONY : clean
clean :
	rm  main $(objects)