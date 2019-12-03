#include <stdio.h>
#include <stdbool.h>
#include "set.h"

int main()
{
  Set* set = createSet();

  addElement(5, set);
  addElement(2, set);
  addElement(10, set);
  addElement(11, set);

  printSet(set);
  printf("\n%d\n", isInTheSet(11, set));
  removeElement(10, set);
  printSet(set);
  printf("\n%d\n", isInTheSet(11, set));

  return 0;
}
