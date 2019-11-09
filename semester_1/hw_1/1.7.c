#include <stdio.h>
#include <stdbool.h>

int main()
{
  const int realArraySize = 100000;
  bool isPrime[realArraySize];

  for (int i = 0; i < realArraySize; i++)
  {
    isPrime[i] = true;
  }

  int value = 0;
  printf("%s", "Enter value: ");
  scanf("%d", &value);

  for (int i = 2; i * i <= value; i++)
  {
    if (isPrime[i])
    {
      for (int j = i * i; j <= value; j += i)
      {
        isPrime[j] = false;
      }
    }
  }

  printf("%s\n", "All the Prime numbers up to a given: ");
  for (int i = 2; i <= value; i++)
  {
    if (isPrime[i])
    {
      printf("%d ", i);
    }
  }

  return 0;
}
