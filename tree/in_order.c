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

void *in_order(struct Node *n){
    if(n != NULL){
        in_order(n->left);
        printf("%d\t", n->data);
        in_order(n->right);
    }
}

int main(){
    //creating nodes of tree
    struct Node *root = create_node(4);
    struct Node *n1 = create_node(1);
    struct Node *n2 = create_node(6);
    struct Node *n3 = create_node(5);
    struct Node *n4 = create_node(2);

    //linking the nodes in tree
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;

    //tree would look like
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    //calling function to traverse
    in_order(root);
}
