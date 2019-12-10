#include <stdio.h>
#include <stdlib.h>

void printLine(int signOne, int *coordinate1, int *coordinate2, int arrayRowSize, int **array ,int currentIndex)
{
  for (int j = 1; j <= currentIndex; j++)
  {
    if (*coordinate1 == arrayRowSize && *coordinate2 == arrayRowSize)
    {
      break;
    }
    *coordinate2 += signOne;
    printf("%d ", array[*coordinate1][*coordinate2]);
  }
  for (int j = 1; j <= currentIndex; j++)
  {
    if (*coordinate1 == arrayRowSize && *coordinate2 == arrayRowSize)
    {
      break;
    }
    *coordinate1 -= signOne;
    printf("%d ", array[*coordinate1][*coordinate2]);
  }
}

void printBySpiral(int **array, int arrayRowSize)
{
  int coordinate1 = (arrayRowSize / 2) + 1;
  int coordinate2 = (arrayRowSize / 2) + 1;
  printf("%d ", array[coordinate1][coordinate2]);
  for (int i = 1; i <= arrayRowSize; i++)
  {
    if ((i % 2) != 0)
    {
      printLine(1, &coordinate1, &coordinate2, arrayRowSize, array, i);
    }
    if ((i % 2) == 0)
    {
      printLine(-1, &coordinate1, &coordinate2, arrayRowSize, array, i);
    }
  }
}

int main()
{
  printf("Enter the arrayRowSize of elements per side of the array : ");
  int arrayRowSize = 0;
  scanf("%d", &arrayRowSize);
  while (arrayRowSize % 2 == 0)
  {
    printf("The arrayRowSize must be odd, enter the arrayRowSize again : ");
    scanf("%d", &arrayRowSize);
  }

  int **array = (int**)malloc(sizeof(int*) * (arrayRowSize + 1));
  for (int i = 1; i <= arrayRowSize; i++)
  {
      array[i] = (int*)malloc(sizeof(int) * (arrayRowSize + 1));
  }

  printf("Enter the array line by line\n");
  for (int i = 1; i <= arrayRowSize; i++)
  {
    printf("Enter %d line : ", i);
    for (int j = 1; j <= arrayRowSize; j++)
    {
      scanf("%d", &array[i][j]);
    }
  }

  printf("Output elements in a spiral : ");
  printBySpiral(array, arrayRowSize);

  for (int i = 1; i <= arrayRowSize; i++)
  {
    free(array[i]);
  }
  free(array);
  return 0;
}
