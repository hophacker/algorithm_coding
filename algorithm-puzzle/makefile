target= quora-nearby
#target= temp

all:
	g++ -o $(target) -g $(target).cpp

.PHONY: run debug

run:
	./${target} < in | tee out

debug:
	gdb ${target}
