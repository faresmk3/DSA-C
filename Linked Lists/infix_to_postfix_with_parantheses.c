#include <stdio.h>
#include <stdlib.h>


/* a struct that represents a node of a linked list, data is the value of the node
and struct Node* next is basically the pointer to the next node of the linked list*/
struct Linked {
  char data;
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

void InsertAtTail(char x) {
  if (head == NULL) {
    Insert(x);
    return;
  }
  struct Linked* temp1 = (struct Linked*) malloc(sizeof(struct Linked));
  struct Linked* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = temp1;
  temp1->next = NULL;
  temp1->data = x;
  return;
}

/* print the values of the linked list*/
void Print() {
  struct Linked* temp = head;
  printf("List is: ");
  while (temp != NULL) {
    printf(" %c", temp->data);
    temp = temp->next;
  }
  printf("\n");
}


struct Node
{
  char data;
  struct Node *next;
};

struct Node *top;

void Push(char x)
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

int Top()
{
  if (isEmpty())
  {
    return 0;
  }
  return top->data;
}

char Pop()
{
  if (isEmpty())
  {
    return 0;
  }
  char res = top->data;
  top = top->next;
  return res;
}

int isAnOperator(char n) {
  if (n == '*' || n == '/' || n == '-' || n == '+') {
    return 1;
  }
  return 0;
} 

int isAnOperand(char n) {
  if ((n - '0') >= 0 && (n - '0') <= 9) {
    return 1;
  }

  return 0;
}

int isOpeningParantheses() {
  return Top() == '(';
}

int HasHigherPrecedence(char op1, char op2) {
  if ((op1 == '*' && op2 == '+') || (op1 == '*' && op2 == '-')) {
    return 1;
  }
  return 0;
}



void InfixToPostfix(char* exp) {
  for (int i = 0; exp[i] != '\0'; i += 1) {
    if (isAnOperand(exp[i])) {
      InsertAtTail(exp[i]);
    } else if (isAnOperator(exp[i])) {
      while (isEmpty() != 1 && isOpeningParantheses() != 1 && HasHigherPrecedence(Top(), exp[i])) {
    InsertAtTail(Top());
    Pop();
      }
      Push(exp[i]);
    } else if (exp[i] == '(') {
      Push(exp[i]);
    } else if (exp[i] == ')') {
      while(isEmpty() != 1 && isOpeningParantheses(Top()) != 1) {
    InsertAtTail(Top());
    Pop();
      }
      Pop();
    }
  }
  while(isEmpty() != 1) {
    InsertAtTail(Top());
    Pop();
  }
}

int main(void) {
  char string[] = "((2+2)*4-2)*3";
  InfixToPostfix(string);
  Print();
  return 0;
}
