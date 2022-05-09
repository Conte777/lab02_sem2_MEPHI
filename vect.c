#include "stack.h"
#ifdef VECTOR
#include <stdlib.h>

void create_stack(int SIZE, stack* s) {
	s->items = (char*)malloc(SIZE * sizeof(char));
	s->SIZE_M = SIZE;
	s->size = -1;
}

int push(char data, stack* s) {
	if (s->size == s->SIZE_M - 1)
		return OF;
	s->size++;
	s->items[s->size] = data;
	return OK;
}

int pop(char* data, stack* s) {
	if (s->size == -1)
		return UN;
	*data = s->items[s->size];
	s->size--;
	return OK;
}

int top(char* data, stack* s) {
	if (s->size == -1)
		return UN;
	else {
		*data = s->items[s->size];
		return OK;
	}
}

void print_stack(stack* s) {
	int i;
	for (i = s->size; i > -1; i--) {
		printf("%c", s->items[i]);
	}
}

void free_stack(stack* s) {
	free(s->items);
}
#endif

