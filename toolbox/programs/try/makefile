target= UVA10099

all:
	#g++ -o $(target) -g $(target).cpp -w
	g++ -o $(target) -g $(target).cpp -w -std=c++11 -Werror -Wall -Wextra

.PHONY: run debug justrun

justrun:
	./${target} 

run:
	./${target} < in

debug:
	gdb ${target}
