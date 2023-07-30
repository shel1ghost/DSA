#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void circular_ll_traverse(struct Node *head){
    struct Node *ptr = head;
    // printf("%d\n", ptr->data);
    // ptr = ptr->next;
    // while(ptr != head){
    //     printf("%d\n", ptr->data);
    //     ptr = ptr->next;
    // }
    do{
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

struct  Node *insert_at_first(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p;
    p = head->next;
    while(p->next != head){
        p = p->next;
    }
    //at this point ptr is at last node in linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    //allocate memory for nodes in the linked list in heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head; //which means linked list ended

    printf("Circular linked list before insertion:\n");
    circular_ll_traverse(head);
    printf("Cicrular linked list after insertion:\n");
    head = insert_at_first(head, 4);
    circular_ll_traverse(head);

}
