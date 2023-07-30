#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *prev;
    struct Node *next;
    int data;
};

void doubly_ll_traverse(struct Node *ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void traverse_from_last(struct Node *ptr){
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    //ptr = NULL
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->prev;
    }

}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 3;
    third->next = NULL;

    printf("Traverse from beginning:\n");
    doubly_ll_traverse(head);
    printf("Traverse from end:\n");
    traverse_from_last(head);

}
