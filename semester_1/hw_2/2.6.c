#include <stdio.h>

void initializeArrayWithZeros(int array[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    array[i] = 0;
  }
}

void promptToEnter(int *value)
{
  printf("%s", "Enter value: ");
  scanf("%d", value);
}

void countingDigitsInANumber(int number, int arrayOfCount[], int base)
{
  while (number != 0)
  {
    arrayOfCount[number % base]++;
    number /= base;
  }
}

void makeMinimumNumber(int *finishValue, int arrayOfCount[], int base)
{
  int count = arrayOfCount[1];
  for (int j = 0; j < count; j++)
  {
    *finishValue *= base;
    *finishValue += 1;
  }
  count = arrayOfCount[0];
  for (int j = 0; j < count; j++)
    {
    *finishValue *= base;
    }
  for (int i = 2; i < base; i++)
  {
    count = arrayOfCount[i];
    for (int j = 0; j < count; j++)
    {
      *finishValue *= base;
      *finishValue += i;
    }
  }
}

void printMinimumNumber(int minimumNumber)
{
  printf("Minimum number = %d\n", minimumNumber);
}

int main() {

  const int base = 10;
  int number[base];
  int value = 0;
  int finishValue = 0;

  initializeArrayWithZeros(number, base);
  promptToEnter(&value);
  countingDigitsInANumber(value, number, base);
  makeMinimumNumber(&finishValue, number, base);
  printMinimumNumber(finishValue);

  return 0;
}
