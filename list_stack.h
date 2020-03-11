#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
typedef int item_type;
struct Stack_node {
 item_type item;
 Stack_node *next;
};
struct Stack {
	Stack_node *top;

bool isEmptyStack(Stack *s) {
	return (!s->top)?true:false;
}

item_type Stack_pop(Stack *s) {
	if (isEmptyStack(s)) return NULL;
	 else {
	    Stack_node *temp;
	 	item_type x;
	 	x=s->top->item;
	 	temp=s->top;
	 	s->top=s->top->next;
	 	free(temp);
	 	return x;
	 }
};
void Stack_destroy (Stack *s) {

	while(!isEmptyStack(s)) {
	Stack_pop(s);
} free(s);
}
int Stack_full(){
	printf("No Memory!!");
	getch();
}

int Stack_push(Stack *s,item_type x) {
	Stack_node *node;
	node=(Stack_node*)malloc(sizeof(Stack_node));
	if (!node) {
		Stack_full(); return 1;
	} else
	{
		node->item=x;
		node->next=s->top;
		s->top=node;
		return 0;
	}
}


