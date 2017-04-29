#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

void help(){	
	cout<<"  ___Command list___\n";
	cout<<"|  help      - command list\n";
	cout<<"|  add       - add student\n";
	cout<<"|  edit      - edit student\n";
	cout<<"|  print     - print student for last name (or find commad)\n";
	cout<<"|  print-all - print students\n";
	cout<<"|  print-list- print list students name and Special\n";
	cout<<"|  sort-name - sort name students\n";
	cout<<"|  sort-spec - sort special students\n";
    cout<<"|  age       - low age special\n";
	cout<<"|  del       - delete student\n";
	cout<<"|  exit      - exit program (or q alternative commad)\n";
}


int menu(Student **list, int &size) {
	cout<<"enter comand : ";
	char key[50];
	cin>>key;	
	
    if (strcmp(key, "help") == 0) {
	//	help();
	} else if (strcmp(key, "add") == 0) {
		createStudent(list, size);
	} else if (strcmp(key, "del") == 0) {
		deleteStudent(list, size);
	} else if (strcmp(key, "edit") == 0) {
        editStudent(*list, findStudent(*list, size));
	} else if (strcmp(key, "print-list") == 0) {
		printList(*list, size);
	} else if (strcmp(key, "print-all") == 0) {
		printAll(*list, size);
	} else if (strcmp(key, "print") == 0) {
		printStudent(*list, findStudent(*list, size));
	} else if (strcmp(key,"sort-name") == 0) {
		sortStudentName(*list, size);
        cout<<"Student name sorted\n";
	} else if (strcmp(key,"sort-spec") == 0) {
		sortStudentSpecial(*list, size);
        cout<<"Student special sorted\n";
	} else if (strcmp(key, "find") == 0) {
		printStudent(*list, findStudent(*list, size));
	} else if (strcmp(key, "age") == 0) {
        middleAgeSpecialStudent(*list, size);
	} else if (strcmp(key, "exit") == 0) {
		exit(1);
	} else if (strcmp(key, "q") == 0) {
		exit(1);
	} else {
		cout<<"eror comand\n"<<endl;
	}
	return 0;
}

