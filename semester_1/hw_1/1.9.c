#include <stdio.h>

long long binaryPower(int basis, int power)
{
  if (power == 0)
  {
    return 1;
  }

  if (power % 2 == 0)
  {
    long long result = binaryPower(basis, power / 2);
    return result * result;
  }

  return binaryPower(basis, power - 1) * basis;
}

int main()
{
  int basis = 0;
  int power = 0;

  printf("%s", "Enter basis(a) and power(n) : ");
  scanf("%d%d", &basis, &power);

  printf("a^n = %lld", binaryPower(basis, power));

  return 0;
}
