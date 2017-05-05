CC = gcc
CXX = g++
CFLAGS = -O3 -Wall 
CXXFLAGS = -Wall
TARGET = exec.e
SRCS = cpp-sum.cpp c-main.c
OBJS = $(addsuffix .o,$(basename $(SRCS)))

all: $(TARGET)
$(TARGET): $(OBJS) 
	$(CC) $(OBJS) -o $@ 
%.o: %.c
	$(CC) -c $< -o $@
%.o: %.cpp
	$(CXX) -c $< -o $@ 
.PHONY: clean
clean: 
	rm -rvf *.o

