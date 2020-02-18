#include <stdio.h>
#include <stdbool.h>
#include "list.h"

int main()
{
  List* list = createList();
  int command = 0;
  char* commandList =
  "0 - exit\n"
  "1 - add element by index\n"
  "2 - remove element by index\n"
  "3 - print list\n";
  printf("%s", commandList);

  while (true)
  {
    printf("Enter the command: ");
    scanf("%d", &command);
    switch (command)
    {
      case 0:
      {
        removeList(list);
        return 0;
      }
      case 1:
      {
        printf("Enter value and index: ");
        int value = 0;
        int index = 0;
        scanf("%d %d", &value, &index);
        addElementByIndex(list, value, index);
        break;
      }
      case 2:
      {
        printf("Enter index: ");
        int value = 0;
        int index = 0;
        scanf("%d", &index);
        removeElementByIndex(list, index);
        break;
      }
      case 3:
      {
        printList(list);
        break;
      }
    }
  }
  return 0;
}
