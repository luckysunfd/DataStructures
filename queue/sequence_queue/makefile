target_app = seq_queue_demo
cc = gcc
deps = seq_queue.h
flags = -std=c99 -Wall -v
objs = seq_queue.o main.o


$(target_app): $(objs)
	$(cc) -o $(target_app) $(objs) $(flags) 

seq_queue.o: $(deps) seq_queue.c 
	$(cc) -c seq_queue.c $(deps)

main.o: $(deps) main.c 
	$(cc) -c main.c $(deps) 
