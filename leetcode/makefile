target= longest-consecutive-sequence


all:
	g++ -o $(target) -g $(target).cpp -w -std=c++11

.PHONY: run read debug

run:
	./${target}

read:
	vim -R ${target}.cpp

debug:
	gdb ${target}

Debug:
	clewn -va ${target}.cpp
