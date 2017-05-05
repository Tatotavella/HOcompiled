CC = gcc
CFLAGS = -O3 -Wall 
TARGET = exec.e
SRCS = f-sum.f90 c-main.c
OBJS = $(addsuffix .o,$(basename $(SRCS)))

all: $(TARGET)
$(TARGET): $(OBJS) 
	$(CC) $(OBJS) -o $@ 
%.o: %.c
	$(CC) -c $< -o $@
%.o: %.f90
	$(CC) -c $< -o $@ -lgfotran 
.PHONY: clean
clean: 
	rm -rvf *.o

