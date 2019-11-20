#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void initializeString(char newString[], int newStringLength)
{
  for (int i = 0; i < newStringLength; i++)
  {
    newString[i] = '\0';
  }
}

bool isNotEmpty(char verifiableString[])
{
  int sizeVerifiableString = strlen(verifiableString);
  for (int i = 0; i < sizeVerifiableString; i++)
  {
    char currentSymbol = verifiableString[i];
    if (!((currentSymbol == ' ') || (currentSymbol == '\n') || (currentSymbol == '\t')))
    {
      return true;
    }
  }
  return false;
}

int main()
{
  const int maxFileAdressLength = 100;
  char adress[maxFileAdressLength];
  initializeString(adress, maxFileAdressLength);

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

  int numberNotEmptyStringsInInputFile = 0;
  const int maxFileStringSize = 1000;
  char stringOfInputFile[maxFileStringSize];
  initializeString(stringOfInputFile, maxFileStringSize);

  while (fgets(stringOfInputFile, maxFileStringSize, inputFile) != NULL)
  {
	  if (isNotEmpty(stringOfInputFile))
    {
      numberNotEmptyStringsInInputFile++;
    }
  }

  printf("Number not empty strings in input file = %d\n", numberNotEmptyStringsInInputFile);

  fclose(inputFile);
  return 0;
}
