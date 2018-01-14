temperature: driver.o temperature.o
	g++ -o temperature driver.o temperature.o
	
driver.o: driver.cpp temperature.h
	g++ -c driver.cpp

temp.o: temperature.cpp temperature.h
	g++ -c temperature.cpp

clean:
	rm *.o temperature
