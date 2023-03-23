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
    Array* arrWorkers = createArr();
    setInitWorkerArr(arrWorkers);
    arrWorkers->init(arrWorkers,0);

    for (size_t i = 0; i < 3; i++)
        {
        Worker* worker = createWorker();
        char* inputStr;

        string_input_error_workers:
        inputStr = read_string(STRING_SIZE_LIMIT);

        if (inputStr == NULL)
            {
            goto string_input_error_workers;
            }
        
        char** workerInfo = workerDataParser(inputStr);
        initWorker(worker,workerInfo);

        setPushWorkerArr(arrWorkers);
        pushWorkerArr(arrWorkers,worker);

        free(inputStr);
        }

    Array* arrStudents = createArr();
    setInitStudentArr(arrStudents);
    arrStudents->init(arrStudents, 0);

    for (size_t i = 0; i < 2; i++)
        {
        Student* student = createStudent();
        char* inputStr;

        string_input_error_students:
        inputStr = read_string(STRING_SIZE_LIMIT);

        if (inputStr == NULL)
            {
            goto string_input_error_students;
            }

        char** studentInfo = studentDataParser(inputStr);
        initStudent(student, studentInfo);

        setPushStudentArr(arrStudents);
        pushStudentArr(arrStudents, student);

        free(inputStr);
        }

    setPrintWorkerArr(arrWorkers);
    arrWorkers->print(arrWorkers);

    setPrintStudentArr(arrStudents);
    arrStudents->print(arrStudents);

    setFreeWorkerArr(arrWorkers);
    arrWorkers->freeArr(arrWorkers);

    setFreeStudentArr(arrStudents);
    arrStudents->freeArr(arrStudents);

    return 1;
	}