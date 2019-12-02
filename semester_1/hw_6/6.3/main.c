#include <stdio.h>
#include "set.h"
typedef struct Set Set;

int main()
{

  Set* set = createSet();
  addElement(1, set);
  print(set);
  return 0;
}
