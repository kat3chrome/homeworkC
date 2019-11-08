#include <stdio.h>

void printFareiSequence(int value, int leftFractionNumerator, int leftFractionDenominator,
  int rightFractionNumerator, int rightFractionDenominator)
{
  int newNumerator = leftFractionNumerator + rightFractionNumerator;
  int newDenominator = leftFractionDenominator + rightFractionDenominator;
  if (newDenominator <= value)
  {
    printFareiSequence(value, leftFractionNumerator, leftFractionDenominator, newNumerator, newDenominator);
    printf("%d/%d ", newNumerator, newDenominator);
    printFareiSequence(value, newNumerator, newDenominator, rightFractionNumerator, rightFractionDenominator);
  }
}

int main()
{
  int value = 0;
  printf("Enter maximum denominator : ");
  scanf("%d", &value);
  printFareiSequence(value, 0, 1, 1, 1);
  printf("\n");
  return 0;
}
