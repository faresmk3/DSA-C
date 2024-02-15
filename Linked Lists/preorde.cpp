#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;
struct BstNode {
  char data;
  struct BstNode* left;
  struct BstNode* right;
};

struct BstNode* CreateNewNode(char data) {
  struct BstNode* node = (struct BstNode*) malloc(sizeof(struct BstNode));
  node->data = data;
  node->left = NULL; // (*node).left 
  node->right = NULL;
  return node;
}

struct BstNode* Insert(struct BstNode* root, char data) {
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

void Preorder(BstNode* root) {
  if (root == NULL) {
    return;
  }
  printf("%c", root->data);
  Preorder(root->left);
  Preorder(root->right);
}

int main(void) {
  return 0;
}
