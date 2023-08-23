#include<stdio.h>

void display(int *A, int n){
    for(int i=0; i<n; i++){
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void insertion_sort(int *A, int n){
    int key, j;
    //loop for passes
    for(int i=1; i<=n-1; i++){
        key = A[i];
        j = i-1;
        //loop for each passes
        while(j >=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    int A[] = {2, 5, 8, 3, 10, 4};
    int n = 6;
    display(A, n);
    insertion_sort(A, n);
    display(A, n);
}
