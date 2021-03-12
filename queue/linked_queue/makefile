target_app = linked_queue_demo
cc = gcc
flags = -std=c99 -Wall -v
deps = linked_queue.h
objs = linked_queue.o main.o

$(target_app): $(objs)
	$(cc) -o $(target_app) $(objs) $(flags)

main.o: main.c $(deps)
	$(cc) -c main.c $(deps)

linked_queue.o: linked_queue.c $(deps)
	$(cc) -c linked_queue.c $(deps)
