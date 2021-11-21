
WARNS = -Wall -Wpedantic
FLAGS = -ansi

main: stack.o main.c rpc.o
	gcc $(WARNS) $(FLAGS) -o main main.c stack.o rpc.o

stack.o: stack.c stack.h
	gcc $(FLAGS) $(WARNS) -c stack.c
	ctags -R .

rpc.o: rpc.c rpc.h
	gcc $(FLAGS) $(WARNS) -c rpc.c
