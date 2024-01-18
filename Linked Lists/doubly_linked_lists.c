#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head;

void InsertAtHead(int value) {
  // a node inserted at head has no prev node
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = value; // (*node).data = value
  if (head == NULL) { // the doubly linked list doesn't contain any elements
    node->prev = NULL;
    node->next = NULL;
    head = node;
    return;
  }
  if (head->next == NULL) {
    node->next = head;
    node->prev = head;
    head->next = node;
    head->prev = node;
    head = node;
    return;
  }
  struct Node* temp = head;
  while (temp->next != head) {
    temp = temp->next;
  }
  // temp here represents the last element of the doubly linked list
  temp->next = node;
  node->prev = temp;
  
  node->next = head;
  head->prev = node;
  head = node;
}

void Print() {
  struct Node* temp = head;
  while (temp->next != head) {
    printf("%d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}


int main(void) {
  head = NULL;
  InsertAtHead(5);
  InsertAtHead(2);
  InsertAtHead(8);
  Print();
  
  return 0;
}
