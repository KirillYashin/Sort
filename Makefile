default: main

main: main.o
	gcc main.o -o main

main.o: main.c	gcc -Wall -Werror -c $<

clean:
	rm -f *.o main