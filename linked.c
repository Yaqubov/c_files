#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data[128];
    struct node *next;
};

struct node *create(char soz[128]){
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->next = NULL;
    strcpy(nn->data,soz);
    return nn;
}

void traverse(struct node *head){
    struct node *temp = head;
    while(temp->next != NULL){
        printf("%s ",temp->data);
        temp = temp -> next;
    }
    printf("\n");
}

void append(struct node *head,char word[128]){
	struct node *new = create(word);
	if(head == NULL){
		head = new;
	}
	struct node *temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next = new;
}

int main(){

    FILE *file = fopen("/home/smv18/Desktop/test.txt","w");
    struct node *head;
    append(head,"salam");
    append(head,"necesen");
    append(head,"menim");
    append(head,"qardasim");
    traverse(head);
    struct node *temp = head;
    while(temp != NULL){
        fputs(temp->data,file);
        temp=temp->next;
    }
    
    fclose(file);
    return 0;
}

