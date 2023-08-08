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

struct Node* search_bst(struct Node* root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        return root;
    }else if(data > root->data){
        search_bst(root->right, data);
    }else{
        search_bst(root->left, data);
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
    struct Node *s = search_bst(root, 2);
    if(s == NULL){
        printf("Element not found!");
    }else{
        printf("Element found: %d", s->data);
    }
}
