CC=clang
CFLAGS=-W -Wall -ansi -pedantic -std=c99 -g 
CPPFLAGS = -I$(shell pwd)
LDFLAGS = -L$(shell pwd) -Wl,-rpath,$(shell pwd)

INC=-I include/
#SRC=src/
EXEC=tp4
 
all: libisqrt.so $(EXEC)
#: $(SRC)tp4.o	 
tp4: tp4.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $< -lm -lisqrt	
	

tp4.o: tp4.c isqrt.h

libisqrt.so: isqrt.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -shared -o $@ $<

isqrt.o: isqrt.c isqrt.h

clean:
	rm -f *.o libisqrt.so tp4