#include <stdio.h>
#include <stdlib.h>

void shellSort(int* unsortedArray, int arraySize)
{
    for (int gap = arraySize / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < arraySize; i++)
        {
            for (int j = i - gap; j >= 0 && unsortedArray[j] > unsortedArray[j + gap]; j -= gap)
            {
                int temporary = unsortedArray[j];
                unsortedArray[j] = unsortedArray[j + gap];
                unsortedArray[j + gap] = temporary;
            }
        }
    }
}

int main()
{
    int arraySize = 0;
    printf("Enter size of array: ");
    scanf("%d", &arraySize);

    int *inputArray = calloc(arraySize, sizeof(int));

    printf("Enter elements of array: ");
    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &inputArray[i]);
    }

    shellSort(inputArray, arraySize);

    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", inputArray[i]);
    }
    printf("\n");

    return 0;
}
