#include <stdio.h>
#include <stdlib.h>

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

char Top()
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

void Print()
{
  struct Node *temp = top;
  for (int i = 0; temp != NULL; i += 1)
  {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int checkBalancedParantheses(char* string, int size) {
  char* temp = string;
  for (int i = 0; i < size; i += 1) {
    printf("%c", *(temp + i));
    if ( *(temp + i) == '{' || *(temp + i) == '(' || *(temp + i) == '[') {
      Push(*(temp + i));
    } else if (*(temp + i) == '}' || *(temp + i) == ')' || *(temp + i) == ']') {
      if (isEmpty() == 1 ||  (*(temp + i) == '}' && Top() != '{') ||
    (*(temp + i) == ')' && Top() != '(') ||
    (*(temp + i) == ']' && Top() != '[')) {
        return -1;
      } else {
        Pop();  
      }
    } 
  }
  return 1;
}

int main(void) {
  char string[] = "[(])";
  int res = checkBalancedParantheses(string, 6);
  printf("%d ", res); 
  return 0;
}
