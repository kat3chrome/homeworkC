#include <stdio.h>

void arrayReverse(int array[], int startArray, int endArray)
{
  int halfSizeArray = endArray / 2;
  for (int i = 0; i < halfSizeArray; i++)
  {
    int temp = array[startArray + i];
    array[startArray + i] = array[endArray + startArray - i - 1];
    array[startArray + endArray - i - 1] = temp;
  }
}

int main()
{
  const int sizeArray = 100;
  int array[sizeArray];
  for (int i = 0; i < sizeArray; i++)
  {
      array[i] = 0;
  }

  int sizeM = 0;
  int sizeN = 0;
  int realSizeOfArray = 0;

  do
  {
    printf("Enter the lengths of the segments: ");
    scanf("%d%d", &sizeM, &sizeN);
  } while(sizeArray < sizeM + sizeN);

  printf("%s", "Enter the array: ");
  for (int i = 0; i < realSizeOfArray; i++)
  {
    scanf("%d", &array[i]);
  }

  arrayReverse(array, 0, sizeM);
  arrayReverse(array, sizeM, sizeN);
  arrayReverse(array, 0, realSizeOfArray);

  printf("%s", "Modified array: ");
  for (int i = 0; i < realSizeOfArray; i++)
  {
    printf("%d ", array[i]);
  }
  return 0;
}
