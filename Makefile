
CC = gcc
CFLAGS = $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)
SOURCES = main.c src/windows/window.c src/windows/dialog.c src/widgets/label.c src/widgets/image.c src/widgets/spinner.c src/widgets/text_view.c src/widgets/level_bar.c src/widgets/progress_bar.c src/widgets/scale.c src/widgets/separator.c src/widgets/button.c src/widgets/check_button.c src/widgets/link_button.c src/widgets/menu_item.c src/widgets/menu.c data_structures/linked_list/linked_list.c src/widgets/menu_button.c
TARGET = application


all: $(TARGET)


$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $(TARGET)


clean:
	rm -f $(TARGET)
