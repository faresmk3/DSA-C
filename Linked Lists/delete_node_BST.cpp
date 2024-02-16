#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

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

struct BstNode* Search(struct BstNode* root, int data) {
  if (root == NULL) {
    return NULL;
  }
  else if (data >= root->data) {
    Search(root->right, data);
  } else if (data <= root->data) {
    Search(root->left, data);
  } else {
    return root; 
  }
  
}

struct BstNode* FindMin(struct BstNode* root) {
  if (root == NULL) {
    return root;
  }
  if (root->left == NULL) {
    return root;
  } else {
    return FindMin(root->left);
  }
}

struct BstNode* Delete(struct BstNode* root, int data) {
  // find the value we have to delete in the first place
  if (root == NULL) {
    return root;
  }
  else if (data > root->data) {
    root->right = Delete(root->right, data);
  }
  else if (data < root->data) {
    root->left = Delete(root->left, data);
  }
  // found it, have to delete it
  else {

    // case 1: no children
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }

    // case 2: has one child
    else if (root->left == NULL) {
      struct BstNode* temp = root;
      root = root->right; // make the right side the root of the current one
      delete temp;
    }
    else if (root->right == NULL) {
      struct BstNode* temp = root;
      root = root->left;
      delete temp;
    }

    // case 3: has two children
    else {
      // search the minimum of the right subtree
      struct BstNode* = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }

  return root;
}
