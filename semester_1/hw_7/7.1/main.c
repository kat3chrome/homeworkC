#include <stdio.h>
#include "set.h"

int main()
{
  Set* set = createSet();

  printf("1 - add integer values to the set\n"
  "2 - delete values\n"
  "3 - check if the value belongs to a set\n"
  "4 - print the current elements of the set in ascending order\n"
  "5 - print the current elements of the set in descending order\n"
  "6 - print the current elements of the set in the format (a b c),"
  " where a is the value in the node, and b and c are similar representations of the subtrees of the right and left child\n"
  "7 - exit\n");

  while (true)
  {
    int command = 0;
    printf("Enter number of command: ");
    scanf("%d", &command);
    switch (command)
    {
      case 1:
      {
        int value = 0;
        printf("Enter value: ");
        scanf("%d", &value);
        addElement(value, set);
        break;
      }
      case 2:
      {
        int value = 0;
        printf("Enter value: ");
        scanf("%d", &value);
        removeElement(value, set);
        break;
      }
      case 3:
      {
        int value = 0;
        printf("Enter value: ");
        scanf("%d", &value);
        if (isInTheSet(value, set))
        {
          printf("There are in the set\n");
        }
        else
        {
          printf("There are not in the set\n");
        }
        break;
      }
      case 4:
      {
        printf("Elements of the set in ascending order: ");
        printInAscendingOrder(set);
        printf("\n");
        break;
      }
      case 5:
      {
        printf("Elements of the set in descending order: ");
        printInDescendingOrder(set);
        printf("\n");
        break;
      }
      case 6:
      {
        printf("Set: ");
        printSet(set);
        printf("\n");
        break;
      }
      case 7:
      {
        removeSet(set);
        return 0;
        break;
      }
      default:
      continue;
    }
  }

  return 0;
}
