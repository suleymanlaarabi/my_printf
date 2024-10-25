##
## EPITECH PROJECT, 2024
## LibMy
## File description:
## Build and clean the LibMy
##

CC = gcc
CFLAGS= -Wextra -Wall
DEBUG_FLAGS= --coverage -g -fprofile-arcs -lcriterion
SRC := $(wildcard *.c)
SRC_DEBUG = tests/*.c
OBJ = $(SRC:.c=.o)
NAME = main
NAME_DEBUG = debug_main
LIB_MY_PATH = ./lib/my/

LIB_MY_INCLUDE = -L$(LIB_MY_PATH) -lmy

LIB = $(LIB_MY_INCLUDE)

libmy:
	make all -C $(LIB_MY_PATH) 1> /dev/null

lib: libmy

all: lib
	gcc -g3 $(SRC) $(LIB) -o $(NAME)

run: all
	./$(NAME)
	make fclean -C $(LIB_MY_PATH) 1> /dev/null

tests_run:
	make debug_build -C $(LIB_MY_PATH) 1> /dev/null
	gcc $(DEBUG_FLAGS) $(SRC_DEBUG) $(LIB) -lm -o $(NAME_DEBUG)
	- ./$(NAME_DEBUG)
	rm -f debug*
	rm -f *.gc*
	make fclean -C $(LIB_MY_PATH) 1> /dev/null

clean_lib:
	make fclean -C $(LIB_MY_PATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
