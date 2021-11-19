# -*- Mode: Makefile; -*-

NAME=datalogger
TYPE=program

BIN= x86-Debug/

CC = /usr/bin/g++

FLAGS = -DSHELL -Wall -Weffc++ -pedantic -Wextra -std=c++1z -fPIC -I/usr/include/qt/ -I/usr/include/qt/QtWidgets/
LDFLAGS = -L/usr/lib/

SRC+= \
	src/main.cpp \
	src/oekofen/bufferTank.cpp \
	src/oekofen/energy.cpp \
	src/oekofen/environment.cpp \
	src/oekofen/heater.cpp \
	src/oekofen/heatingCircuit.cpp \
	src/oekofen/hotWaterTank.cpp \
	src/oekofen/logEntry.cpp \
	src/oekofen/pelletronic.cpp

.PHONY: clean

all: $(SRC)
	mkdir -p $(BIN)
	$(CC) $(SRC) -o $(BIN)$(NAME) $(FLAGS)

clean:
	rm -f $(BIN)$(NAME)
