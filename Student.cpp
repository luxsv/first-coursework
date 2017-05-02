#include <iostream>
#include "Student.h"
#include <cstring>
using namespace std;

int setAge(){
    int a;
    while(true){
        cout<<"Enter age : ";
        cin >> a;
        if (cin.good()){
            cin.ignore(20,'\n');
            if (a < 12 || a > 35){
                cout<<"Age min 12, max 35 Year\n";
                continue;
            }
            break;
        }
        cin.clear(); 
        cin.ignore(20,'\n');
        cout<<"Age min 12, max 35 Year\n";
    }
    return a ;
}



void createStudent(Student **list, int &size) {
    Student *temp = new Student[size+1];
    for (int i=0; i < size; i++) {
        temp[i] = list[0][i];
    }
    cout<<"Enter Name : ";
    cin>>temp[size].Name;
    cout<<"Enter Surname : ";
    cin>>temp[size].Surname;
    cout<<"Enter Middle Name  : ";
    cin>>temp[size].MiddleName;
    
    temp[size].Age = setAge();

    cout<<"Finish colegee ? enter yes or no : ";
    char key[4];
    cin>>key;
    temp[size].College = !strcmp(key,"yes") ? true : false;

    cout<<"Press digit for special : \n";
    cout<< "1)Code(default)  2)Hardvare  3)Gymanitaryy\n";
    char fl = 0;
    cout<<"> ";
    getchar();
    fl = getchar();
    switch(fl){
        case '1':temp[size].Special = Code; 
        break;
        case '2':temp[size].Special = Hard; 
        break;
        case '3':temp[size].Special = Gyman;    
        break;
        default :temp[size].Special = Code; 
    }   
    cout<<"- - student aded! - -\n";
    delete[] *list;
    *list = temp;
    ++size;
}



void sortStudentSpecial(Student *list, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j >  0; j--){
            if (list[j-1].Special > list[j].Special){ 
                swap(list[j-1], list[j]); 
            }
        } 
    }
}


void sortStudentName(Student *list, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0; j--){
            if (strcmp(list[j-1].Surname,list[j].Surname) > 0){ 
                swap(list[j-1], list[j]); 
            }
        } 
    }
}


void printList(Student *list, int size){
    sortStudentName(list ,size);
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - -\n"; 
    cout<<"Initial\t\t\t\t\tage\tfinish college\tSpecial\n";
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - -\n"; 
    for (int i = 0; i < size; i++) {
        cout<<list[i].Surname<<" "<<list[i].Name<<" "<<list[i].MiddleName<<"\t";
        cout<<"\t"<<list[i].Age<<"\t";
        cout<<(list[i].College == true ? "yes" : "no")<<"\t\t";
        switch(list[i].Special){
            case Code : cout<<"Code\n"; 
                        break;
            case Hard : cout<<"Hard\n"; 
                        break;
            case Gyman : cout<<"Gymanitaryy\n"; 
                        break;
            default : cout<<"Code\n";   
        }
    }
}

void printListIsSpeciall(Student *list, int size, SpecialList a){
    sortStudentName(list ,size);
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - -\n"; 
    cout<<"Initial\t\t\t\tSpecial\n";
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - -\n"; 
    for (int i = 0; i < size; i++) {
        switch(a){
            case Code : 
                if (list[i].Special == Code){
                cout<<list[i].Surname<<" "<<list[i].Name<<" "<<list[i].MiddleName<<"\t";
                cout<<"Code\n"; }
                        break;
            case Hard :
                if (list[i].Special == Hard){
                cout<<list[i].Surname<<" "<<list[i].Name<<" "<<list[i].MiddleName<<"\t";
                cout<<"Hard\n"; }
                        break;
            case Gyman :
                if (list[i].Special == Gyman){
                cout<<list[i].Surname<<" "<<list[i].Name<<" "<<list[i].MiddleName<<"\t";
                cout<<"Gymanitaryy\n";} 
                        break;
            default :   break;  
        }
    }


}

void printListIsCollege(Student *list, int size){
    sortStudentName(list ,size);
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"; 
    cout<<"Initial\t\t\t\tfinish college\tSpecial\n";
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"; 
    for (int i = 0; i < size; i++) {
        if (list[i].College){
            cout<<list[i].Surname<<" "<<list[i].Name<<" "<<list[i].MiddleName<<"\t";
            cout<<(list[i].College == true ? "yes" : "no")<<"\t\t";
            switch(list[i].Special){
                case Code : cout<<"Code\n"; 
                            break;
                case Hard : cout<<"Hard\n"; 
                            break;
                case Gyman : cout<<"Gymanitaryy\n"; 
                             break;
                default : cout<<"Code\n";   
            }
        }
    }
}

void printStudent(Student *list, int i) {
    cout<<"- - - - - - - - - - - - \n";
    cout<<list[i].Surname<<" "<<list[i].Name<<" "<<list[i].MiddleName<<endl;
    cout<<"Age : "<<list[i].Age<<endl; cout<<"finish college : ";
    cout<<(list[i].College == true ? "yes" : "no")<<endl;
    cout<<"Special : ";
    switch(list[i].Special){
        case Code : cout<<"Code\n"; 
        break;
        case Hard : cout<<"Hard\n"; 
        break;
        case Gyman : cout<<"Gymanitaryy\n"; 
        break;
        default : cout<<"Code\n";   
    }
}


void printAll(Student *list, int size) {
    for (int i = 0; i < size; i++) {
        printStudent(list, i);
    }
}


int findStudent(Student *list, int size) {
    cout<<"enter lastname find student : ";
    char key[50];
    getchar();
    cin>>key;
    for (int i = 0; i < size; i++) {
        if (strstr(list[i].Surname, key) != nullptr)
        cout<<"find index "<<i<<" : "<<list[i].Name<<" "<<list[i].Surname<<endl;
    }
    cout<<"Press index to choose studen : ";
    int index;
    cin>>index;

    if (index >= size || index < 0) {
        cout<<"Error index\n"; return -1;
    }
    return index;
}



void deleteStudent(Student **list, int &size) {
    int index = findStudent(*list, size);
    if (index >= size || index < 0) {;
        return;
    }
    --size;
    Student *temp = new Student[size];
    for (int i = 0, j = 0; i < size; i++,j++) {
        if (i == index) {++j;}
        temp[i] = list[0][j];   
    }
    delete[] *list;
    *list = temp;
    cout<<"Student deletet\n";
}


void middleAgeSpecialStudent(Student *list, int size){
    int age = 0, count = 0 , spec; 
    cout<<"Press digit for special middle age: \n";
    cout<< "1)Code(default)  2)Hardvare  3)Gymanitaryy\n";
    char fl = 0;
    cout<<"> ";
    getchar();
    fl = getchar();
    switch(fl){
        case '1': spec = Code;  
        break;
        case '2': spec = Hard;  
        break;
        case '3': spec = Gyman; 
        break;
        default : spec = Code;  
    }   
    for (int i = 0; i < size; i++){
        if (spec == list[i].Special){
            age += list[i].Age;
            ++count;
        }
    }
    cout<<(float)(count == 0 ? 0 : age/count)<<endl;
}


void editStudent(Student *list, int size){
    char buff[50];
    cout<<"Enter new Name or y not change : ";
    cin>>buff;
    
    if (strcmp(buff, "y") != 0){
        strcpy(list[size].Name, buff);
    }

    cout<<"Enter new Surname or y not change : ";
    cin>>buff;
    if (strcmp(buff ,"y") != 0){
        strcpy(list[size].Surname, buff);
    }
    
    cout<<"Enter new Middle name or y not change : ";
    cin>>buff;
    if (strcmp(buff ,"y") != 0){
        strcpy(list[size].MiddleName, buff);
    }
    
    list[size].Age = setAge();
        
    cout<<"Finish colegee ? enter yes or no : ";
    char key[4];
    cin>>key;
    list[size].College = !strcmp(key,"yes") ? true : false;
    cout<<"Press digit for special : \n";
    cout<< "1)Code(default)  2)Hardvare  3)Gymanitaryy\n";
    char fl = 0;
    cout<<"> ";
    getchar();
    fl = getchar();
    switch(fl){
        case '1':list[size].Special = Code; 
        break;
        case '2':list[size].Special = Hard; 
        break;
        case '3':list[size].Special = Gyman;    
        break;
        default :list[size].Special = Code; 
    }   
    cout<<"- - student edit! - -\n";
}


