#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stdio.h>

typedef struct String String;

struct String;

String* createString(int size);
void deleteString(String* string);
int getLength(String* string);
char* convertStringToCharPointer(String* string);
String* convertCharsToString(char* string);
bool isStringEmpty(String* string);
bool areEqualStrings(String* stringA, String* stringB);
String* cloneString(String* string);
void printString(String* string);

#endif