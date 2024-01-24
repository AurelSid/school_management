#define _CRT_SERCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void mainMenu();
void secondMenu();

// Defining 'Student' Struct

typedef struct student
{   char name[20];
    unsigned int id;
    unsigned int grade;
}Student;

//Defining Course Struct

typedef struct course
{   char name[20];
    double averageGrade;
    unsigned int totalStudents;
    Student* studentArray;
}Course;

// Defining 'School' Struct

typedef struct school
{   
    char name[20];
    unsigned int totalCourses;
    Course* courseArray;

    
}School;

//Creating a new student 

Student* createstudent()
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("Enter Student Name:");
    scanf("%s", newStudent->name);
    printf("Enter Student ID:");
    scanf("%u", &(newStudent->id));
      printf("Enter Student grade:");
    scanf("%u", &(newStudent->grade));
    return newStudent;
}

//Creating new Course

Course* createCourse()
{
    Course* newCourse = (Course*)malloc(sizeof(Course));
    printf("Enter Course Name:");
    scanf("%s", newCourse->name);
    printf("Enter Number of Students: ");
    scanf("%u", &(newCourse->totalStudents));
    newCourse->studentArray = (Student*)malloc(sizeof(Student) * newCourse->totalStudents);

    for(int i = 0 ; i < newCourse->totalStudents;i++)
    {
        printf("Enter informations for student number #%d \n",i+1);
        Student* newStudent = createstudent();
        newCourse->studentArray[i] = *newStudent;
        free(newStudent);
    }
    return newCourse;
}

//Creating a school

School* createSchool()
{
    char userInput;
    printf("Press ENTER to add an Establishment\n");
    scanf("%c",&userInput);
    if(userInput=='\n')
    {    
        School* newSchool =  (School*)malloc(sizeof(School));
        printf("ENTER SCHOOL NAME: ");
        scanf("%s", newSchool->name);
        printf("Enter number of courses: ");
        scanf("%u",&(newSchool->totalCourses));
        newSchool->courseArray=(Course*)malloc(sizeof(Course) * newSchool->totalCourses);

        for (int i=0 ; i < newSchool->totalCourses ; i++)
        {
            printf("Enter infos about Course course number #%d \n",i+1);
            Course* newCourse = createCourse();
            newSchool->courseArray[i] = *newCourse;
            free (newCourse);
        }
        return newSchool;
    }
}

//Printing students details

void printStudentDetails(Student* student)
{
    printf("student name: %s\n", student->name);
    printf("StudentID: %u\n", student->id);
    printf("Student grade: %u\n",student->grade);
    
}

//Printing Course details

void printCourseDetails(Course* course)
{
    printf("\n----------  DETAILS FOR COURSE: %s  ---------- \n\n", course->name);
    printf("course Average : %2f\n",course->averageGrade);
    printf("Course total students: %u \n",course->totalStudents);
    
    for(int i=0 ; i < course->totalStudents;i++)
    {
        printf("Details about student number %d \n",i+1);
        printStudentDetails(&(course->studentArray[i]));

    }

}

//Printing All Student's Courses

void printStudentCourses(School* School, int StudentID)
{
    printf("Student %d is enroled in the following courses: \n",StudentID);
    for(int i = 0 ; i < School->totalCourses;i++)
    {
        for(int j = 0; j<School->courseArray[i].totalStudents; j++)
        {
             if (School->courseArray[i].studentArray[j].id == StudentID)
            {
                printf("- %s \n",School-> courseArray[i].name);
                 break; //student found
            }
        }
    }
}

//Printin failing students

void printStudentsWhoFailed(Course* course, double cutOffGrade)
{
    printf("Students who failed the %s course: \n", course->name);
    for(int i=0; i < course->totalStudents; i++)
    {
        if(course->studentArray[i].grade < cutOffGrade)
        printStudentDetails(&(course->studentArray[i]));
    }
}

//printing student who passed the course

void printStudentsWhoPassed(Course* course, double cutOffGrade)
{
    printf("Students who passed the %s course: \n", course->name);
    for(int i=0; i < course->totalStudents; i++)
    {
        if(course->studentArray[i].grade >= cutOffGrade)
        printStudentDetails(&(course->studentArray[i]));
    }
}

// printing all courses with pass average grade 

void printCoursesWithPassAvgGrade(School* school, double cutOffGrade)
{
    printf("Courses With and average that passes : \n");
    for(int i=0; i < school->totalCourses;i++)
    {
        if(school->courseArray[i].averageGrade >= cutOffGrade)
        {
            printCourseDetails(&(school->courseArray[i]));
        }
    }
}

void printCoursesWithFailAvgGrade(School* school, double cutOffGrade)
{
    printf("Courses With and average that do not pass : \n");
    for(int i=0; i < school->totalCourses;i++)
    {
        if(school->courseArray[i].averageGrade < cutOffGrade)
        {
            printCourseDetails(&(school->courseArray[i]));
        }
    }
}

//printing average grade between all courses
void printAverageGradeAllCourses(School* school)
{
    
    double totalGrade=0;
    for (int i=0; i < school->totalCourses; i++)
    {
        totalGrade += (school->courseArray[i].averageGrade);
        
    }
    double average = totalGrade / school->totalCourses;

    printf("The total average grade for the %s School is: %2f \n ", school->name, average);
}

//printing course with highest average

void printCourseWithHighestAverage(School* school)
{
    
    double highestAvg = 0;

    Course* highestAvgCourse = NULL;

    for(int i=0; i < school->totalCourses; i++)
    {
        if(school->courseArray[i].averageGrade > highestAvg)
        {
            highestAvg = school->courseArray[i].averageGrade;
            highestAvgCourse = &(school->courseArray[i]);
        }
    }

    printf("The total average grade for the %s School is course : \n ", school->name);
    printCourseDetails(highestAvgCourse);
}

void printSchoolDetails(School* school)
{
    for(int i =0; i < school->totalCourses; i++)
    {
        printCourseDetails(&(school->courseArray[i]));
    }
}




//FIRST MENU ********************************************


void mainMenu()
{
     printf("\n\n******************* WELCOME TO EDUSERV *********************\n\n");

  
        printf("You do not manage any establishments at the moment\n\n");
        School* mySchool = createSchool();
        secondMenu(mySchool);
    
}


//SECOND MENU ***********************************************


void secondMenu(School *myschool)
{
    int choice=0;
    
    printf("\n******************** CHOOSE AN OPTION AN PRESS ENTER******************** \n\n");

    printf("\n 1. -Print school details \n");
    printf("\n 1. -Print course details \n");
    printf("\n 1. -Print student details \n");
    printf("\n 1. -Print student course \n");
    printf("\n 1. -Print course with highest average \n");
    printf("\n 1. -Print school details \n");

    scanf("%d",&choice);

    switch(choice)
    {
        case 1:printSchoolDetails(myschool);
        break;

       

    }


}

int main()
{   
  
    mainMenu();
}