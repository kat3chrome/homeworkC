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

void initializingOfArray(int *array, int sizeOfArray)
{
  for (int i = 0; i < sizeOfArray; i++)
  {
    array[i] = 0;
  }
}

void getDoubleNumberInBits(char *pointerOfFirstByteOfNumber, int *doubleNumberInBits, int numberOfBitInDouble)
{
  int sizeOfNumberType = 8;
  int index = 0;
  for (int i = sizeOfNumberType - 1; i >= 0; i--)
  {
    int decimalNumber = pointerOfFirstByteOfNumber[i];
    if (decimalNumber < 0)
    {
      decimalNumber = 256 + decimalNumber;
    }

    int numberOfBinaryDigits = 8;
    int binaryNumber[numberOfBinaryDigits];
    initializingOfArray(binaryNumber, numberOfBinaryDigits);
    decimalToBinary(decimalNumber, binaryNumber, numberOfBinaryDigits);

    for (int j = 0; j < numberOfBinaryDigits; j++)
    {
      doubleNumberInBits[index] = binaryNumber[j];
      index++;
    }
  }

}

void printDoubleNumberInBits(int *doubleNumberInBits)
{
  printf("%d", doubleNumberInBits[0]);
  printf(" ");
  for (int i = 1; i <= 11; i++)
  {
    printf("%d", doubleNumberInBits[i]);
  }
  printf(" ");
  for (int i = 12; i < 64; i++)
  {
    printf("%d", doubleNumberInBits[i]);
  }
  printf("\n");
}

int binaryToDecimal(int *binaryNumber, int numberOfBinaryDigits)
{
  int decimalNumber = 0;
  bool isOne = false;
  for (int i = 0; i < numberOfBinaryDigits; i++)
  {
    if (!isOne && binaryNumber[i] == 1)
    {
      isOne = true;
      decimalNumber += binaryNumber[i] * pow(2, numberOfBinaryDigits - i);
      continue;
    }
    else if (isOne)
    {
      decimalNumber += binaryNumber[i] * pow(2, numberOfBinaryDigits - i);
    }
  }
  decimalNumber /= 2;
  return decimalNumber;
}

void printMantiss(int *doubleNumberInBits)
{
  int sizeOfMantiss = 52;
  int arrayOfMantiss[sizeOfMantiss];
  initializingOfArray(arrayOfMantiss, sizeOfMantiss);
  for (int i = 0; i < sizeOfMantiss; i++)
  {
    arrayOfMantiss[i] = doubleNumberInBits[12 + i];
  }

  double mantiss = 0;
  for (int i = 0; i < sizeOfMantiss; i++)
  {
    mantiss += arrayOfMantiss[i] * pow(2, - i - 1);
  }

  printf("%.16g", mantiss + 1);
}

void printExponent(int *doubleNumberInBits)
{
  int sizeOfExponent = 11;
  int arrayOfExponent[sizeOfExponent];
  initializingOfArray(arrayOfExponent, sizeOfExponent);
  for (int i = 0; i < sizeOfExponent; i++)
  {
    arrayOfExponent[i] = doubleNumberInBits[1 + i];
  }
  int exponent = binaryToDecimal(arrayOfExponent, sizeOfExponent) - 1023;
  printf("*2^%d\n", exponent);
}

void printDoubleNumberByItsRepresentationInMemory(int *doubleNumberInBits)
{
  int numberOfBitInDouble = 64;
  doubleNumberInBits[0] == 0 ? printf("+") : printf("-");
  printMantiss(doubleNumberInBits);
  printExponent(doubleNumberInBits);
}

int main()
{
  while(true)
  {
    double number = 0;
    printf("Enter a number: ");
    scanf("%lf", &number);
    int numberOfBitInDouble = 64;
    int doubleNumberInBits[numberOfBitInDouble];
    initializingOfArray(doubleNumberInBits, numberOfBitInDouble);
    getDoubleNumberInBits((char*)&number, doubleNumberInBits, numberOfBitInDouble);
    printf("Result: ");
    printDoubleNumberByItsRepresentationInMemory(doubleNumberInBits);
  }
  return 0;
}
