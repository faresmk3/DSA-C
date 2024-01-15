#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* head;

void add_s(struct Node** head, int value) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = value;
  if (*head == NULL) {
    node->next = NULL;
    *head = node;
  }
  node->next = *head;
  *head = node;
}

void remove_s(struct Node** head) {
  if(*head == NULL) {
    return;
  }
  struct Node* temp = *head;
  *head = (*head)->next;
  free(temp);
}

void print_list(struct Node* head) {
  struct Node* current = head;  // Use a temporary variable for iteration
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

/*
void print_list(struct Node* head) {
  struct Node* temp = head;
  while (temp->next != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
*/
/*
void print_list(struct Node* head) {
  while(head != NULL) {
    printf("%d", head->data);
    head = head->next;
  }
}
*/
int main() {
  
  add_s(&head, 2);
  add_s(&head, 5);
  add_s(&head, 6);
  print_list(head);
  
  return 0;
}
