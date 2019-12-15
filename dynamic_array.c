#include<stdio.h>
#include<stdlib.h>

struct vektor{
	int *buff;
	int size;
	int pos;
};

struct vektor *init(int size){
	struct vektor *v = (struct vektor*) malloc(sizeof(struct vektor));
	v->buff = (int*)  malloc(sizeof(int) * size);
	v->size = size;
	v->pos = -1;
}

void push(struct vektor *v, int data){
	if(v->pos >= v->size)
		return;
	v->pos = (v->pos) + 1;
	v->buff[v->pos] = data;

}

void print_arr(struct vektor *v){
	v->pos = 0;
	while(v->buff[v->pos] != 0 && v->pos <= v->size ){
		printf("%d ",v->buff[v->pos]);
		v->pos++;
	}
	printf("\n");
}

void change_element(struct vektor *v,int data,int pos){
	if(pos >= v->size)
		return;
	v->pos = pos;
	v->buff[v->pos] = data; 

}
int pop(struct vektor *v){
	if(v->pos <= -1)
		return -1e9;
	int res = v->buff[v->pos--];
	return res;
}
int main(){
	struct vektor *v = init(8);
	push(v,11);
	push(v,22);
	push(v,33);
	/*while(v->pos >= 0){
		printf("%d\n",pop(v));
	}*/
	print_arr(v);
	change_element(v,44,1);
	print_arr(v);




	return 0;
}
