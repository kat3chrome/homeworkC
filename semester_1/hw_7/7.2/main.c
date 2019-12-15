#include "string.h"

int main()
{
  String* newString = createString(10);

  String* secondString = cloneString(newString);

  
  deleteString(newString);
  deleteString(secondString);

  return 0;
}
