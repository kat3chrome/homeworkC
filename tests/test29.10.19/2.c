#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b)
{
    const int *arg1 = a;
    const int *arg2 = b;

    return *arg1 - *arg2;
}

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

  const int sizeArray = 26;
  int array[sizeArray];
  for (int i = 0; i < sizeArray; i++)
  {
    array[i] = 0;
  }

  while (fgets(stringOfInputFile, maxFileStringSize, inputFile) != NULL)
  {
    int sizeVerifiableString = strlen(stringOfInputFile);
    for (int i = 0; i < sizeVerifiableString; i++)
    {
      char currentSymbol = stringOfInputFile[i];
      int numberChar = currentSymbol - 'a';
      if (numberChar < 26 && numberChar >= 0)
      {
        array[numberChar]++;
      }
    }
  }

  fclose(inputFile);

  const int maxFileAdressLengthOut = 100;
  char adressOut[maxFileAdressLengthOut];
  initializeString(adressOut, maxFileAdressLengthOut);

  printf("Enter adress of output file : ");
  scanf("%s", adressOut);

  FILE *outputFile;
  outputFile = fopen(adressOut, "w");

  qsort(array, sizeArray, sizeof(int), compare_ints);

  for (int i = 0; i < sizeArray; i++)
  {
    if (array[i] != 0)
    {
      fprintf(outputFile, "%c: %d\n", i + 'a', array[i]);
    }
  }
  
  fclose(outputFile);

  return 0;
}
