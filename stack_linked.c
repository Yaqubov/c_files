#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *init(int data){
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	return new;
}

void push(struct node **top,int data){
	struct node *new = init(data);
    struct node *temp = *top;
	if(*top == NULL){
		*top == new;
	}
    new->next = *top;
    *top = new;
}

int pop(struct node **top){
    struct node *temp = *top;
    *top = (*top)->next;
    return temp->data;
}

void traverse(struct node *top){
    while(top!=NULL){
        printf("%d ",pop(&top));
    }
    printf("\n");
}

int main(){
	struct node *top = NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    traverse(top);
    






}
