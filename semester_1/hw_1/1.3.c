#include <stdio.h>

void arrayReverse(int array[], int beginArray, int sizeArray)
{
  int halfSizeArray = sizeArray / 2;
  for (int i = 0; i < halfSizeArray; i++)
  {
    int temp = array[beginArray + i];
    array[beginArray + i] = array[sizeArray + beginArray - i - 1];
    array[beginArray + sizeArray - i - 1] = temp;
  }
}

int main(){

  const int sizeArray = 100;
  int array[sizeArray];
  for (int i = 0; i < sizeArray; i++)\
  {
      array[i] = 0;
  }

  int sizeM = 0;
  int sizeN = 0;

  printf("Enter the lengths of the segments: ");
  scanf("%d%d", &sizeM, &sizeN);

  int realSizeArray = sizeM + sizeN;

  while (sizeArray < sizeM + sizeN)
  {
    printf("Enter the correct lengths of the segments: ");
    scanf("%d%d", &sizeM, &sizeN);
  }

  printf("%s", "Enter the array: ");
  for (int i = 0; i < realSizeArray; i++)
  {
    scanf("%d", &array[i]);
  }

  arrayReverse(array, 0, sizeM);
  arrayReverse(array, sizeM, sizeN);
  arrayReverse(array, 0, realSizeArray);

  printf("%s", "Modified array: ");
  for (int i = 0; i < realSizeArray; i++)
  {
    printf("%d ", array[i]);
  }
  return 0;
}
