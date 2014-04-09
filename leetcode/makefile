target= palindrome-partitioning


all:
	g++ -o $(target) -g $(target).cpp -std=c++11  -Wno-deprecated

.PHONY: run read debug

run:
	./${target}

read:
	vim -R ${target}.cpp

debug:
	gdb ${target}

Debug:
	clewn -va ${target}.cpp
