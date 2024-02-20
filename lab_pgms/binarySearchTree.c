#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};

void preorder(struct node* root){
  if(root==NULL){
      return; 
  }
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}


void inorder(struct node* root){
  if(root==NULL){
    return; 
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void postorder(struct node* root){
  if(root==NULL){
    return; 
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

struct node* createBST(struct node* root, int val){
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->data = val;
  temp->right = NULL;
  temp->left = NULL;
  if(root == NULL){
    return temp;
  }
  if(val < root->data){
    root->left = createBST(root->left, val);
  } else {
    root->right = createBST(root->right, val);
  }
  return root;
}

// struct node* inOrderSuccessor(struct node* root){
//   struct node* curr = root;
//   while(curr && curr->left != NULL){
//     curr = curr->left;
//   }
//   return curr;
// }


struct node* inOrderSuccessor(struct node* root){
  struct node* curr = root;
  while(curr && curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}

// struct node* deletion(struct node* root, int del){
//   struct node* temp;
//   if(root == NULL){
//     return NULL;
//   }
//   if(del < root->data){
//     root->left = deletion(root->left, del);
//   }
//   else if(del > root->data){
//     root->right = deletion(root->right, del);
//   }
//   else{
//     if(root->left == NULL){
//       temp = root->right;
//       free(root);
//       return temp;
//     }
//     if(root->right == NULL){
//       temp = root->left;
//       free(root);
//       return temp;
//     }
//     temp = inOrderSuccessor(root->right); // inorder successor which means a value that comes after root and greater than root ofc so inorder->increasing series hence it's root->right
//     root->data = temp->data;  // swapping the data of inorder successor with the node to be deleted
//     root->right = deletion(root->right, temp->data);
//   }
//   return root;
// }


struct node* deletion(struct node* root, int val){
  struct node* temp;
  if(root == NULL){
    return NULL;
  }
  if(val < (root->data)){
    root->left = deletion(root->left, val);
  } else if (val > (root->data)) {
    root->right = deletion(root->right, val);
  } else {
    if(root->left == NULL){
      temp = root->right;
      free(root);
      return temp;
    }
    if(root->right == NULL){
      temp = root->left;
      free(root);
      return temp;
    } 
    temp = inOrderSuccessor(root->right);
    root->data = temp->data;
    root->right = deletion(root->right, temp->data);
  }
  return root;
}

int main(void){
  struct node* root = NULL;
  int val, ch, del;
  while(1){
    printf("\n1.To create\n2.Preorder\n3.Inorder\n4.Postorder\n5.delete\n6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch){
      case 1:{
        printf("\nRead item to be inserted: ");
        scanf("%d", &val);
        root = createBST(root, val);
        break;
      }
      case 2:{
        printf("\nThe preorder config: \n");
        preorder(root);
        break;
      }
      case 3:{
        printf("\nThe inorder config: \n");
        inorder(root);
        break;
      }
      case 4:{
        printf("\nThe postorder config: \n");
        postorder(root);
        break;
      }
      case 5:{
        printf("\nRead node to be deleted: ");
        scanf("%d", &del);
        root = deletion(root, del);
        break;
      }
      default: {
        exit(0);
      }
    }
  }
  return 0;
}




// struct node* createBST(struct node* root, int val){
//   struct node* temp;
//   temp = (struct node*) malloc(sizeof(struct node));
//   temp->data = val;
//   temp->left = NULL;
//   temp->right = NULL;
//   if(root==NULL){
//     return temp;
//   }
//   if(val < (root->data))
//     root->left = createBST(root->left, val);
//   else 
//     root->right = createBST(root->right, val);
//   return root;
// }

