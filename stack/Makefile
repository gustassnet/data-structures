test.exe: Test.o Stack.o
	gcc -std=c99 -o test.exe Test.o Stack.o

Test.o: Test.c Stack.h
	gcc -std=c99 -c Test.c

Stack.o: Stack.c Stack.h
	gcc -std=c99 -c Stack.c

clean:
	del /q *.o test.exe