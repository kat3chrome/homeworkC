#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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

void validationOfLineAndPrintError(char inputString[], const int sizeOfInputString)
{
  for
}

void printInputPromptAndInitializationOfTemporaryNumber(int temporaryNumbers[], const int numberOfNumbers)
{
  char charTemporaryNumbers[numberOfNumbers];
  printf("Try to guess : ");
  scanf("%s", &charTemporaryNumbers);
  validationOfLineAndPrintError(charTemporaryNumbers, numberOfNumbers);
  printf("%s\n", charTemporaryNumbers);
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
    printInputPromptAndInitializationOfTemporaryNumber(temporaryNumbers, numberOfNumbers);

  }

  return 0;
}
