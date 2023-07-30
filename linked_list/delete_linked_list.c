#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void linked_list_traverse(struct Node *ptr){
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *delete_from_first(struct Node *head){
    struct Node *ptr = head;
    head = head->next; //head lai saareko agaadiko element ma
    free(ptr);
    return head;
}

struct Node *delete_from_end(struct Node *head){
     struct Node *p = head;
     struct Node *q = p->next;
     while(q->next != NULL){
         p = p->next;
         q = q->next;
     }
     p->next = NULL;
     free(q);
     return head;
}

struct Node *delete_from_index(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i=0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *delete_given_value(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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
    third->next = NULL; //which means linked list ended

    printf("Linked list before deletion:\n");
    linked_list_traverse(head);
    printf("Linked list after deletion:\n");
    //delete first element
    //head = delete_from_first(head);
    //delete from index
    //head = delete_from_index(head, 1);
    //head = delete_from_end(head);
    head = delete_given_value(head, 2);
    linked_list_traverse(head);


}
