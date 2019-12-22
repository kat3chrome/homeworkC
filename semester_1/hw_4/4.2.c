#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "phoneBook.h"

int main()
{
  printGreetings();

  PhoneBook* phoneBook = getPhoneBook();

  commandProcessing(phoneBook);

  return 0;
}
