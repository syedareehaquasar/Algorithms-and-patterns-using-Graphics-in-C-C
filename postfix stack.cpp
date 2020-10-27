#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 

// Stack declaration
struct Stack 
{ 
	int top; 
	unsigned capacity; 
	int* array; 
}; 

struct Stack* evalStack( unsigned capacity ) 
{ 
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

	if (!stack) return NULL; 

	stack->top = -1; 
	stack->capacity = capacity; 
	stack->array = (int*) malloc(stack->capacity * sizeof(int)); 

	if (!stack->array) return NULL; 

	return stack; 
} 

// checking whether stack is empty or not
int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1 ; 
} 

//peek stack
char peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
} 

// poping out
char pop(struct Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 

// for pushing elements
void push(struct Stack* stack, char op) 
{ 
	stack->array[++stack->top] = op; 
} 


// takes expression as input and evaluates postfix expression 
int evaluatePostfix(char* exp) 
{ 
	struct Stack* stack = evalStack(strlen(exp)); 
	int i; 

	if (!stack) return -1; 

	// Scan all characters one by one 
	for (i = 0; exp[i]; ++i) 
	{ 
		if (isdigit(exp[i])) {
			printf("\n %c \n", exp[i]);
			push(stack, exp[i] - '0'); }

		else
		{ 
			int val1 = pop(stack); 
			int val2 = pop(stack); 
			switch (exp[i]) 
			{ 
			case '+': push(stack, val2 + val1); break; 
			case '-': push(stack, val2 - val1); break; 
			case '*': push(stack, val2 * val1); break; 
			case '/': push(stack, val2/val1); break; 
			} 
		} 
	} 
	return pop(stack); 
} 

int main() 
{ 
	char exp[] = "921*-8-4+"; 
	printf ("Enter the postfix expression\n");
	scanf("%s",exp);
	printf ("postfix evaluation: %d", evaluatePostfix(exp)); 
	return 0; 
}
