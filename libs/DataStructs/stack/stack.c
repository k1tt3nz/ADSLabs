#include "stack.h"

void InitStack(Stack *st, size_t sizeBuf){
    st->arr = malloc(sizeof(int) * sizeBuf);
    st->capacity = sizeBuf;
    st->top = 0;
}

bool isEmptyStack(Stack *st){
    return st->top == 0;
}

bool isFullStack(Stack *st){
    return st->top == st->capacity;
}

void PutStack(Stack *st, int item){
    if(isFullStack(st)){
        errno = STACK_OVER;
        perror("Error");
    }else
        st->arr[st->top++] = item;
}

void GetStack(Stack *st,int item);

void ReadStack(Stack *st);

void DoneStack(Stack *st);