#!/usr/bin/make -f

BIN:=parser
BIN_DEP:=main.cpp
BIN_OBJ:=$(BIN_DEP:%.cpp=%.o)

INSTALL_DIR:=./$(BIN)

CC=$(shell which g++)
GDB=$(shell which gdb)
VALGRIND=$(shell which valgrind)
STRIP=$(shell which strip)

CFLAGS=-Wall $(shell pkg-config --cflags gdal) -g
LDFLAGS=$(shell pkg-config --libs gdal)

.PHONY: clean

all: $(BIN)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS)

$(BIN): $(BIN_OBJ)
	$(CC) -o $(BIN) main.cpp $(CFLAGS) $(LDFLAGS)
clean:
	rm -f $(BIN) $(BIN_OBJ)
