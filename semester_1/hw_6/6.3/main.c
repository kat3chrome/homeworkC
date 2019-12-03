#include <stdio.h>
#include <stdbool.h>
#include "set.h"

int main()
{
  Set* set = createSet();

  addElement(5, set);
  addElement(10, set);
  addElement(7, set);
  addElement(11, set);
  addElement(50, set);
  addElement(9, set);

  int value = 10;
  printSet(set);
  printf("\n%d\n", isInTheSet(value, set));
  removeElement(value, set);
  printSet(set);
  // printf("\n%d\n", isInTheSet(value, set));

  return 0;
}
