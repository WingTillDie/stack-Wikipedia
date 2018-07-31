#include <stdio.h>
#include <stdlib.h>

typedef int item;

typedef struct frame{
	item data;
	struct frame *next;
} frame;

typedef struct stack{
	frame *head;
	int size;
}stack;

void initialize(stack *stk);
void print(stack stk);
void push(stack *stk, item x);
item pop(stack *stk);
void free_stack(stack *stk);

int main(){
	stack stk;
	initialize(&stk);
	push(&stk, 3);
	push(&stk, 4);
	print(stk);
	
	pop(&stk);
	print(stk);
	pop(&stk);
	print(stk);
	pop(&stk);
	print(stk);
	free_stack(&stk);
}

void initialize(stack *stk){
	stk->head=NULL;
	stk->size=0;
}

void print(stack stk){
	frame *current=stk.head;
	if(current==NULL){
		printf("Stack is empty.\n");
		return;
	}
	for(int i=0; i<stk.size; i++){
		printf("%d ", current->data);
		current=current->next;
	}
	printf("\n");
}

void push(stack *stk, item x){
	frame *newhead=malloc(sizeof(frame));
	newhead->data=x;
	newhead->next=stk->head;
	stk->head=newhead;
	stk->size++;
}

item pop(stack *stk){
	frame *old_head=stk->head;
	if(old_head==NULL){
		printf("Pop failed: stack is empty.\n");
		return -1;
	}
	item r=stk->head->data;
	stk->head=stk->head->next;
	free(old_head);
	stk->size--;
	return r;
}

void free_stack(stack *stk){
	frame *current=stk->head;
	for(int i=0; i<stk->size; i++){
		frame *next=current->next;
		free(current);
		current=next;
	}
	stk->head=NULL;
	stk->size=0;
}
