target_app = bin/dlinked_demo1
cc = gcc
flags = -std=c99 -Wall -v
deps = dlinked_list.h 
objs = main.o dlinked_list.o


$(target_app): $(objs)
	$(cc) -o $(target_app) $(objs) $(flags)

main.o: main.c $(deps)
	$(cc) -c main.c $(deps)

dlinked_list.o: dlinked_list.c $(deps)
	$(cc) -c dlinked_list.c $(deps)
