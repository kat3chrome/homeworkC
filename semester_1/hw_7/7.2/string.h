#ifndef STRING_H
#define STRING_H

#include <stdbool.h>

struct String;
typedef struct String String;

String* createString(int length);
void deleteString(String* string);
String* cloneString(String* string);
void concatenationOfStrings(String* firstString, String* secondString);
bool isEqualStrings(String* firstString, String* secondString);
int getLength(String* string);
bool isEmpty(String* string);
char* stringToCharasters(String* string);

#endif
