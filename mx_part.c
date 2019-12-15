#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int mx[4][4] = {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}
    };
    int n;
    int m;
    scanf("%d %d",&n,&m);
    
    int int_r = 4/n;
    int int_c = 4/m;
    int r=0;
    while(r<r+int_r){
        int c =0;
        while(c<c+int_c){
            printf("%d ",mx[r][c]);
            c++;
        }
        r++;
        printf("\n");
    }


    return 0;
}
