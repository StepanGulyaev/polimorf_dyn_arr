#ifndef WORKER_H
#define WORKER_H

#include "stdlib.h"

typedef struct Worker
	{
	char* name;
	size_t age;

	} Worker;

Worker* createWorker();
void initWorker(Worker* self,char** info);
char** workerDataParser(char* inputStr);
void printWorkerInfo(Worker* self);
void freeWorker(Worker* self);


#endif