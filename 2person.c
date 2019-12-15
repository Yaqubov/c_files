#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct person{
	double *x;
	double *y;
	int pos;
	int start;
	double r;
};

struct person *init(int size_x, int size_y,double radius){
	struct person *p = (struct person*) malloc(sizeof(struct person));
	p->x = (double*) malloc(sizeof(double) * size_x);
	p->y = (double*) malloc(sizeof(double) * size_y);
	p->start = 0;
	p->pos = -1;
	p->r = radius;
}

void walk(struct person *p, int x, int y){
	p->pos = p->pos + 1;
	p->x[p->pos] = x;
	p->y[p->pos] = y;
}

void if_see(struct person *p1,struct person *p2){
	for(int i=0; i<=(p1->pos - p1->start);i++){
		for(int j = 0;j<=(p2->pos - p2->start);j++){
			double dis = sqrt(pow(p1->x[i] - p2->x[j],2) + pow(p1->y[i] - p2->y[j],2));
			if(dis<=p1->r + p2->r){
				printf("They see each other in the %dth step of p1 and the %dth step of p2. \n",i,j);}
			/*else
				printf("They cant see each other in the %dth step of p1 and the %dth step of p2. \n",i,j);*/
		}
	}
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
	printf("---------------------------------------------------------------------------------\n");
}
int main(){
	struct person *p1 = init(50,50,2);
	struct person *p2 = init(50,50,2.5);
	walk(p1,5,6);
	walk(p1,9,7);
	walk(p2,4,6);
	walk(p2,7,3);
	printf("P1:\n");
	see_x_y(p1);
	printf("P2:\n");
	see_x_y(p2);
	printf("p1 radius: %.2f \n",p1->r);
	printf("p2 radius: %.2f \n",p2->r);
	if_see(p1,p2);
	


	return 0;
}
