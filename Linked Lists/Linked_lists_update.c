#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next; // store the link of the next node in the linked list
};

struct Node* head; // address of the head pointer to the linked list

void Insert(int value) {
  struct Node* temp1 = (struct Node*) malloc(sizeof(struct Node));
  temp1->next = head; // or (*temp1).next = NULL;
  temp1->data = value; // (*temp1).data = value;
  head = temp1;
}

void Print() {
  struct Node* temp = head;
  printf("List is: ");
  while (temp != NULL) {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void Insert_nth(int value, int index) {
  struct Node* temp1 = (struct Node*) malloc(sizeof(struct Node));
  temp1->next = head;
  temp1->data = value;
  if (index == 1) {
    temp1->next = head; // works when the list is empty cuz head would be NULL in that case
    head = temp1;
    return;
  }
  struct Node* temp2 = head;
  for (int i = 0; i < index-2; i += 1) { // index-2 cuz we already start at the head and we start at index 0
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}


void Delete(int index) {
  struct Node* temp1  = head;
  if (index == 1) {
    head = temp1->next;
    free(temp1);
    return;
  }
  for (int i = 0; i < index-2; i += 1) {
    temp1 = temp1->next;
  } // temp1 now points at (n-1)th node
  
  struct Node* temp2 = temp1->next; // store the nth node to free its memory afterwards
  temp1->next = temp2->next; // fix the links
  free(temp2);

}

void Delete_value(int value) {
  if (head == NULL) { // list is empty, no need to do anything
    return;
  }
  struct Node* prev = NULL;
  struct Node* current = head;
  if (current->data == value) { // want to delete the first element of the list (current is pointing to head)
    head = head->next; // head is now pointing towards the second item of the list
    free(current); // current points towards the first element, we free it
    return;
  } // this code defeats the purpose of the block that comes just after
  
  for (int i = 0; current != NULL; i += 1) { // could be a while loop
    if (current->data == value) {
      prev->next = current->next;
      free(current);
      return;
    } else {
      prev = current;
      current = current->next;
    }
  }
}

int main(void) {
  head = NULL;
  Insert(2);
  Insert(3);
  Insert(4);
  Insert(5);
  Print();
  int n;
  //printf("Enter a Position: \n");
  printf("Enter a value to delete from the list given above: \n");
  scanf("%d", &n);
  Delete_value(n);
  //Delete(n);
  Print();
  
  
  return 0;
  
}

/*
int main(void) {
  head = NULL; // initially the list is empty
  printf("How many numbers would you like to have in your linked list? \n");
  int n,x;
  scanf("%d", &n);
  for (int i = 0; i < n; i += 1){
    printf("Enter the number you would like to insert into the linked list \n");
    scanf("%d", &x);
    Insert(x);
    Print();
  }
  return 0;
}
*/
