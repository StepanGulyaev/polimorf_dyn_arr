#ifndef ARRAY_H
#define ARRAY_H

#include "stdio.h"
#include "stdlib.h"
#include "Worker.h"
#include "Student.h"


typedef union Elements
	{
	Worker** workerArr;
	Student** studentArr;
	} Elements;

typedef struct Array
	{
	Elements arr;
	size_t length;

	void(*init)(struct Array* self,size_t length);
	void(*push)(struct Array* self);
	void(*fill)(struct Array* self);
	void(*print)(struct Array* self);
	void(*freeArr)(struct Array* self);

	} Array;

Array* createArr();

//set structure we work with

void setWorkerMode(Array* self);
void setStudentMode(Array* self);

//init functions Worker

void initWorkerArr(Array* self, size_t workerArrLength);
void setInitWorkerArr(Array* self);

//init functions Student

void initStudentArr(Array* self, size_t studentArrLength);
void setInitStudentArr(Array* self);

//push functions Worker

void pushWorkerArr(Array* self,Worker* to_push);
void setPushWorkerArr(Array* self);

//push functions Student

void pushStudentArr(Array* self, Student* to_push);
void setPushStudentArr(Array* self);

//fill functions Worker

void fillWorkerArr(Array* self);
void setFillWorkerArr(Array* self);

//fill functions Student

void fillStudentArr(Array* self);
void setFillStudentArr(Array* self);

//print functions Worker

void printWorkerArr(Array* self);
void setPrintWorkerArr(Array* self);

//print functions Student

void printStudentArr(Array* self);
void setPrintStudentArr(Array* self);

//free functions Worker

void freeWorkerArr(Array* self);
void setFreeWorkerArr(Array* self);

//free functions Student

void freeStudentArr(Array* self);
void setFreeStudentArr(Array* self);


#endif
