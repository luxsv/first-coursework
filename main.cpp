#include <cstring>
#include "Student.h"
#include "Menu.h"
#include "File.h"

using namespace std;

int main () {
	int size = 0;
	Student *list = new Student[size];
    //defStudent(list);
    fileRead(&list,size);
    help();
	while (true) {
		menu(&list,size);
	}
	delete[] list;	
	return 0;
}

