#include<stdio.h>
#define MAX 5
struct stack{
    int items[MAX];
    int top;
};

int isFull(struct stack *s){
    if(s->top == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct stack *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void traverse(struct stack *s){
    if(isEmpty(s)){
        printf("The stack is empty!\n");
    }else{
        for(int i=0; i<=s->top; i++){
            printf("%d\n", s->items[i]);
        }
    }
}

void push(struct stack *s, int data){
    if(isFull(s)){
        printf("The stack is full!\n");
    }else{
        s->top++;
        s->items[s->top] = data;
        printf("%d pushed to stack!\n");
    }
}

void pop(struct stack *s){
    if(isEmpty(s)){
        printf("The stack is empty!\n");
    }else{
        int del = s->items[s->top];
        s->top--;
        printf("The deleted item is %d\n", del);
    }
}

int main(){
    struct stack *s;
    //making stack empty
    s->top = -1;
    //manually adding element '2' to stack
    s->items[0] = 2;
    s->top++;
    //adding items with function
    push(s, 3);
    push(s, 4);
    push(s, 5);
    //deleting item
    pop(s);
    printf("The items are: \n");
    traverse(s);
}
