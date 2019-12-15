#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	FILE *file = fopen("/home/smv18/Desktop/test.txt","a");
    char str[128];
    fgets(str,128,stdin);
    fputs(str,file);

    fclose(file);



	return 0;
}
