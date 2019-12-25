#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool checkFirstTwoDigits(char* inputString)
{
  if (inputString[0] >= '0' && inputString[0] <= '9' && inputString[1] >= '0' && inputString[1] <= '9' )
  {
    return true;
  }
  return false;
}

bool checkThirdDigit(char* inputString)
{
  if (inputString[2] == 'B' || inputString[2] == 'M' || inputString[2] == 'S')
  {
    return true;
  }
  return false;
}

bool checkDigitAfterThird(char* inputString)
{
  if (inputString[3] >= '0' && inputString[3] <= '9' && inputString[4] == '-' &&  inputString[5] == 'm' && inputString[6] == 'm' && inputString[7] == '\0')
  {
    return true;
  }
  else if (inputString[3] == '1' && inputString[4] == '0' && inputString[5] == '-' &&  inputString[6] == 'm' && inputString[7] == 'm' && inputString[8] == '\0')
  {
    return true;
  }
  return false;
}

bool regularExpression(char* inputString)
{
  bool isNumber = true;
  isNumber = checkFirstTwoDigits(inputString);
  if (!isNumber)
  {
    return false;
  }
  isNumber = checkThirdDigit(inputString);
  if (!isNumber)
  {
    return false;
  }
  isNumber = checkDigitAfterThird(inputString);
  if (!isNumber)
  {
    return false;
  }
  return isNumber;
}

void printResult(bool isNumber)
{
  isNumber ? printf("It is correct string\n") : printf("It is not correct string\n");
}

int main()
{
  int sizeOfString = 128;
  char* inputString = calloc(sizeOfString, sizeof(char));
  printf("Enter the string: ");
  scanf("%s", inputString);
  bool isNumber = regularExpression(inputString);
  printResult(isNumber);
  return 0;
}
