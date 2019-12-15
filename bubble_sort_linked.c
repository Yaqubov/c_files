#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *init(int data){
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

void append(struct node **head,int data){
    struct node *new = init(data);
    struct node *temp = *head;
    if(*head == NULL){
        *head = new;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
}

void bubble_sort(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        struct node *temp1 = head;
        while(temp1->next != NULL){
            if(temp1->next->data <temp1->data){
                int t = temp1->next->data;
                temp1->next->data = temp1->data;
                temp1->data = t;
            }
            temp1=temp1->next;
        }
        temp=temp->next;
    }
}

void traverse(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *head = NULL;
    append(&head,11);
    append(&head,99);
    append(&head,55);
    append(&head,44);
    append(&head,1);
    traverse(head);
    bubble_sort(head);
    traverse(head);
}











