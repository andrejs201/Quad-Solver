CC		= gcc
CFLAGS	= -Wall -pedantic -std=c99
OBJS	= qsolve.o verify.o
PROG	= qsolve

qsolve:	 $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(PROG) -lm
	 
verify.o: verify.h

clean:
	rm -f *.o core qsolve
test:
	./qsolve
val:
	valgrind ./qsolve
