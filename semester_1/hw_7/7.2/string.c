#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "string.h"

struct String
{
  int length;
  char* text;
};

String* createString()
{
  String* newString = calloc(1, sizeof(String));
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
  return (getLength(string) == 0);
}

char* stringToCharasters(String* string)
{
  return string->text;
}

String* getSubstring(String* string, int begin, int end)
{
  int lengthOfSubstring = end - begin;
  String* substring = createString();
  resizeString(substring, lengthOfSubstring);

  for (int i = 0; i < lengthOfSubstring; i++)
  {
    substring->text[i] = string->text[i + begin];
  }

  return substring;
}

void addCharasterToString(char* charasters, String* string)
{
  int currentSize = string->length;
  int index = 0;

  while (true)
  {
    if (charasters[index] == '\0')
    {
      return;
    }
    currentSize++;
    resizeString(string, currentSize);
    string->text[currentSize - 1] = charasters[index];
    index++;

  }
}

void printString(String* string)
{
  for (int i = 0; i < string->length; i++)
  {
    if (string->text[i] == '\0')
    {
      return;
    }
    printf("%c", string->text[i]);
  }
}
