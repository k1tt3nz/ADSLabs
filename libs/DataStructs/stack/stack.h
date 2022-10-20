#ifndef STACK2_H
#define STACK2_H

#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define STACK_OK 0
#define STACK_OVER 101
#define STACK_EMPTY 102
#define STACK_ALLOCATE_MEM 103

#define ERROR_HANDLING(ERR) \
switch (ERR) { \
    case 101: \
        fprintf(stderr,"Warning: Stack over" "\n"); \
        break; \
    case 102: \
        fprintf(stderr,"Warning: Stack empty" "\n"); \
        break; \
    case 103: \
    fprintf(stderr,"Warning: Failed to allocate memory for stack" "\n"); \
        break; \
}

typedef struct Stack{
    int top;
    size_t capacity;
    int *arr;
}Stack;

// Инициализация стека
void InitStack(Stack *st, size_t sizeBuf);

// Проверяет пуст ли стек
bool isEmptyStack(Stack *st);

// Проверяет заполнен ли стек
bool isFullStack(Stack *st);

//Помещает элемент в стек
void Push(Stack *st, int item);

// Извлекает элемент из стека
void Pop(Stack *st, int *item);

// Считывает элемент из стека
void Peek(Stack *st, int *item);

// Удаляет стек освобождая память
void DeleteStack(Stack *st);


#include "stack.c"

#endif //STACK2_H
