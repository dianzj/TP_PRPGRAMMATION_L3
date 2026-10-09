CC=clang
CFLAGS=-W -Wall -ansi -pedantic -std=c99 -g 
CPPFLAGS = -I$(shell pwd)
LDFLAGS  = -L$(shell pwd)

INC=-I include/
SRC=src/
EXEC=tp4
 
all: libisqrt.so $(EXEC)
	 
tp4: $(SRC)tp4.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $< -lm -lisqrt	
	

tp4.o: tp4.c isqrt.h

libisqrt.so: isqrt.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -shared -o $@ $<

isqrt.o: isqrt.c isqrt.h

clean:
	rm -rf $(SRC)*.o