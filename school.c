#define _CRT_SERCURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void mainMenu();
void secondMenu();
void printSchoolDetails();
int clearInputBuffer();

//Clear the buffer

int clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return c;
}


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
    scanf("%c", &userInput);
    if (userInput == '\n')
    {
        School* newSchool = (School*)malloc(sizeof(School));
        printf("ENTER SCHOOL NAME: ");
        scanf("%s", newSchool->name);
        printf("Enter number of courses: ");
        scanf("%u", &(newSchool->totalCourses));
        newSchool->courseArray = (Course*)malloc(sizeof(Course) * newSchool->totalCourses);

        for (int i = 0; i < newSchool->totalCourses; i++)
        {
            printf("Enter infos about Course course number #%d \n", i + 1);
            Course* newCourse = createCourse();
            newSchool->courseArray[i] = *newCourse;
        }

        printf("SCHOOL ADDED select School details to see all the schools details.");
        secondMenu(newSchool);
        return newSchool;
    }
    return NULL; 
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



void printSchoolDetails(School* school)
{
    char userInput = 'c';

    for(int i = 0; i < school->totalCourses; i++)
    {
        printCourseDetails(&(school->courseArray[i]));
    }

    printf("Press ENTER to go back to Menu");

    // Consume the newline character from the buffer
    while (getchar() != '\n');

    // Read the user input
    scanf("%c", &userInput);

    if(userInput == '\n')
    {
        secondMenu(school);  // Pass the school argument to secondMenu
    }
}


//FIRST MENU ********************************************


void mainMenu()
{
     printf("\n\n******************* WELCOME TO EDUSERV *********************\n\n");

  
        printf("You do not manage any establishments at the moment\n\n");
        School* mySchool = createSchool();
       
    
}


//SECOND MENU ***********************************************

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

        //clearInputBuffer();

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                myschool = createSchool();
                break;

            case 2:
                printSchoolDetails(myschool);
                break;

            case 3:
                // Add functionality to print course details
                break;

            case 4:
                // Add functionality to print student details
                break;

            case 5:
                // Add functionality to print student course
                break;

            case 6:
                // Add functionality to print course with the highest average
                break;

            case 7:
                return;  // Exit the function

            default:
                printf("Invalid choice\n");
        
        }
}




int main()
{   
  
    mainMenu();
}