#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct queue{
    int front;
    int rear;
    int items[MAX];
};
int isFull(struct queue *q){
    if(q->rear == MAX-1){
        return 1;
    }else{
        return 0;
    }
}
int isEmpty(struct queue *q){
    if(q->rear == q->front){
        return 1;
    }else{
        return 0;
    }
}

void traverse_queue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!");
    }else{
        for(int i=0; i<=q->rear; i++){
            printf("%d\n", q->items[i]);
        }
    }
}

void enqueue(struct queue *q, int data){
    if(isFull(q)){
        printf("Queue is full!\n");
    }else{
        q->rear++;
        q->items[q->rear] = data;
        printf("%d added to queue!\n", data);
    }
}

int dequeue(struct queue *q){
    //to return something if queue is empty -1 or some error occurs in dequeuing
    int data = -1;
    if(isEmpty(q)){
        printf("Queue is empty!");
    }else{
        q->front++;
        data = q->items[q->front];
    }
    return data;
}

int main(){
    struct queue *q;
    //initially at index -1, means empty
    q->front = -1;
    q->rear = -1;
    //manually adding data to queue
    q->rear++;
    q->items[q->rear] = 2;
    //adding data to queue with function
    enqueue(q, 3);
    enqueue(q, 4);
    //removing first element with dequeue function
    //printf("%d dequeued!\n", dequeue(q));
    printf("The items is the queue are:\n");
    traverse_queue(q);
}
