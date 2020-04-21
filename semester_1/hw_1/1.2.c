#include <stdio.h>

int main()
{
    int divisor = 0;
    int dividend = 0;
    int quotient = 0;

    printf("Enter the divisor(a) and the dividend(b): ");
    scanf("%d%d", &divisor, &dividend);

    while (divisor >= dividend)
    {
        divisor -= dividend;
        quotient++;
    }

    printf("quotient = %d \n", quotient);

    return 0;
}
