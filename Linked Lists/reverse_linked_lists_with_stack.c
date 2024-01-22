#include <stdio.h>
#include <stdlib.h>

/* a struct that represents a node of a linked list, data is the value of the node
and struct Node* next is basically the pointer to the next node of the linked list*/
struct Linked {
  int data;
  struct Linked* next; // store the link of the next node in the linked list
};

// we should ofc have a pointer towards the head of the list
struct Linked* head; // address of the head pointer to the linked list

/* insert a value into the linked list*/
void Insert(int value) {
  struct Linked* temp1 = (struct Linked*) malloc(sizeof(struct Linked));
  temp1->next = head; // or (*temp1).next = NULL;
  temp1->data = value; // (*temp1).data = value;
  head = temp1;
}

/* print the values of the linked list*/
void Print_list() {
  struct Linked* temp = head;
  printf("List is: ");
  while (temp != NULL) {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

struct Node
{
  struct Linked* data;
  struct Node *next;
};

struct Node *top;

void Push(struct Linked* x)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  if (node == NULL)
  {
    return;
  }
  node->data = x;
  node->next = NULL;
  if (top == NULL)
  {
    top = node;
    return;
  }
  node->next = top;
  top = node;
  return;
}

int isEmpty()
{
  if (top == NULL)
  {
    return 1;
  }
  return 0;
}

struct Linked* Top()
{
  if (isEmpty())
  {
    return 0;
  }
  return top->data;
}

struct Linked* Pop()
{
  if (isEmpty())
  {
    return 0;
  }
  struct Linked* res = top->data;
  top = top->next;
  return res;
}

void Print()
{
  struct Node *temp = top;
  for (int i = 0; temp != NULL; i += 1)
  {
    printf("%p ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void ReverseLinkedList() {
  struct Linked* temp = head;
  for (int i = 0; temp != NULL; i += 1) {
    Push(temp);
    temp = temp->next;
  }
  head = Top();
  temp = head;
  Pop();
  struct Linked* current = head;
  for (int j = 0; isEmpty() != 1; j += 1) {
    temp->next = Top();
    temp = Pop();
  }
  temp->next = NULL;
  return;
  
}

int main(void) {
  Insert(5);
  Insert(6);
  Insert(4);
  Insert(3);
  Insert(9);
  Print_list();
  ReverseLinkedList();
  Print_list();

  return 0;
}
