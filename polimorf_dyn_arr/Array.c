#include "stdio.h"
#include "stdlib.h"
#include "Array.h"

Array* createArr()
	{
	return (Array*)calloc(1, sizeof(Array));
	}

void initWorkerArr(Array* self,size_t workerArrLength)
	{
	self->length= workerArrLength;
	self->workerArr = (Worker**)calloc(workerArrLength,sizeof(Worker));
	}

void setInitWorkerArr(Array* self)
	{
	self->init = initWorkerArr;
	}

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

void freeArray(Array* self)
	{
	for (size_t i = 0; i < self->length; i++)
		{
		freeWorker(self->workerArr[i]);
		}
	free(self->workerArr);
	free(self);
	}
