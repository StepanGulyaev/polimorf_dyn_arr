#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stddef.h"
#include "Student.h"


Student* createStudent()
	{
	return (Student*)calloc(1, sizeof(Student));
	}

void initStudent(Student* self, char** info)
	{
	self->name = (char*)calloc(strlen(info[0]) + 1, sizeof(char));
	strcpy(self->name, info[0]);
	self->course = atoi(info[1]);
	self->university = (char*)calloc(strlen(info[2]) + 1, sizeof(char));
	strcpy(self->university, info[2]);

	free(info[0]);
	free(info[1]);
	free(info[2]);
	free(info);
	}

char** studentDataParser(char* inputStr)
	{
	char** info = (char**)calloc(3, sizeof(char*));
	char* name = strtok(inputStr, " ");
	info[0] = (char*)calloc(strlen(name) + 1, sizeof(char));
	char* course = strtok(NULL, " ");
	info[1] = (char*)calloc(strlen(course) + 1, sizeof(char));
	char* university = strtok(NULL, "");
	info[2] = (char*)calloc(strlen(university) + 1, sizeof(char));
	strcpy(info[0], name);
	strcpy(info[1], course);
	strcpy(info[2], university);
	return info;
	}

void printStudentInfo(Student* self)
	{
	printf("Name: %s; Course: %llu; University: %s\n", self->name, self->course, self->university);
	}

void freeStudent(Student* self)
	{
	free(self->name);
	free(self->university);
	free(self);
	}