GENERATES = fakerm.so
TRASH = *.o *.a *.txt

all:     fakerm.so

test1:    
	touch FIXtest1.txt
	touch test1.txt
	echo "С библиотекой"
	LD_PRELOAD=$(shell pwd)/fakerm.so rm ./test1.txt ./FIXtest1.txt; true
test2:    
	touch test2.txt
	touch FIXtest2.txt
	echo "Без библиотек"
	rm ./FIXtest2.txt ./test2.txt; true
fakerm.so:    fakerm.c
	cc -shared -fPIC fakerm.c -ldl -o fakerm.so

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)
