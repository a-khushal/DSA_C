#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void preOrder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}


int searchItem(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

struct node* buildTreeUsingPreorderAndInorder(int preorder[], int inorder[], int start, int end){

    if(start>end){
        return NULL;
    }

    static int idx = 0;
    int curr = preorder[idx];
    idx++;
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = curr;

    if(start == end){
        return n;
    }
    
    int pos = searchItem(inorder, start, end, curr);
    n->left = buildTreeUsingPreorderAndInorder(preorder, inorder, start, pos-1);
    // n->right = buildTreeUsingPreorderAndInorder(preorder, inorder, pos+1, end);

    return n;
}


struct node* buildTreeUsingPostorderAndInorder(int postorder[], int inorder[], int start, int end){

    if(start>end){
        return NULL;
    }

    static int idx = 4;
    int curr = postorder[idx];
    idx--;
    struct node* n = (struct node*) malloc(sizeof(struct node));
    n->data = curr;

    if(start == end){
        return n;
    }

    int pos = searchItem(inorder, start, end, curr);
    n->right = buildTreeUsingPostorderAndInorder(postorder, inorder, pos+1, end);
    n->left = buildTreeUsingPostorderAndInorder(postorder, inorder, start, pos-1);
    return n;
}




int main(void){
    struct node* root = (struct node*) malloc(sizeof(struct node));
    root->data = 1;

    root->left = (struct node*) malloc(sizeof(struct node));
    root->left->data = 2;
    root->right = (struct node*) malloc(sizeof(struct node));
    root->right->data = 3;

    /* root->left->left = (struct node*) malloc(sizeof(struct node));
    root->left->left->data = 4;
    root->left->right = (struct node*) malloc(sizeof(struct node));
    root->left->right->data = 5; */

    root->right->left = (struct node*) malloc(sizeof(struct node));
    root->right->left->data = 6;
    root->right->right = (struct node*) malloc(sizeof(struct node));
    root->right->right->data = 7;

    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    // int preorder[] = {1,2,3,4,5};
    // int inorder[] = {4,2,1,5,3};

    // struct node* n = buildTreeUsingPreorderAndInorder(preorder, inorder, 0, 4);
    // inOrder(n);

    // int postorder[] = {4,2,5,3,1};
    // int inorder[] = {4,2,1,5,3};

    // struct node* n = buildTreeUsingPostorderAndInorder(postorder, inorder, 0, 4);
    // inOrder(n);

    return 0;
}
