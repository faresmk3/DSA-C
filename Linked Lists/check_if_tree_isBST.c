#include <stdio.h>
#include <stdlib.h>

struct BstNode {
  int data;
  struct BstNode* left;
  struct BstNode* right;
};

struct BstNode* CreateNewNode(int data) {
  struct BstNode* node = (struct BstNode*) malloc(sizeof(struct BstNode));
  node->data = data;
  node->left = NULL; // (*node).left 
  node->right = NULL;
  return node;
}

struct BstNode* Insert(struct BstNode* root, int data) {
  struct BstNode* node = CreateNewNode(data);
  if (root == NULL)  { // empty tree
    root = node;
  }
  else if (data <= root->data) {
    root->left = Insert(root->left, data);
  }
  else {
    root->right = Insert(root->right, data);
  }
  return root;
  
}

int IsSubTreeGreater(struct BstNode*, int value) {
  if (root == NULL) {
    return 1;
  }
  if (root->data <= value
      && IsSubTreeGreater(root->left, value)
      && IsSubTreeGreater(root->left, value)) {
    return 1;
  } else {
    return 0;
  }
}

int IsSubTreeLesser(struct BstNode*, int value) {
  if (root == NULL) {
    return 1;
  }
  if (root->data <= value
      && IsSubTreeLesser(root->left, value)
      && IsSubTreeLesser(root->left, value)) {
    return 1;
  } else {
    return 0;
  }
}


int IsBinarySearchTree(struct BstNode* root) {
  if (IsSubTreeLesser(root->left, root->data) && IsSubTreeGreater(root->right, root->data)
      && IsBinarySeachTree(root->left) && IsBinarySearchTree(root->right)) {
    return 1;
  } else {
    return 0;
  }
}



int main(void) {

  return 0;
}
