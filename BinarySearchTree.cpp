#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
if (root != NULL){
  traverseInOrder(root->left);
  cout<<root->key<<" ";
  traverseInOrder(root->right);
}
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
//if it's an empty tree then a new root node containing the input wil be created    
if (node==NULL){
  node=new struct node;
  node->key=key;
  node->left=NULL;
  node->right=NULL;
}
//If the input is less than or equal to the root node, it'll be inserted to the left side of the tree
else if (key<node->key){
  node->left=insertNode(node->left,key);
}
//If the input is less than the root node, it'll be inserted to the left side of the tree
else if(key>node->key){
  node->right=insertNode(node->right,key);
}
return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
// Base case (if the root is empty)
if (root==NULL){
  return NULL;
} 
//left sub tree's root will be checked first if the dta is less than the root
else if (key<root->key){
  root->left=deleteNode(root->left,key);
}
//right sub tree's root will be checked first if the data is greater than the root 
else if (key>root->key){
  root->right=deleteNode(root->right,key);
}
else{
  if (root->left==NULL){
    return root->right;
  }
  else if (root->right==NULL){
    return root->left;
  }
  else{
    struct node *temp=root->right;
    while(temp->left!=NULL){
      temp=temp->left;
    }
    root->key=temp->key;
    root->right=deleteNode(root->right,temp->key);
  }
}
return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
