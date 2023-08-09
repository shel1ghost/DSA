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

struct Node *inorder_predecessor(struct Node *root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct Node *delete(struct Node *root, int data){
    struct Node *inorder_pre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    //search for the node to be deleted
    if(data < root->data){
        root->left = delete(root->left, data);
    }else if(data > root->data){
        root->right = delete(root->right, data);
    }
    //deleting strategy when the node is found
    else{
        inorder_pre = inorder_predecessor(root);
        root->data = inorder_pre->data;
        root->left = delete(root->left, inorder_pre->data);
    }
    return root;
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
    in_order(root);
    printf("\n");
    root = delete(root, 4);
    in_order(root);

}
