
# PROGRAM:    Application 4
# PROGRAMMER: William Freriks
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign4: source.o Vector3.o
	g++ $(CCFLAGS) -o assign4 source.o Vector3.o

# Rules to compile source code files to object code
source.o: source.cpp Vector3.h
	g++ $(CCFLAGS) -c source.cpp

Vector3.o: Vector3.cpp Vector3.h
	g++ $(CCFLAGS) -c Vector3.cpp


# Pseudo-target to remove object code and executable files

clean:
	rm *.o assign4
