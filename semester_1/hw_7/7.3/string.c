#include <stdlib.h>
#include "string.h"

struct String
{
  int length;
  char* text;
};

String* createString(int size)
{
    String* string = calloc(1, sizeof(String));
    string->text = calloc(size + 1, sizeof(char));
    string->length = 0;
    return string;
}

void deleteString(String* string)
{
    if (string != NULL)
    {
        if (string->text != NULL)
        {
            free(string->text);
        }
        free(string);
    }
}

int getLength(String *string)
{
    if (string == NULL)
    {
        return 0;
    }

    return string->length;
}

char* convertStringToCharPointer(String* string)
{
    if (string == NULL)
    {
        return NULL;
    }

    return string->text;
}

void stringCopy(char* distance, char* source, int numberOfCharacters)
{
    for (int i = 0; i < numberOfCharacters; i++)
    {
        distance[i] = source[i];
    }
}

String* convertCharsToString(char* characters)
{
    if (characters == NULL)
    {
        return 0;
    }
    
    int charactersLength = 0;
    for (charactersLength; characters[charactersLength] != '\00'; charactersLength++);
    String* newString = createString(charactersLength);
    stringCopy(newString->text, characters, charactersLength + 1);
    newString->length = charactersLength;

    return newString;
}

bool isStringEmpty(String* string)
{
    return getLength(string) == 0;
}

bool areEqualStrings(String* firstString, String* secondString)
{
    if (firstString == NULL || secondString == NULL)
    {
        return false;
    }

    if (getLength(firstString) != getLength(secondString))
    {
        return false;
    }

    for (int i = 0; i < getLength(firstString); i++)
    {
        if (firstString->text[i] != secondString->text[i])
        {
            return false;
        }
    }
    return true;
}

String* cloneString(String* string)
{
    if (string == NULL)
    {
        return NULL;
    }

    String* copyOfString = createString(getLength(string));
    copyOfString->length = getLength(string);
    stringCopy(copyOfString->text, string->text, copyOfString->length);

    return copyOfString;
}

void printString(String* string)
{
    if (string == NULL)
    {
        return;
    }

    printf("%s", string->text);
}