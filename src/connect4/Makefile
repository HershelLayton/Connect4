#DIRECTORY
BIN_DIR = bin
OBJ_DIR = etc
LIB_DIR = lib
DEP_DIR = include

#FILES
BIN     = $(BIN_DIR)/Connect4.bin

#Macro
CC      = gcc
CFLAGS  = -Wall -Wextra -ansi -pedantic -I./$(DEP_DIR)
LDFLAGS = -o 
LIBFLAGS = -L./lib -lmatrix
RM      = rm -rf
OBJS =  $(OBJ_DIR)/main.o \
		$(OBJ_DIR)/game.o
DEPS =  $(DEP_DIR)/matrix.h \
		$(DEP_DIR)/game.h

.PHONY : compile

#RULES
all: compile

compile : $(BIN_DIR) $(BIN)

#BINARIES
$(BIN): $(OBJS) $(BIN_DIR)
	$(CC) -static $< $(LDFLAGS) $@ $(LIBFLAGS)

#OBJECT
$(OBJ_DIR)/%.o:
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/main.o    : src/connect4/main.c     $(DEPS) $(OBJ_DIR)
$(OBJ_DIR)/game.o   : src/connect4/game.c     $(DEPS) $(OBJ_DIR)

#OTHERS
$(BIN_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@
$(BIN_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@