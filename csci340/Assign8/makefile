#
# PROGRAM:    Application 8
# PROGRAMMER: William Freriks
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assignment8.exe: assignment8.o
	g++ $(CCFLAGS) -o assignment8.exe assignment8.o

# Rules to compile source code files to object code
assignment8.o: assignment8.cc assignment8.h
	g++ $(CCFLAGS) -c assignment8.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment8.exe

