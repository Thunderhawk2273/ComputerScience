#
# PROGRAM:    Lab Training Exercise
# PROGRAMMER: William Freriks
#

CC = g++
CCFLAGS = -Wall

labtrain: labtrain.o
	$(CC) $(CCFLAGS) -o labtrain labtrain.o

labtrain.o: labtrain.cpp
	$(CC) $(CCFLAGS) -c labtrain.cpp

clean:
	- rm *.o labtrain
