#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *value1, const void *value2)
{
     return -(*(int*)value1 - *(int*)value2);
}

int main()
{

  int arraySize = 0;
  printf("Enter size of array: ");
  scanf("%d", &arraySize);

  int *array = (int*)malloc(arraySize * sizeof(int));

  for (int i = 0; i < arraySize; i++)
  {
    scanf("%d", &array[i]);
  }

  qsort(array, arraySize, sizeof(int), compare);

  bool isElement = false;
  for (int i = 1; i < arraySize; i++)
  {
    if (array[i - 1] == array[i])
    {
      printf("Maximum array element that occurs more than once : %d\n", array[i]);
      isElement = true;
      break;
    }
  }

  if (!isElement)
  {
    printf("Maximum array element that occurs more than once is not in the array");
  }

  free(array);

  return 0;
}
