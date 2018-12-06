target_app = bin/demo
cc = gcc
flags = -std=c99 -Wall -v
deps = seq_stack.h
objs = main.o seq_stack.o 


$(target_app): $(objs)
	$(cc) -o $(target_app) $(objs) $(flags)

main.o: main.c $(deps)
	$(cc) -c main.c $(deps)

seq_stack.o: seq_stack.c $(deps)
	$(cc) -c seq_stack.c $(deps)