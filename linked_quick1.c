#include<stdio.h>
#include<stdlib.h>
int in = -1;

struct node{
    int data ;
    struct node*next ;
    int index ;
};
struct node* init (int data){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    in++;
    new->index=in;
}

void append(struct node **head,int data){
    struct node *temp = *head;
    struct node *new = init(data);
    if(*head == NULL){
        *head = new;
        return;
    }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = new;
}

int in_index(struct node *head,int index){
    struct node *temp = head;
    while(temp!=NULL){
        if(temp->index == index){
            return temp->data;                
        }
        temp=temp->next;
    }
}

void swap(struct node *head,int i,int j){
    struct node *temp=head;
    struct node *temp1,*temp2;
    while(temp!=NULL){
        if(temp->index == i){
            temp1 = temp;
        }
        if(temp->index == j){
            temp2 = temp;
        }
        temp=temp->next;
    }
    int t = temp1->data;
    temp1->data = temp2->data;
    temp2->data = t;
}

void quick_sort(struct node* head,int low,int high){
    int pivot , i , j  , temp ;
    if(low<high){
        pivot = low;
        i = low;
        j = high;
        while(i<j){
            while(in_index(head,i) <= in_index(head,pivot) && i<high){
                i++;
            }
            while(in_index(head,j) > in_index(head,pivot)){
                j--;
            }
            if (i<j){
                swap(head,i,j);
            }
        }
        swap(head,pivot,j);
        quick_sort(head,low,j-1);
        quick_sort(head,j+1,high);
    }
}



void traverse(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node *head = NULL;
    append(&head,55);
    append(&head,6);
    append(&head,11);
    append(&head,27);
    append(&head,1);
    traverse(head);
    quick_sort(head,0,in);
    traverse(head);
}



















