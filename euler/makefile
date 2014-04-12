CFLAGS=-g
CC=g++
DEP=euler.h
OBJ=21
all:$(OBJ)
bigint-dir=BigFeng
bigint-objects =BigIntBase.o
bigint-lib=$(patsubst %,$(bigint-dir)/%,$(bigint-objects))

temp:temp.cc euler.o

17:17.cc numberSpell.o
	$(CC) $(CFLAGS) -o $@ $^

19:19.o euler.o
21:21.o euler.o
	$(CC) $(CFLAGS) -o $@ $^

16:16.o euler.o $(bigint-lib)

20:20.o $(bigint-lib)

$(bigint-lib):

%.o:%.cc
	$(CC) $(CFLAGS) -c $< 

clean:
	rm $(OBJ) *.o
#find -executable  -maxdepth 1 ! -iname "*.sh -exec rm {} \;
