#include <stdio.h>
#include <stdlib.h>

void arraySort(int *unsortedArray, int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        for (int j = i + 1; j < arraySize; j++)
        {
            if (j % 2 == 0)
            {
                continue;
            }

            if (unsortedArray[i] > unsortedArray[j])
            {
                int temporary = unsortedArray[i];
                unsortedArray[i] = unsortedArray[j];
                unsortedArray[j] = temporary;
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

    arraySort(inputArray, arraySize);

    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", inputArray[i]);
    }
    printf("\n");

    return 0;
}