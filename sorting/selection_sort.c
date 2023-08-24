#include<stdio.h>

void display(int *A, int n){
    for(int i=0; i<n; i++){
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void selection_sort(int *A, int n){
    int indexOfmin, temp;
    for(int i=0; i<n-1; i++){ //kati times chalxa (total passes)
        indexOfmin = i;
        for(int j=i+1; j<n; j++){ //kati ota comparision hunxa
            if(A[j] < A[indexOfmin]){
                indexOfmin = j;
            }
        }
        //swap A[i] and indexOfmin
        temp = A[i];
        A[i] = A[indexOfmin];
        A[indexOfmin] = temp;
    }
}

int main(){
    int A[] = {2, 5, 8, 3, 10, 4};
    int n = 6;
    display(A, n);
    selection_sort(A, n);
    display(A, n);
}
