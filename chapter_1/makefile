objects = main.o 1-1.o practice_1.o practice_2.o practice_3.o practice_4.o

vpath %.c source
vpath %.h header
#VPATH = source:header

# 指令后面要有tab键，clean用于在命令行中输入make clean，.o文件自动推到同名的.c文件及cc命令
main : $(objects)
	cc -g -Wall $(objects) -o main
main.o : 1-1.h practice_1.h practice_2.h practice_3.h practice_4.h
	cc -c -g -Wall source/main.c -o main.o
1-1.o : 
	cc -c -g -Wall source/1-1.c -o 1-1.o
practice_1.o :
	cc -c -g -Wall source/practice_1.c -o practice_1.o
practice_2.o :
	cc -c -g -Wall source/practice_2.c -o practice_2.o
practice_3.o :
	cc -c -g -Wall source/practice_3.c -o practice_3.o
practice_4.o :
	cc -c -g -Wall source/practice_4.c -o practice_4.o
 
.PHONY : clean
clean :
	rm  main $(objects)
