objects_problem = main.o problem.o
objects_practice = main.o practice.o

vpath %.c source
vpath %.h header

main : $(objects_problem)
	gcc -g -Wall $(objects_problem) -o main
main.o : problem.h practice.h
	gcc -c -g -Wall source/main.c -o main.o
# problem.c
problem.o :
	gcc -c -g -Wall source/problem.c -o problem.o
# practice.c
# practice.o : practice.h
# 	gcc -c -g -Wall source/practice.c -o practice.o
.PHONY : clean
clean :
	rm main $(objects_problem)
