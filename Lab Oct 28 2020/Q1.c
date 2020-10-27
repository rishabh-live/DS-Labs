/*
*Name = Rishabh
*Reg No = 201800631
*Dept = IT
*Lab Date = 28 Sep 2020
*Lab Work : 9
*
*AIM :  C program to Push, Pop and Display Stack
*/



#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
	int data;   			// integer data
	struct Node* next;  	// pointer to the next node
};

// Utility function to add an element x in the stack
void push(struct Node **top, int x) // insert at the beginning
{
	// Allocate the new node in the heap
	struct Node* node = NULL;
	node = (struct Node*)malloc(sizeof(struct Node));

	// check if stack (heap) is full. Then inserting an element would
	// lead to stack overflow
	if (!node)
	{
		printf("\nHeap Overflow");
		exit(1);
	}

	printf("Inserting %d\n", x);

	// set the data in allocated node
	node->data = x;

	// Set the .next pointer of the new node to point to the current
	// top node of the list
	node->next = *top;

	// update top pointer
	*top = node;
}

// Utility function to check if the stack is empty or not
int isEmpty(struct Node* top)
{
	return top == NULL;
}

// Utility function to return top element in a stack
int peek(struct Node *top)
{
	// check for empty stack
	if (!isEmpty(top))
		return top->data;
	else
		exit(EXIT_FAILURE);
}

// Utility function to pop top element from the stack
void pop(struct Node** top) // remove at the beginning
{
	struct Node *node;

	// check for stack underflow
	if (*top == NULL)
	{
		printf("\nStack Underflow");
		exit(1);
	}

	printf("Removing %d\n", peek(*top));

	node = *top;

	// update the top pointer to point to the next node
	*top = (*top)->next;

	// free allocated memory
	free(node);
}

int main(void)
{
	struct Node *top = NULL;

	
	push(&top, 5);
	printf("Top element is %d\n", peek(top));
	
	push(&top, 7);
	printf("Top element is %d\n", peek(top));
    
    push(&top, 12);
	printf("Top element is %d\n", peek(top));
    
    push(&top, 8);
	printf("Top element is %d\n", peek(top));
    
    push(&top, 10);
	printf("Top element is %d\n", peek(top));
	
	push(&top, 1);
	printf("Top element is %d\n", peek(top));
    
	pop(&top);
	printf("Top element is %d\n", peek(top));
	pop(&top);
	printf("Top element is %d\n", peek(top));
	pop(&top);
	printf("Top element is %d\n", peek(top));
	pop(&top);
	printf("Top element is %d\n", peek(top));
    pop(&top);
	printf("Top element is %d\n", peek(top));
    pop(&top);
	printf("Top element is %d\n", peek(top));


	if (isEmpty(top))
		printf("Stack is empty");
	else
		printf("Stack is not empty");

	return 0;
}