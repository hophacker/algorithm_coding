target= 32013p0

all:
	g++ -o $(target) -g $(target).cpp -std=c++11

.PHONY: run debug read

run:
	./${target} < in | tee out

debug:
	gdb ${target}

read:
	vim -R ${target}.cpp
