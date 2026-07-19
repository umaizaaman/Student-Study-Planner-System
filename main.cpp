#include <iostream>

#include "UserAccount.h"
#include "Course.h"
#include "Assignment.h"
#include "Exam.h"
#include "StudyPlanner.h"
#include "Reminder.h"
#include "ProgressTracker.h"
#include "Student.h"
#include "FileManager.h"

using namespace std;

void showDashboard(Student& student);

int main()
{
    try
    {
        //==========================================
        // Welcome Screen
        //==========================================

        cout << "========================================================\n";
        cout << "          STUDENT STUDY PLANNER SYSTEM\n";
        cout << "========================================================\n\n";

        //==========================================
        // Main Menu
        //==========================================

        cout << "1. Create New Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n\n";

        int choice;

        cout << "Enter your choice : ";
        cin >> choice;

      

//==========================================
// Process User Choice
//==========================================

switch (choice)
{
case 1:
{
    //==========================================
    // Create New Account
    //==========================================

    UserAccount account;
    Student student;

    account.registerUser();

    //==========================================
// Student Information
//==========================================

string studentName;
string studentID;
string department;
int semester;

cin.ignore();

cout << "\nEnter Student Name : ";
getline(cin, studentName);

cout << "Enter Student ID : ";
getline(cin, studentID);

cout << "Enter Department : ";
getline(cin, department);

cout << "Enter Semester : ";
cin >> semester;

student.setStudentName(studentName);
student.setStudentID(studentID);
student.setDepartment(department);
student.setSemester(semester);
student.setUserAccount(account);

cout << "\nStudent Profile Created Successfully!\n";

showDashboard(student);

break;
}
    

case 2:
{
    //==========================================
    // Login
    //==========================================

    Student student;
    FileManager fileManager;

    try
    {
        fileManager.loadStudent(student);
    }
    catch (...)
    {
        cout << "\nNo Saved Account Found!\n";
        break;
    }

    string username;
    string password;

    cin.ignore();

    cout << "\n========== LOGIN ==========\n";

    cout << "Enter Username : ";
    getline(cin, username);

    cout << "Enter Password : ";
    getline(cin, password);

    if (username == student.getUserAccount().getUsername() &&
        password == student.getUserAccount().getPassword())
    {
        cout << "\nLogin Successful!\n";

          showDashboard(student);
    }
    else
    {
        cout << "\nInvalid Username or Password!\n";
    }

    break;
}

case 3:

    cout << "\nThank you for using Student Study Planner.\n";
    break;

default:

    cout << "\nInvalid Choice!\n";
}

    }
    catch (const exception& e)
    {
        cout << "\nException: " << e.what() << endl;
    }

    return 0;
}

void showDashboard(Student& student)
{
bool logout = false;

while (!logout)
{
    //==========================================
    // Dashboard
    //==========================================

    cout << "\n========================================================\n";
    cout << "                    DASHBOARD\n";
    cout << "========================================================\n\n";

   cout << "1. Add Course\n";
   cout << "2. Add Assignment\n";
   cout << "3. Add Exam\n";
   cout << "4. Add Reminder\n";
   cout << "5. Update Study Planner\n";
   cout << "6. Update Progress Tracker\n";
   cout << "7. View Complete Record\n";
   cout << "8. Save Data\n";
    cout << "9. Logout\n";

    int dashboardChoice;

    cout << "Enter your choice : ";
    cin >> dashboardChoice;

    switch (dashboardChoice)
    {
    case 1:
    
{
    //==========================================
    // Add Course
    //==========================================

    Course course;

    string courseName;
    string courseCode;
    int creditHours;

    cin.ignore();

    cout << "\n========== ADD COURSE ==========\n";

    cout << "Enter Course Name : ";
    getline(cin, courseName);

    cout << "Enter Course Code : ";
    getline(cin, courseCode);

    cout << "Enter Credit Hours : ";
    cin >> creditHours;

    course.setCourseName(courseName);
    course.setCourseCode(courseCode);
    course.setCreditHours(creditHours);

    student.addCourse(course);

    cout << "\nCourse Added Successfully!\n";

    break;
}
    

    case 2:

{
    //==========================================
    // Add Assignment
    //==========================================

    Assignment assignment;
    Course course;

    string assignmentName;
    string courseName;
    string issueDate;
    string dueDate;

    cin.ignore();

    cout << "\n========== ADD ASSIGNMENT ==========\n";

    cout << "Enter Assignment Name : ";
    getline(cin, assignmentName);

    cout << "Enter Course Name : ";
    getline(cin, courseName);

    cout << "Enter Issue Date (DD-MM-YYYY) : ";
    getline(cin, issueDate);

    cout << "Enter Due Date (DD-MM-YYYY) : ";
    getline(cin, dueDate);

    course.setCourseName(courseName);

    assignment.setAssignmentName(assignmentName);
    assignment.setCourse(course);
    assignment.setIssueDate(issueDate);
    assignment.setDueDate(dueDate);
    assignment.setStatus(false);

    student.addAssignment(assignment);

    cout << "\nAssignment Added Successfully!\n";

    break;
}

    case 3:

{
    //==========================================
    // Add Exam
    //==========================================

    Exam exam;
    Course course;

    string courseName;
    string examType;
    string examDate;

    cin.ignore();

    cout << "\n========== ADD EXAM ==========\n";

    cout << "Enter Course Name : ";
    getline(cin, courseName);

   cout << "Enter Exam Type (Quiz/Mid/Final/Lab Test) : ";
    getline(cin, examType);

    cout << "Enter Exam Date (DD-MM-YYYY) : ";
    getline(cin, examDate);

    course.setCourseName(courseName);

    exam.setCourse(course);
    exam.setExamType(examType);
    exam.setExamDate(examDate);

    student.addExam(exam);

    cout << "\nExam Added Successfully!\n";

    break;
}

    case 4:

{
    //==========================================
    // Add Reminder
    //==========================================

    Reminder reminder;

    string reminderMessage;
    string reminderDate;

    cin.ignore();

    cout << "\n========== ADD REMINDER ==========\n";

    cout << "Enter Reminder Message : ";
    getline(cin, reminderMessage);

    cout << "Enter Reminder Date (DD-MM-YYYY) : ";
    getline(cin, reminderDate);

    reminder.setReminderMessage(reminderMessage);
    reminder.setReminderDate(reminderDate);

    student.addReminder(reminder);

    cout << "\nReminder Added Successfully!\n";

    break;
}
       
    case 5:
{
    //==========================================
    // Update Study Planner
    //==========================================

    int studyHours;
    int dailyTarget;

    cout << "\n========== UPDATE STUDY PLANNER ==========\n";

    cout << "Enter Study Hours : ";
    cin >> studyHours;

    cout << "Enter Daily Target : ";
    cin >> dailyTarget;

    student.getStudyPlanner().setStudyHours(studyHours);
    student.getStudyPlanner().setDailyTarget(dailyTarget);

    cout << "\nStudy Planner Updated Successfully!\n";

    break;
}

   case 6:
{
    int progressChoice;

    cout << "\n========== UPDATE PROGRESS TRACKER ==========\n\n";

    cout << "1. Add Completed Task\n";
    cout << "2. Add Pending Task\n";
    cout << "3. Back to Dashboard\n\n";

    cout << "Enter your choice : ";
    cin >> progressChoice;

    switch (progressChoice)
    {
    case 1:
{
    string task;

    cin.ignore();

    cout << "\nEnter Completed Task : ";
    getline(cin, task);

    student.getProgressTracker().addCompletedTask(task);

    cout << "\nCompleted Task Added Successfully!\n";

    break;
}

    case 2:
{
    string task;

    cin.ignore();

    cout << "\nEnter Pending Task : ";
    getline(cin, task);

    student.getProgressTracker().addPendingTask(task);

    cout << "\nPending Task Added Successfully!\n";

    break;
}

    case 3:

        cout << "\nReturning to Dashboard...\n";
        break;

    default:

        cout << "\nInvalid Choice!\n";
    }

    break;
}
case 7:
{
    student.displayCompleteStudentRecord();
    break;
}

case 8:
{
    FileManager fileManager;

    fileManager.saveStudent(student);

    cout << "\nData Saved Successfully!\n";

    break;
}
case 9:
{
    cout << "\nLogging Out...\n";
    logout = true;
    break;
}
    default:

        cout << "\nInvalid Choice!\n";
    }
}
}