#include<stdio.h>

void display(int *A, int n){
    for(int i=0; i<n; i++){
        printf("%d\t", A[i]);
    }
    printf("\n");
}

int partion(int *A, int low, int high){
    int pivot = A[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }
        //swap low and A[j]
        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i<j);
    //interchange A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quick_sort(int *A, int low, int high){
    if(low < high){
        int partionIndex = partion(A, low, high); //getting right position of frist element
        quick_sort(A, low, partionIndex-1);
        quick_sort(A, partionIndex+1, high);
    }
}

int main(){
    int A[] = {2, 5, 8, 3, 10, 4};
    //int A[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    display(A, n);
    quick_sort(A, 0, n-1);
    display(A, n);

}
