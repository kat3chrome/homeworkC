#include <stdio.h>
#include <stdlib.h>

void moveToEnd(int *array, int currentIndex, int arraySize)
{
  for (int i = currentIndex; i < arraySize - 1; i++)
  {
    int temp = array[i];
    array[i] = array[i + 1];
    array[i + 1] = temp;
  }
}

int main()
{
  int arraySize = 0;

  printf("Enter array size: ");
  scanf("%d", &arraySize);

  int *array = (int*)malloc(arraySize * sizeof(int));
  printf("Enter values: ");
  for (int i = 0; i < arraySize; i++)
  {
    scanf("%d", &array[i]);
  }

  for (int i = 0; i < arraySize; i++)
  {
    if (array[i] == 0)
    {
      moveToEnd(array, i, arraySize);
    }
  }

  printf("Modified array : ");
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", array[i]);
  }

  free(array);
  return 0;
}
