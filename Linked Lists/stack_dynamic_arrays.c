#include <stdio.h>
#include <stdlib.h>
int size;
int top;
int *stack;

int *CreateStack(int size)
{
  int *newStack = (int *)malloc(size * sizeof(int));
  if (newStack == NULL)
  {
    return NULL;
  }
  return newStack;
}

void CopyStack(int *newStack)
{
  int *temp = stack;
  for (int i = 0; i < size; i += 1)
  {
    *(newStack + i) = *(temp + i);
  }
}

void ResizeAndCopy(int newSize)
{
  int *newStack = CreateStack(newSize);
  if (newStack == NULL)
  {
    return;
  }
  CopyStack(newStack);
  free(stack);
  stack = newStack;
  size = newSize;
}

int isEmpty()
{
  if (top == -1)
  { // 1 is true and the stack is empty
    return 1;
  }
  return 0; // false
}

int Top()
{
  return stack[top];
}

void Push(int x)
{
  if (top == size - 1)
  {
    ResizeAndCopy(2 * size);
  }
  top += 1;
  stack[top] = x;
}

int Pop()
{
  if (isEmpty())
  {
    return 0; // false
  }
  int res = stack[top];
  top -= 1;
  return res;
}

void Print()
{
  int *temp = stack;
  for (int i = 0; i < top; i += 1)
  {
    printf("%d", *(temp + i));
  }
}
int main(void)
{
  size = 5;
  top = -1;
  stack = CreateStack(size);
  printf("%p", (void *)stack);
  Push(5);
  Push(4);
  Push(9);
  Push(6);
  Push(3);
  Push(2);
  Print();
  free(stack);
  return 0;
}