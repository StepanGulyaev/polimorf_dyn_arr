#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stddef.h"
#include "ServiceFunctions.h"

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
            printf("Input string is too long. String size limit: % llu. Input will be deleted.", limit);
            free(string);
            return NULL;
            }
        }
    return string;
    }