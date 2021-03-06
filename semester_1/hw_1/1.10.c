#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char inputString[])
{
  int stringLenght = strlen(inputString);
  int halfOfStringLenght = stringLenght / 2;
  for (int i = 0; i <= halfOfStringLenght; i++)
  {
    if (inputString[i] != inputString[stringLenght - i - 1])
    {
      return false;
    }
  }
  return true;
}

int main()
{

  const int stringLenght = 100;
  char inputString[stringLenght];
  for (int i = 0; i < stringLenght; i++)
  {
    inputString[i] = '\0';
  }

  printf("%s","Enter string: " );
  scanf("%s", inputString);

  if (isPalindrome(inputString))
  {
    printf("%s", "It is palindrome");
  }
  else
  {
    printf("%s", "It isn't palindrome");
  }

  return 0;
}
