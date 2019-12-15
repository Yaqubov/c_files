#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	char *buff;
	int top;
	int size;
};

struct stack *init(int size){
	struct stack *new = (struct stack*)malloc(sizeof(struct stack));
	new->buff = (char*)malloc(sizeof(char)*size);
	new->top = -1;
	new->size = size;
	return new;
}

void push(struct stack *s,char item){
	s->top = s->top + 1;
	s->buff[s->top] = item;
}

char top(struct stack *s){
	return s->buff[s->top];
}

int is_empty(struct stack *s){
	if(s->top == -1){
		return 1;
	}
	else
		return 0;
}

void pop(struct stack *s){
	if(is_empty(s)){
		return;
	}
	s->top = s->top - 1;

}

int check(char a,char b){
	if((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']')){
		return 1;
	}
	else
		return 0;
				
}


/*void NGE(int *arr,int n){
	struct stack *s = init(n);
	int element,next,i;
	push(s,arr[0]);
	for(i=1;i<n;i++){
		next = arr[i];
		if(!is_empty(s)){
			element = top(s);
			pop(s);
			while(element<next){
				printf("%d -- %d\n",element,arr[i]);
				if(is_empty){
					break;
				}
				element = top(s);
				pop(s);
			}
			if(element>next){
				push(s,element);
			}
			
		}
		push(s,next);
	}
	while(!is_empty){
		element = top(s);
		pop(s);
		next = -1;
		printf("%d -- %d\n",element,next);
	}
}
*/
int check_bracket(char *exp){
	struct stack *s = init(50);
	int i = 0;
	for(i;i<strlen(exp);i++){
		char c = exp[i];
		if(c == '(' || c =='[' || c=='{'){
			push(s,c);
		}
		if(c==')' || c==']' || c=='}'){
			if(check(top(s),c)){
				pop(s);
			}
			else
				return 0;
		}

	}
	if(is_empty(s)){
		return 1;
	}
	else
		return 0;

}

int main(){
	char exp[] = "{5+6}(9+6){{{}}}[[[]]]";
	printf("%d \n",check_bracket(exp));
	int arr[] = {5,9,6,4,8};
	int n = sizeof(arr)/sizeof(int);
	//NGE(arr,n);
	return 0;


}
