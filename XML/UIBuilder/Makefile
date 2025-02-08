#############################################################################################################################
#                                                                                                                           #
# @file : Makefile                                                                                                          #
#                                                                                                                           #
# Auteur : Ayyoub el kouri                                                                                                  #
#                                                                                                                           #
# date : 07/02/2025                                                                                                         #
#                                                                                                                           #
# lastUpdate : 07/02/2025                                                                                                   #
#                                                                                                                           #
#############################################################################################################################

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I../include $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)

# Chemins relatifs depuis XML/
SOURCES = $(wildcard ../../src/windows/*.c ../../src/widgets/*.c ../../src/containers/*.c) \
          uibuilder.c \
          ../../data_structures/linked_list/linked_list.c \
          ../../src/supp.c

# Génération des chemins objets dans obj/
OBJS = $(foreach src, $(SOURCES), \
    $(if $(filter ../../%, $(src)), \
        ../../obj/$(patsubst ../../%,../%,$(src:.c=.o)), \
        ../../obj/XML/$(src:.c=.o)))

TARGET = application

# Dossiers de recherche pour les sources
vpath %.c .. ../../src ../../src/windows ../../src/widgets ../../src/containers \
          ../../data_structures/linked_list

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

../../obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ../../obj ../../bin

.PHONY: all clean