#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head;

/* creates a new node of our chained doubly linked list */
struct Node* CreateNewNode(int value) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  (*node).data = value;
  (*node).prev = NULL;
  (*node).next = NULL;
  return node;
}

/* inserts an element at head into our chained doubly linked list */
void InsertAtHead(int value) {
  // a node inserted at head has no prev node nor next node
  struct Node* node = CreateNewNode(value);
  if (head == NULL) {
    head = node;
    return;
  }
  /*
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = value; // (*node).data = value
  if (head == NULL) { // the doubly linked list doesn't contain any elements
    node->prev = NULL;
    node->next = NULL;
    head = node;
    return;
  }
  */
  if (head->next == NULL) { // when we insert a second element to the linked list we fix the links only
    node->next = head;
    node->prev = head;
    head->next = node;
    head->prev = node;
    head = node;
    return;
  }

  // in this case we have to traverse the whole list to get to the last element and fix the links
  // the next of the last element is the head, the prev if the head is the last element
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

/* prints out the values of our chained doubly linked list */
void Print() {
  struct Node* temp = head;
  do {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != head);
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
