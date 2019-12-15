#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "string.h"

struct String
{
  int length;
  char* text;
};

void addCharasterToString(char charaster, String* string)
{
  resizeString(string, string->length + 1);
  string->text[string->length - 1] = charaster;
}


String* createString(char* charasters)
{
  String* newString = malloc(sizeof(String));
  newString->length = 0;
  newString->text = calloc(sizeof(char), 1);

  int index = 0;
  while (true)
  {
    if (charasters[index] == '\0')
    {
      return;
    }
    
  }
  return newString;
}

void deleteString(String* string)
{
  free(string->text);
  free(string);
}

String* cloneString(String* string)
{
  int lengthOfFirstString = string->length;
  String* newString = createString(lengthOfFirstString);
  newString->length = lengthOfFirstString;

  for (int i = 0; i < lengthOfFirstString; i++)
  {
    newString->text[i] = string->text[i];
  }

  return newString;
}

void resizeString(String* string, int newLength)
{
  string->text = realloc(string->text, newLength);
  int lastLength = string->length;
  string->length = newLength;

  for (int i = lastLength; i < newLength; i++)
  {
    string->text[i] = '\0';
  }
}

void concatenationOfStrings(String* firstString, String* secondString)
{
  int firstLength = firstString->length;
  int secondLength = secondString->length;
  int newLength = firstLength + secondLength;

  resizeString(firstString, newLength);
  for (int i = 0; i < secondLength; i++)
  {
    firstString->text[firstLength + i] = secondString->text[i];
  }
}

bool isEqualStrings(String* firstString, String* secondString)
{
  if (firstString->length != secondString->length)
  {
    return false;
  }

  int length = firstString->length;
  for (int i = 0; i < length; i++)
  {
    if (firstString->text[i] != secondString->text[i])
    {
      return false;
    }
  }

  return true;
}

int getLength(String* string)
{
  return string->length;
}

bool isEmpty(String* string)
{
  if (getLength(string) == 0)
  {
    return true;
  }

  return true;
}

char* stringToCharasters(String* string)
{
  return string->text;
}
