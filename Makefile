CXX = g++
CXXFLAGS = -std=c++0x -g -Wall
OBJECTS = main.o
EXEC = bin/Straights
${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
main.o : main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp -o main.o
run:
	./bin/Straights
clean:
	rm -rf *.o
	rm -rf bin/Straights
