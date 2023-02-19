CC=gcc
CFLAGS= -Wall -Wextra -Werror -O0 -pedantic -std=c99 -g -I .
# LDFLAGS= -L .
# LDLIBS= -lmy -lncurses
DEPS= *.h
OBJ= main.o elssh-cleanup.o elssh-execute.o elssh-helper.o elssh-init.o elssh-readline.o elssh-run.o elssh-splitline.o
# SRC= *.c

# all: $(OBJ)
# 	$(CC) -o my_sokoban $(OBJ) $(CFLAGS)

EXECUTABLE_NAME=launch_elssh

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.Phony: clean
clean:
	rm -f $(EXECUTABLE_NAME) *.o