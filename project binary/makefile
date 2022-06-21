main.o: main.cpp
	g++ -c main.cpp -o main.o

login.o: login.cpp
	g++ -c login.cpp -o login.o

user.o: user.cpp
	g++ -c user.cpp -o user.o

persistance_manager.o: persistance_manager.cpp
	g++ -c persistance_manager.cpp -o persistance_manager.o

all: login.o user.o persistance_manager.o main.o
	g++ user.o login.o persistance_manager.o main.o -o myExecutable -g

clean: 
	rm -f *.o
	rm -f userDataStore/*.utext
	rm -f myExecutable
