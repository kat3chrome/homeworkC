#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void stringInitializationWithZeros(char string[], int stringLenght)
{
  for (int i = 0; i < stringLenght; i++)
  {
    string[i] = '\0';
  }
}

void makeAStringOfLowercaseLetters(char string[], int stringLenght)
{
  for(int i = 0; i < stringLenght; i++)
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
    array[(int)string[i] - 'a']++;
  }
}

void arrayInitializationWithZeros(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
      array[i] = 0;
    }
}

bool isArraysAreEqual(int array1[], int array1Size, int array2[], int array2Size)
{
  if (array1Size != array1Size)
  {
    return false;
  }
  for (int i = 0; i < array1Size; i++)
  {
    if (array1[i] != array2[i])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  const int numberOfLettersInTheAlphabet = 26;
  int stringLenght = 100;
  int subStringLenght = 100;

  char string[stringLenght];
  char subString[subStringLenght];

  stringInitializationWithZeros(string, stringLenght);
  stringInitializationWithZeros(subString, subStringLenght);

  printf("Enter string and substring : ");
  scanf("%s%s", string, subString);

  int arrayOfStringLetters[numberOfLettersInTheAlphabet];
  int arrayOfSubStringLetters[numberOfLettersInTheAlphabet];

  arrayInitializationWithZeros(arrayOfStringLetters, numberOfLettersInTheAlphabet);
  arrayInitializationWithZeros(arrayOfSubStringLetters, numberOfLettersInTheAlphabet);

  makeArrayOfStringLetters(string, stringLenght, arrayOfStringLetters, numberOfLettersInTheAlphabet);
  makeArrayOfStringLetters(subString, subStringLenght, arrayOfSubStringLetters, numberOfLettersInTheAlphabet);

  if(isArraysAreEqual(arrayOfStringLetters, numberOfLettersInTheAlphabet, arrayOfSubStringLetters, numberOfLettersInTheAlphabet))
  {
    printf("%s\n", "Yes");
  }
  else
  {
    printf("%s\n", "No");
  }

  return 0;
}
