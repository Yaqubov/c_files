#include<stdio.h>

void quick_sort(int *arr,int low,int high){
    if(low < high){
        int pivot = arr[high-1];
        int i = low-1;
        for(int j = low;j<high;j++){
            int temp;
            if(arr[j] <= pivot){
                i++;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp; 
            }
        }
        quick_sort(arr,low,i);
        quick_sort(arr,i+1,high);
    }
}

int main(){
    int arr[11] = {5,6,9,3,2,1,4,8,7,10,1};
    quick_sort(arr,0,11);
    for(int i = 0;i<11;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
