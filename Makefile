CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla -lX11 -L/usr/X11/lib -I/usr/X11/include
OBJECTS = main.o grid.o graphicsdisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = gol

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
