#include "phoneBook.h"

int main()
{
  printGreetings();

  PhoneBook* phoneBook = getPhoneBook();
  commandProcessing(phoneBook);

  return 0;
}
