#ifndef STRING_H
#define STRING_H

#include <stdbool.h>

struct String;
typedef struct String String;

String* createString();
void deleteString(String* string);
String* cloneString(String* string);
void concatenationOfStrings(String* firstString, String* secondString);
bool isEqualStrings(String* firstString, String* secondString);
int getLength(String* string);
bool isEmpty(String* string);
char* stringToCharasters(String* string);
String* getSubstring(String* string, int begin, int end);
void addCharasterToString(char* charasters, String* string);
void printString(String* string);

#endif
