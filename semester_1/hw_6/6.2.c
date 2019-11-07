#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void arrayReverse(int *array, int sizeOfArray)
{

  int halfSizeArray = sizeOfArray / 2;
  for (int i = 0; i < halfSizeArray; i++)
  {
    int temp = array[i];
    array[i] = array[sizeOfArray - i - 1];
    array[sizeOfArray - i - 1] = temp;
  }
}

void decimalToBinary(int decimalNumber, int *binaryNumber ,int numberOfBinaryDigits)
{
  int index = 0;
  while (decimalNumber > 0)
  {
    binaryNumber[index] = decimalNumber % 2;
    decimalNumber = decimalNumber / 2;

    index++;
  }

  arrayReverse(binaryNumber, numberOfBinaryDigits);
}

void binaryToDecimal(int *decimalNumber, int *binaryNumber ,int numberOfBinaryDigits)
{
  bool isOne = false;
  for (int i = 0; i < numberOfBinaryDigits; i++)
  {
    if (!isOne && binaryNumber[i] == 1)
    {
      isOne = true;
      *decimalNumber += binaryNumber[i] * pow(2, numberOfBinaryDigits - i);
      continue;
    }
    else if (isOne)
    {
      *decimalNumber += binaryNumber[i] * pow(2, numberOfBinaryDigits - i);
    }
  }
  *decimalNumber /= 2;
}

void initializingOfArray(int *array, int sizeOfArray)
{
  for (int i = 0; i < sizeOfArray; i++)
  {
    array[i] = 0;
  }
}

void printBinaryNumber(int *binaryNumber, int numberOfBinaryDigits)
{
  bool isOne = false;
  for (int i = 0; i < numberOfBinaryDigits; i++)
  {
    if (!isOne && binaryNumber[i] == 1)
    {
      isOne = true;
      printf("%d", binaryNumber[i]);
      continue;
    }
    else if (isOne)
    {
      printf("%d", binaryNumber[i]);
    }
  }
  printf("\n");
}

void sumOfBinaryNumbers(int *binaryNumber1, int *binaryNumber2, int *binarySum, int numberOfBinaryDigits)
{
  int buckupDigit = 0;
  for (int i = numberOfBinaryDigits - 1; i >= 1; i--)
  {
    int digitFromBinaryNumber1 = binaryNumber1[i];
    int digitFromBinaryNumber2 = binaryNumber2[i];

    int sumOfCurrentDigits = digitFromBinaryNumber1 + digitFromBinaryNumber2;

    switch (sumOfCurrentDigits)
    {
      case 0:
        binarySum[i] = buckupDigit;
        buckupDigit = 0;
        break;
      case 1:
        if (buckupDigit == 0)
        {
          binarySum[i] = 1;
        }
        else
        {
          binarySum[i] = 0;
          buckupDigit = 1;
        }
        break;
      case 2:
        if (buckupDigit == 0)
        {
          binarySum[i] = 0;
          buckupDigit = 1;
        }
        else
        {
          binarySum[i] = 1;
          buckupDigit = 1;
        }
        break;
    }
  }
}

int main()
{
  int decimalNumber1 = 0;
  int decimalNumber2 = 0;
  int numberOfBinaryDigits = 32;
  int binaryNumber1[numberOfBinaryDigits];
  int binaryNumber2[numberOfBinaryDigits];
  initializingOfArray(binaryNumber1, numberOfBinaryDigits);
  initializingOfArray(binaryNumber2, numberOfBinaryDigits);

  printf("Enter the numbers : ");
  scanf("%d%d", &decimalNumber1, &decimalNumber2);

  decimalToBinary(decimalNumber1, binaryNumber1, numberOfBinaryDigits);
  decimalToBinary(decimalNumber2, binaryNumber2, numberOfBinaryDigits);

  binaryToDecimal(&decimalNumber1, binaryNumber1, numberOfBinaryDigits);
  binaryToDecimal(&decimalNumber2, binaryNumber2, numberOfBinaryDigits);

  int binarySum[numberOfBinaryDigits];
  initializingOfArray(binarySum, numberOfBinaryDigits);
  sumOfBinaryNumbers(binaryNumber1,  binaryNumber2, binarySum, numberOfBinaryDigits);

  printf("First number in binary form : ");
  printBinaryNumber(binaryNumber1, numberOfBinaryDigits);
  printf("Second number in binary form : ");
  printBinaryNumber(binaryNumber2, numberOfBinaryDigits);
  printf("The sum of the numbers in binary form : ");
  printBinaryNumber(binarySum, numberOfBinaryDigits);

  int decimalSum = 0;
  binaryToDecimal(&decimalSum, binarySum, numberOfBinaryDigits);
  printf("The sum of the numbers in decimal form :  %d\n", decimalSum);
  return 0;
}
