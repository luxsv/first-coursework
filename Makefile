all:
	g++ main.cpp Student.cpp File.cpp -o course
clang:
	clang++ main.cpp Student.cpp File.cpp -o course -std=c++14
run:
	./course
clean:
	rm -rf course *.o 
