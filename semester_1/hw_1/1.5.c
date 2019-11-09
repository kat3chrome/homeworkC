#include <stdio.h>
#include <string.h>

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

  int realLenghtString = strlen(inputString);
  for (int i = 0; i <= realLenghtString; i++)
  {
    if (leftBracket < rightBracket)
    {
      break;
    }
    if (inputString[i] == '(')
    {
      leftBracket++;
    }
    else if (inputString[i] == ')')
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
