#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void initializeStringWithZeros(char string[], int stringLenght)
{
  for (int i = 0; i < stringLenght; i++)
  {
    string[i] = '\0';
  }
}

void makeAStringOfLowercaseLetters(char string[], int stringLenght)
{
  for (int i = 0; i < stringLenght; i++)
   {
       if (string[i] >= 'A' && string[i] <= 'Z')
       {
           string[i] = tolower(string[i]);
       }
   }
}

void makeArrayOfStringLetters(char string[], int stringLenght, int array[], int sizeArray)
{
  makeAStringOfLowercaseLetters(string, stringLenght);
  for (int i = 0; i < stringLenght; i++)
  {
    array[(int)(string[i] - 'a')]++;
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
  int stringFirstLenght = 100;
  int stringSecondLenght = 100;

  char stringFirst[stringFirstLenght];
  char stringSecond[stringSecondLenght];

  initializeStringWithZeros(stringFirst, stringFirstLenght);
  initializeStringWithZeros(stringSecond, stringSecondLenght);

  printf("Enter first string and second string : ");
  scanf("%s%s", stringFirst, stringSecond);

  int arrayOfStringFirstLetters[numberOfLettersInTheAlphabet];
  int arrayOfstringSecondLetters[numberOfLettersInTheAlphabet];

  initializeArrayWithZeros(arrayOfStringFirstLetters, numberOfLettersInTheAlphabet);
  initializeArrayWithZeros(arrayOfstringSecondLetters, numberOfLettersInTheAlphabet);

  makeArrayOfStringLetters(stringFirst, stringFirstLenght, arrayOfStringFirstLetters, numberOfLettersInTheAlphabet);
  makeArrayOfStringLetters(stringSecond, stringSecondLenght, arrayOfstringSecondLetters, numberOfLettersInTheAlphabet);

  if(isArraysAreEqual(arrayOfStringFirstLetters, numberOfLettersInTheAlphabet, arrayOfstringSecondLetters, numberOfLettersInTheAlphabet))
  {
    printf("%s\n", "Yes, you can rearrange the characters in the first string to get the second string.");
  }
  else
  {
    printf("%s\n", "No, you can't rearrange the characters in the first string to get the second string.");
  }

  return 0;
}
