#include <stdio.h>
#include <stdlib.h>

void scanArrayOfStudentsAndTheirTestNumber(int *students, int number)
{
  int numberOfStudent = 0;
  int numberOfTest = 0;

  for (int i = 0; i < number; i++)
  {
    scanf("%d %d", &numberOfStudent, &numberOfTest);
    students[numberOfStudent - 1] = numberOfTest - 1;
  }
}

void getStudentTestNumber(int *students, int number)
{

  for (int i = 0; i < number; i++)
  {
    while (students[i] > 2)
    {
      students[i] = students[students[i]];
    }
  }
}

int main()
{
  int number = 0;
  printf("Enter number of students: ");
  scanf("%d", &number);

  int *students = malloc(sizeof(int) * number);

  scanArrayOfStudentsAndTheirTestNumber(students, number);
  getStudentTestNumber(students, number);

  printf("List of pairs of numbers, where the first number is the student's number, the second — number of test\n");
  for (int i = 0; i < number; i++)
  {
    printf("%d %d\n", i + 1, students[i] + 1);
  }
  free(students);

  return 0;
}
