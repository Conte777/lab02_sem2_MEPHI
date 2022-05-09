#include <stdio.h>
//#define VECTOR 

typedef enum {
    OK = 0,
    OF = -1,
    UN = -2
}errors;

#ifndef VECTOR
typedef struct item {
    char item;
    struct item* next;
}item;
#endif

typedef struct stack {
    int SIZE_M;
    int size;
#ifdef VECTOR
    char* items;
#else
    item* top_item;
#endif
}stack;

void create_stack(int SIZE, stack* s);

int push(char data, stack* s);

int pop(char* data, stack* s);

void print_stack(stack* s);

int top(char* data, stack* s);

void free_stack(stack* s);