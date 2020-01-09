#
# PROGRAM:    assign8
# PROGRAMMER: Cory Stojan
# LOGON ID:   z1804761
# DATE DUE:   26APRIL18
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o 
	g++ $(CCFLAGS) -o assign8 assign8.o 

# Rules to compile source code file to object code
assign8.o: assign8.cpp sorts.h quicksort.h mergesort.h
	g++ $(CCFLAGS) -c assign8.cpp

sorts.o: sorts.h
	g++ $(CCFLAGS) -c sorts.h

quicksort.o: quicksort.h
	g++ $(CCFLAGS) -c quicksort.h

mergesort.o: mergesort.h
	g++ $(CCFLAGS) -c mergesort.h


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
