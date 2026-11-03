test.exe: Test.o Vector.o
	gcc -std=c99 -o test.exe Test.o Vector.o

Test.o: Test.c Vector.h
	gcc -std=c99 -c Test.c

Vector.o: Vector.c Vector.h
	gcc -std=c99 -c Vector.c

clean:
	rm -f *.o test.exe