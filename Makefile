all:
	gcc -Wall -c include/*.h                # compila os .h em .gch
	gcc -Wall -c *.c -I include            # compila os .c em .o
	gcc -o sig-burger *.o

clean:
	rm -f *.o  sig-burger include/*.gch