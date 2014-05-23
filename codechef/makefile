target= COOK46-ANUBGC_2

all:
	g++ -o $(target) -g $(target).cpp -std=c++11 -Wno-deprecated

.PHONY: run debug read

run:
	./${target} < in | tee out

justrun:
	./${target}
debug:
	gdb ${target}

read:
	vim -R ${target}.cpp
