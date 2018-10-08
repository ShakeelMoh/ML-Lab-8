#My own makefile for ML lab 8

#Declare variables
CC=g++
LIBS=-lm

#First create ".exe" called ReinforcementLearning
ReinforcementLearning: ReinforcementLearning.o
	$(CC) ReinforcementLearning.o -o ReinforcementLearning $(LIBS)

#Need to make ReinforcementLearning.o file though
ReinforcementLearning.o: ReinforcementLearning.cpp
	$(CC) -c ReinforcementLearning.cpp


#Other rules

#Clean .o and exe
clean:
	@rm -f *.o
	@rm -f ReinforcementLearning

#To run program
run:
	./ReinforcementLearning
