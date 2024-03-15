CC = gcc
CFLAGS = -std=gnu17 -W -Wall -Wextra

all: sish

sish:
	$(CC) $(CFLAGS) ./source/*.c -o ./build/sish

clean:
	rm -rf build
	mkdir build
