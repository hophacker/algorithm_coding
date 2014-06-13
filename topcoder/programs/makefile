target= SwitchingGame

all:
	#g++ -o $(target) -g $(target).cpp -w
	g++ -o $(target) -g $(target).cpp -w -std=c++11

.PHONY: run debug justrun

justrun:
	./${target} 

run:
	./${target} > out

debug:
	gdb ${target}
