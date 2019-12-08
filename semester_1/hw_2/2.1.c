#include <stdio.h>
#include <stdlib.h>

int min(int numberA, int numberB)
{
  return (numberA < numberB ? numberA : numberB);
}

void printSums(int needAdd, int *currentSummands, int numberOfSummands)
{
  if (needAdd == 0)
  {
    for (int i = 0; i < numberOfSummands; i++)
    {
      printf("%d", currentSummands[i]);
      printf("%s", (i + 1 == numberOfSummands ? ";\n" : " + "));
    }

    return;
  }

  int maxTerm = 0;

  if (numberOfSummands > 0)
  {
    maxTerm = min(needAdd,currentSummands[numberOfSummands - 1]);
  }
  else
  {
    maxTerm = needAdd;
  }

  for (int term = maxTerm; term > 0; term--)
  {
    currentSummands[numberOfSummands] = term;
    printSums(needAdd - term,currentSummands, numberOfSummands + 1);
  }
}

int main()
{
  int number = 0;
  printf("Enter the number:");
  scanf("%d", &number);

  printf("ThecurrentSummandss of %d are:\n", number);
  int *numberSum = malloc(number * sizeof(int));
  printSums(number, numberSum, 0);

  free(numberSum);
  return 0;
}
