window.out: main.o
ifeq ($(OS),Windows_NT) 
	gcc main.o -o window.exe `pkg-config --cflags --libs gtk+-3.0` -mwindows
else
	gcc main.o -o window.out `pkg-config --cflags --libs gtk+-3.0`
endif

main.o: main.c
	gcc main.c -c `pkg-config --cflags --libs gtk+-3.0` -static

clean:
	rm *.o window.exe window.out
