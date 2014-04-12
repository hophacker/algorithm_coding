CFLAGS=-g
CC=g++
dd=dmd
obj= 399D
$(obj):$(obj).o

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<



.PHONY: clean debug

clean:
	rm $(obj)

debug:
	gdb $(obj)

run: 
	./$(obj) < in
#%:%.d
#	$(dd) $(CFLAGS)  $<

