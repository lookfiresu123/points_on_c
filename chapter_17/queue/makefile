objects_queue_static = main.o queue_static.o

main : $(objects_queue_static)
	cc -g -Wall $(objects_queue_static) -o main
main.o : ./queue_static/queue_static.h
	cc -c -g -Wall main.c -o main.o
# queue_static
queue_static.o : ./queue_static/queue_static.h
	cc -c -g -Wall ./queue_static/queue_static.c -o queue_static.o
.PHONY : clean
clean :
	rm main $(objects_queue_static)
