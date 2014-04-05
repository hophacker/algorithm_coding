target= 405E

all:
	g++ -o $(target) -g $(target).cpp

.PHONY: run debug

run:
	./${target} < in

debug:
	gdb ${target}
