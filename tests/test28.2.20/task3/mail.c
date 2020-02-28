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

void printComment(char verifiableString[])
{
    int sizeVerifiableString = strlen(verifiableString);
    bool wasStartOfComment = false;
    for (int i = 0; i < sizeVerifiableString; i++)
    {
        char currentSymbol = verifiableString[i];
        if (currentSymbol == '\n')
        {
            printf("\n");
            return;
        }
        else if (currentSymbol == ';')
        {
            printf("%c", currentSymbol);
            wasStartOfComment = true;
        }
        else if (wasStartOfComment)
        {
            printf("%c", currentSymbol);
        }
    }
    printf("\n");
    return;
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
    while (inputFile == NULL)
    {
        printf("Could not open the file, enter the correct address : ");
        scanf("%s", adress);
        inputFile = fopen(adress, "r");
    }

    const int maxFileStringSize = 1000;
    char stringOfInputFile[maxFileStringSize];
    initializeString(stringOfInputFile, maxFileStringSize);

    while (fgets(stringOfInputFile, maxFileStringSize, inputFile) != NULL)
    {
        printComment(stringOfInputFile);
    }

    fclose(inputFile);
    return 0;
}
