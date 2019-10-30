#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void initializeTheString(char string[])
{
  int stringLenght = strlen(string);
  for (int i = 0; i < stringLenght; i++)
  {
    string[i] = '\0';
  }
}

bool isSubstringInString(char substring[], char string[], int startIndex)
{
  int substringLenght = strlen(substring);
  for(int i = 0; i < substringLenght; i++)
  {
    if (string[i + startIndex] != substring[i])
    {
      return false;
    }
  }
  return true;
}

int countNumberSubstringInString(char inputString[], char inputSubstring[])
{
  int inputStringLength = strlen(inputString);
  int inputSubstringLength = strlen(inputSubstring);
  int numberSubstringInString = 0;

  for (int i = 0; i <= inputStringLength - inputSubstringLength; i++)
  {
    if (isSubstringInString(inputSubstring, inputString, i))
    {
      numberSubstringInString++;
    }
  }

  return numberSubstringInString;
}

int main()
{

  const int maxStringLength = 100;
  char inputString[maxStringLength];
  char inputSubstring[maxStringLength];

  initializeTheString(inputString);
  initializeTheString(inputSubstring);

  printf("%s", "Enter string (1) and substring (2): ");
  scanf("%s%s", inputString, inputSubstring);

  int numberSubstringInString = countNumberSubstringInString(inputString, inputSubstring);

  printf("%s", "Number of substring in the string = ");
  printf("%d", numberSubstringInString);

  return 0;
}
