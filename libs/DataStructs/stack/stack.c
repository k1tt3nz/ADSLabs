#include "stack.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <malloc.h>

void InitStack(Stack *st, size_t sizeBuf){
    st->arr = malloc(sizeof(int) * sizeBuf);
    if(st->arr == NULL){
        errno = STACK_ALLOCATE_MEM;
        ERROR_HANDLING(errno);
        return;
    }

    st->capacity = sizeBuf;
    st->top = -1;
}

bool isEmptyStack(Stack *st){
    return st->top == -1;
}

bool isFullStack(Stack *st){
    return st->top == st->capacity - 1;
}

void Push(Stack *st, int item){
    if(isFullStack(st)){
        errno = STACK_OVER;
        ERROR_HANDLING(errno);
    }
    else
        st->arr[++st->top] = item;
}

void Pop(Stack *st, int *item){
    if(isEmptyStack(st)){
        errno = STACK_EMPTY;
        ERROR_HANDLING(errno);
    }

    *item = st->arr[st->top--];
}

void Peek(Stack *st, int *item){
    if(isEmptyStack(st)){
        errno = STACK_EMPTY;
        ERROR_HANDLING(errno);
    }

    *item = st->arr[st->top];
}

void DeleteStack(Stack *st){
    free(st->arr);
    st->top = NULL;
    st->capacity = NULL;
}

