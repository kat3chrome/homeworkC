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
  return (char)(rand()%20+ 65);
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
  char commands[] = "0 - exit\n1 - add an entry (name and phone number)\n2 - find phone by name\n3 - find the name on the phone\n4 - save current data to file\n5 - print a list of commands";
  printf("List of commands :\n%s\n", commands);
}

void printGreetings()
{
  char title[] = "████████████████████████████████████████████████\n█────█─██─█────█─██─█───███────██────█────█─██─█\n█─██─█─██─█─██─█──█─█─█████─██──█─██─█─██─█─█─██\n█────█────█─██─█─█──█───███────██─██─█─██─█──███\n█─████─██─█─██─█─██─█─█████─██──█─██─█─██─█─█─██\n█─████─██─█────█─██─█───█─█────██────█────█─██─█\n████████████████████████████████████████████████";
  printf("%s\n", title);
  printf("! Thank you for choosing our software !\n");
}

void createPhoneBookFileOrDoNothing()
{
  char nameOfPhoneBook[] = "PHONE.BOOK";
  FILE *phoneBook;
  if (existsFile(nameOfPhoneBook))
  {
    phoneBook = fopen(nameOfPhoneBook, "r");
    fclose(phoneBook);
    return;
  }

  phoneBook = fopen(nameOfPhoneBook, "w");
  fclose(phoneBook);
}

void addContactToTemporayFile(FILE *temporaryFile)
{
  char number[100];
  char name[100];
  stringInitialization(number);
  stringInitialization(name);

  printf("Enter name and phone : ");
  scanf("%s%s", name, number);
  fprintf(temporaryFile, "`%s:%s`", name, number);
}

saveTheCurrentDatatoFile(FILE *phoneBook, FILE *temporaryFile)
{

}

void commandProcessing(FILE *phoneBook, FILE *temporaryFile)
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
        addContactToTemporayFile(temporaryFile);
        break;

      case 2:
        break;

      case 3:
        break;

      case 4:
        saveTheCurrentDatatoFile(phoneBook, temporaryFile);
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
  // const int lengthTemporaryFileAdress = 10;
  // char temporaryFileAdress[lengthTemporaryFileAdress];
  // stringInitialization(temporaryFileAdress);
  // getNameOfTemporaryFile(lengthTemporaryFileAdress, temporaryFileAdress);
  char temporaryFileAdress[7] = "T.temp";
  createPhoneBookFileOrDoNothing();

  printGreetings();

  FILE *phoneBook;
  phoneBook = fopen(temporaryFileAdress, "r");
  FILE *temporaryFile;
  temporaryFile = fopen(temporaryFileAdress, "w");

  commandProcessing(phoneBook, temporaryFile);

  fclose(phoneBook);
  fclose(temporaryFile);
  return 0;
}
