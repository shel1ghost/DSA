#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(int data){
    struct Node *n;
    n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){
    //creating nodes of tree
    struct Node *root = create_node(1);
    struct Node *n1 = create_node(2);
    struct Node *n2 = create_node(3);

    //linking the nodes in tree
    root->left = n1;
    root->right = n2;
}
