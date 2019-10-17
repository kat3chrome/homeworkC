#include <stdio.h>

int main()
{

  const int stringLenght = 200;
  char inputString[stringLenght];
  for (int i = 0; i < stringLenght; i++)
  {
    inputString[i] = '\0';
  }

  printf("%s", "Enter string: ");
  scanf("%s", inputString);

  int rightBracket = 0;
  int leftBracket = 0;

  for (int i = 0; i <= stringLenght; i++)
  {
    if (leftBracket - rightBracket < 0)
    {
      break;
    }
    if (inputString[i] == '(')
    {
      leftBracket++;
    }
    if (inputString[i] == ')')
    {
      rightBracket++;
    }
  }

  if (leftBracket == rightBracket)
  {
    printf("Good string");
  }
  else
  {
    printf("Bad string");
  }
  return 0;
}
