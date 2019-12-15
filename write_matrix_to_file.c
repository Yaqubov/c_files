#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[3][4] = {
        {1,1,1,1},
        {2,2,2,2},
        {3,3,3,3}
    };

    FILE *f = fopen("/home/smv18/Desktop/for_writing.txt","w");
    for(int i = 0;i<3;i++){
        for(int j = 0;j<4;j++){
            char str[10];
            sprintf(str, "%d", arr[i][j]);
            fputs(str,f);
            fputs(" ",f);
        }
        fputs("\n",f);
    }
    fclose(f);

}
