#include <stdio.h>
#include <stdlib.h>

int swap(int array[], int a, int b)
{
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}

void siftDown(int array[], int sizeArray, int index)
{
  int indexRightChild = index * 2 + 1;
  int indexLeftChild = index * 2 + 2;
  int indexMinimum = index;

  if ((indexLeftChild < sizeArray) && (array[indexLeftChild] < array[indexMinimum]))
  {
    indexMinimum = indexLeftChild;
  }
  if ((indexRightChild < sizeArray) && (array[indexRightChild] < array[indexMinimum]))
  {
    indexMinimum = indexRightChild;
  }
  if (indexMinimum != index)
  {
    swap(array, indexMinimum, index);
    siftDown(array, sizeArray, indexMinimum);
  }
}

void createHeap(int array[], int sizeArray)
{
  for (int i = sizeArray / 2 - 1; i >= 0; i--)
  {
    siftDown(array, sizeArray, i);
  }
}

void heapSort(int array[], int sizeArray)
{
  createHeap(array, sizeArray);

  for (int i = sizeArray - 1; i > 0; i--)
  {
    swap(array, 0, i);
    siftDown(array, i, 0);
  }
}

int main()
{
  int sizeArray = 0;
  printf("Enter size of array : ");
  scanf("%d", &sizeArray);
  int *array = malloc(sizeArray * sizeof(int));

  printf("Enter array : ");
  for (int i = 0; i < sizeArray; i++)
  {
    scanf("%d", &array[i]);
  }

  heapSort(array, sizeArray);

  printf("Sorted array : ");
  for (int i = 0; i < sizeArray; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  free(array);
  return 0;
}
