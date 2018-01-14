bit: main7.o bitarray.o
	g++ -o bit main7.o bitarray.o
	
main7.o: main7.cpp bitarray.h sieve.h
	g++ -c main7.cpp

bitarray.o: bitarray.cpp bitarray.h
	g++ -c bitarray.cpp

clean:
	rm *.o bit
