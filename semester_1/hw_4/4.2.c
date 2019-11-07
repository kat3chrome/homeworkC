#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void stringInitialization(char inputString[])
{
  int stringLength = strlen(inputString);

  for (int i = 0; i < stringLength; i++)
  {
    inputString[i] = '\0';
  }
}

bool existsFile(char fileAdress[100])
{
  FILE *file = fopen(fileAdress, "r");
  if (file != NULL)
  {
    fclose(file);
    return true;
  }

  return false;
}

char getRandomCharacter()
{
  srand(time(0));
  return (char)(rand() % 20 + 65);
}

char* concatenateTwoStrings(const char *string1, const char *string2)
{
  char *result = malloc(strlen(string1) + strlen(string2) + 1);
  strcpy(result, string1);
  strcat(result, string2);
  return result;
}

void getNameOfTemporaryFile(int lengthTemporaryFileAdress, char temporaryFileAdress[])
{
  char systemSting[] = ".temp";
  const int lengthSystemString = strlen(systemSting);

  lengthTemporaryFileAdress -= lengthSystemString;
  temporaryFileAdress[0] = getRandomCharacter();
  int index = 0;

  while (existsFile(concatenateTwoStrings(temporaryFileAdress,systemSting)))
  {
    index = (index + 1) % lengthTemporaryFileAdress;
    temporaryFileAdress[index] = getRandomCharacter();
  }

  temporaryFileAdress = strcat(temporaryFileAdress, systemSting);
}

void printCommands()
{
  char commands[] = "0 - exit\n1 - add an entry (name and phone number)\n2 - find phone by name\n3 - find the name by phone\n4 - save current data to file\n5 - print a list of commands";
  printf("List of commands :\n%s\n", commands);
}

void printGreetings()
{
  char title[] = "████████████████████████████████████████████████\n█────█─██─█────█─██─█───███────██────█────█─██─█\n█─██─█─██─█─██─█──█─█─█████─██──█─██─█─██─█─█─██\n█────█────█─██─█─█──█───███────██─██─█─██─█──███\n█─████─██─█─██─█─██─█─█████─██──█─██─█─██─█─█─██\n█─████─██─█────█─██─█───█─█────██────█────█─██─█\n████████████████████████████████████████████████";
  printf("%s\n", title);
  printf("! Thank you for choosing our software !\n");
}

void addContactToTemporayFile(char temporaryFileAdress[])
{
  char number[100];
  char name[100];
  stringInitialization(number);
  stringInitialization(name);

  printf("Enter name and phone : ");
  scanf("%s%s", name, number);

  while (strstr(name, "~") != NULL || strstr(number, "~") != NULL || strstr(name, "#") != NULL || strstr(number, "#") != NULL)
  {
    printf("¡Enter the correct data!\nDon't use \"~\" or \"#\",please\nEnter name and phone : ");
    scanf("%s%s", name, number);
  }

  FILE *temporaryFile = fopen(temporaryFileAdress, "a+");
  fprintf(temporaryFile, "%s#%s~", name, number);
  fclose(temporaryFile);
}

void saveTheCurrentDataToFile(char phoneBookAdress[], char temporaryFileAdress[])
{
  FILE *phoneBook = fopen(phoneBookAdress, "a+");
  FILE *temporaryFile = fopen(temporaryFileAdress, "a+");
  char temporaryCharaster;

  while ((temporaryCharaster = getc(temporaryFile)) != EOF)
  {
    fprintf(phoneBook, "%c", temporaryCharaster);
  }

  fclose(phoneBook);
  fclose(temporaryFile);
  remove(temporaryFileAdress);
}

bool findNameByNumberOrNumberByName(char phoneBookAdress[], char name[] ,char number[] ,int position)
{
  char temporaryCharaster;
  FILE *phoneBook = fopen(phoneBookAdress, "r");

  char temporaryNumber[100];
  char temporaryName[100];
  stringInitialization(temporaryNumber);
  stringInitialization(temporaryName);

  int index = 0;
  bool isName = true;
  bool foundSomething = false;
  while ((temporaryCharaster = getc(phoneBook)) != EOF)
  {
    if (isName && temporaryCharaster != '#')
    {
      temporaryName[index] = temporaryCharaster;
      index++;
    }
    else if (temporaryCharaster == '#')
    {
      index = 0;
      isName = false;
    }
    else if (!isName && temporaryCharaster != '~')
    {
      temporaryNumber[index] = temporaryCharaster;
      index++;
    }
    else if (temporaryCharaster == '~')
    {
      temporaryNumber[index] = '\0';
      index = 0;
      isName = true;
      if (strcmp(temporaryName, name) == 0 && position == 0)
      {
        foundSomething = true;
        break;
      }
      else if (strcmp(temporaryNumber, number) == 0 && position == 1)
      {
        foundSomething = true;
        break;
      }
      stringInitialization(temporaryName);
      stringInitialization(temporaryNumber);
    }
  }
  if (position == 0 && foundSomething)
  {
    strcpy(number, temporaryNumber);
    return foundSomething;
  }
  else if (position == 1 && foundSomething)
  {
    strcpy(name, temporaryName);
    return foundSomething;
  }
  else
  {
    return foundSomething;
  }
}

void findPhoneNumberByNameAndPrintResult(char phoneBookAdress[])
{
  char number[100];
  char name[100];
  stringInitialization(number);
  stringInitialization(name);

  printf("Enter enter the name to search : ");
  scanf("%s", name);

  bool foundSomething = findNameByNumberOrNumberByName(phoneBookAdress, name, number, 0);

  if (foundSomething)
  {
    printf("%s has this number %s\n", name, number);
  }
  else
  {
  printf("Sorry, there is no such contact in the phone book\n");
  }
}

void findNameByPhoneNumberAndPrintResult(char phoneBookAdress[])
{
  char number[100];
  char name[100];
  stringInitialization(number);
  stringInitialization(name);

  printf("Enter enter the number to search : ");
  scanf("%s", number);

  bool foundSomething = findNameByNumberOrNumberByName(phoneBookAdress, name, number, 1);

  if (foundSomething)
  {
    printf("%s has this number %s\n", name, number);
  }
  else
  {
  printf("Sorry, there is no such contact in the phone book\n");
  }
}

void commandProcessing(char phoneBookAdress[], char temporaryFileAdress[])
{
  int command = 0;
  printCommands();
  do
  {
    printf("Enter the command : \n");
    scanf("%d", &command);

    switch (command)
    {
      case 0:
        printf("Goodbye!\n");
        break;

      case 1:
        addContactToTemporayFile(temporaryFileAdress);
        break;

      case 2:
        findPhoneNumberByNameAndPrintResult(phoneBookAdress);
        break;

      case 3:
        findNameByPhoneNumberAndPrintResult(phoneBookAdress);
        break;

      case 4:
        saveTheCurrentDataToFile(phoneBookAdress, temporaryFileAdress);
        break;

      case 5:
        printf("\n");
        printCommands();
        printf("\n");
        break;

      default:
        printf("\nEnter the correct command!\n\n");
    }
  } while(command != 0);
}

int main()
{
  const int lengthTemporaryFileAdress = 10;
  char temporaryFileAdress[lengthTemporaryFileAdress];
  stringInitialization(temporaryFileAdress);
  getNameOfTemporaryFile(lengthTemporaryFileAdress, temporaryFileAdress);
  char phoneBookAdress[] = "PHONE.BOOK";

  printGreetings();
  FILE *phoneBook = fopen(phoneBookAdress, "a");
  FILE *temporaryFile = fopen(temporaryFileAdress, "w");
  fclose(phoneBook);
  fclose(temporaryFile);

  commandProcessing(phoneBookAdress, temporaryFileAdress);

  fclose(phoneBook);
  fclose(temporaryFile);
  remove(temporaryFileAdress);
  return 0;
}
