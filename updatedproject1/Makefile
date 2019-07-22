EXEC = run
CC = g++
CFLAGS = -c -Wall

# $(EXEC) has the value of shell variable EXEC, which is run.
# run depends on the files Main.o util.o heap.o
$(EXEC)	: Main.o util.o heap.o
# run is created by the command g++ -o run Main.o util.o heap.o
	$(CC) -o $(EXEC) Main.o util.o heap.o

# main.o depends on the files Main.h Main.cpp
# main.o is created by the command g++ -c -Wall Main.cpp
Main.o	: Main.h Main.cpp
	$(CC) $(CFLAGS) Main.cpp

util.o	: util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

heap.o	: heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

clean	:
	rm *.o
