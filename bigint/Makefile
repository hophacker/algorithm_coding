all:
%.o: %.cc
	g++ -c -O2 -Wall -Wextra -pedantic $<
library-objects =  BigUnsigned.o  BigInteger.o  BigIntegerAlgorithms.o  BigUnsignedInABase.o  BigIntegerUtils.o  
library-headers = NumberlikeArray.hh BigUnsigned.hh BigInteger.hh BigIntegerAlgorithms.hh BigUnsignedInABase.hh BigIntegerLibrary.hh 

library: $(library-objects)

$(library-objects): $(library-headers)

# TESTSUITE (NOTE: Currently expects a 32-bit system)
testsuite.o: $(library-headers)
testsuite: testsuite.o $(library-objects)
	g++ $^ -o $@

# Extract the expected output from the testsuite source.
testsuite.expected: testsuite.cc
	nl -ba -p -s: $< | sed -nre 's,^ +([0-9]+):.*//([^ ]),Line \1: \2,p' >$@
	#nl 	b:use STYLE for numbering body lines
	#		a:number all lines
	#		p:--no-renumber
	#		s:add STRING ":" after (possible) line number
	#sed 	n: quiet
	#		r: --regexp-extended
	#		e: add the script to the commands to be executed
.PHONY: test
test: testsuite testsuite.expected
	./run-testsuite
testsuite-cleanfiles = \
	testsuite.o testsuite testsuite.expected \
	testsuite.out testsuite.err


program = myTest
program-objects =  myTest.o
$(program-objects) : $(library-headers)
$(program) : $(program-objects) $(library-objects)
	g++ $^ -o $@

clean :
	rm -f $(library-objects) $(testsuite-cleanfiles) $(program-objects) $(program)

all : library $(progra)
