CC = gcc 
CFLAGS = -Wall -g #replace -g with -O when not debugging 
DEPS     = lab5.h Makefile 
OBJS     = lab5.o
EXECS    = lab5 

all:	$(EXECS) 

%.o:	%.c $(DEPS) 
	$(CC) $(CFLAGS) -c -o $@ $<  

insertionsort: $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^  

clean: 
	/bin/rm -i *.o $(EXECS) 