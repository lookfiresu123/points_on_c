objects_stack_static = main.o stack_static.o
objects_stack_dynamic = main.o stack_dynamic.o
objects_stack_list = main.o stack_list.o

main : $(objects_stack_list)
	cc -g -Wall $(objects_stack_list) -o main
main.o : ./stack_static/stack_static.h ./stack_dynamic/stack_dynamic.h ./stack_list/stack_list.h
	cc -c -g -Wall main.c -o main.o 
# stack_static
# stack_static.o : ./stack_static/stack_static.h
# 	cc -c -g -Wall ./stack_static/stack_static.c -o stack_static.o
# stack_static
# stack_dynamic.o : ./stack_dynamic/stack_dynamic.h
# 	cc -c -g -Wall ./stack_dynamic/stack_dynamic.c -o stack_dynamic.o
# stack_list
stack_list.o : ./stack_list//stack_list.h
	cc -c -g -Wall ./stack_list/stack_list.c -o stack_list.o
.PHONY : clean
clean :
	rm main $(objects_stack_list)
