DEPS=mul.h merry.h
CC=g++
%.o:%.cc $(DEPS)
	$(CC) -c -O2 -Wall -Wextra -pedantic $<
hello:hello.o merry.o mul.o

clean:
	rm *.o
