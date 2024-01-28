#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mainMenu()
{
    printf("\n\n******************* WELCOME TO EDUSERV *********************\n\n");

    printf("You do not manage any establishments at the moment\n\n");

    School *mySchool = createSchool();
}

// SECOND MENU ***********************************************

void secondMenu(School *myschool)
{
    int choice = 0;

    printf("\n\n\n******************** CHOOSE AN OPTION AND PRESS ENTER ******************** \n\n");

    printf("1. - Add new course\n");
    printf("2. - Search students details\n");
    printf("3. - Search course details\n");
    printf("7. - Exit\n");

    scanf("%d", &choice);
    int index = 0;
    char userInput;
    switch (choice)
    {
    case 1:
        printf("Enter infos about Course ");
        myschool->totalCourses = myschool->totalCourses + 1;
        myschool->courseArray = (Course *)realloc(myschool->courseArray, sizeof(Course) * myschool->totalCourses);

        index++;
        char courseName[20];
        char studentName[20];
        Course *newCourse = createCourse();

        myschool->courseArray[index] = *newCourse;

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        printf("Press Enter to continue...");
        while (getchar() != '\n')
            ;

        secondMenu(myschool);
        break;

    case 2:
        printf("Please enter a Student name and press enter:");
        char *studentNamePointer = studentName;
        scanf("%19s", studentNamePointer);
        searchStudent(myschool, studentNamePointer);
        break;

    case 3:

        printf("Please enter a Course name and press enter:");
        scanf("%19s", courseName);
        char *courseNamePointer = courseName;
        searchCourse(myschool, courseNamePointer);
        break;
    case 4:

        printf("\n\nPlease enter the name of the Course to ass the student to:");
        scanf("%19s", courseName);
        addStudentToCourse(myschool, courseName);
        printf("Student Added successfully");
        secondMenu(myschool);
        break;

    default:
        printf("Invalid choice\n");
    }
    while (getchar() != '\n')
        ;
}