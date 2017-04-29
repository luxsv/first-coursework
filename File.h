#ifndef FILE_H
#define FILE_H

void fileRead(Student **list, int &size);
void copyBase(Student **list, int &size, char buffstr[]);
void fileWrite(Student *list, int size);

#endif
