/*A C Program to input and store the data of a certain number of students and print the details as a table
Program Features:
1. Program will store the data of an unlimited number of students and asks user to stop or proceed storing data after each student entry
2. Makes use of structures and functions in order to organize the program and the data
3. First asks the user to input the name of the school/university/educational institution
4. Then asks the user the Grade and section of the class of the students whose data is to be stored
5. Next inputs and stores student details, which are: Name, Gender,  Roll number and Blood group
6. Includes an option for the user to terminate and print the entry of the student data when necessary*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure for student details
struct Student
{
  char name[50];
  char gender;
  int rollNumber;
  char bloodGroup[5];
};

// Function to input student details
void inputStudentDetails(struct Student *student)
{
  printf("Enter name: ");
  scanf("%s", student->name);
  printf("Enter gender (M/F): ");
  scanf(" %c", &student->gender);
  printf("Enter roll number: ");
  scanf("%d", &student->rollNumber);
  printf("Enter blood group: ");
  scanf("%s", student->bloodGroup);
}

// Function to print student details
void printStudentDetails(struct Student student)
{
  printf("| %-20s | %-6c | %-11d | %-5s |\n", student.name, student.gender, student.rollNumber, student.bloodGroup);
}

int main()
{
  char institutionName[100];
  printf("Enter the name of the institution: ");
  scanf("%s", institutionName);

  char grade[5];
  char section;
  printf("Enter grade: ");
  scanf("%s", grade);
  printf("Enter section: ");
  scanf(" %c", &section);

  struct Student students[MAX_STUDENTS];
  int numStudents = 0;
  char choice;

  // Do-While loop Input student details
  do
  {
    printf("\nEnter details for student %d:\n", numStudents + 1);
    inputStudentDetails(&students[numStudents]);
    numStudents++;

    printf("\nDo you want to add another student? (Y/N): ");
    scanf(" %c", &choice);
  } while (choice == 'Y' || choice == 'y');

  // Printing student details as a table
  printf("\n\nInstitution: %s\n", institutionName);
  printf("Grade: %s\n", grade);
  printf("Section: %c\n\n", section);
  printf("Student Details:\n");
  printf("| %-20s | %-6s | %-11s | %-5s |\n", "Name", "Gender", "Roll Number", "Blood Group");
  printf("|----------------------|--------|-------------|----------|\n");
  for (int i = 0; i < numStudents; i++)
  {
    printStudentDetails(students[i]);
  }

  return 0;
}