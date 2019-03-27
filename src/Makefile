CC		= gcc
CFLAGS	= -Wall -pedantic -std=c99
OBJS	= qsolve.o
PROG	= qsolve

qsolve:	 $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(PROG) -lm
clean:
	rm -f *.o core qsolve
test:
	./qsolve
