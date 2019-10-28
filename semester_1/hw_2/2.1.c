#include <stdio.h>
#include <stdlib.h>

int min(int numberA, int numberB)
{
    return (numberA < numberB ? numberA : numberB);
}

void printSums(int needAdd, int *sum, int numberOfSum)
{
  if (needAdd == 0)
    {
      for (int i = 0; i < numberOfSum; i++)
      {
        printf("%d", sum[i]);
        printf("%s", (i + 1 == numberOfSum ? ";\n" : " + "));
      }

      return;
    }

  int maxTerm = 0;

  if (numberOfSum > 0)
    {
      maxTerm = min(needAdd, sum[numberOfSum - 1]);
    }
  else
    {
      maxTerm = needAdd;
    }

  for (int term = maxTerm; term > 0; term--)
  {
    sum[numberOfSum] = term;
    printSums(needAdd - term, sum, numberOfSum + 1);
  }
}

int main()
{
    int number = 0;
    printf("Enter the number:");
    scanf("%d", &number);

    printf("The sums of %d are:\n", number);
    int *numberSum = malloc(number * sizeof(int));
    printSums(number, numberSum, 0);

    free(numberSum);
    return 0;
}
