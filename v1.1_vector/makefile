v1.1_vector.exe : main.o funkcija.o
	g++ main.o funkcija.o -o v1.1_vector.exe

main.o : main.cpp funkcija.cpp funkcija.h
	g++ -Wall -c main.cpp

funkcija.o : funkcija.cpp funkcija.h
	g++ -Wall -c funkcija.cpp

clean :
	rm *.o v1.1_vector.exe
