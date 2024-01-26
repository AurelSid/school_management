#define _CRT_SERCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void mainMenu();
void secondMenu();
void printSchoolDetails();
int clearInputBuffer();

// Clear the buffer

int clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return c;
}

// Defining 'Student' Struct

typedef struct student
{
    char name[20];
    unsigned int id;
    unsigned int grade;
} Student;

// Defining Course Struct

typedef struct course
{
    char name[20];
    double averageGrade;
    unsigned int totalStudents;
    Student *studentArray;
} Course;

// Defining 'School' Struct

typedef struct school
{
    char name[20];
    unsigned int totalCourses;
    Course *courseArray;

} School;

// Creating a new student

Student *createstudent()
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    printf("Enter Student Name:");
    scanf("%s", newStudent->name);
    printf("Enter Student ID:");
    scanf("%u", &(newStudent->id));
    printf("Enter Student grade:");
    scanf("%u", &(newStudent->grade));
    return newStudent;
}

// Creating new Course

Course *createCourse()
{
    Course *newCourse = (Course *)malloc(sizeof(Course));
    printf("Enter Course Name:");
    scanf("%s", newCourse->name);
    printf("Enter Number of Students: ");
    scanf("%u", &(newCourse->totalStudents));
    newCourse->studentArray = (Student *)malloc(sizeof(Student) * newCourse->totalStudents);

    for (int i = 0; i < newCourse->totalStudents; i++)
    {
        printf("Enter informations for student number #%d \n", i + 1);
        Student *newStudent = createstudent();
        newCourse->studentArray[i] = *newStudent;
        free(newStudent);
    }
    return newCourse;
}

// Creating a school
School *createSchool()
{

    School *newSchool = (School *)malloc(sizeof(School));
    printf("ENTER SCHOOL NAME: ");
    scanf("%s", newSchool->name);
    printf("Enter number of courses: ");
    scanf("%u", &(newSchool->totalCourses));
    newSchool->courseArray = (Course *)malloc(sizeof(Course) * newSchool->totalCourses);

    for (int i = 0; i < newSchool->totalCourses; i++)
    {
        printf("Enter infos about Course course number #%d \n", i + 1);
        Course *newCourse = createCourse();
        newSchool->courseArray[i] = *newCourse;
    }

    printf("SCHOOL ADDED select School details to see all the schools details.");
    secondMenu(newSchool);
    return newSchool;

    return NULL;
}
// Printing students details

void printStudentDetails(Student *student)
{
    printf("student name: %s\n", student->name);
    printf("StudentID: %u\n", student->id);
    printf("Student grade: %u\n", student->grade);
}

// Printing Course details

void printCourseDetails(Course *course)
{
    printf("\n----------  DETAILS FOR COURSE: %s  ---------- \n\n", course->name);
    printf("course Average : %2f\n", course->averageGrade);
    printf("Course total students: %u \n", course->totalStudents);

    for (int i = 0; i < course->totalStudents; i++)
    {
        printf("Details about student number %d \n", i + 1);
        printStudentDetails(&(course->studentArray[i]));
    }
}

void printSchoolDetails(School *school)
{
    char userInput = 'c';

    for (int i = 0; i < school->totalCourses; i++)
    {
        printCourseDetails(&(school->courseArray[i]));
    }

    printf("\n\nPress ENTER to go back to Menu");

    // Consume the newline character from the buffer
    while (getchar() != '\n')
        ;

    // Read the user input
    scanf("%c", &userInput);

    if (userInput == '\n')
    {
        secondMenu(school); // Pass the school argument to secondMenu
    }
}

// FIRST MENU ********************************************

void mainMenu()
{
    printf("\n\n******************* WELCOME TO EDUSERV *********************\n\n");

    printf("You do not manage any establishments at the moment\n\n");

    char userInput;
    printf("Press ENTER to add an Establishment\n");
    scanf("%c", &userInput);
    if (userInput == '\n')
    {
        School *mySchool = createSchool();
    }
}

// SECOND MENU ***********************************************

void secondMenu(School *myschool)
{
    int choice = 0;

    printf("\n******************** CHOOSE AN OPTION AND PRESS ENTER ******************** \n\n");

    printf("1. - Add new school\n");
    printf("2. - Print school details\n");
    printf("3. - Print course details\n");
    printf("4. - Print student details\n");
    printf("5. - Print student course\n");
    printf("6. - Print course with the highest average\n");
    printf("7. - Exit\n");

    scanf("%d", &choice);
    int index = 0;
    switch (choice)
    {
    case 1:

        printf("Enter infos about Course ");
        myschool->totalCourses = myschool->totalCourses + 1;
        myschool->courseArray = (Course *)realloc(myschool->courseArray, sizeof(Course) * myschool->totalCourses);
        index++;
        Course *newCourse = createCourse();
        myschool->courseArray[index] = *newCourse;

        while (getchar() != '\n')
            ;

        // Read the user input
        char userInput;
        scanf("%c", &userInput);

        if (userInput == '\n')
        {
            secondMenu(myschool); // Pass the school argument to secondMenu
        }

        break;

    case 2:
        printSchoolDetails(myschool);
        break;

    case 3:
        // Add functionality to print course details
        break;

    default:
        printf("Invalid choice\n");
    }
}

int main()
{

    mainMenu();
}