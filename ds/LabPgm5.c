#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct StackI
{
	int top;
	unsigned capacity;
	int* arr;
};

struct StackI* createStack( unsigned capacity )
{
	struct StackI* stackV = (struct StackI*) malloc(sizeof(struct StackI));
	if (!stackV)
        return NULL;
	stackV->top = -1;
	stackV->capacity = capacity;
	stackV->arr = (int*) malloc(stackV->capacity * sizeof(int));

	if (!stackV->arr)
        return NULL;

	return stackV;
}

int isEmpty(struct StackI* stackV)
{
	return stackV->top == -1 ;
}

char peek(struct StackI* stackV)
{
	return stackV->arr[stackV->top];
}

char pop(struct StackI* stackV)
{
	if (!isEmpty(stackV))
		return stackV->arr[stackV->top--] ;
	return '$';
}

void push(struct StackI* stackV, char op)
{
	stackV->arr[++stackV->top] = op;
}

int evaluatePostfix(char* exp)
{
	struct StackI* stackV = createStack(strlen(exp));
	int i;

	if (!stackV)
        return -1;
	for (i = 0; exp[i]; ++i)
	{
		if (isdigit(exp[i]))
			push(stackV, exp[i] - '0');

		else
		{
			int val1 = pop(stackV);
			int val2 = pop(stackV);
			switch (exp[i])
			{
			case '+': push(stackV, val2 + val1); break;
			case '-': push(stackV, val2 - val1); break;
			case '*': push(stackV, val2 * val1); break;
			case '/': push(stackV, val2/val1); break;
			}
		}
	}
	return pop(stackV);
}

void main()
{
	char exp[30];
	printf("Enter the postfix Expression: \n");
	scanf("%s",&exp);
	printf ("postfix evaluation: %d", evaluatePostfix(exp));
}

