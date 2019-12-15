#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    
    int m,n,a,b;

    scanf("%d",&m);
    scanf("%d",&n);
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    int copy[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            copy[i][j] = arr[i][j];
        }
    }

    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
           printf("%d ",arr[i][j]);
       }
       printf("\n");
    }
    
    scanf("%d",&a);
    scanf("%d",&b);
    if(a==m & b==n || a>m || b>n){
        exit(1);
    }
    for(int j=0;j<n;j++){
        for(int i=m-a;i>=0;i--){
            int sum = 0;
            for(int k=i;k<i+a;k++){
                sum+=copy[k][j];
            }
            copy[i+a-1][j] = sum;
        }
    }
    /*for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
            printf("%d ",copy[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

    for(int i=a-1;i<m;i++){
        for(int j=n-1;j>=b-1;j--){
            int sum2 = 0;
            for(int k=j;k>=j-b+1;k--){
                sum2+=copy[i][k];
            }
            copy[i][j] = sum2;
        }
    }
    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",copy[i][j]);
        }
        printf("\n");
    }*/
    int maxsum = copy[0][0];
    int x,y;
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            if(copy[i][j] > maxsum){
                maxsum = copy[i][j];
                x=i;
                y=j;
            }
        }
    }
    printf("Maximum sum = %d\n",maxsum);

    for(int i=x-a+1;i<=x;i++){
        for(int j=y-b+1;j<=y;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;

}























