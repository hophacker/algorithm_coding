target= 431D

all:
	g++ -o $(target) -g $(target).cpp -w
#g++ -o $(target) -g $(target).cpp -w -std=c++11

.PHONY: run debug

run:
	./${target} < in | tee out

justrun:
	./${target} 

debug:
	gdb ${target}
