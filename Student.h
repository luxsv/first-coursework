#ifndef STUDENT_H
#define STUDENT_H

enum SpecialList {Code, Hard, Gyman};

struct Student {
	char FirstName[50];
	char LastName[50];
    int Age;
	bool College;
	SpecialList Special;
	int Averating;
};

void defStudent(Student *list);
int setAge();
void createStudent(Student **list, int &size);
void sortStudentSpecial(Student *list, int size);
void sortStudentName(Student *list, int size);
void printList(Student *list, int size);
void printStudent(Student *list,int index);
void printAll(Student *list, int size);
int findStudent(Student *list, int size);
void deleteStudent(Student **list, int &size);
void middleAgeSpecialStudent(Student *list, int size);
void editStudent(Student *list, int size);

#endif 
