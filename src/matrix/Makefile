#DIRECTORY
BIN_DIR = bin
OBJ_DIR = etc
LIB_DIR = lib
DEP_DIR = include

#FILES
BIN     = $(BIN_DIR)/testmatrix.bin
STATIC_LIB = $(LIB_DIR)/libmatrix.a
DYN_LIB = $(LIB_DIR)/libmatrix.so

#Macro
CC      = gcc 
CFLAGS  = -Wall -fPIC -Wextra -ansi -pedantic -I./$(DEP_DIR) 
LDFLAGS = -shared  -o
LIBFLAGS = -L./lib -lmatrix
RM      = rm -rf
AR = ar rcs
OBJS =  $(OBJ_DIR)/matrix.o
DEPS =  $(DEP_DIR)/matrix.h


#RULES
all: staticlib dynamiclib testmatrix

testmatrix : $(BIN)

staticlib : $(STATIC_LIB)

dynamiclib : $(DYN_LIB)
#BINARIES
$(BIN): $(OBJ_DIR)/testmatrix.o $(DYN_LIB) $(BIN_DIR)
	$(CC) -o $@  $< -static $(LIBFLAGS)

#LIBRARIES
$(STATIC_LIB): $(OBJ_DIR)/matrix.o $(LIB_DIR)
	$(AR) $@ $<

$(DYN_LIB): $(OBJ_DIR)/matrix.o $(LIB_DIR)
	$(CC) $(LDFLAGS) $@ $<


#OBJECT
$(OBJ_DIR)/%.o: 
	$(CC) $(CFLAGS) -c -o $@ $<  

$(OBJ_DIR)/matrix.o    : src/matrix/matrix.c     $(DEPS) $(OBJ_DIR)
$(OBJ_DIR)/testmatrix.o    : src/matrix/testmatrix.c     $(DEPS) $(OBJ_DIR)

#OTHERS
$(BIN_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(LIB_DIR):
	mkdir $@
