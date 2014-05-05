<<<<<<< HEAD
target= manyPrices
=======
target= R1A2014C
>>>>>>> 8ea67614540813d9826e3c029eb36e4cc7116fb2

all:
	g++ -o $(target) -g $(target).cpp -std=c++11 -Wno-deprecated

.PHONY: run debug read

run:
	./${target} < in | tee out

debug:
	gdb ${target}

read:
	vim -R ${target}.cpp
