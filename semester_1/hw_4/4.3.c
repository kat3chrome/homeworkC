#include <stdio.h>
#include <stdlib.h>

void printBySpiral(int **array, int number)
{
  int coordinate1 = (number / 2) + 1;
  int coordinate2 = (number / 2) + 1;
  printf("%d ", array[coordinate1][coordinate2]);
  for (int i = 1; i <= number; i++)
  {
    if ((i % 2) != 0)
    {
      for (int j = 1; j <= i; j++)
      {
        if (coordinate1 == number && coordinate2 == number)
        {
          break;
        }
        coordinate2++;
        printf("%d ", array[coordinate1][coordinate2]);
      }
      for (int j = 1; j <= i; j++)
      {
        if (coordinate1 == number && coordinate2 == number)
        {
          break;
        }
        coordinate1--;
        printf("%d ", array[coordinate1][coordinate2]);
      }
    }
    if ((i % 2) == 0)
    {
      for (int j = 1; j <= i; j++)
      {
        if (coordinate1 == number && coordinate2 == number)
        {
          break;
        }
        coordinate2--;
        printf("%d ", array[coordinate1][coordinate2]);
      }
      for (int j = 1; j <= i; j++)
      {
        if (coordinate1 == number && coordinate2 == number)
        {
          break;
        }
        coordinate1++;
        printf("%d ", array[coordinate1][coordinate2]);
      }
    }
  }
}

int main()
{
  printf("Enter the number of elements per side of the array : ");
  int number = 0;
  scanf("%d", &number);
  while (number % 2 == 0)
  {
    printf("The number must be odd, enter the number again : ");
    scanf("%d\n", &number);
  }

  int **array = (int**)malloc(sizeof(int*) * (number + 1));
  for (int i = 1; i <= number; i++)
  {
      array[i] = (int*)malloc(sizeof(int) * (number + 1));
  }

  printf("Enter the array line by line\n");
  for (int i = 1; i <= number; i++)
  {
    printf("Enter %d line : ", i);
    for (int j = 1; j <= number; j++)
    {
      scanf("%d", &array[i][j]);
    }
  }

  printf("Output elements in a spiral : ");
  printBySpiral(array, number);

  for (int i = 1; i <= number; i++)
  {
    free(array[i]);
  }
  free(array);
  return 0;
}
