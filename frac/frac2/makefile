flist: main.o flist.o frac.o
	g++ -o flist flist.o main.o frac.o

main.o: main.cpp flist.h
	g++ -c main.cpp

flist.o: flist.cpp flist.h
	g++ -c flist.cpp

frac.o: frac.cpp frac.h
	g++ -c frac.cpp

clean:
	rm *.o flist
