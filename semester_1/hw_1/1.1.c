#include <stdio.h>

int main()
{
    float variable = 0;
    printf("Enter a variable (x) to calculate  x^4 + x^3 + x^2 + x + 1 : ");
    scanf("%f", &variable);
    float squaredVariable = variable * variable;
    float result = ((squaredVariable + variable) * (squaredVariable + 1) + 1);
    printf("x4 + x3 + x2 + x + 1 = %f \n", result);
    return 0;
}
