#include<stdio.h>
#include<stdlib.h>
#define MAX 6
struct cqueue{
    int front;
    int rear;
    int items[MAX];
};

int isFull(struct cqueue *cq){
    if((cq->rear+1)%MAX == cq->front){ //basically trying to say 0
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct cqueue *cq){
    if(cq->front == cq->rear){
        return 1;
    }else{
        return 0;
    }
}

void traverse(struct cqueue *cq){
    if(isEmpty(cq)){
        printf("Queue is empty!");
    }else{
        for(int i=1; i<=cq->rear; i++){
            printf("%d\n", cq->items[i]);
        }
    }
}

void enqueue(struct cqueue *cq, int data){
    if(isFull(cq)){
        printf("Queue is full\n");
    }else{
        cq->rear=(cq->rear+1)%MAX;
        cq->items[cq->rear] = data;
        printf("%d added to queue!\n", data);
    }
}

void dequeue(struct cqueue *cq){
    int del = -1;
    if(isEmpty(cq)){
        printf("Queue is empty!\n");
    }else{
        cq->front = (cq->front+1)%MAX;
        del = cq->items[cq->front];
        printf("%d was deleted!\n", del);
    }
}

int main(){
    struct cqueue *cq;
    //initializing circular queue as empty
    cq->rear = 0;
    cq->front = 0;
    //manually adding element to circular queue
    cq->rear = (cq->rear+1)%MAX;
    cq->items[cq->rear] = 2;
    //adding element with function
    enqueue(cq, 3);
    enqueue(cq, 4);
    traverse(cq);
    dequeue(cq);
    traverse(cq);
}
