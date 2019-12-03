#include <stdio.h>
#include <stdbool.h>
#include "list.h"

int main()
{
  List* list = createList();

  int sizeOflist = 0;

  printf("Сколько элементов в списке? : ");
  scanf("%d", &sizeOflist);

  int temporary = 0;
  printf("Введите элементы списка (после каждого числа нажимайте ENTER) :\n");
  for (int i = 0; i < sizeOflist; i++)
  {
    scanf("%d", &temporary);
    addValue(temporary, list);
  }

  insertionSort(list);
  printList(list);

  return 0;
}
