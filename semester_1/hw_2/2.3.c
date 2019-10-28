#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

void generationOfNumbers(int array[], int sizeOfArray)
{
  srand(time(NULL));

  for (int i = 0; i < sizeOfArray; i++)
  {
    array[i] = rand() % 10;
  }
}

void printingDotsWithDelay()
{
  int numbersOdDots = 0;
  for (int i = 0; i < numbersOdDots; i++)
  {
    printf(".");
    sleep(1);
    fflush(stdout);
  }
}

void printTitleAndGreeting(int numberOfNumbers)
{
  char title[1181] = "╔══╗─╔╗─╔╗╔╗───╔╗───╔═══╗     ╔═══╗╔═╗─╔╗╔═══╗     ╔═══╗╔═══╗──────╔═══╗\n║╔╗║─║║─║║║║───║║───║╔═╗║     ║╔═╗║║║╚╗║║╚╗╔╗║     ║╔═╗║║╔═╗║──────║╔═╗║\n║╚╝╚╗║║─║║║║───║║───║╚══╗     ║║─║║║╔╗╚╝║─║║║║     ║║─╚╝║║─║║╔╗╔╗╔╗║╚══╗\n║╔═╗║║║─║║║║─╔╗║║─╔╗╚══╗║     ║╚═╝║║║╚╗║║─║║║║     ║║─╔╗║║─║║║╚╝╚╝║╚══╗║\n║╚═╝║║╚═╝║║╚═╝║║╚═╝║║╚═╝║     ║╔═╗║║║─║║║╔╝╚╝║     ║╚═╝║║╚═╝║╚╗╔╗╔╝║╚═╝║\n╚═══╝╚═══╝╚═══╝╚═══╝╚═══╝     ╚╝─╚╝╚╝─╚═╝╚═══╝     ╚═══╝╚═══╝─╚╝╚╝─╚═══╝";
  printf("%s\n", title);

  printf("Welcome to the game!\nThe secret number has %d digits", numberOfNumbers);
  printingDotsWithDelay();
  printf("try to guess the number as quickly as possible!\n");
}

bool isNoNumberInTheString(char inputString[])
{
  int sizeOfString = strlen(inputString);

  for (int i = 0; i < sizeOfString; i++)
  {
    if ((inputString[i] < '0') || (inputString[i] > '9'))
    {
      return true;
    }
  }

  return false;
}

void stringOfCharactersToStringOfNumbers(char charTemporaryNumbers[], int temporaryNumbers[], int numberOfNumbers)
{
  for (int i = 0; i < numberOfNumbers; i++)
  {
    temporaryNumbers[i] = charTemporaryNumbers[i] - '0';
  }
}

bool isCorrectOfLineAndPrintError(char inputString[], const int correctSizeOfInputString, const int numberOfNumbers)
{
  if (strlen(inputString) != correctSizeOfInputString)
  {
    printf("¡Enter a number of the desired length!\n");
    return false;
  }
  else if (isNoNumberInTheString(inputString))
  {
    printf("¡Enter only numbers!\n");
    return false;
  }
  return true;
}

bool isNumberOfRepeats(int temporaryNumbers[], int index, int numberOfNumbers)
{
  int currentDigit = temporaryNumbers[index];
  for (int i = index + 1; i < numberOfNumbers; i++)
  {
    if (currentDigit == temporaryNumbers[i])
    {
      return true;
    }
  }
  return false;
}

bool isCorrectInputNumberAndPrintError(int temporaryNumbers[], int numberOfNumbers)
{
  for (int i = 0; i < numberOfNumbers; i++)
  {
    if (isNumberOfRepeats(temporaryNumbers, i, numberOfNumbers))
    {
      printf("¡The number must be of different characters¡\n");
      return false;
    }
  }
  return true;
}

void printInputPromptAndInitializationOfTemporaryNumber(int temporaryNumbers[], const int numberOfNumbers)
{
  char charTemporaryNumbers[numberOfNumbers];
  printf("Try to guess : ");
  scanf("%s", charTemporaryNumbers);
  bool isCorrectString = isCorrectOfLineAndPrintError(charTemporaryNumbers, numberOfNumbers, numberOfNumbers);

  int currentTemporaryNumbers[numberOfNumbers];
  if (isCorrectString)
  {
    stringOfCharactersToStringOfNumbers(charTemporaryNumbers, currentTemporaryNumbers, numberOfNumbers);
  }

  bool isCorrectNumber = isCorrectInputNumberAndPrintError(currentTemporaryNumbers, numberOfNumbers);
  if (isCorrectNumber)
  {
    stringOfCharactersToStringOfNumbers(charTemporaryNumbers, temporaryNumbers, numberOfNumbers);
  }
}

int main()
{
  const int numberOfNumbers = 4;
  int numbers[numberOfNumbers];
  generationOfNumbers(numbers, numberOfNumbers);

  printTitleAndGreeting(numberOfNumbers);

  int temporaryNumbers[numberOfNumbers];

  int bulls = 0;
  int cows = 0;
  while (bulls != numberOfNumbers)
  {
    temporaryNumbers[0] = -1;
    printInputPromptAndInitializationOfTemporaryNumber(temporaryNumbers, numberOfNumbers);
  }

  return 0;
}
