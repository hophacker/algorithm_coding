target= 4140

all:
	g++ -o $(target) -g $(target).cpp -w -std=c++11

.PHONY: run debug

run:
	./${target} < in

debug:
	gdb ${target}
