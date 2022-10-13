#ifndef STACK2_H
#define STACK2_H

#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define STACK_OK 0
#define STACK_OVER 101 
#define STACK_UNDER 102

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
void PutStack(Stack *st, int item);

// Извлекает элемент из стека
void GetStack(Stack *st,int item);

// Считывает элемент из стека
void ReadStack(Stack *st);

// Удаляет стек освобождая память
void DoneStack(Stack *st);


#include "stack.c"

#endif //STACK2_H
