target_app = demo
cc = gcc
flags = -std=c99 -Wall -v
deps = clinked_list.h
objs = main.o clinked_list.o 

$(target_app): $(objs)
	$(cc) -o $(target_app) $(objs) $(flags)

main.o: $(deps) main.c
	$(cc) -c main.c $(deps)

clinked_list.o: $(deps) clinked_list.c
	$(cc) -c clinked_list.c $(deps)
