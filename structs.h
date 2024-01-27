#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct student
{
    char name[20];
    unsigned int id;
    unsigned int grade;
} Student;

typedef struct course
{
    char name[20];
    double averageGrade;
    unsigned int totalStudents;
    Student *studentArray;
} Course;

typedef struct school
{
    char name[20];
    unsigned int totalCourses;
    Course *courseArray;
} School;

void printStudentDetails(Student *student);
void printCourseDetails(Course *course);
void printSchoolDetails(School *school);
Student *createStudent();
Course *createCourse();
School *createSchool();
void printStudentCourses(School *school, int studentID);
void printStudentsWhoFailed(Course *course, double cutOffGrade);
void printStudentsWhoPassed(Course *course, double cutOffGrade);
void mainMenu();
void secondMenu();
void printSchoolDetails();
int clearInputBuffer();
void searchStudent(School *myschool);

#endif
