CC = gcc
CFLAGS = -g -Wall
all: fair_parts
fair_parts: fair_parts.o
	$(CC) $(CFLAGS) -o fair_parts fair_parts.o -lm

fair_parts.o: fair_parts.c
	$(CC) $(CFLAGS) -c fair_parts.c 
clean:
	$(RM) $(all)

