#include<stdio.h>
#include<stdio.h>

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int mx[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d ",&mx[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",mx[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        int k = i;
        int j = 0;
        while(k>=0 && j<=m){
            printf("%d ",mx[k][j]);
            k-=1;
            j+=1;
        }
        printf("\n");
    }
    for(int j=1;j<m;j++){
        int k = j;
        int i = n-1;
        while(i>=0 && k<m){
            printf("%d ",mx[i][k]);
            i--;
            k++;
        }
        printf("\n");
    }

}
