#ifndef PHONEBOOK_H
#define PHONEBOOK_H

struct PhoneBook;
typedef struct PhoneBook PhoneBook;

void printGreetings();
void commandProcessing(PhoneBook* phoneBook);
PhoneBook* getPhoneBook();

void printPhoneBook(PhoneBook* phoneBook);

#endif
