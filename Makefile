all:
	g++ main.cpp Student.cpp File.cpp -o main
clang:
	clang++ main.cpp Student.cpp File.cpp -o main -std=c++14
o:
	./main
clean:
	rm -rf main *.o 
