#Mohammed Ahmed 1001655176
#makefile for C++ program
SRC1 = Code4_1001655176.cpp
SRC2 = CokeMachine.cpp
SRC3 = CokeLib.cpp
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
EXE = $(SRC1:.cpp=.e)

HFILES = CokeMachine.h CokeLib.h

CFLAGS = -g -std=c++11

all : $(EXE)
 
$(EXE): $(OBJ1) $(OBJ2)
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) -o $(EXE)

$(OBJ1) : $(SRC1)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1)
	
$(OBJ2) : $(SRC2)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2)
	
$(OBJ3) : $(SRC3)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3)

