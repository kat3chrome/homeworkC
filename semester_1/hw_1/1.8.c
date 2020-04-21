#include <stdio.h>

int recursiveFactorial(int variable)
{
  if (variable == 1)
  {
    return 1;
  }
  return variable * recursiveFactorial(variable - 1);
}

int iterativeFactorial(int variable)
{
  int value = 1;
  for (int i = 1; i <= variable; i++)
  {
    value *= i;
  }
  return value;
}

int main()
{
  int variable = 0;
  printf("%s", "Enter variable: ");
  scanf("%d", &variable);
  printf("Recursive factorial = %d\nIterative factorial = %d \n", recursiveFactorial(variable), iterativeFactorial(variable));
  return 0;
}
