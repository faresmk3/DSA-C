#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *top;

void Push(int x)
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

int Pop()
{
  if (isEmpty())
  {
    return 0;
  }
  int res = top->data;
  top = top->next;
  return res;
}

void Print()
{
  struct Node *temp = top;
  for (int i = 0; temp != NULL; i += 1)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  printf("%d\n", isEmpty());
  Push(5);
  Push(2);
  Push(4);
  Push(6);
  Print();
  Pop();
  Print();
  printf("%d\n", Top());
  printf("%d\n", isEmpty());
  return 0;
}