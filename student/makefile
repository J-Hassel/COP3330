stud: main.o student.o
	g++ -o stud main.o student.o

main.o: main.cpp student.h
	g++ -c main.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

clean:
	rm *.o stud
