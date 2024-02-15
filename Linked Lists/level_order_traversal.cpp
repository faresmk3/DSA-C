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

void LevelOrder(struct BstNode* root) {
  if (root == NULL) {
    return;
  }
  queue<BstNode*> Q;
  Q.push(root);
  // while there's at least one discovered node
  while(!Q.empty()) {
    BstNode* current = Q.front();
    cout<<current->data<<" ";
    if (current->left != NULL) {
      Q.push(current->left);
    }
    if (current->right != NULL) {
      Q.push(current->right);
    }
    Q.pop();
  }
}

int main(void) {
  struct BstNode* root = NULL;
  root = Insert(root,A);
  root = Insert(root,B);
  root = Insert(root,C);
  root = Insert(root,D);
  root = Insert(root,E);
  root = Insert(root,F);
  return 0;
}
