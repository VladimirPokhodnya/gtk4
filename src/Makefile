CC=gcc -std=c11 -Wall -Wextra -Werror -pedantic
CFLAGS= `pkg-config --cflags --libs gtk4`

BUILD=../build/

main:
	$(CC) main.c demowidget.c $(CFLAGS) -c 
	$(CC) main.o demowidget.o $(CFLAGS) -o $(BUILD)main

style:
	@clang-format -i --style=Google *.c
	@clang-format -i --style=Google *.h

clean:
	@rm -rf *.o *.a $(BUILD)*
