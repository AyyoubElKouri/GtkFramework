
CC = gcc
CFLAGS = $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)
SOURCES = main.c src/windows/window.c src/windows/dialog.c src/widgets/label.c src/widgets/image.c src/widgets/spinner.c src/widgets/text_view.c
TARGET = application


all: $(TARGET)


$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $(TARGET)


clean:
	rm -f $(TARGET)
