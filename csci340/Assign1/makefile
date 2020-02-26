#
# PROGRAM:    Application 1
# PROGRAMMER: William Freriks
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rules to compile source code files to object code
assign1.o: assign1.cc
	g++ $(CCFLAGS) -c assign1.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1

