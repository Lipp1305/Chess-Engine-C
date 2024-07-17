#RUNS FROM /Game

#Compiler and Linker Flags (-I for include, -L for library)
CC = gcc
CFLAGS = -I/opt/homebrew/opt/sdl2/include/SDL2 -Wall -g
LDFLAGS = -L/opt/homebrew/opt/sdl2/lib -lSDL2

# Directories
SRCDIR = ./Game/src
INCDIR = ./Game/include
BINDIR = ./Game
#Source files
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/board.c

#Object files
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(SRCDIR)/%.o)

#Target executable
TARGET = $(BINDIR)/chess_game

#Default target builds the project
.PHONY: build
build: $(TARGET)

#Rule to build the project
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

#Rule to compile source files into object files
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

#Target to run the project
.PHONY: run
run: build
	$(TARGET)

#Clean the build files
.PHONY: clean
clean: 
	rm -f $(TARGET) $(OBJECTS)
