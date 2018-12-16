#Makefile to build Red Black tree app

INCLUDE_DIR = include
CC = gcc
CFLAGS = -I $(INCLUDE_DIR) -Wall -c
DFLAGS =
ifeq ($(DEBUG), true)
	DFLAGS = -g
endif
OBJ_DIR = obj
SRC_DIR = src
OUT_DIR = .
OUTPUT = rbtree

FILES = $(foreach file,$(SRC_DIR),$(wildcard $(file)/*.c))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(FILES))

help : default

default :
	@echo "Usage:"
	@echo "Build: make $(OUTPUT) [DEBUG=true]"
	@echo "Clean: make clean"
	@echo "Tags: make tags"
 
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDE_DIR)/rbtree_header.h
	@$(CC) $(CFLAGS) $(DFLAGS) -o $@ $<
	@echo "[Compiling] ->> $<"

$(OUTPUT) : $(OBJ)
	@$(CC) -o $(OUT_DIR)/$(OUTPUT) $^
	@echo "[Linking all object files]"
	@echo "[Executable] ->> $(OUTPUT)"

tags :
	@ctags -R
	@echo "[Generated TAGS file]"

clean :
	@rm -f $(OBJ_DIR)/*.o $(OUT_DIR)/$(OUTPUT) ./tags
	@echo "[Removed object files and executable files]"
