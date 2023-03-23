#ifndef STUDENT_H
#define STUDENT_H

#include "stdlib.h"

typedef struct Student
	{
	char* name;
	size_t course;
	char* university;

	} Student;

Student* createStudent();
void initStudent(Student* self, char** info);
char** studentDataParser(char* inputStr);
void printStudentInfo(Student* self);
void freeStudent(Student* self);


#endif