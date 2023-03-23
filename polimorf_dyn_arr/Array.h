#ifndef ARRAY_H
#define ARRAY_H

#include "stdio.h"
#include "stdlib.h"
#include "Worker.h"

typedef struct Array
	{
	Worker** workerArr;
	size_t length;

	void(*init)(struct Array* self,size_t workerArrLength);
	void(*push)(struct Array* self);
	void(*print)(struct Array* self);

	} Array;

Array* createArr();

void initWorkerArr(Array* self, size_t workerArrLength);
void setInitWorkerArr(Array* self);

void pushWorkerArr(Array* self,Worker* to_push);
void setPushWorkerArr(Array* self);

void printWorkerArr(Array* self);
void setPrintWorkerArr(Array* self);

void freeArray(Array* self);



#endif
