#include <stdio.h>
#include <stdlib.h>

/* a struct that represents a node of a linked list, data is the value of the node
and struct Node* next is basically the pointer to the next node of the linked list*/
struct Node {
  int data;
  struct Node* next; // store the link of the next node in the linked list
};

// we should ofc have a pointer towards the head of the list
struct Node* front = NULL; // address of the head pointer to the linked list

struct Node* rear = NULL;

int isEmpty() {
  if (front == NULL && rear == NULL) {
    return 1;
  }
  return 0;
}

void Enqueue(int value) {
  struct Node* temp1 = (struct Node*) malloc(sizeof(struct Node));
  temp1->next = NULL;
  temp1->data = value;
  if (isEmpty()) {
    front = temp1;
    rear = temp1;
    return;
  }
  rear->next = temp1;
  rear = temp1;
}

void Dequeue() {
  struct Node* temp = front;
  if (front == NULL) {
    return;
  }
  if (front == rear) {
    front = NULL;
    rear = NULL;
    free(temp);
  }
  front = front->next;
  free(temp);
  return;
}

int frontv() {
  return front->data;
}

void Print() {
  struct Node* temp = front;
  while (temp != NULL) {
    printf("%d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(void) {
  Enqueue(5);
  Enqueue(6);
  printf("%d\n",frontv());
  Enqueue(7);
  Enqueue(1);
  Print();
  Dequeue();
  Print();
  
  return 0;
}
