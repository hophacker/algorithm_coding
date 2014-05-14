vpath %.cc .
CC=g++
CFLAGS=-g

_TAR = testBigIntBase euler
_OBJ = $(patsubst %,%.o,$(_TAR)) BigIntBase.o

TAR = $(patsubst %,obj/%,$(_TAR))
OBJ = $(patsubst %,obj/%,$(_OBJ))

.PHONY: all clean print test debug

all: $(TAR)

print: 
	echo $(OBJ)

debug:
	./obj/testBigIntBase
test:
	./obj/testBigIntBase 2>error

$(TAR):$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
$(OBJ): | obj
obj:
	@mkdir -p $@

obj/%.o : %.cc %.h
	@echo $<
	$(CC) -c -o $@ $< $(CFLAGS)




.PHONY : clean
clean:
	rm -rf *.o obj/ testBigIntBase test BigIntBase
