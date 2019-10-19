#include <stdio.h>
#include <stdlib.h>
int main()
{
  int arraySize = 0;
  int zeroCount = 0;
  int sizeOfInt = sizeof(int);

  printf("Enter array size: ");
  scanf("%d", &arraySize);

  int *array = (int*)malloc(arraySize * sizeOfInt);
  printf("Enter values: ");

  int realIterator = 0;
  for (int i = 0; i < arraySize; i++)
  {
    int temp = 0;
    scanf("%d", &temp);

    if (temp == 0)
    {
      zeroCount++;
    }
    else
    {
      array[realIterator] = temp;
      realIterator++;
    }
  }

  for (realIterator++; realIterator < arraySize; realIterator++)
  {
      array[realIterator] = 0;
  }

  printf("Modified array : ");
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", array[i]);
  }

  free(array);
  return 0;
}
