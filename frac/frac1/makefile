frac: driver.o frac.o
	g++ -o frac driver.o frac.o

driver.o: driver.cpp frac.h
	g++ -c driver.cpp

frac.o: frac.cpp frac.h
	g++ -c frac.cpp

clean:
	rm *.o frac
