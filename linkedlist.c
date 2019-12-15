#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *create(int data){
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void traverse(struct node *head){
	struct node *temp = head;
	if(head == NULL){
		printf("Head is NULL \n");
		return;
	}
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	print("\n");
}

void reverse(struct node **head){
	struct node *cur,*prev;

	if(head!=NULL){
		prev = *head;
		cur = (*head)->next;
		*head = (*head)->next;

		prev->next = NULL;

		while(*head!=NULL){
			*head = (*head)->next;
			cur->next = prev;
			prev = cur;
			cur = *head;

		}
		*head = prev;
	}
	
}

int count(struct node *head){
	struct node *temp = head;
	int c = 0;
	if(head == NULL){
		return 0;
	}
	while(temp!=NULL){
		temp = temp->next;
		c++;
	}
	return c;
}

void push(struct node **head,int data){
	struct node *new = create(data);
	if(*head == NULL){
		*head = new;
		return;
	}
	new->next = *head;
	*head = new;	
	}

void append(struct node *head,int data){
	struct node *new = create(data);
	if(head == NULL){
		head = new;
	}
	struct node *temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next = new;

}

void insert(struct node **head,int data,int pos){
	struct node *new = create(data);
	if(pos == 0){
		new->next=(*head);
		*head = new;
	}
	if(pos>count(*head)){
		printf("You cant add node to this position \n");
		return;
	}
	struct node *temp = *head;
	struct node *t;
	int c = 0;
	while(c<pos-1){
		temp = temp->next;
		c++;
	}
	t = temp->next;
	temp->next = new;
	new->next = t;

}

void delete_first(struct node **head){
	if(*head == NULL){
		return;
	}

	struct node *temp = *head;
	*head = (*head)->next;
	free(temp);
}

void delete_pos(struct node **head,int pos){
	struct node *temp = *head;
	if(pos == 0){
		*head = (*head)->next;
		free(temp);
		return;
	}

	int c = 1;
	while(c<pos && temp->next->next!=NULL){
		temp=temp->next;
		c++;
	}
	if(pos>count(*head)-1 || pos<0){
		printf("Invalid position\n");
		return;
	}
	else{
		struct node *t = temp->next;
		free(t);
		temp->next = temp->next->next;
	}


}

void delete_last(struct node **head){
	struct node *temp = *head,*prev;
	if(temp->next == NULL){
		*head = NULL;
		return;
	}
	else if(temp == NULL){
		return;
	}
	else{	
		prev = temp;
		temp = temp->next;
		while(temp->next!=NULL){
			temp = temp->next;
			prev = prev->next;
	}
	free(temp);
	prev->next = NULL;}
}

void search_element(struct node *head,int data){
	if(head == NULL){
		printf("Not found\n");
		return;
	}
	struct node *temp = head;
	int c = 1;
	while(temp->next!=NULL && temp->data !=data){
		temp = temp->next;
		c++;
	}
	if(temp->data == data){
		printf("Element found at node %d \n",c);
	}
	else{
		printf("Not found\n");
	}
}

int main(){
	
	struct node *head = NULL;
	push(&head,11);
	push(&head,22);
	push(&head,33);
	push(&head,44);
	traverse(head);
	reverse(&head);
	traverse(head);
	append(head,11);
	traverse(head);
	insert(&head,2,3);
	traverse(head);
	delete_first(&head);
	traverse(head);
	delete_pos(&head,3);
	traverse(head);
	delete_last(&head);
	traverse(head);
	search_element(head,33);



	printf("The number of nodes: %d \n",count(head));

	return 0;
}
