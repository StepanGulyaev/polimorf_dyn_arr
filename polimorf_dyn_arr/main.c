#define DEBUG

#ifdef DEBUG
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif



#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stddef.h"
#include "Worker.h"
#include "Array.h"

int main()
	{

    size_t size;
    printf("Enter size of workers arr: ");
    scanf("%llu%*c",&size);
    Array* arrWorkers = createArr();
    setWorkerMode(arrWorkers);
    arrWorkers->init(arrWorkers, size);
    arrWorkers->fill(arrWorkers);
    arrWorkers->print(arrWorkers);
    arrWorkers->freeArr(arrWorkers);

    printf("Enter size of students arr: ");
    scanf("%llu%*c", &size);
    Array* arrStudents = createArr();
    setStudentMode(arrStudents);
    arrStudents->init(arrStudents, size);
    arrStudents->fill(arrStudents);
    arrStudents->print(arrStudents);
    arrStudents->freeArr(arrStudents);

    #ifdef DEBUG
        _CrtDumpMemoryLeaks();
    #endif

    return 0;
	}