#include <cstring>
#include "Student.h"
#include "Menu.h"
#include "File.h"

using namespace std;

int main () {
	int size = 0;
	Student *list = new Student[size];
    fileRead(&list,size);
    help();
    int c = 0; 
	while (!c) {
		c = menu(&list,size);
	}
    fileWrite(list, size);
	
    delete[] list;	
	return 0;
}

