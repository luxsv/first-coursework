#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Student.h"

using namespace std;

void help(){    
    cout<<"  ___Command list___\n";
    cout<<"|  help      - command list\n";
    cout<<"|  add       - add student\n";
    cout<<"|  edit      - edit student\n";
    cout<<"|  print     - print student for last name (or find commad)\n";
    cout<<"|  print-all - print students\n";
    cout<<"|  print-c   - custum print list students\n";
    cout<<"|  sort-n    - sort name students\n";
    cout<<"|  sort-s    - sort special students\n";
    cout<<"|  age       - low age special\n";
    cout<<"|  del       - delete student\n";
    cout<<"|  clear     - clear console\n";
    cout<<"|  exit      - exit program (or q alternative commad)\n";
}


int menu(Student **list, int &size) {
    cout<<"enter comand : ";
    char key[50];
    cin>>key;   
    if (strcmp(key, "help") == 0) {
        help();
    } else if (strcmp(key, "add") == 0) {
        createStudent(list, size);
    } else if (strcmp(key, "del") == 0) {
        deleteStudent(list, size);
    } else if (strcmp(key, "edit") == 0) {
        editStudent(*list, findStudent(*list, size));
    } else if (strcmp(key, "print-all") == 0) {
        printAll(*list, size);
    } else if (strcmp(key, "print") == 0) {
        printStudent(*list, findStudent(*list, size));
    } else if (strcmp(key, "print-c") == 0) {
        cout<<"1)Full list 2)Finnish college\n"; 
        cout<<"3)Code 4)Hardvare 5)Gumanitar \n>";
        char ch;
        cin>>ch;
        switch(ch){
            case '1': printList(*list, size);
                break;
            case '2': printListIsCollege(*list,size);
                break;
            case '3': printListIsSpeciall(*list,size, Code);
                break;
            case '4': printListIsSpeciall(*list,size, Hard);
                break;
            case '5': printListIsSpeciall(*list,size, Gyman);
                break;
            default: break;
        }
    } else if (strcmp(key,"sort-n") == 0) {
        sortStudentName(*list, size);
        cout<<"Student name sorted\n";
    } else if (strcmp(key,"sort-s") == 0) {
        sortStudentSpecial(*list, size);
        cout<<"Student special sorted\n";
    } else if (strcmp(key, "find") == 0) {
        printStudent(*list, findStudent(*list, size));
    } else if (strcmp(key, "age") == 0) {
        middleAgeSpecialStudent(*list, size);
    } else if (strcmp(key, "clear") == 0) {
#ifdef _WIN32
        system("cls");
#else
        cout << string( 100, '\n' );
#endif
    } else if (strcmp(key, "exit") == 0) {
        return 1;
    } else if (strcmp(key, "q") == 0) {
        return 1;
    } else {
        cout<<"-- eror command --\n";
    }
    return 0;
}
