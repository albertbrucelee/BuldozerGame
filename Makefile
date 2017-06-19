
#
exe= main
src= main.cpp
assembler= g++

#
obj= $(patsubst %.asm,%.o,$(src))

default: main

.PHONY: main
main:
	g++ main.cpp -Wall -o main  -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -lglut -lGLU -lsfml-audio

.PHONY: clean
clean:
	rm -f *.o *.lst $(exe) *~ .*.gdb
