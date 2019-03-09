window.out: main.o
	gcc main.o -o window.out `pkg-config --cflags --libs gtk+-3.0`

main.o: main.c
	gcc main.c -c `pkg-config --cflags --libs gtk+-3.0`

clean:
	rm *.o window.out
