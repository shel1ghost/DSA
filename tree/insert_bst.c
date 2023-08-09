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

void insert(struct Node *root, int data){
    struct Node *prev = NULL;
    while(root != NULL){
        prev = root;
        if(root->data == data){
            printf("Cannot insert data! It already exits.");
            return;
        }else if(root->data < data){
            root = root->right;
        }else{
            root = root->left;
        }
    }
    struct Node *new = create_node(data);
    if(data > prev->data){
        prev->right = new;
    }else{
        prev->left = new;
    }
}

int main(){
    //creating nodes of tree
    struct Node *root = create_node(5);
    struct Node *n1 = create_node(3);
    struct Node *n2 = create_node(6);
    struct Node *n3 = create_node(2);
    struct Node *n4 = create_node(4);

    //linking the nodes in tree
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;

    //tree would look like
    //      5
    //     / \
    //    3   6
    //   / \
    //  2   4
    insert(root, 8);
    printf("%d", root->right->right->data);
}
