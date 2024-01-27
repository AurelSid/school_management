#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStudentDetails(Student *student)
{
    printf("student name: %s\n", student->name);
    printf("StudentID: %u\n", student->id);
    printf("Student grade: %u\n", student->grade);
}

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

    while (getchar() != '\n')
        ;

    scanf("%c", &userInput);

    if (userInput == '\n')
    {
        secondMenu(school);
    }
}

Student *createStudent()
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
        Student *newStudent = createStudent();
        newCourse->studentArray[i] = *newStudent;
        free(newStudent);
    }
    return newCourse;
}

School *createSchool()
{
    char userInput;
    printf("Press ENTER to add an Establishment\n");
    scanf("%c", &userInput);
    if (userInput == '\n')
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
        // Assuming secondMenu is declared somewhere
        secondMenu(newSchool);
        return newSchool;
    }
    return NULL;
}

void printStudentCourses(School *school, int studentID)
{
    printf("Student %d is enroled in the following courses: \n", studentID);
    for (int i = 0; i < school->totalCourses; i++)
    {
        for (int j = 0; j < school->courseArray[i].totalStudents; j++)
        {
            if (school->courseArray[i].studentArray[j].id == studentID)
            {
                printf("- %s \n", school->courseArray[i].name);
                break;
            }
        }
    }
}

void printStudentsWhoFailed(Course *course, double cutOffGrade)
{
    printf("Students who failed the %s course: \n", course->name);
    for (int i = 0; i < course->totalStudents; i++)
    {
        if (course->studentArray[i].grade < cutOffGrade)
            printStudentDetails(&(course->studentArray[i]));
    }
}

void printStudentsWhoPassed(Course *course, double cutOffGrade)
{
    printf("Students who passed the %s course: \n", course->name);
    for (int i = 0; i < course->totalStudents; i++)
    {
        if (course->studentArray[i].grade >= cutOffGrade)
            printStudentDetails(&(course->studentArray[i]));
    }
}

void searchStudent(School *myschool)
{
    while (getchar() != '\n')
        ;

    char studentName[20];
    printf("Please enter a student's name and press enter: ");
    scanf("%19s", studentName);

    int studentFound = 0;
    while (getchar() != '\n')

        for (unsigned int i = 0; i < myschool->totalCourses; i++)
        {
            for (unsigned int j = 0; j < myschool->courseArray[i].totalStudents; j++)
            {
                if (strcmp(myschool->courseArray[i].studentArray[j].name, studentName) == 0)
                {
                    printf("Student Found:\n");
                    printf("School: %s\n", myschool->name);
                    printf("Course: %s\n", myschool->courseArray[i].name);
                    printf("Student Name: %s\n", studentName);
                    printf("Student ID: %u\n", myschool->courseArray[i].studentArray[j].id);
                    printf("Student Grade: %u\n", myschool->courseArray[i].studentArray[j].grade);
                    studentFound = 1;
                    break;
                }
            }
        }

    if (!studentFound)
    {
        printf("Student with name '%s' not found.\n", studentName);
    }

    while (getchar() != '\n')
        ;
}

int searchCourse(School *myschool, char *courseName)
{
    while (getchar() != '\n')
        ;

    int courseFound = 0;
    while (getchar() != '\n')
        ;

    for (unsigned int i = 0; i < myschool->totalCourses; i++)
    {

        if (strcmp(myschool->courseArray[i].name, courseName) == 0)
        {
            printf("Course found:\n");
            printf("School: %s\n", myschool->name);
            printf("Number of students: %d\n", myschool->courseArray[i].totalStudents);
            printf("Course: %s\n", myschool->courseArray[i].name);
            printf("Course: %s\n", myschool->courseArray[i].name);
            courseFound = 1;
            return i;
            break;
        }
    }

    if (!courseFound)
    {
        printf("COURSE with name: '%s' not found.\n", courseName);
    }

    while (getchar() != '\n')
        ;
}

void addStudentToCourse(School *myschool, Course *mycourse)
{
    // REPLACE INDEWX WITH FOUND COURSE
    int courseIndex = myschool->totalCourses - 1; //
    int studentIndex = myschool->courseArray[courseIndex].totalStudents;

    printf("Enter infos about new student ");
    Student *newStudent = createStudent();
    myschool->courseArray[courseIndex].totalStudents++;
    myschool->courseArray[courseIndex].studentArray =
        (Student *)realloc(myschool->courseArray[courseIndex].studentArray,
                           sizeof(Student) * myschool->courseArray[courseIndex].totalStudents);

    if (myschool->courseArray[courseIndex].studentArray == NULL)
    {

        printf("Memory reallocation failed.\n");
        free(newStudent);
        return;
    }

    myschool->courseArray[courseIndex].studentArray[studentIndex] = *newStudent;

    free(newStudent);
}