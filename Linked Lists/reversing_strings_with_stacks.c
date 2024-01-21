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

void ReverseString(char *str)
{
  char *temp = str;
  int index;
  for (int i = 0; temp[i] != '\0'; i += 1)
  {
    Push(temp[i]);
    index += 1;
  }
  for (int i = 0; isEmpty() != 1; i += 1)
  {
    str[i] = Pop();
  }
}

void PrintString(char *str)
{
  char *temp = str;
  for (int i = 0; temp[i] != '\0'; i += 1)
  {
    printf("%c ", temp[i]);
  }
  printf("\n");
}

int main()
{
  char string[] = "abcdefg";
  PrintString(string);
  ReverseString(string);
  PrintString(string);
  return 0;
}