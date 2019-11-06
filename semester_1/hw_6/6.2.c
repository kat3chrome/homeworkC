#include <stdio.h>
#include <math.h>

void decimalToBinary(int decimalNumber, int *binaryNumber ,int numberOfBinaryDigits)
{
  int index = 0;
  while (decimalNumber > 0)
  {
    binaryNumber[index] = decimalNumber % 2;
    decimalNumber = decimalNumber / 2;

    index++;
  }
}

void binaryToDecimal(int *decimalNumber, int *binaryNumber ,int numberOfBinaryDigits)
{
  for (int i = 0; i < numberOfBinaryDigits; i++)
  {
    *decimalNumber += binaryNumber[i] * pow(2, i);
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
  for (int i = 0; i < numberOfBinaryDigits; i++)
  {
    printf("%d", binaryNumber[i]);
  }
  printf("\n");
}

// void sumOfBinaryNumbers(int *binaryNumber1, int *binaryNumber2, int *binarySum, int numberOfBinaryDigits)
// {
//
// }

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

  // binarySum[numberOfBinaryDigits];
  // initializingOfArray(binarySum, numberOfBinaryDigits);
  // sumOfBinaryNumbers(binaryNumber1,  binaryNumber2, binarySum, numberOfBinaryDigits);

  printf("First number in binary : ");
  printBinaryNumber(binaryNumber1, numberOfBinaryDigits);
  printf("Second number in binary : ");
  printBinaryNumber(binaryNumber2, numberOfBinaryDigits);

  return 0;
}
