#############################################################################################################################
#                                                                                                                           #
# @file : Makefile                                                                                                          #
#                                                                                                                           #
# Autour : Ayyoub el kouri                                                                                                  #
#                                                                                                                           #
# date : 25/01/2025                                                                                                         #
#                                                                                                                           #
# lastUpdate : 25/01/2025                                                                                                   #
#                                                                                                                           #
#############################################################################################################################



CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iheaders $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)


SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include
TEST_DIR = DossierForTesting


SOURCES = $(wildcard $(SRC_DIR)/windows/*.c $(SRC_DIR)/widgets/*.c $(SRC_DIR)/containers/*.c $(TEST_DIR)/test_project_1/*.c $(TEST_DIR)/test_project_2/*.c) main.c data_structures/linked_list/linked_list.c src/*.c XML/*.c
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(BIN_DIR)/application


all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)


-include $(OBJS:.o=.d)

.PHONY: all clean
