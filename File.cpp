#include <iostream>
#include <stdio.h>
#include <cstring>
#include "Student.h"

using namespace std;


void copyBase(Student **list, int &size, char buffstr[]){
	Student *temp = new Student[size+1];
    for (int i = 0; i < size; i++) {
		temp[i] = list[0][i];
	}
    
    char buff[50] = {};

    for (int i = 0,j = 0, fl = 0; buff[i] == '\0'; ++i, ++j) {
        if (buffstr[i] == ':') {
            switch(fl){
                case 0 : strcpy(temp[size].FirstName, buff);
                    break;
                case 1 : strcpy(temp[size].LastName, buff);
                    break;
                case 2 : temp[size].Age = atoi(buff);
                    break;
                case 3 : temp[size].College = atoi(buff);
                    break;
                case 4 : temp[size].Special = (SpecialList)atoi(buff);
                    break;
                default: break; 
            }  
            
            memset(&buff,0,50);
            ++fl;
            j = -1;
        } else { 
            buff[j] = buffstr[i];
        }
    }
    delete[] *list; 
    *list = temp;
    ++size;
}


void fileRead(Student **list, int &size){
    FILE *f1;
    if ((f1 = fopen("base", "r")) == NULL)
        cout<<"file not open\n";     
    char buffstr[255] = {};
    fgets(buffstr,255,f1);
    
    while(!feof(f1)){
        copyBase(list, size , buffstr);    
        fgets(buffstr,255,f1);
    }
    fclose(f1);
}
