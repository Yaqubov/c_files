#include<stdio.h>
#include<stdlib.h>


int main(){
    
    FILE *f = fopen("/home/smv18/Desktop/for_writing.txt","w");
    FILE *t = fopen("/home/smv18/Documents/tasks/stack.c","r");

    char ch;

    while((ch = fgetc(t)) != EOF){
        fputc(ch,f);
    }
    fclose(f);
    fclose(t);
}
