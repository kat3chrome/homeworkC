#include "phoneBook.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Entry Entry;
typedef struct PhoneBook PhoneBook;

const int maxSize = 128;
char* phoneBookFileName = "phoneBook";

struct Entry
{
  char* name;
  char* number;
};

struct PhoneBook
{
  int numberOfEntries;
  Entry* entries;
};

Entry* createEntry(char* name, char* number)
{
  Entry* entry = malloc(sizeof(Entry));

  entry->name = calloc(maxSize, sizeof(char));
  entry->number = calloc(maxSize, sizeof(char));

  strcpy(entry->name, name);
  strcpy(entry->number, number);

  return entry;
}

PhoneBook* createPhoneBook()
{
  PhoneBook* phoneBook = calloc(1, sizeof(PhoneBook));

  phoneBook->entries = malloc(sizeof(Entry));
  phoneBook->numberOfEntries = 0;

  return phoneBook;
}

void printCommands()
{
  char* commands =
  "0 - exit\n"
  "1 - add an entry (phone number and name)\n"
  "2 - find phone by name\n"
  "3 - find the name by phone\n"
  "4 - save current data to file\n"
  "5 - print a list of commands\n";

  printf("List of commands :\n%s\n", commands);
}

void printGreetings()
{
  char* title =
  "████████████████████████████████████████████████\n"
  "█────█─██─█────█─██─█───███────██────█────█─██─█\n"
  "█─██─█─██─█─██─█──█─█─█████─██──█─██─█─██─█─█─██\n"
  "█────█────█─██─█─█──█───███────██─██─█─██─█──███\n"
  "█─████─██─█─██─█─██─█─█████─██──█─██─█─██─█─█─██\n"
  "█─████─██─█────█─██─█───█─█────██────█────█─██─█\n"
  "████████████████████████████████████████████████";

  printf("%s\n", title);
  printf("! Thank you for choosing our software !\n");
}

void addEntry(PhoneBook* phoneBook, char* name, char* number)
{
  Entry* temporayEntry = createEntry(name, number);
  phoneBook->numberOfEntries++;
  phoneBook->entries = realloc(phoneBook->entries, phoneBook->numberOfEntries * sizeof(Entry));
  phoneBook->entries[phoneBook->numberOfEntries - 1] = *temporayEntry;
  free(temporayEntry);
}

void printEntry(Entry entry)
{
  printf("%s %s\n", entry.name, entry.number);
}

void printPhoneBook(PhoneBook* phoneBook)
{
  for (int i = 0; i < phoneBook->numberOfEntries; i++)
  {
    printEntry(phoneBook->entries[i]);
  }
}

PhoneBook* getPhoneBook()
{
  PhoneBook* phoneBook = createPhoneBook();

  FILE* phoneBookFile = fopen(phoneBookFileName, "r");

  if (phoneBookFile == NULL)
  {
    return phoneBook;
  }

  while (feof(phoneBookFile) == false)
  {
    char* temporayName = calloc(maxSize, sizeof(char));
    char* temporayNumber = calloc(maxSize, sizeof(char));
    fscanf(phoneBookFile, "%s %[^\n]", temporayNumber, temporayName);
    if (strlen(temporayNumber) == 0)
    {
      continue;
    }

    addEntry(phoneBook, temporayName, temporayNumber);
    free(temporayName);
    free(temporayNumber);
  }

  fclose(phoneBookFile);
  return phoneBook;
}

void findPhoneByNameAndPrintThem(PhoneBook* phoneBook, char* name)
{
  for (int i = 0; i < phoneBook->numberOfEntries; i++)
  {
    if (strcmp(phoneBook->entries[i].name, name) == 0)
    {
      printf("%s\n", phoneBook->entries[i].number);
      return;
    }
  }
  printf("[-]\n");
}

void findNameByPhoneAndPrintThem(PhoneBook* phoneBook, char* number)
{
  for (int i = 0; i < phoneBook->numberOfEntries; i++)
  {
    if (strcmp(phoneBook->entries[i].number, number) == 0)
    {
      printf("%s\n", phoneBook->entries[i].name);
      return;
    }
  }
  printf("[-]\n");
}

void saveDate(PhoneBook* phoneBook)
{
  FILE* phoneBookFile = fopen(phoneBookFileName, "w");
  for (int i = 0; i < phoneBook->numberOfEntries; i++)
  {
    fputs("\n", phoneBookFile);
    fputs(phoneBook->entries[i].number, phoneBookFile);
    fputs(" ", phoneBookFile);
    fputs(phoneBook->entries[i].name, phoneBookFile);
  }

  fclose(phoneBookFile);
}

void deletePhoneBook(PhoneBook* phoneBook)
{
  for (int i = 0; i < phoneBook->numberOfEntries; i++)
  {
    free(phoneBook->entries[i].name);
    free(phoneBook->entries[i].number);
  }
  free(phoneBook->entries);
  free(phoneBook);
}

void commandProcessing(PhoneBook* phoneBook)
{
  int command = 0;
  printCommands();
  do
  {
    printf("Enter the command: \n");
    scanf("%d", &command);

    switch (command)
    {
      case 0:
      {
        printf("Goodbye!\n");
        deletePhoneBook(phoneBook);
        break;
      }
      case 1:
      {
        printf("Enter number and name: ");
        char* temporayName = calloc(maxSize, sizeof(char));
        char* temporayNumber = calloc(maxSize, sizeof(char));
        scanf("%s %[^\n]", temporayNumber, temporayName);
        addEntry(phoneBook, temporayName, temporayNumber);

        free(temporayName);
        free(temporayNumber);
        break;
      }
      case 2:
      {
        char* temporayName = calloc(maxSize, sizeof(char));
        printf("Enter the name: ");
        scanf("%s", temporayName);
        findPhoneByNameAndPrintThem(phoneBook, temporayName);

        free(temporayName);
        break;
      }
      case 3:
      {
        char* temporayNumber = calloc(maxSize, sizeof(char));
        printf("Enter the number: ");
        scanf("%s", temporayNumber);
        findNameByPhoneAndPrintThem(phoneBook, temporayNumber);

        free(temporayNumber);
        break;
      }
      case 4:
      {
        saveDate(phoneBook);
        break;
      }
      case 5:
      {
        printf("\n");
        printCommands();
        printf("\n");
        break;
      }
      default:
      {
        printf("\nEnter the correct command!\n\n");
      }
    }
  } while(command != 0);
}
