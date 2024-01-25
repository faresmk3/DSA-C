#include <stdio.h>
#include <stdio.h>

int front = 0;
int rear = -1;
int A[10];
int size = 10;

void Enqueue(int x) {
  if (rear <= 9) {
    rear += 1;
    A[rear] = x;
    return;
  }
  return;
}

int Dequeue() {
  int res = A[front];
  front += 1;
  return res;
}

int IsEmpty() {
  if (rear == -1 && front == 0) {
    return 1;
  }
  return 0;
}

int peek() {
  return A[front];
}

void Print() {
  int i = front;
  while (i < rear+1) {
    printf("%d\n", A[i]);
    i += 1;
  }
  printf("\n");
}

int main(void) {
  IsEmpty();
  Enqueue(5);
  Enqueue(7);
  Print();
  Enqueue(6);
  Enqueue(8);
  Enqueue(11);
  Print();
  Dequeue();
  Print();
  return 0;
}
