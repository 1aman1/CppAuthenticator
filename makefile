main.o: main.cpp
	g++ -c main.cpp -o main.o

login.o: login.cpp
	g++ -c login.cpp -o login.o

user.o: user.cpp
	g++ -c user.cpp -o user.o

all: login.o user.o main.o
	g++ user.o login.o main.o -o myExecutable

clean: 
	rm -f *.o
	rm -f myExecutable