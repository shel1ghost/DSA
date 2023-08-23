#include<stdio.h>

void display(int *A, int n){
    for(int i=0; i<n; i++){
        printf("%d\t", A[i]);
    }
    printf("\n");
}

//simple bubble sort
void bubble_sort(int *A, int n){
    int temp;
    for(int i =0; i<n-1; i++){ //for passes i.e n-1 passes
        for(int j=0; j<n-1-i; j++){ //number of comparision in each passes i.e n-1-i
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

//adaptive bubble sort (jasle if array already sorted xa vane comparision na garos)
void adaptive_bubble_sort(int *A, int n){
    int temp, is_sorted = 1;
    for(int i =0; i<n-1; i++){ //for passes i.e n-1 passes
        printf("Working on pass %d\n", i+1);
        for(int j=0; j<n-1-i; j++){ //number of comparision in each passes i.e n-1-i
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                is_sorted = 0;
            }
        }
        if(is_sorted){
            return;
        }
    }
}


int main(){
    int A[] = {2, 5, 8, 3, 10, 4};
    //int A[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    display(A, n);
    bubble_sort(A, n);
    display(A, n);
    //adaptive_bubble_sort(A, n);
    //display(A, n);

}
