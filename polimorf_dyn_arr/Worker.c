
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Worker.h"


Worker* createWorker()
	{
	return (Worker*)calloc(1, sizeof(Worker));
	}

void initWorker(Worker* self, char** info)
	{
	self->name = (char*)calloc(strlen(info[0])+1,sizeof(char));
    strcpy(self->name,info[0]);
    self->age= atoi(info[1]);

    free(info[0]);
    free(info[1]);
    free(info);
	}

char** workerDataParser(char* inputStr)
    {
	char** info = (char**)calloc(2, sizeof(char*));
	char* name = strtok(inputStr, " ");
	info[0] = (char*)calloc(strlen(name) + 1, sizeof(char));
	char* age = strtok(NULL, "");
	info[1] = (char*)calloc(strlen(age) + 1, sizeof(char));
	strcpy(info[0], name);
	strcpy(info[1], age);
	return info;
    }

void printWorkerInfo(Worker* self)
	{
	printf("Name: %s; Age: %d\n",self->name,self->age);
	}

void freeWorker(Worker* self)
	{
	free(self->name);
	free(self);
	}