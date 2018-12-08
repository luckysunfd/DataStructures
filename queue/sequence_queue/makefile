target_app = bin/seq_queue_demo1
cc = gcc
flags = -std=c99 -Wall -v
deps = seq_queue.h
objs = main.o seq_queue.o 


$(target_app): $(objs)
	$(cc) -o $(target_app) $(objs) $(flags)

main.o: main.c $(deps)
	$(cc) -c main.c $(deps)

seq_queue.o: seq_queue.c $(deps)
	$(cc) -c seq_queue.c $(deps)

