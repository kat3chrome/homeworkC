#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

enum conditionList {INITIAL, FIRSTDIGIT, SECONDDIGIT, DIRECTION, FIRSTDIGITEQUALONE, FIRSTDIGITNOTEQUALONE, NUMBEROFGROUP, DASH, FIRSTM, SECONDM, ERROR};

int getCondition(enum conditionList condition, char inputCharaster)
{
  switch (condition)
  {
    case INITIAL:
    {
      if (isdigit(inputCharaster))
      {
        return FIRSTDIGIT;
      }
      return ERROR;
    }
    case FIRSTDIGIT:
    {
      if (isdigit(inputCharaster))
      {
        return SECONDDIGIT;
      }
      return ERROR;
    }
    case SECONDDIGIT:
    {
      if (inputCharaster == 'B' || inputCharaster == 'M' || inputCharaster == 'S')
      {
        return DIRECTION;
      }
      return ERROR;
    }
    case DIRECTION:
    {
      if (isdigit(inputCharaster))
      {
        if (inputCharaster == '1')
        {
          return FIRSTDIGITEQUALONE;
        }
        return FIRSTDIGITNOTEQUALONE;
      }
      return ERROR;
    }
    case FIRSTDIGITEQUALONE:
    {
      if (inputCharaster == '0')
      {
        return NUMBEROFGROUP;
      }
      return ERROR;
    }
    case FIRSTDIGITNOTEQUALONE:
    {
      if (inputCharaster == '-')
      {
        return DASH;
      }
    }
    case NUMBEROFGROUP:
    {
      if (inputCharaster == '-')
      {
        return DASH;
      }
    }
    case DASH:
    {
      if (inputCharaster == 'm')
      {
        return FIRSTM;
      }
      return ERROR;
    }
    case FIRSTM:
    {
      if (inputCharaster == 'm')
      {
        return SECONDM;
      }
      return ERROR;
    }
    case SECONDM:
    {
      return ERROR;
    }
  }
}

int regularExpression(char* inputString)
{
  enum conditionList condition = INITIAL;
  int index = 0;
  while (inputString[index] != '\0')
  {
    condition = getCondition(condition, inputString[index]);
    if (condition == ERROR)
    {
      return false;
    }
    index++;
  }
  return true;
}

int main()
{
  int sizeOfString = 128;
  char* inputString = calloc(sizeOfString, sizeof(char));

  printf("Enter the string: ");
  scanf("%s", inputString);

  bool isCorrect = regularExpression(inputString);
  if (isCorrect)
  {
    printf("String is correct\n");
  }
  else
  {
    printf("String is not correct\n");
  }

  free(inputString);
  return 0;
}
