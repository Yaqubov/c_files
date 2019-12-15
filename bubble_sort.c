#include<stdio.h>

void bubble_sort(int *arr, int N){
    for(int i = 0; i<N-1;i++){
        for(int j = 0; j<N-i-1;j++){
            int temp;
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[9] = {5,9,6,5,4,7,2,3,1};

    bubble_sort(arr,9);
    for(int i = 0; i<9;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
