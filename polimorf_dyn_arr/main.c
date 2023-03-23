#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Worker.h"
#include "Array.h"


#define STRING_SIZE_LIMIT 100

char* read_string(size_t limit)
    {
    char* string = (char*)calloc(1, sizeof(char));
    size_t length = 1;
    string[0] = '\0';
    while (1)
        {
        char symbol = getc(stdin);

        if (symbol == '\n')
            {
            break;
            }
        length++;

        char* test_not_null = (char*)realloc(string, length * sizeof(char));
        if (test_not_null == NULL)
            {
            printf("Not enough memory to store input string.Input will be deleted\n");
            free(string);
            return NULL;
            }

        string = test_not_null;
        string[length - 1] = '\0';
        string[length - 2] = symbol;

        if (length >= limit)
            {
            printf("Input string is too long. String size limit: % llu. Input will be deleted.",limit);
            free(string);
            return NULL;
            }
        }
    return string;
    }

int main()
	{
    Array* arr = createArr();
    setInitWorkerArr(arr);
    arr->init(arr,0);

    for (size_t i = 0; i < 3; i++)
        {
        Worker* worker = createWorker();
        char* inputStr;

        string_input_error: 
        inputStr = read_string(STRING_SIZE_LIMIT);

        if (inputStr == NULL)
            {
            goto string_input_error;
            }
        
        char** workerInfo = workerDataParser(inputStr);
        initWorker(worker,workerInfo);

        setPushWorkerArr(arr);
        pushWorkerArr(arr,worker);

        free(inputStr);
        }

    setPrintWorkerArr(arr);
    arr->print(arr);
    freeArray(arr);

    return 1;
	}