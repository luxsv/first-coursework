#ifndef STUDENT_H
#define STUDENT_H

enum SpecialList {Code, Hard, Gyman};

struct Student {
    char Name[50];
    char Surname[50];
    char MiddleName[50];
    int Age;
    bool College;
    SpecialList Special;
};

void printListIsCollege(Student *list, int size);
void printListIsSpeciall(Student *list, int size, SpecialList a);
void printList(Student *list, int size);
void printStudent(Student *list,int index);
void printAll(Student *list, int size);
void sortStudentSpecial(Student *list, int size);
void sortStudentName(Student *list, int size);
void defStudent(Student *list);
int setAge();
int findStudent(Student *list, int size);
void editStudent(Student *list, int size);
void createStudent(Student **list, int &size);
void deleteStudent(Student **list, int &size);
void middleAgeSpecialStudent(Student *list, int size);

#endif 
