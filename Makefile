TARGET = Sorting_Array
CC = gcc

SRC = $(shell find . -name '*.c') # $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
HDR = $(addprefix -I, $(shell dirname $(shell find . -name "*.h")))

CHEK  = $(echo)
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o : %.c
	$(CC) $(HDR)  -c $< -o $@

c :
	rm $(TARGET) $(OBJ)

b: 
	open $(TARGET)