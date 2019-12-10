#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum operands {MINUS = -1, PLUS = 1};

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
      {
        binarySum[i] = buckupDigit;
        buckupDigit = 0;
        break;
      }
      case 1:
      {
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
      }
      case 2:
      {
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
}

void copyOfBinaryNumber(int *recipientBinaryNumber, int *senderBinaryNumber, int numberOfBinaryDigits)
{
  for (int i = 0; i < numberOfBinaryDigits; i++)
  {
    recipientBinaryNumber[i] = senderBinaryNumber[i];
  }
}

void binaryNumberToReverseCode(int *temporaryBinaryNumber, int *binaryNumber, int numberOfBinaryDigits)
{
  for (int i = 0; i < numberOfBinaryDigits; i++)
  {
    if (binaryNumber[i] == 0)
    {
      temporaryBinaryNumber[i] = 1;
    }
    else
    {
      temporaryBinaryNumber[i] = 0;
    }
  }
}

void binaryNumberToAdditionalCode(int *temporaryBinaryNumber, int *binaryNumber, int numberOfBinaryDigits)
{
  binaryNumberToReverseCode(temporaryBinaryNumber, binaryNumber, numberOfBinaryDigits);
  int binaryOne[numberOfBinaryDigits];
  initializingOfArray(binaryOne, numberOfBinaryDigits);
  binaryOne[numberOfBinaryDigits - 1] = 1;

  sumOfBinaryNumbers(temporaryBinaryNumber, binaryOne, temporaryBinaryNumber, numberOfBinaryDigits);
  printBinaryNumber(temporaryBinaryNumber, numberOfBinaryDigits);
}

void differenceOfBinaryNumbers(int *binaryNumber1, int *binaryNumber2, int *binaryDifference, int numberOfBinaryDigits)
{
  int temporaryBinaryNumber[numberOfBinaryDigits];
  initializingOfArray(temporaryBinaryNumber, numberOfBinaryDigits);
  binaryNumberToAdditionalCode(temporaryBinaryNumber, binaryNumber2, numberOfBinaryDigits);

  sumOfBinaryNumbers(binaryNumber1, temporaryBinaryNumber, binaryDifference, numberOfBinaryDigits);
  printBinaryNumber(binaryDifference, numberOfBinaryDigits);


}

int getSignOfDecimalNumber(int number)
{
  return number > 0 ? PLUS : MINUS;
}

void makeUnsignedDecimalNumber(int *number)
{
  if (*number < 0)
  {
    *number = -*number;
  }
}

void printSignOfNumber(int sign)
{
  if (sign == PLUS)
  {
    printf("+");
  }
  else
  {
    printf("-");
  }
}

void smallestNumberOnFirstPlace(int *decimalNumber1, int *decimalNumber2)
{
  if (*decimalNumber1 > *decimalNumber2)
  {
    int temporary = *decimalNumber1;
    *decimalNumber1 = *decimalNumber2;
    *decimalNumber2 = temporary;
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

  int signOfFirstNumber = getSignOfDecimalNumber(decimalNumber1);
  int signOfSecondNumber = getSignOfDecimalNumber(decimalNumber2);
  int signOfSumOfNumbers = getSignOfDecimalNumber(decimalNumber1 + decimalNumber2);
  int signOfCompositionOfNumbers = getSignOfDecimalNumber(decimalNumber1 * decimalNumber2);

  makeUnsignedDecimalNumber(&decimalNumber1);
  makeUnsignedDecimalNumber(&decimalNumber2);
  smallestNumberOnFirstPlace(&decimalNumber1, &decimalNumber2);

  decimalToBinary(decimalNumber1, binaryNumber1, numberOfBinaryDigits);
  decimalToBinary(decimalNumber2, binaryNumber2, numberOfBinaryDigits);

  int binarySum[numberOfBinaryDigits];
  initializingOfArray(binarySum, numberOfBinaryDigits);

  if (signOfCompositionOfNumbers == MINUS)
  {
    differenceOfBinaryNumbers(binaryNumber1, binaryNumber2, binarySum, numberOfBinaryDigits);
  }
  else
  {
    sumOfBinaryNumbers(binaryNumber1,  binaryNumber2, binarySum, numberOfBinaryDigits);
  }

  binaryToDecimal(&decimalNumber1, binaryNumber1, numberOfBinaryDigits);
  binaryToDecimal(&decimalNumber2, binaryNumber2, numberOfBinaryDigits);

  printf("Greater number in binary form : ");
  printSignOfNumber(signOfFirstNumber);
  printBinaryNumber(binaryNumber1, numberOfBinaryDigits);
  printf("Another in binary form : ");
  printSignOfNumber(signOfSecondNumber);
  printBinaryNumber(binaryNumber2, numberOfBinaryDigits);
  printf("The sum of the numbers in binary form : ");
  printSignOfNumber(signOfSumOfNumbers);
  printBinaryNumber(binarySum, numberOfBinaryDigits);

  int decimalSum = 0;
  binaryToDecimal(&decimalSum, binarySum, numberOfBinaryDigits);
  printf("The sum of the numbers in decimal form : ");
  printSignOfNumber(signOfSumOfNumbers);
  printf("%d\n", decimalSum);
  return 0;
}
