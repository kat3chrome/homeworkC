#include <stdio.h>
#include <stdlib.h>

int swap(int *array, int i, int j)
{
    int temporary = array[i];
    array[i] = array[j];
    array[j] = temporary;
}

void arraySort(int *unsortedArray, int arraySize)
{
    for (int i = 1; i < arraySize; i++)
    {
        int j = i;
        int currentElement = unsortedArray[i];
        while (j > 0 && unsortedArray[j - 1] > currentElement)
        {
            swap(unsortedArray, j, j - 1);
            j--;
        }
        unsortedArray[j] = currentElement;
    }
}

int getNumberOfEvenElements(int *array, int arraySize)
{
    int counter = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] % 2 == 0)
        {
            counter++;
        }
    }

    return counter;
}

void arraySortOnlyEvenValues(int *array, int arraySize)
{
    int numberOfEvenElements = getNumberOfEvenElements(array, arraySize);
    int *arrayOfEvenElements = calloc(numberOfEvenElements, sizeof(int));

    int indexOfArrayOfEvenElements = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] % 2 == 0)
        {
            arrayOfEvenElements[indexOfArrayOfEvenElements] = array[i];
            indexOfArrayOfEvenElements++;
        }
    }

    arraySort(arrayOfEvenElements, numberOfEvenElements);

    indexOfArrayOfEvenElements = 0;
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] % 2 == 0)
        {
            array[i] = arrayOfEvenElements[indexOfArrayOfEvenElements];
            indexOfArrayOfEvenElements++;
        }
    }

    free(arrayOfEvenElements);
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

    arraySortOnlyEvenValues(inputArray, arraySize);

    printf("Array with sorted elements by even indexes: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", inputArray[i]);
    }
    printf("\n");

    free(inputArray);

    return 0;
}