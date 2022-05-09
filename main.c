#include "stack.h"

int prior(char data, stack* sign, stack* res) {
	char a = 0;
	int k = top(&a, sign);
	switch (data) {
	case '+':
	case '-':
		if (k == UN || a == ')') {
			if (push(data, sign) == OF)
				return OF;
		}
		else {
			while (k != UN && a != ')') {
				char b;
				if (pop(&b, sign) == UN)
					return UN;
				if (push(b, res) == OF)
					return OF;
				k = top(&a, sign);
			}
			if (push(data, sign) == OF)
				return OF;
		}
		return OK;
	case '*':
	case '/':
		if (k == UN || a == ')' || a == '+' || a == '-') {
			if (push(data, sign) == OF)
				return OF;
		}
		else {
			while (k != UN && a != ')' && a != '+' && a != '-') {
				char b;
				if (pop(&b, sign) == UN)
					return UN;
				if (push(b, res) == OF)
					return OF;
				k = top(&a, sign);
			}
			if (push(data, sign) == OF)
				return OF;
		}
		return OK;
	case '(':
		top(&a, sign);
		while (a != ')') {
			char b;
			if (pop(&b, sign) == UN)
				return UN;
			if (push(b, res) == OF)
				return OF;
			top(&a, sign);
		}
		pop(&a, sign);
		return OK;
	case ')':
		if (push(data, sign) == OF)
			return OF;
		return OK;
	default:
		if (push(data, res) == OF)
			return OF;
		return OK;
	}
}

int push_res(stack* sign, stack* res) {
	char a;
	while (top(&a, sign) != UN) {
		if (pop(&a, sign) == UN)
			return UN;
		if (push(a, res) == OF)
			return OF;
	}
	return OK;
}

int main() {
#ifdef VECTOR
	printf("VECTOR\n");
#else
	printf("LIST\n");
#endif
	stack sign, res, s;
	int size = 100;
	create_stack(size, &sign);
	create_stack(size, &res);
	create_stack(size, &s);
	char data;
	int flag = 1;
	printf("Enter formula in infix notation: ");
	scanf("%c", &data);
	while (data != '\n') {
		if (push(data, &s) == OF) {
			flag = 0;
			printf("OverFlow");
			break;
		}
		scanf("%c", &data);
	}
	while (top(&data, &s) != UN && flag) {
		char a;
		flag = 1;
		pop(&a, &s);
		switch (prior(a, &sign, &res)) {
		case OF:
			printf("Overflow");
			flag = 0;
			break;
		case UN:
			printf("Underflow");
			flag = 0;
			break;
		}
	}
	if (flag) {
		int k = push_res(&sign, &res);
		if (k == UN) {
			printf("Underflow");
			flag = 0;
		}
		if (k == OF) {
			printf("Overflow");
			flag = 0;
		}
	}
	if (flag) {
		printf("Formula in prefix representation: ");
		print_stack(&res);
		printf("\n");
	}
	free_stack(&sign);
	free_stack(&res);
	free_stack(&s);
	return 0;
}
