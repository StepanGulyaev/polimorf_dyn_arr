#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"
#include "ServiceFunctions.h"
#include "Array.h"

Array* createArr()
	{
	return (Array*)calloc(1, sizeof(Array));
	}

//set structure we work with

void setWorkerMode(Array* self)
	{
	setInitWorkerArr(self);
	setPushWorkerArr(self);
	setFillWorkerArr(self);
	setPrintWorkerArr(self);
	setFreeWorkerArr(self);
	}

void setStudentMode(Array* self)
	{
	setInitStudentArr(self);
	setPushStudentArr(self);
	setFillStudentArr(self);
	setPrintStudentArr(self);
	setFreeStudentArr(self);
	}

//init functions Worker

void initWorkerArr(Array* self,size_t workerArrLength)
	{
	self->length= workerArrLength;
	self->arr.workerArr = (Worker**)calloc(workerArrLength,sizeof(Worker));
	}

void setInitWorkerArr(Array* self)
	{
	self->init = initWorkerArr;
	}


//init functions Student

void initStudentArr(Array* self, size_t studentArrLength)
	{
	self->length = studentArrLength;
	self->arr.studentArr = (Student**)calloc(studentArrLength, sizeof(Student));
	}

void setInitStudentArr(Array* self)
	{
	self->init = initStudentArr;
	}


//push functions Worker

void pushWorkerArr(Array* self, Worker* to_push)
	{
	self->length++;
	Worker** test_for_null = (Worker**)realloc(self->arr.workerArr, self->length * sizeof(Worker*));
	if(test_for_null == NULL)
		{
		printf("Can't add element. Not enough RAM\n");
		return;
		}
	self->arr.workerArr = test_for_null;
	self->arr.workerArr[self->length - 1] = to_push;
	}

void setPushWorkerArr(Array* self)
	{		
	self->push = pushWorkerArr;		
	}

//push functions Student

void pushStudentArr(Array* self, Student* to_push)
	{
	self->length++;
	Student** test_for_null = (Student**)realloc(self->arr.studentArr, self->length * sizeof(Worker*));
	if (test_for_null == NULL)
		{
		printf("Can't add element. Not enough RAM\n");
		return;
		}
	self->arr.studentArr = test_for_null;
	self->arr.studentArr[self->length - 1] = to_push;
	}

void setPushStudentArr(Array* self)
	{
	self->push = pushStudentArr;
	}


//fill functions Worker

void fillWorkerArr(Array* self)
	{
	for (ptrdiff_t i = 0; i < self->length; i++)
		{
		Worker* worker = createWorker();
		char* inputStr;

		string_input_error:
		inputStr = read_string(100);

		if (inputStr == NULL)
			{
			goto string_input_error;
			}

		char** workerInfo = workerDataParser(inputStr);
		initWorker(worker, workerInfo);
		self->arr.workerArr[i] = worker;
		free(inputStr);
		}
	}

void setFillWorkerArr(Array* self)
	{
	self->fill = fillWorkerArr;
	}

//fill functions Student

void fillStudentArr(Array* self)
	{
	for (ptrdiff_t i = 0; i < self->length; i++)
		{
		Student* student = createStudent();
		char* inputStr;

		string_input_error:
		inputStr = read_string(100);

		if (inputStr == NULL)
			{
			goto string_input_error;
			}

		char** studentInfo = studentDataParser(inputStr);
		initStudent(student, studentInfo);
		self->arr.studentArr[i] = student;
		free(inputStr);
		}
	}

void setFillStudentArr(Array* self)
	{
	self->fill = fillStudentArr;
	}

//print functions Worker

void printWorkerArr(Array* self)
	{
	for (ptrdiff_t i = 0; i < self->length; i++)
		{
		printWorkerInfo(self->arr.workerArr[i]);
		}
	}

void setPrintWorkerArr(Array* self)
	{
	self->print = printWorkerArr;
	}

//print functions Student

void printStudentArr(Array* self)
	{
	for (ptrdiff_t i = 0; i < self->length; i++)
		{
		printStudentInfo(self->arr.studentArr[i]);
		}
	}

void setPrintStudentArr(Array* self)
	{
	self->print = printStudentArr;
	}

//free functions Worker


void freeWorkerArr(Array* self)
	{
	for (ptrdiff_t i = 0; i < self->length; i++)
		{
		freeWorker(self->arr.workerArr[i]);
		}
	free(self->arr.workerArr);
	free(self);
	}

void setFreeWorkerArr(Array* self)
	{
	self->freeArr = freeWorkerArr;
	}

//free functions Student

void freeStudentArr(Array* self)
	{
	for (ptrdiff_t i = 0; i < self->length; i++)
		{
		freeStudent(self->arr.studentArr[i]);
		}
	free(self->arr.studentArr);
	free(self);
	}

void setFreeStudentArr(Array* self)
	{
	self->freeArr = freeStudentArr;
	}