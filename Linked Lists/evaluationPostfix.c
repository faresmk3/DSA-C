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

int Perform(char op1, char op2, char operator) {
  int res;

  switch(operator) {
  case '+':
    res = (op1 - '0') + (op2 - '0');
    break;
  case '-':
    res = (op1 - '0') - (op2 - '0');
    break;
  case '*':
    res = (op1 - '0')  * (op2 - '0');
    break;
  case '/':
    if (op2 - '0' != 0) {
      res = (op1 - '0') / (op2 - '0');
    } else {
      printf("cannot devide by zero\n");
      return 0;
    }
    break;
  default:
    printf("invalid operator\n");
    return -1;
  }

  return res;
}


int EvaluatePostfix(char* exp) {
  for (int i = 0; exp[i] != '\0'; i += 1) {
    if (isAnOperand(exp[i])) {
      Push(exp[i] - '0');
    } else if (isAnOperator(exp[i])) {
      char op2 = Pop();
      char op1 = Pop();
      int res = Perform(op1, op2, exp[i]);
      Push(res);
    }
  }
  return Top();
}

int main() {
  char* exp = "23*54*+9-";
  int res = EvaluatePostfix(exp);
  printf("%d \n", res);
  return 0;
}
