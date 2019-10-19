#include <stdio.h>

int main()
{
  int numberOfUsers = 0;
  int requiredNumberOfActions = 0;
  int timePeriod = 0;

  printf("Enter number of users, required number of actions and time period : ");
  scanf("%d%d%d", &numberOfUsers, &requiredNumberOfActions, &timePeriod);

  int numberOfCorrectUser = 0;
  for (int i = 0; i < numberOfUsers; i++)
  {
    int numberOfActions = 0;
    printf("Enter number of actions : ");
    scanf("%d", &numberOfActions);

    int numberOfActionsInTheDesiredTimePeriod = 0;
    for (int j = 0; j < numberOfActions; j++)
    {
      int actionTime = 0;
      scanf("%d", &actionTime);

      if (actionTime <= timePeriod)
      {
        numberOfActionsInTheDesiredTimePeriod++;
      }
    }

    if (numberOfActionsInTheDesiredTimePeriod == requiredNumberOfActions)
    {
      numberOfCorrectUser++;
    }
  }

  printf("Number of users who meet our terms and conditions = %d", numberOfCorrectUser);

  return 0;
}
