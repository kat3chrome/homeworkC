#include <stdio.h>
#include <stdlib.h>

void arraySort(int *unsortedArray, int arraySize)
{
    for (int i = 1; i < arraySize - 2; i += 2)
    {
        for (int j = i + 2; j < arraySize; j += 2)
        {
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

    printf("Array with sorted elements by even indexes: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", inputArray[i]);
    }
    printf("\n");

    free(inputArray);
    
    return 0;
}