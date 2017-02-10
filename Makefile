# Makefile for ItsTerminal program
# Modify: brondan 2017.2.9
IS_DEBUG=0

CC=g++
TAR=new_test
OBJ=base_device.o main.o
INC=-Iinclude
LIB=-lboost_locale -lboost_log -lboost_system -lboost_thread -lpthread

ifeq ($(IS_DEBUG), 1)
	CCFLAG=-Wall -std=c++11 -g -o
	OFLAG=-std=c++11 -g -c
	SOFLAG=-std=c++11 -fPIC -shared -g
else
	CCFLAG=-Wall -std=c++11 -o
	OFLAG=-std=c++11 -c
	SOFLAG=-std=c++11 -fPIC -shared
endif

vpath %.cpp src:src/component

.PHONY:all
all:$(OBJ) $(TAR)

$(TAR):$(OBJ)
	$(CC) $(CCFLAG) $@ $^ $(LIB)

main.o:main.cpp
	$(CC) $(OFLAG) $(INC) $<

base_device.o:base_device.cpp
	$(CC) $(OFLAG) $(INC) $<

.PHONY:clean
clean:
	rm *.o