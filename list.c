#include "stack.h"
#ifndef VECTOR
#include <stdlib.h>

void create_stack(int SIZE, stack* s) {
    s->SIZE_M = SIZE;
    s->size = -1;
    s->top_item = NULL;
}

int push(char data, stack* s) {
    s->size++;
    item* i = (item*)malloc(sizeof(item));
    i->item = data;
    i->next = s->top_item;
    s->top_item = i;
    return OK;
}

int pop(char* data, stack* s) {
    if (s->size == -1)
        return UN;
    *data = (s->top_item)->item;
    s->size--;
    item* i = s->top_item;
    s->top_item = (s->top_item)->next;
    free(i);
    return OK;
}

int top(char* data, stack* s) {
    if (s->size == -1)
        return UN;
    else {
        *data = s->top_item->item;
        return OK;
    }
}

void print_stack(stack* s) {
    item* i = s->top_item;
    while (i != NULL) {
        printf("%c", i->item);
        i = i->next;
    }
}

void free_stack(stack* s) {
    while (s->top_item != NULL) {
        item* i = s->top_item;
        s->top_item = s->top_item->next;
        free(i);
    };
}
#endif

