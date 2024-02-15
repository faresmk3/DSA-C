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

int Search(struct BstNode* root, int data) {
  if (root == NULL) {
    return 0;
  }
  else if (root->data == data) {
    return 1;
  }
  else if (data <= root->data) {
    return Search(root->left, data);
  }
  else {
    return Search(root->right, data);
  }
}

int FindMinIterate(struct BstNode* root) {
  if (root == NULL) {
    return -1;
  }
  while (root->left != NULL) {
    root = root->left;
  }
  return root->data;
}


int FindMin(struct BstNode* root) {
  if (root == NULL) {
    return -1;
  }
  if (root->left == NULL) {
    return root->data;
  } else {
    return FindMin(root->left);
  }
}

int FindMax(struct BstNode* root) {
  if (root == NULL) {
    return -1;
  }
  if (root->right == NULL) {
    return root->data;
  } else {
    return FindMax(root->right);
  }
}


int FindMaxIterate(struct BstNode* root) {
  if (root == NULL) {
    return -1;
  }
  while (root->right != NULL) {
    root = root->right;
  }
  return root->data;
}

int FindHeight(struct BstNode* root) {
  if (root == NULL) {
    return -1; // here -1 is not an error return code but rather to balance out the defenition of height
  }
  return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}


int main(void) {
  struct BstNode* root = NULL;
  root = Insert(root,15);
  root = Insert(root,10);
  root = Insert(root,20);
  root = Insert(root, 25);
  root = Insert(root, 8);
  root = Insert(root, 12);
  printf("%d\n", Search(root, 12));
  printf("%d\n", FindMin(root));
  printf("%d\n", FindMinIterate(root));
  printf("%d\n", FindMax(root));
  printf("%d\n", FindMaxIterate(root));
  return 0;
}
