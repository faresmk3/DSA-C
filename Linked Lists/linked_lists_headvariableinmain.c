#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void Insert(struct Node** head, int value) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = value;
  temp->next = *head;
  *head = temp;
}

void Print(struct Node** head) {
  struct Node* temp = *head;
  printf("list is: \n");
  while (temp !=  NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}


int main(void) {
  struct Node* head = NULL;
  printf("How many numbers would you like to have in your linked list? \n");
  int n,x;
  scanf("%d", &n);
  for (int i = 0; i < n; i += 1){
    printf("Enter the number you would like to insert into the linked list \n");
    scanf("%d", &x);
    Insert(&head,x);
    Print(&head);
  }
  return 0;
  
}
