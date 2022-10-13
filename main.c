#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>
#include <conio.h>
#include "stack.h"
#include "sort.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "stack.h"

void outputArray(int *a, const size_t size){
    for (size_t i = 0; i < size - 1; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}



#define ARR_SIZE 3

int main(void) {
    system("chcp 1251");

    Stack st1;
    InitStack(&st1,1);
    PutStack(&st1,1);
    PutStack(&st1,1);
    getchar();



    return EXIT_SUCCESS;
}
