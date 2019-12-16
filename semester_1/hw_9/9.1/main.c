#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


enum typeOfToken { SIGN, DOT, DIGIT, EXPONENT, END, SPACE, ERROR};

char* getConsoleInput()
{
  char* input;
  int length = 0;

  char temporary;
  while((temporary = getchar()) != '\n')
  {
    length++;
    input = realloc(input, length);
    input[length - 1] = temporary;
  }
  length++;
  input = realloc(input, length);
  input[length - 1] = '\0';

  return input;
}

int getTypeOfToken(char charaster)
{
  if (charaster == '-' || charaster == '+')
  {
    return SIGN;
  }
  else if (charaster == '.')
  {
    return DOT;
  }
  else if (charaster >= '0' && charaster <= '9')
  {
    return DIGIT;
  }
  else if (charaster == 'E')
  {
    return EXPONENT;
  }
  else if (charaster == '\0')
  {
    return END;
  }
  else if (charaster == ' ')
  {
    return SPACE;
  }
  else
  {
    return ERROR;
  }
}

void deleteFirstCharaster(char* input)
{
  int length = strlen(input);
  for (int i = 1; i < length; i++)
  {
    input[i - 1] = input[i];
  }

  input[length - 1] = '\0';
}

bool checkSign(char* input)
{
  int typeOfCurrentToken = getTypeOfToken(input[0]);

  if (typeOfCurrentToken == SIGN)
  {
    deleteFirstCharaster(input);
    return true;
  }
  else if (typeOfCurrentToken == DIGIT)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool checkDigitsBeforDot(char* input)
{
  while(true)
  {
    int typeOfCurrentToken = getTypeOfToken(input[0]);
    if (typeOfCurrentToken != DIGIT)
    {
      if (typeOfCurrentToken == DOT || typeOfCurrentToken == EXPONENT || typeOfCurrentToken == END)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
    deleteFirstCharaster(input);
  }
}

bool checkDigitsAfterDot(char* input)
{
  int typeOfCurrentToken = getTypeOfToken(input[0]);

  if (typeOfCurrentToken == DOT && getTypeOfToken(input[0]) == DIGIT)
  {
    deleteFirstCharaster(input);
  }
  else if (typeOfCurrentToken == DOT && getTypeOfToken(input[0]) != DIGIT)
  {
    return false;
  }

  while(true)
  {
    int typeOfCurrentToken = getTypeOfToken(input[0]);
    if (typeOfCurrentToken != DIGIT)
    {
      if (typeOfCurrentToken == EXPONENT || typeOfCurrentToken == END)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    deleteFirstCharaster(input);
  }
}

bool checkMantissa(char* input)
{
  bool isMantissa = true;

  isMantissa = checkSign(input);
  isMantissa = checkDigitsBeforDot(input);
  isMantissa = checkDigitsAfterDot(input);
}

bool checkExponent(char* input)
{
  bool isExponent = true;

  int typeOfCurrentToken = getTypeOfToken(input[0]);
  if (typeOfCurrentToken == EXPONENT)
  {
    deleteFirstCharaster(input);
  }
  else if (typeOfCurrentToken == END)
  {
    return true;
  }
  else if (typeOfCurrentToken != DIGIT)
  {
    return false;
  }

  isExponent = checkSign(input);
  isExponent = checkDigitsBeforDot(input);
}
// (+ | -)? digit+ (. digit+)? (E(+ | -)? digit+)?
bool isRealNumber(char* inputString)
{
  bool isRealNumber = true;

  isRealNumber = checkMantissa(inputString);
  if(!isRealNumber)
  {
    return false;
  }
  isRealNumber = checkExponent(inputString);
  if(!isRealNumber)
  {
    return false;
  }

  return true;
}

int main()
{
  printf("Enter the string: ");
  char* inputString = getConsoleInput();

  if (isRealNumber(inputString))
  {
    printf("It is real number\n");
  }
  else
  {
    printf("It is not real number\n");
  }
  return 0;
}
