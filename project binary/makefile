main.o: main.cpp
	g++ -c main.cpp -o main.o

iam.o: iam.cpp
	g++ -c iam.cpp -o iam.o

user_attr.o: user_attr.cpp
	g++ -c user_attr.cpp -o user_attr.o

obj_attr.o: obj_attr.cpp
	g++ -c obj_attr.cpp -o obj_attr.o

persistance_manager.o: persistance_manager.cpp
	g++ -c persistance_manager.cpp -o persistance_manager.o

all: persistance_manager.o obj_attr.o user_attr.o iam.o main.o
	g++ user_attr.o obj_attr.o persistance_manager.o iam.o main.o -o myExecutable.exe -g

clean: 
	rm -f *.o
	rm -f userDataStore/*.*
	rm -f myExecutable.exe
