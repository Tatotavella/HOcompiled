.PHONY: default help object executable all clean
CC = gcc
LDFLAGS = -lgfortran
LD = $(CC) 

SOURCE_C = $(wildcard *.c)
OBJECTS_C = $(patsubst %.c, %_c.o, $(SOURCE_C))

SOURCE_F = $(wildcard *.f90)
OBJECTS_F = $(patsubst %.f90, %_f90.o, $(SOURCE_F))

EXECUTABLE = c-main.e

default: help

help:
	@echo "\
Options:\n\n\
  make objects_c:     compiler makes objects for every *.c\n\
  make objects_f:     compiler makes objects for every *.f90\n\
  make executable:    compiler makes executable\n\
  make all:           build all previous\n\
  make clean:         delete output files\n\
  make help:          display this help"

objects_c: $(OBJECTS_C)

objects_f: $(OBJECTS_F)

executable: $(EXECUTABLE)

all: objects executable

%_c.o: %.c
	$(CC) -c $^ -o $@

%_f90.o: %.f90
	$(CC) -c $^ -o $@ $(LDFLAGS)

%.e: $(OBJECTS_C) $(OBJECTS_F)
	$(CC) $^ -o $@

clean:
	rm -rfv $(OBJECTS_C) $(OBJECTS_F) $(EXECUTABLE)
