CC = gcc

CFLAGS = -Wall -g

DEPS	= Makefile
OBJS	= project1.o
EXECS	= find

all:	$(EXECS)

%.o:	%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

writestat: $(OBJS) writestat.o
	$(CC) $(CFLAGS) -o $@ $^

readstat: $(OBJS) readstat.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	/bin/rm -i *.o $(EXECS) 
