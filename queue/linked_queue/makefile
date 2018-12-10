target_app = bin/demo1
cc = gcc
flags = -std=c99 -Wall -v
deps = linked_queue.h
objs = main.o linked_queue.o 


$(target_app): $(objs)
	$(cc) -o $(target_app) $(objs) $(flags)

main.o: main.c $(deps)
	$(cc) -c main.c $(deps)

linked_queue.o: linked_queue.c $(deps)
	$(cc) -c linked_queue.c $(deps)