#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct id{
	int idnum;
	char *name;
	char *surname;
};

struct customer{
	struct id *number;
	struct customer *next;

};

int count = 1; 

struct customer *create(char *name, char *sur){
	struct customer *nn = (struct customer*)malloc(sizeof(struct customer));
	struct id *nm = (struct id*)malloc(sizeof(struct id));
	nm->name = name;
	nm->surname = sur;
	nm->idnum = count;
	count++;
	nn->number = nm;
	nn->next = NULL;
	return nn;
} 

void push(struct customer **head,char *n,char *s){
	struct customer *new = create(n,s);
	if(*head == NULL){
		*head = new;
		return;
	}
	new->next = *head;
	*head = new;
}
void traverse(struct customer *head){
	struct customer *temp = head;
	while(temp != NULL){
		printf("%d %s %s \n",temp->number->idnum,temp->number->name,temp->number->surname);
		temp = temp->next;
	}
}

int main(){
	struct customer *head = NULL;
	push(&head,"Tahir","Yagubov");
	push(&head,"Bahman","Musayev");
	push(&head,"Magsud","Mirzazada");
	traverse(head);


	return 0;
}

