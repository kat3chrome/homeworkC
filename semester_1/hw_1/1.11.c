#include <stdio.h>
#include <stdlib.h>


void swap(int *relocatable1, int *relocatable2)
{
    int temp = *relocatable1;
    *relocatable1 = *relocatable2;
    *relocatable2 = temp;
}

int quickSort(int array[], int leftExtremeIndex, int rightExtremeIndex)
{
    if (leftExtremeIndex >= rightExtremeIndex)
    {
        return 0;
    }

    int referenceElement = array[(leftExtremeIndex + rightExtremeIndex) / 2];
    int leftIndex = leftExtremeIndex;
    int rightIndex = rightExtremeIndex;

    do
    {
        while (array[leftIndex] < referenceElement)
        {
            leftIndex++;
        }

        while (array[rightIndex] > referenceElement)
        {
            rightIndex--;
        }

        if (leftIndex <= rightIndex)
        {
            swap(&array[leftIndex], &array[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
    }
    while (leftIndex <= rightIndex);

    quickSort(array, leftExtremeIndex, rightIndex);
    quickSort(array, leftIndex, rightExtremeIndex);
}

int main()
{
    const int maximumArraySize = 100;
    int array[maximumArraySize];
    for (int i = 0; i < maximumArraySize; i++)
    {
        array[i] = 0;
    }

    int arraySize = 0;
    printf("Enter size of array : ");
    scanf("%d", &arraySize);

    while ((arraySize <= 0) && (arraySize > 100))
    {
      printf("Enter correct size of array ([1:100]) : ");
      scanf("%d", &arraySize);
    }

    printf("Enter elements of array : ");
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, arraySize - 1);

    printf("Sorted array : ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
