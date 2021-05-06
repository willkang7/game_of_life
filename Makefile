CXX=g++
CXXFLAGS=-std=c++14 -MMD
OBJECTS=main.o grid.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=gol

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
