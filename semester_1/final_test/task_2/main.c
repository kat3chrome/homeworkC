#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *matrix[], int marixSize)
{
    for (int i = 0; i < marixSize - 1; i++)
        for (int j = 0; j < marixSize - i - 1; j++)
        {
            if (matrix[j][0] > matrix[j + 1][0])
            {
                for (int k = 0; k < marixSize; k++)
                {
                    int temporary = matrix[j][k];
                    matrix[j][k] = matrix[j + 1][k];
                    matrix[j + 1][k] = temporary;
                }
            }
        }
}

int main(int argc, char const *argv[])
{
    int sizeOfMatrix = 0;
    printf("Enter size of matrix: ");
    scanf("%d", &sizeOfMatrix);

    int* matrix[sizeOfMatrix];
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        matrix[i] = malloc(sizeof(int) * sizeOfMatrix);
    }

    printf("Enter matrix line by line\n");
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    bubbleSort(matrix, sizeOfMatrix);

    printf("Sorted matrix line by line\n");
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
