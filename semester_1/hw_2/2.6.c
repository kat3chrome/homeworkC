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

void countDigitsInANumber(int number, int arrayOfCount[], int base)
{
  while (number != 0)
  {
    arrayOfCount[number % base]++;
    number /= base;
  }
}

void makeMinimumNumber(int *finishValue, int arrayOfCount[], int base)
{
  int index = 1;
  for (int i = 1; i < 10; i++)
  {
    if (arrayOfCount[i] > 0)
    {
      index = i;
      break;
    }
  }

  *finishValue *= base;
  *finishValue += index;
  arrayOfCount[index]--;

  int count = arrayOfCount[0];
  for (int j = 0; j < count; j++)
  {
    *finishValue *= base;
  }
  for (int i = 1; i < base; i++)
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

int main()
{

  const int base = 10;
  int number[base];
  int value = 0;
  int finishValue = 0;

  initializeArrayWithZeros(number, base);
  promptToEnter(&value);
  countDigitsInANumber(value, number, base);
  makeMinimumNumber(&finishValue, number, base);
  printMinimumNumber(finishValue);

  return 0;
}
