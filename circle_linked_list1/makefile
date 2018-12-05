target_app = bin/demo
cc = gcc
flags = -std=c99 -Wall -v
deps = clinked_list.h
objs = main.o clinked_list.o 

$(target_app): $(objs)
	$(cc) -o $(target_app) $(objs) $(flags)

main.o: main.c $(deps)
	$(cc) -c main.c $(deps)

clinked_list.o:  clinked_list.c $(deps)
	$(cc) -c clinked_list.c $(deps)
