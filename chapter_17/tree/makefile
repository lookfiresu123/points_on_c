objects_binary_tree = main.o binary_tree.o

main : $(objects_binary_tree)
	cc -g -Wall $(objects_binary_tree) -o main
main.o : binary_tree/binary_tree.h
	cc -c -g -Wall main.c -o main.o
binary_tree.o : binary_tree/binary_tree.h
	cc -c -g -Wall binary_tree/binary_tree.c -o binary_tree.o

.PHONY : clean
clean :
	rm main $(objects_binary_tree)
