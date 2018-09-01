IPATH=-Iinc/
SRC=src/
OBJ=obj/
BIN=bin/

all:app

app:main.o
	@g++ $(OBJ)main.o -o $(BIN)thumbmulator
main.o:
	@g++ $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.o

clean:
	rm -rf $(OBJ)*.o
	rm -rf $(BIN)*
