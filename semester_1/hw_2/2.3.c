#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

bool isDigitInArray(int array[], int temporaryDigit, int index)
{
  for (int i = 0; i < index; i ++)
  {
    if (array[i] == temporaryDigit)
    {
      return true;
    }
  }

  return false;
}

void generateNumber(int array[], int sizeOfArray)
{
  srand(time(NULL));

  for (int i = 0; i < sizeOfArray; i++)
  {
    int temporaryDigit = rand() % 10;
    while (isDigitInArray(array, temporaryDigit, i))
    {
      temporaryDigit = rand() % 10;
    }

    array[i] = temporaryDigit;
  }
}

void printingDotsWithDelay(int numbersOdDots)
{
  for (int i = 0; i < numbersOdDots; i++)
  {
    printf(".");
    sleep(1);
    fflush(stdout);
  }
}

void printTitleAndGreeting(int numberOfNumbers)
{
  char *title =
  "╔══╗─╔╗─╔╗╔╗───╔╗───╔═══╗     ╔═══╗╔═╗─╔╗╔═══╗     ╔═══╗╔═══╗──────╔═══╗\n"
  "║╔╗║─║║─║║║║───║║───║╔═╗║     ║╔═╗║║║╚╗║║╚╗╔╗║     ║╔═╗║║╔═╗║──────║╔═╗║\n"
  "║╚╝╚╗║║─║║║║───║║───║╚══╗     ║║─║║║╔╗╚╝║─║║║║     ║║─╚╝║║─║║╔╗╔╗╔╗║╚══╗\n"
  "║╔═╗║║║─║║║║─╔╗║║─╔╗╚══╗║     ║╚═╝║║║╚╗║║─║║║║     ║║─╔╗║║─║║║╚╝╚╝║╚══╗║\n"
  "║╚═╝║║╚═╝║║╚═╝║║╚═╝║║╚═╝║     ║╔═╗║║║─║║║╔╝╚╝║     ║╚═╝║║╚═╝║╚╗╔╗╔╝║╚═╝║\n"
  "╚═══╝╚═══╝╚═══╝╚═══╝╚═══╝     ╚╝─╚╝╚╝─╚═╝╚═══╝     ╚═══╝╚═══╝─╚╝╚╝─╚═══╝";

  printf("%s\n", title);
  printf("Welcome to the game!\nThe secret number has %d digits", numberOfNumbers);
  int numbersOdDots = 4;
  printingDotsWithDelay(numbersOdDots);
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
    if (isNoNumberInTheString(inputString))
    {
      printf("¡Enter only numbers!\n");
    }
    return false;
  }

  else if (isNoNumberInTheString(inputString))
  {
    printf("¡Enter only numbers!\n");
    if (strlen(inputString) != correctSizeOfInputString)
    {
      printf("¡Enter a number of the desired length!\n");
    }
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

void printInputPromptAndInitializationOfTemporaryNumber(int temporaryNumbers[], const int numberOfNumbers , int numbers[], bool *isCorrectInputString)
{
  char charTemporaryNumbers[numberOfNumbers];

  printf("Try to guess : ");
  scanf("%s", charTemporaryNumbers);

  //for test
  if (charTemporaryNumbers[0] == 'h' && charTemporaryNumbers[numberOfNumbers - 1] == 'k')
  {
    for (int i = 0; i < numberOfNumbers; i++)
    {
      printf("%d", numbers[i]);
    }
    printf("\n");
  }
  //for test

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
    *isCorrectInputString = true;
  }
}

int numberOfBulls(int temporaryNumbers[], int numbers[], int numberOfNumbers)
{
  int bulls = 0;

  for (int i = 0; i < numberOfNumbers; i++)
  {
    if (temporaryNumbers[i] == numbers[i])
    {
      bulls++;
    }
  }

  return bulls;
}

bool isCurrentDigitAndIsNotBull(int temporaryNumbers[], int numbers[], int numberOfNumbers, int index)
{
  int currentDigit = temporaryNumbers[index];

  for (int i = 0; i < numberOfNumbers; i++)
  {
    if ((currentDigit == numbers[i]) && (i != index))
    {
      return true;
    }
  }

  return false;
}

int numberOfCows(int temporaryNumbers[], int numbers[], int numberOfNumbers)
{
  int cows = 0;

  for (int i = 0; i < numberOfNumbers; i++)
  {
    if(isCurrentDigitAndIsNotBull(temporaryNumbers, numbers, numberOfNumbers, i))
    {
      cows++;
    }
  }

  return cows;
}

void printGreeting()
{
  char *congrats =
  "▄▄▄░░░░░░░░░░░░░░░░░░░░░░▄▄▄\n"
  "░███░░░░░░░░▄▄▄▄░░░░░░░░███░\n"
  "░░█▀█▄▄▄░░░██████░░░▄▄▄█▀█░░\n"
  "░░▀█░░░▀▀██▄▄▄▄▄▄██▀▀░░░█▀░░\n"
  "░░░░▀███▄██████████▄███▀░░░░\n"
  "░░░▄█▀▄███▀██████▀███▄▀█░░░░\n"
  "░░▄██▄██░██████████░██▄██▄░░\n"
  "░░███████░████████░███████░░\n"
  "░░████████░█▀▀▀▀█░████████░░\n"
  "░░▀███████░█▄▄▄▄█░███████▀░░\n"
  "░░░▀███████▄▄▄▄▄▄███████▀░░░\n"
  "░░░░▀██████████████████▀░░░░\n"
  "░░░░░▀████████████████▀░░░░░\n"
  "░░░░░░████████████████░░░░░░\n"
  "░░░░░░█████░░▀▀░░█████░░░░░░\n"
  "░░░░░░▀███░░░░░░░░███▀░░░░░░\n"
  "░░░░░░░███░░░░░░░░███░░░░░░░\n"
  "░░░░░░░███░░░░░░░░███░░░░░░░\n"
  "░░░░░░█████░░░░░░█████░░░░░░";

  printf("%s\n", congrats);
  printf("Congratulations, you were able to do it!!!\n");
}

int main()
{
  const int numberOfNumbers = 4;
  int numbers[numberOfNumbers];
  generateNumber(numbers, numberOfNumbers);

  printTitleAndGreeting(numberOfNumbers);

  int bulls = 0;
  int cows = 0;
  while (bulls != numberOfNumbers)
  {
    bulls = 0;
    cows = 0;
    int temporaryNumbers[numberOfNumbers];
    bool isCorrectInputString = false;

    printInputPromptAndInitializationOfTemporaryNumber(temporaryNumbers, numberOfNumbers, numbers, &isCorrectInputString);


    if (isCorrectInputString)
    {
      bulls = numberOfBulls(temporaryNumbers, numbers, numberOfNumbers);
      cows = numberOfCows(temporaryNumbers, numbers, numberOfNumbers);

      printf("The number of bulls = %d and the number of cows = %d\n", bulls, cows);
    }
  }

  printGreeting();

  return 0;
}
