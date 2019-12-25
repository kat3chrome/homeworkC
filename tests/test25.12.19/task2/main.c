#include <stdio.h>
#include <stdbool.h>
#include "list.h"

int main()
{
  List* list = createList();
  int command = 0;
  char* commandList =
  "0 - exit\n"
  "1 - fill the list with random values (Enter size, low value and top value)\n"
  "2 - reverse list\n"
  "3 - print list\n";
  printf("%s", commandList);

  while (true)
  {
    printf("Enter the command: \n");
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
        printf("Enter size, low value and top value: ");
        int size = 0;
        int low = 0;
        int top = 0;
        scanf("%d %d %d", &size, &low, &top);
        if (size <= 0 || low > top)
        {
          printf("Enter correct values!\n");
          break;
        }
        removeList(list);
        list = makeList(size, low, top);
        break;
      }
      case 2:
      {
        reverseList(list);
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
