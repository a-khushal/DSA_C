#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};
typedef struct node* Node;

void display(Node root){
  if(root!=NULL){
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
  }
}

Node createNode(Node root,int data){
  Node temp = (Node) malloc(sizeof(struct node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

Node insertLeft(Node root, int item){
  root->left = createNode(root, item);
  return root->left;
}

Node insertRight(Node root, int item){
  root->right = createNode(root, item);
  return root->right;
}

int countNode(Node root){
  if(root == NULL){
    return 0;
  }
  return (countNode(root->left) + countNode(root->right) + 1);
}

int height(Node root){
  if(root == NULL){
    return -1; // height is the number of edges in the longest subtree so if tree has one element height is 0 if tree doesn't exist then height is -1
  }
  int rh = height(root->right);
  int lh = height(root->left);
  if(lh > rh)
    return lh+1;
  return rh+1;
}

int leafNode(Node root){
  if(root == NULL){
    return 0;
  } else if (root->right == NULL && root->left == NULL){
    return 1;
  } else {
    return (leafNode(root->left) + leafNode(root->right));
  } 
}

int nonLeafNode(Node root){
  if(root == NULL){
    return 0;
  }
  if(root->left == NULL && root->right == NULL){
    return 0;
  } else {
    return (nonLeafNode(root->left) + nonLeafNode(root->right)) + 1;
  }
}

int main(void){
  Node root = NULL;
  root = createNode(root, 10);
  insertLeft(root, 20);
  insertRight(root, 30);
  insertLeft(root->left, 60);
  insertRight(root->left, 50);
  insertRight(root->right, 40);
  insertRight(root->left->right, 70);
  printf("The inorder traversal: ");
  display(root);
  printf("\nThe Number of nodes is: %d", countNode(root));
  printf("\nThe Number of leafNode is: %d", leafNode(root));
  printf("\nHeight of tree: %d", height(root));
  printf("\nThe number of non leaf nodes: %d\n", nonLeafNode(root));
  return 0;
}

// perfect binary tree, strictly binary tree, complete binary tree
// a perfect is complete