#include <stdio.h>

int main()
{
  const int numberAmount = 28;
  int numberOfLuckyTickets = 0;
  int amounts[numberAmount];

  for (int i = 0; i < numberAmount; i++)
  {
    amounts[i] = 0;
  }

  for (int a = 0; a < 10; a++)
  {
    for (int b = 0; b < 10; b++)
    {
      for (int c = 0; c < 10; c++)
      {
        amounts[a + b + c]++;
      }
    }
  }

  for (int i = 0; i < numberAmount; i++)
  {
      numberOfLuckyTickets += amounts[i] * amounts[i];
  }

  printf("%s", "Number of lucky tickets = ");
  printf("%d\n", numberOfLuckyTickets);
  return 0;
}
