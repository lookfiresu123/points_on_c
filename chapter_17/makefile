objects_stack = main.o stack.o

main : $(objects_stack)
	cc -g -Wall $(objects_stack) -o main
main.o : stack.h
	cc -c -g -Wall main.c -o main.o
stack.o : stack.h
	cc -c -g -Wall stack.c -o stack.o
.PHONY : clean
clean :
	rm main $(objects_stack)
