CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = shared_memory

all: $(TARGET)

$(TARGET): main.c shared.h
	$(CC) $(CFLAGS) main.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
