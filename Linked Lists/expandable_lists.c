#include <stdio.h>
#include <stdlib.h>
int *array;          // a global variable that serves as the variable that stocks the array
int size;            // current size of the array, gets modified when needed in the functions
int currentCapacity; // current number of elements present in the array, helps with tracking elements, shifting and inserting.

/* Creates an array of fixed size using dynamic memory allocation.
  Paramaters:
    size (int) : the size of the array to be created. i.e. size = 10 means the array will stock 10 integers
*/
int *Create(int size)
{
  int *array = (int *)malloc(size * sizeof(int));
  if (array == NULL)
  {
    return NULL;
  }
  int *temp = array;
  for (int i = 0; i < size; i += 1)
  {
    *(temp + i) = '\0';
  }
  return array;
}

/* Copy elements from one array to another.
  Paramaters:
    newArray : a newly created array to copy elements to. of size > array.
*/
void CopyArray(int *newArray)
{
  int *temp = array;
  for (int i = 0; i < size; i += 1)
  {
    *(newArray + i) = *(array + i);
  }
}

/* an auxiliary function to help with repeated code. creates a new array with a bigger size, uses the CopyArray function to copy
  from the previous array to the newly created one while making sure to free the memory and reasigning variables where needed

  Paramaters:
    newSize: the new size of the array
  */
void ResizeAndCopy(int newSize)
{
  int *newArr = Create(newSize);
  CopyArray(newArr);
  free(array);
  array = newArr;
  size = newSize;
}

/* an auxiliary function to help copy an array when expanding in size which leaves the first element empty to facilitate adding a new value at the head
  Paramaters:
    newArray: the pointer of the newly created array to copy elements to
*/
void CopyArrayHead(int *newArray)
{
  int *temp = array;
  for (int i = 0; i < size; i += 1)
  {
    *(newArray + (i + 1)) = *(array + i);
  }
}

/* an auxiliary function that helps with shifting elements from the end of the list up to where a new element will be inserted
  Paramaters:
    start: the index from which shifting starts, propably from the last index.
    end: where to stop shifting elements, probably at the index at which we are to insert a new element
  */
void ShiftElementsInwards(int start, int end)
{
  for (int i = end; i >= start; i -= 1)
  {
    array[i + 1] = array[i];
  }
}

void ShiftElementsBackwards(int start, int end)
{
  for (int i = start; i < end; i += 1)
  {
    array[i - 1] = array[i];
  }
}
/* Inserts a value at the head of the array, shifting elements where needed and expanding the array too (where needed).
  Paramaters:
    value: the number to insert in the list
*/
void InsertAtHead(int value)
{
  if (array[0] == '\0')
  { // first element of the list is empty or the list is empty
    array[0] = value;
    currentCapacity += 1;
    return;
  }
  if (currentCapacity < size)
  {
    for (int i = currentCapacity - 1; i >= 0; i -= 1)
    {
      array[i + 1] = array[i];
    }
    array[0] = value;
    currentCapacity += 1;
    return;
  }
  if (currentCapacity == size)
  {
    int newSize = size * 2;
    ResizeAndCopy(newSize);
    array[0] = value;
    currentCapacity += 1;
  }
}

/* inserts an element at the last index of the list, no shift here but array exapnds where needed .
  Paramaters:
    value: the number to add at the end of the array.
*/
void InsertAtTail(int value)
{
  if (array[0] == '\0')
  {
    array[0] = value;
    currentCapacity += 1;
    return;
  }
  if (currentCapacity < size)
  {
    array[currentCapacity] = value;
    currentCapacity += 1;
    return;
  }
  int newSize = size * 2;
  ResizeAndCopy(newSize);
  array[currentCapacity] = value;
  currentCapacity += 1;
}

/* this function will add an element to the list at a given index (at the N-th index), shifting elements where needed and expanding the list. will not support insertion at random indices where inserting other elements disturbes the order of the list
  Paramaters:
    value: the number to add at the N-th index.
    index: the index at which we will be adding the number.
*/
void InsertAtNth(int value, int index)
{
  if (index < 1 || index > currentCapacity + 1)
  {
    return;
  }
  if (currentCapacity == size)
  {
    int newSize = size * 2;
    ResizeAndCopy(newSize);
  }
  if (index == 1)
  {
    InsertAtHead(value);
    return;
  }
  if (index == currentCapacity && array[index] == '\0')
  {
    InsertAtTail(value);
    return;
  }
  for (int i = currentCapacity - 1; i >= index; i -= 1)
  {
    array[i + 1] = array[i];
  }
  array[index] = value;
  currentCapacity += 1;
  return;
}

/* deletes the element at a specific index given in paramater, shifts elemnents where needed
  Paramaters:
    index: the index at which the element should be removed
*/
void DeleteNth(int index)
{
  if (index < 0 || index > currentCapacity + 1)
  {
    return;
  }
  if (index == 0)
  {
    ShiftElementsBackwards(index + 1, currentCapacity);
    array[currentCapacity] = '\0';
    currentCapacity -= 1;
    return;
  }
  if (index == currentCapacity)
  {
    array[currentCapacity] = '\0';
    currentCapacity -= 1;
    return;
  }
  for (int i = index + 1; i < currentCapacity + 1; i += 1)
  {
    array[i - 1] = array[i];
  }
  array[currentCapacity] = '\0';
  currentCapacity -= 1;
}

/* deletes a specific number from the list, if the number is not in the list, nothing happens. shifts elements when needed.
  Paramaters:
    value: the number to be deleted from the list.
*/
void DeleteValue(int value)
{
  int *temp = array;
  int index;
  for (int i = 0; i < currentCapacity; i += 1)
  {
    if (*(temp + i) == value)
    {
      DeleteNth(i);
      return;
    }
  }
}

int main()
{
  size = 5;
  currentCapacity = 0;
  array = Create(size);
  InsertAtNth(7, 1);
  InsertAtHead(9);
  InsertAtHead(2);
  InsertAtHead(1);
  InsertAtHead(3);
  InsertAtNth(5, 5);
  InsertAtNth(4, 3);
  free(array);
  return 0;
}