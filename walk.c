#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct person{
	double *x;
	double *y;
	int start;
	int pos;

};

struct person *init(int x,int y){
	struct person *p = (struct person*) malloc(sizeof(struct person));
	p->x = (double*) malloc(sizeof(double) * x);
	p->y = (double*) malloc(sizeof(double) * y);
	p->start = 0;
	p->pos = -1;
}

void walk(struct person *p, int x, int y){
	p->pos = p->pos + 1;
	p->x[p->pos] = x;
	p->y[p->pos] = y;
}

void see_x_y(struct person *p){
	if (p->pos < p->start){
		return;
	}
	int c = 0;
	printf("x: ");
	while(c <= p->pos - p->start){
		printf("%.2f ",p->x[c]);
		c++;
	}
	printf("\n");
	c = 0;
	printf("y: ");
	while(c <= p->pos - p->start){
		printf("%.2f ",p->y[c]);
		c++;
	}
	printf("\n");
}

double distance(struct person *p){
	if(p->pos < p->start){
		return -1e9;
	}
	double dis = 0;
	int c = 0;
	while(c < p->pos - p->start){
		dis += sqrt(pow((p->x[c] - p->x[c+1]),2) + pow((p->y[c] - p->y[c+1]),2));
		c++;
	}
	return dis;
}

int main(){
	struct person *p = init(50,50);
	walk(p,2,6);
	walk(p,5,10);
	walk(p,6,10);
	see_x_y(p);
	printf("%.2f \n",distance(p));
	return 0;
}
