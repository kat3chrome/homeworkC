#include <stdio.h>
#include <stdbool.h>

struct cellPhoneBase
{
  char* name;
  int number;
};

void initializeString(char newString[], int newStringLength)
{
  for (int i = 0; i < newStringLength; i++)
  {
    newString[i] = '\0';
  }
}

int main()
{
  const int maxFileAdressLength = 100;
  char adress[maxFileAdressLength];
  initializeString(adress, maxFileAdressLength);

  printf("Enter adress of phone number base file : ");
  scanf("%s", adress);

  FILE *inputFile;
  inputFile = fopen(adress, "r");
  if (inputFile  != NULL)
  {
    //Считать из файла построчно
  }

  struct cellPhoneBase phoneBase[1];

  printf("List numbers of commands\n0-exit\n1 - add an entry (name and phone number)\n2-find phone by name\n3-find the name on the phone\n4-save current data to a file.\n");

  while (true)
  {
    int command = 0;
    printf("Enter number of command");
    scanf("%d", &command);

    if (command = 0)
    {
      break;
    }

    struct cellPhoneBase temp = {'temp', 0000};
    switch (command)
    {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
    }
  }


  return 0;
}
