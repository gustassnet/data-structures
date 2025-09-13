test.exe: Test.o Queue.o
	gcc -std=c99 -o test.exe test.o Queue.o

Test.o: Test.c Queue.h
	gcc -std=c99 -c Test.c

Queue.o: Queue.c Queue.h
	gcc -std=c99 -c Queue.c

clean:
	del /q *.o test.exe