GENERATES = prog prog-a prog-so README
TRASH = *.o *~ o.* *.a *.so *.txt
CFLAGS=-fPIC
PAR=str
PAR3=s st str

all:     README liboutput_static.a liboutput.so prog prog-a prog-so

test:    
	2> prog_without.txt ./prog > prog_without.txt
	2> prog-a_without.txt ./prog-a > prog-a_without.txt
	2> prog-so_without.txt LD_LIBRARY_PATH=`pwd` ./prog-so > prog-so_without.txt
	2> prog_with_one.txt ./prog $(PAR) > prog_with_one.txt
	2> prog-a_with_one.txt ./prog-a $(PAR) > prog-a_with_one.txt
	2> prog-so_with_one.txt LD_LIBRARY_PATH=`pwd` ./prog-so $(PAR) > prog-so_with_one.txt
	cmp prog_with_one.txt prog-a_with_one.txt
	cmp prog_with_one.txt prog-so_with_one.txt
	cmp prog-a_with_one.txt prog-so_with_one.txt
	2> prog_with_three.txt ./prog $(PAR3) > prog_with_three.txt
	2> prog-a_with_three.txt ./prog-a $(PAR3) > prog-a_with_three.txt
	2> prog-so_with_three.txt LD_LIBRARY_PATH=`pwd` ./prog-so $(PAR3) > prog-so_with_three.txt
	cmp prog_with_three.txt prog-a_with_three.txt
	cmp prog_with_three.txt prog-so_with_three.txt
	cmp prog-a_with_three.txt prog-so_with_three.txt

prog:    const.o fun.o prog.o

prog-a:    prog.o liboutput_static.a
	cc -L. prog.o liboutput_static.a -o prog-a

prog-so:    prog.o liboutput.so
	cc -L. prog.o liboutput.so -o prog-so

README:     prog
	./$< 2> $@

fun.o:    outlib.h

liboutput_static.a:    fun.o const.o
	ar -rcs liboutput_static.a const.o fun.o

liboutput.so:    fun.o const.o
	cc -shared fun.o const.o -o liboutput.so
clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)