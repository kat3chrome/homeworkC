#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findValueInArray(int array[], int sizeOfArray, int value)
{
  for (int i = 0; i < sizeOfArray; i++)
  {
    if (array[i] == value)
    {
      return i;
    }
  }

  return -1;
}

void bubbleSort(int* array, int* count, int numberOfValues)
{
  for (int i = 0; i < numberOfValues - 1; i++)
  {
    for (int j = (numberOfValues - 1); j > i; j--)
    {
      if (array[j - 1] > array[j])
      {
        int temp = array[j - 1];
        array[j - 1] = array[j];
        array[j] = temp;

        temp = count[j - 1];
        count[j - 1] = count[j];
        count[j] = temp;
      }
    }
  }
}

void getConsoleInputAndPrintResult()
{
  int numberOfValues = 0;
  int* array = calloc(numberOfValues + 1, sizeof(int));
  int* count = calloc(numberOfValues + 1, sizeof(int));

  int temporary = 0;

  while(true)
  {
    scanf("%d", &temporary);
    if (temporary == 0)
    {
      break;
    }

    int index = findValueInArray(array, numberOfValues, temporary);
    if (index == -1)
    {
      numberOfValues++;
      array = realloc(array, numberOfValues * sizeof(int));
      count = realloc(count, numberOfValues * sizeof(int));
      array[numberOfValues - 1] = temporary;
      count[numberOfValues - 1] = 1;
    }
    else
    {
      count[index]++;
    }
  }

  bubbleSort(array, count, numberOfValues);

  for (int i = 0; i < numberOfValues; i++)
  {
    printf("The number %d has risen %d times\n", array[i], count[i]);
  }

  free(array);
  free(count);
}

int main()
{

  printf("Enter the numbers: ");
  getConsoleInputAndPrintResult();

  return 0;
}
