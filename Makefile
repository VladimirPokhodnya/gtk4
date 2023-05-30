all:
	gcc test.c `pkg-config --cflags --libs gtk4` -o test
#	gcc $( pkg-config --cflags gtk4 ) -o test test.c $( pkg-config --libs gtk4 )