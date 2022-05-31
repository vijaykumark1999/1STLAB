
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StackI
{
	int top;
	unsigned capacity;
	int* arr;
};

struct StackI* createStack( unsigned capacity )
{
	struct StackI* stackV = (struct StackI*)
		malloc(sizeof(struct StackI));

	if (!stackV)
		return NULL;

	stackV->top = -1;
	stackV->capacity = capacity;

	stackV->arr = (int*) malloc(stackV->capacity *
								sizeof(int));
	return stackV;
}

int isEmpty(struct StackI* stackV)
{
	return stackV->top == -1 ;
}

char peek(struct StackI* stackv)
{
	return stackv->arr[stackv->top];
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

int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') ||
		(ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int infixToPostfix(char* exp)
{
	int i, k;

	struct StackI* stackV = createStack(strlen(exp));
	if(!stackV)
		return -1 ;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		if (isOperand(exp[i]))
			exp[++k] = exp[i];

		else if (exp[i] == '(')
			push(stackV, exp[i]);

		else if (exp[i] == ')')
		{
			while (!isEmpty(stackV) && peek(stackV) != '(')
				exp[++k] = pop(stackV);
			if (!isEmpty(stackV) && peek(stackV) != '(')
				return -1;
			else
				pop(stackV);
		}
		else
		{
			while (!isEmpty(stackV) &&
				precedence(exp[i]) <= precedence(peek(stackV)))
				exp[++k] = pop(stackV);
			push(stackV, exp[i]);
		}

	}

	while (!isEmpty(stackV))
		exp[++k] = pop(stackV);

	exp[++k] = '\0';
	printf( "%s", exp );
}

void main()
{
	char exp[50];
	printf("Enter the INFIX NOTATION: \n");
	scanf("%s",&exp);
	printf("\nPOSTFIX NOTATION:\n");
	infixToPostfix(exp);
}
