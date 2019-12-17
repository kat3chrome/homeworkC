#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void initializeStringWithZeros(char string[], int stringLength)
{
  for (int i = 0; i < stringLength; i++)
  {
    string[i] = '\0';
  }
}

void makeAStringOfLowercaseLetters(char string[], int stringLength)
{
  for (int i = 0; i < stringLength; i++)
   {
       if (string[i] >= 'A' && string[i] <= 'Z')
       {
           string[i] = tolower(string[i]);
       }
   }
}

void makeArrayOfStringLetters(char string[], int stringLength, int array[], int sizeArray)
{
  makeAStringOfLowercaseLetters(string, stringLength);
  for (int i = 0; i < stringLength; i++)
  {
    int currentPosition = (int)(string[i] - 'a');
    if (currentPosition < 0 || currentPosition >= sizeArray)
    {
      continue;
    }
    array[currentPosition]++;
  }
}

void initializeArrayWithZeros(int array[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    array[i] = 0;
  }
}

bool isArraysAreEqual(int arrayFirst[], int arrayFirstSize, int arraySecond[], int arraySecondSize)
{
  if (arrayFirstSize != arrayFirstSize)
  {
    return false;
  }
  for (int i = 0; i < arrayFirstSize; i++)
  {
    if (arrayFirst[i] != arraySecond[i])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  const int numberOfLettersInTheAlphabet = 26;
  const int stringFirstLength = 100;
  const int stringSecondLength = 100;

  char stringFirst[stringFirstLength];
  char stringSecond[stringSecondLength];

  initializeStringWithZeros(stringFirst, stringFirstLength);
  initializeStringWithZeros(stringSecond, stringSecondLength);

  printf("Enter first string and second string : ");
  scanf("%s%s", stringFirst, stringSecond);

  int arrayOfStringFirstLetters[numberOfLettersInTheAlphabet];
  int arrayOfstringSecondLetters[numberOfLettersInTheAlphabet];

  initializeArrayWithZeros(arrayOfStringFirstLetters, numberOfLettersInTheAlphabet);
  initializeArrayWithZeros(arrayOfstringSecondLetters, numberOfLettersInTheAlphabet);

  makeArrayOfStringLetters(stringFirst, stringFirstLength, arrayOfStringFirstLetters, numberOfLettersInTheAlphabet);
  makeArrayOfStringLetters(stringSecond, stringSecondLength, arrayOfstringSecondLetters, numberOfLettersInTheAlphabet);

  if (isArraysAreEqual(arrayOfStringFirstLetters, numberOfLettersInTheAlphabet, arrayOfstringSecondLetters, numberOfLettersInTheAlphabet))
  {
    printf("%s\n", "Yes, you can rearrange the characters in the first string to get the second string.");
  }
  else
  {
    printf("%s\n", "No, you can't rearrange the characters in the first string to get the second string.");
  }

  return 0;
}
