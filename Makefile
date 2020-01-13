##DIRECTORY
BIN_DIR = bin
OBJ_DIR = etc
LIB_DIR = lib
DOC_DIR = doc
INC_DIR = include
SRC_DIR = src

#Macro
MAKEF   = make -sf
RM      = rm -rf
TARNAME = Connect4
TAR     = ./$(DOC_DIR) ./$(INC_DIR) ./$(SRC_DIR) ./$(LIB_DIR) Makefile README

.PHONY : all matrix Connect4 tar distclean clean
.SILENT: matrix tar

#RULES
all: matrix Connect4

distclean:
	$(RM) $(BIN_DIR) $(LIB_DIR) $(OBJ_DIR)

clean    :
	$(RM) $(OBJ_DIR)/*

#OTHERS MAKEFILE
matrix:
	$(MAKEF) ./src/matrix/Makefile all

Connect4:
	$(MAKEF) ./src/connect4/Makefile compile

#OTHERS
tar      : distclean
	tar zcf $(TARNAME).tar.gz $(TAR)
