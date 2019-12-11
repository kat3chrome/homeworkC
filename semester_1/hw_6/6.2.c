#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const int sizeOfBinaryNumber = 32;

void arrayInitialization(bool *array, int sizeOfArray);
void decimalToBinary(bool *binaryNumber, int decimalNumber);
void printBinaryNumber(bool binaryNumber[]);
void sumOfBinaryNumbers(bool *binaryNumber1, bool *binaryNumber2, bool *binarySum);
int binaryToDecimal(bool *binaryNumber);

int main()
{
  int decimalFirstNumber = 0;
  int decimalSecondNumber = 0;
  printf("Enter the numbers: ");
  scanf("%d %d", &decimalFirstNumber, &decimalSecondNumber);

  bool binaryFirstNumber[sizeOfBinaryNumber];
  bool binarySecondNumber[sizeOfBinaryNumber];
  bool binarySumOfNumbers[sizeOfBinaryNumber];
  arrayInitialization(binaryFirstNumber, sizeOfBinaryNumber);
  arrayInitialization(binarySecondNumber, sizeOfBinaryNumber);
  arrayInitialization(binarySumOfNumbers, sizeOfBinaryNumber);

  decimalToBinary(binaryFirstNumber, decimalFirstNumber);
  decimalToBinary(binarySecondNumber, decimalSecondNumber);

  sumOfBinaryNumbers(binaryFirstNumber, binarySecondNumber, binarySumOfNumbers);
  int decimalSumNumbers = binaryToDecimal(binarySumOfNumbers);

  printf("First input number in binary form: ");
  printBinaryNumber(binaryFirstNumber);
  printf("Second input number in binary form: ");
  printBinaryNumber(binarySecondNumber);
  printf("Sum of input numbers in binary form: ");
  printBinaryNumber(binarySumOfNumbers);
  printf("Sum of input numbers in decimal form: ");
  printf("%d\n", decimalSumNumbers);

  return 0;
}

void arrayInitialization(bool *array, int sizeOfArray)
{
  for (int i = 0; i < sizeOfArray; i++)
  {
    array[i] = false;
<<<<<<< HEAD
  }
}

void decimalToBinary(bool *binaryNumber, int decimalNumber)
{
  for (int i = 0; i < sizeOfBinaryNumber; i++)
  {
    binaryNumber[i] = decimalNumber >> i & 1;
  }
}

void printBinaryNumber(bool binaryNumber[])
{
  int placeOfLastOne = 0;
  for (int i = sizeOfBinaryNumber - 1; i >= 1; i--)
  {
    if (binaryNumber[i] == true)
    {
      placeOfLastOne = i;
      break;
    }
  }
  for (int i = placeOfLastOne; i >= 0; i--)
  {
=======
  }
}

void decimalToBinary(bool *binaryNumber, int decimalNumber)
{
  for (int i = 0; i < sizeOfBinaryNumber; i++)
  {
    binaryNumber[i] = decimalNumber >> i & 1;
  }
}

void printBinaryNumber(bool binaryNumber[])
{
  int placeOfLastOne = 0;
  for (int i = sizeOfBinaryNumber - 1; i >= 1; i--)
  {
    if (binaryNumber[i] == true)
    {
      placeOfLastOne = i;
      break;
    }
  }
  for (int i = placeOfLastOne; i >= 0; i--)
  {
>>>>>>> 4ccd7abf043d681ae9dd4ac1375d157aa6b2c7f6
    printf("%d", binaryNumber[i]);
  }
  printf("\n");
}

void sumOfBinaryNumbers(bool *binaryNumber1, bool *binaryNumber2, bool *binarySum)
{
  int buckupDigit = 0;
  int currentSum = 0;

  for (int i = 0; i < sizeOfBinaryNumber; i++)
  {
    currentSum = binaryNumber1[i] + binaryNumber2[i] + buckupDigit;
    binarySum[i] = currentSum % 2;
    buckupDigit = currentSum / 2;
  }
}

int binaryToDecimal(bool *binaryNumber)
{
  int decimalNumber = 0;

<<<<<<< HEAD
  if (binaryNumber[sizeOfBinaryNumber - 1] == 0)
  {
      for (int i = sizeOfBinaryNumber - 1; i >= 0; i--)
      {
          decimalNumber += binaryNumber[i] * (int) pow(2, i);
      }
  }
  else
  {
      for (int i = sizeOfBinaryNumber - 1; i >= 0; i--)
      {
          decimalNumber += !binaryNumber[i] * pow(2, i);
      }
      decimalNumber++;
      decimalNumber *= -1;
=======
  for (int i = 0; i < sizeOfBinaryNumber; i++)
  {
    if (binaryNumber[i] == true)
    {
      decimalNumber += pow(2, i);
    }
>>>>>>> 4ccd7abf043d681ae9dd4ac1375d157aa6b2c7f6
  }

  return decimalNumber;
}
