#include <stdio.h>

unsigned int getFibonacciNumber(int number)
{
  unsigned int fibonacciNumberFirst = 1;
  unsigned int fibonacciNumberSecond = 0;

  for (int i = 0; i < number; i++)
  {
    fibonacciNumberFirst += fibonacciNumberSecond;
    fibonacciNumberSecond = fibonacciNumberFirst - fibonacciNumberSecond;
  }

  return fibonacciNumberSecond;
}

int main()
{
  int number = 0;
  printf("Enter the number of Fibonacci numbers : ");
  scanf("%d", &number);

  printf("The Fibonacci number with this number is %d\n", getFibonacciNumber(number));
  return 0;
}
