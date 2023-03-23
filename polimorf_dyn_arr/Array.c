#include "stdio.h"
#include "stdlib.h"
#include "Array.h"

Array* createArr()
	{
	return (Array*)calloc(1, sizeof(Array));
	}

//init functions Worker

void initWorkerArr(Array* self,size_t workerArrLength)
	{
	self->length= workerArrLength;
	self->workerArr = (Worker**)calloc(workerArrLength,sizeof(Worker));
	}

void setInitWorkerArr(Array* self)
	{
	self->init = initWorkerArr;
	}


//init functions Student

void initStudentArr(Array* self, size_t studentArrLength)
	{
	self->length = studentArrLength;
	self->studentArr = (Worker**)calloc(studentArrLength, sizeof(Worker));
	}

void setInitStudentArr(Array* self)
	{
	self->init = initStudentArr;
	}


//push functions Worker

void pushWorkerArr(Array* self, Worker* to_push)
	{
	self->length++;
	Worker** test_for_null = (Worker**)realloc(self->workerArr, self->length * sizeof(Worker*));
	if(test_for_null == NULL)
		{
		printf("Can't add element. Not enough RAM\n");
		return;
		}
	self->workerArr = test_for_null;
	self->workerArr[self->length - 1] = to_push;
	}

void setPushWorkerArr(Array* self)
	{		
	self->push = pushWorkerArr;		
	}

//push functions Student

void pushStudentArr(Array* self, Student* to_push)
	{
	self->length++;
	Student** test_for_null = (Student**)realloc(self->studentArr, self->length * sizeof(Worker*));
	if (test_for_null == NULL)
		{
		printf("Can't add element. Not enough RAM\n");
		return;
		}
	self->studentArr = test_for_null;
	self->studentArr[self->length - 1] = to_push;
	}

void setPushStudentArr(Array* self)
	{
	self->push = pushStudentArr;
	}


//print functions Worker

void printWorkerArr(Array* self)
	{
	for (size_t i = 0; i < self->length; i++)
		{
		printWorkerInfo(self->workerArr[i]);
		}
	}

void setPrintWorkerArr(Array* self)
	{
	self->print = printWorkerArr;
	}

//print functions Student

void printStudentArr(Array* self)
	{
	for (size_t i = 0; i < self->length; i++)
		{
		printStudentInfo(self->studentArr[i]);
		}
	}

void setPrintStudentArr(Array* self)
	{
	self->print = printStudentArr;
	}

//free functions Worker


void freeWorkerArr(Array* self)
	{
	for (size_t i = 0; i < self->length; i++)
		{
		freeWorker(self->workerArr[i]);
		}
	free(self->workerArr);
	free(self);
	}

void setFreeWorkerArr(Array* self)
	{
	self->freeArr = freeWorkerArr;
	}

//free functions Student

void freeStudentArr(Array* self)
	{
	for (size_t i = 0; i < self->length; i++)
		{
		freeStudent(self->studentArr[i]);
		}
	free(self->studentArr);
	free(self);
	}

void setFreeStudentArr(Array* self)
	{
	self->freeArr = freeStudentArr;
	}