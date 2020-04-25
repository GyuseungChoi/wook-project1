CC = gcc
CFLAGS = -g -Wall
TARGETS = main
OBJECTS = main.c consume.o
.SUFFIXES = .c .o
main.exe_debug : $(TARGETS)
main.exe_debug : DEBUGOPTION = -DDEBUG

$(TARGETS) : $(OBJECTS)
	$(CC) $(CFLAGS) $(DEBUGOPTION) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) $(DEBUGOPTION) -c $<

clean :
	rm *.o $(TARGETS)
