#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void stringInitialization(char inputString[])
{
  int stringLength = strlen(inputString);

  for (int i = 0; i < stringLength; i++)
  {
    inputString[i] = '\0';
  }
}

bool isNumber(char temporaryCharaster)
{
  return (temporaryCharaster - '0' >= 0 && temporaryCharaster - '9' <= 0) ? true : false;
}

bool isDot(char temporaryCharaster)
{
  return (temporaryCharaster == '.') ? true : false;
}

bool isSpace(char temporaryCharaster)
{
  return (temporaryCharaster == ' ') ? true : false;
}

int numberFromCharaster(char charaster)
{
  return (int)charaster - '0';
}

int stringDateToArray(int *dateInArray, char dateInString[])
{
  dateInArray[0] = dateInString[1] * 10 + dateInString[2];
  dateInArray[1] = dateInString[4] * 10 + dateInString[5];
  dateInArray[2] = dateInString[7] * 1000 + dateInString[8] * 100 + dateInString[9] * 10 + dateInString[10];
}

bool theFirstIsMoreThanTheSecond(int firstArray[], int secondArray[])
{
  if (firstArray[2] > secondArray[2])
  {
    return true;
  }

  else if (firstArray[2] == secondArray[2] && firstArray[1] > secondArray[1])
  {
    return true;
  }

  else if (firstArray[2] == secondArray[2] && firstArray[1] == secondArray[1] && firstArray[0] > firstArray[0])
  {
    return true;
  }

  return false;
}

void findMinumunDateAndPrintResult(char inputFileName[])
{
  char temporaryCharaster;
  FILE *inputFile = fopen(inputFileName, "r");

  int lengthOfDate = 12;
  char temporaryDate[lengthOfDate];
  stringInitialization(temporaryDate);

  bool isFirstDate = true;
  int minimumDate[3];
  int currentDate[3];
  for (int i = 0; i < 3; i++)
  {
    currentDate[i] = 0;
    minimumDate[i] = 0;
  }

  while ((temporaryCharaster = getc(inputFile)) != EOF)
  {
    int lengthOfTemporaryDate = strlen(temporaryDate);

    if (lengthOfTemporaryDate == lengthOfDate)
    {
      if (isFirstDate)
      {
        isFirstDate == false;
        stringDateToArray(currentDate, temporaryDate);
        stringInitialization(temporaryDate);
      }
      else if (!theFirstIsMoreThanTheSecond(currentDate, minimumDate))
      {
        minimumDate [2] = currentDate[2];
        minimumDate [1] = currentDate[1];
        minimumDate [0] = currentDate[1];
      }
    }

    else  if (!isNumber(temporaryCharaster) || !isDot(temporaryCharaster) || !isSpace(temporaryCharaster))
    {
      stringInitialization(temporaryDate);
      continue;
    }

    else if (isSpace(temporaryCharaster))
    {
      if (lengthOfTemporaryDate != 0 && lengthOfTemporaryDate != 11)
      {
        stringInitialization(temporaryDate);
      }
    }

    else if (isNumber(temporaryCharaster) || isDot(temporaryCharaster))
    {
      temporaryDate[lengthOfTemporaryDate] = temporaryCharaster;
    }
  }
  fclose(inputFile);
  printf("The minimum date is %d %d %d\n", minimumDate[0], minimumDate[1], minimumDate[2]);
}

int main()
{
  const int maxFileAdressLength = 100;
  char adress[maxFileAdressLength];
  stringInitialization(adress);

  printf("Enter adress of input file : ");
  scanf("%s", adress);

  FILE *inputFile;
  inputFile = fopen(adress, "r");
  while (inputFile  == NULL)
  {
    printf("Could not open the file, enter the correct address : ");
    scanf("%s", adress);
    inputFile = fopen(adress, "r");
  }
  fclose(inputFile);

  findMinumunDateAndPrintResult(adress);

  return 0;
}
