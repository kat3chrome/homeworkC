#include "string.h"
#include <stdio.h>

int main()
{
  String* newString = createString();
  addCharasterToString("test", newString);
  printf("%d\n", getLength(newString));
  addCharasterToString("TEST", newString);
  printf("%d\n", getLength(newString));
  printString(newString);
  printf("\n");

  String* substring = getSubstring(newString, 1 , 5);
  printString(substring);
  printf("\n");

  deleteString(substring);
  deleteString(newString);
  return 0;
}
