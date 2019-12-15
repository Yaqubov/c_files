#include<stdio.h>
#include<stdlib.h>

struct queue{
	int *buff;
	int first;
    int last;
	int size;
	int count;
};

struct queue *init(int size){
	struct queue *qq = (struct queue*)malloc(sizeof(struct queue));
	qq->buff = (int*)malloc(sizeof(int)*size);
	qq->first = 0;
    qq->last = -1;
	qq->size = size;
	qq->count = 0;
	return qq;
}

void enqueue(struct queue *qq,int data){
	if(qq->count < qq->size){
		qq->last = (qq->last + 1)%qq->size;
        qq->buff[qq->last] = data;
		qq->count = qq->count + 1;
    }

}

int dequeue(struct queue *qq){
	if (qq->count == 0){
		return 1e9;
	}
	int res = qq->buff[qq->first];
	qq->first = (qq->first + 1)%qq->size;
    qq->count = qq->count -1;
	return res;
}

 
int search(struct queue *qq,int data){
	int i = qq->first;
	int c = qq->count;
	while(c-- && qq->buff[i] != data){
	    i = (i+1)%qq->size;
	}
	if(qq->buff[i] == data){
		return i;
	}
	else
		return -1e9;

}

int min_in_queue(struct queue *qq){
	int i = qq->first;
	int min = qq->buff[qq->first];
    int c = qq->count;
	while(c--){
        if(qq->buff[i] < min){
            min = qq->buff[i];
        }
        i = (i+1)%qq->size;
    }
	return min;
}

int max_in_queue(struct queue *qq){
	int i = qq->first;
	int max = qq->buff[qq->first];
    int c = qq->count;
	while(c--){
        if(qq->buff[i] > max){
            max = qq->buff[i];
        }
        i = (i+1)%qq->size;
    }
	return max;
}

void traverse(struct queue *qq){
	if(qq->count == 0){
		return;
	}
	int i = qq->first;
    int c = qq->count;
	while(c--){
        printf("%d ",qq->buff[i]);
        i = (i+1)%qq->size;
    }
	printf("\n");
}

int main(){
	struct queue *qq = init(5);
	enqueue(qq,11);
	enqueue(qq,22);
	enqueue(qq,33);
	enqueue(qq,44);
	enqueue(qq,55);
    traverse(qq);
    printf("%d\n",dequeue(qq));
    printf("%d\n",dequeue(qq));
    enqueue(qq,77);
    enqueue(qq,88);
	traverse(qq);
	printf("The number of elements in queue: %d\n",qq->count);
	printf("Max element in queue: %d\n",max_in_queue(qq));
	printf("Position of max element in queue: %d \n",search(qq,max_in_queue(qq)));
	printf("Min element in queue: %d\n",min_in_queue(qq));
	printf("Position of min element in queue: %d\n",search(qq,min_in_queue(qq)));

	return 0;
}
