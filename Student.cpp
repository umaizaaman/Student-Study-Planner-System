#include "Student.h"
#include "CustomException.h"

/*
==========================================
Class : Student

This class manages:
- Student Profile
- User Account
- Courses
- Assignments
- Exams
- Study Planner
- Progress Tracker
- Reminders
==========================================
*/

Student::Student()
{
    progressTracker.setStudyPlanner(studyPlanner);

}

Student::Student(string studentName,
                 string studentID,
                 string department,
                 int semester)
{
    setStudentName(studentName);
    setStudentID(studentID);
    setDepartment(department);
    setSemester(semester);

    progressTracker.setStudyPlanner(studyPlanner);
}

//==========================================
// Setter Functions
//==========================================

void Student::setStudentName(string studentName)
{
    if (studentName.empty())
    {
        throw InvalidStudentNameException();
    }

    this->studentName = studentName;
}

void Student::setStudentID(string studentID)
{
    if (studentID.empty())
    {
        throw InvalidStudentIDException();
    }

    this->studentID = studentID;
}

void Student::setDepartment(string department)
{
    if (department.empty())
    {
        throw InvalidDepartmentException();
    }

    this->department = department;
}

void Student::setSemester(int semester)
{
    if (semester < 1 || semester > 8)
    {
        throw InvalidSemesterException();
    }

    this->semester = semester;
}

void Student::setUserAccount(const UserAccount& account)
{
    this->account = account;
}

//==========================================
// Getter Functions
//==========================================

string Student::getStudentName() const
{
    return studentName;
}

string Student::getStudentID() const
{
    return studentID;
}

string Student::getDepartment() const
{
    return department;
}

int Student::getSemester() const
{
    return semester;
}

const UserAccount& Student::getUserAccount() const
{
    return account;
}

StudyPlanner& Student::getStudyPlanner()
{
    return studyPlanner;
}

ProgressTracker& Student::getProgressTracker()
{
    return progressTracker;
}

const StudyPlanner& Student::getStudyPlanner() const
{
    return studyPlanner;
}

const ProgressTracker& Student::getProgressTracker() const
{
    return progressTracker;
}

//==========================================
// Read-Only Collection Getters
//==========================================

const vector<Course>& Student::getCourses() const
{
    return courses;
}

const vector<Assignment>& Student::getAssignments() const
{
    return assignments;
}

const vector<Exam>& Student::getExams() const
{
    return exams;
}

const vector<Reminder>& Student::getReminders() const
{
    return reminders;
}
//==========================================
// Management Functions
//==========================================

void Student::addCourse(const Course& course)
{
    courses.push_back(course);
}

void Student::addAssignment(const Assignment& assignment)
{
    assignments.push_back(assignment);
}

void Student::addExam(const Exam& exam)
{
    exams.push_back(exam);
}

void Student::addReminder(const Reminder& reminder)
{
    reminders.push_back(reminder);
}
//==========================================
// Remove Functions
//==========================================

void Student::removeCourse(string courseCode)
{
    for (auto it = courses.begin(); it != courses.end(); it++)
    {
        if (it->getCourseCode() == courseCode)
        {
            courses.erase(it);
            cout << "Course removed successfully." << endl;
            return;
        }
    }

    cout << "Course not found." << endl;
}

void Student::removeAssignment(string assignmentName)
{
    for (auto it = assignments.begin(); it != assignments.end(); it++)
    {
        if (it->getAssignmentName() == assignmentName)
        {
            assignments.erase(it);
            cout << "Assignment removed successfully." << endl;
            return;
        }
    }

    cout << "Assignment not found." << endl;
}

void Student::removeExam(string examType)
{
    for (auto it = exams.begin(); it != exams.end(); it++)
    {
        if (it->getExamType() == examType)
        {
            exams.erase(it);
            cout << "Exam removed successfully." << endl;
            return;
        }
    }

    cout << "Exam not found." << endl;
}

void Student::removeReminder(string reminderMessage)
{
    for (auto it = reminders.begin(); it != reminders.end(); it++)
    {
        if (it->getReminderMessage() == reminderMessage)
        {
            reminders.erase(it);
            cout << "Reminder removed successfully." << endl;
            return;
        }
    }

    cout << "Reminder not found." << endl;
}
//==========================================
// Display Function
//==========================================

void Student::displayStudent() const
{
    cout << "\n========================================================\n";
    cout << "                 STUDENT PROFILE\n";
    cout << "========================================================\n";

    cout << "Student Name : " << studentName << endl;
    cout << "Student ID   : " << studentID << endl;
    cout << "Department   : " << department << endl;
    cout << "Semester     : " << semester << endl;
}

void Student::displayCompleteStudentRecord() const
{
    displayStudent();

     cout << endl;
     studyPlanner.displayStudyPlanner();

     cout << endl;

    progressTracker.displayProgress();

    cout << "\n========================================================\n";
    cout << "                    COURSES\n";
    cout << "========================================================\n\n";

int count = 1;

for (const Course& course : courses)
{
    course.displayCourse(count);
    count++;
}
cout << "\n========================================================\n";
cout << "                  ASSIGNMENTS\n";
cout << "========================================================\n\n";

int assignmentCount = 1;

for (const Assignment& assignment : assignments)
{
    assignment.displayAssignment(assignmentCount);
    assignmentCount++;
}
cout << "\n========================================================\n";
cout << "                     EXAMS\n";
cout << "========================================================\n\n";

int examCount = 1;

for (const Exam& exam : exams)
{
    exam.displayExam(examCount);
    examCount++;
}
cout << "\n========================================================\n";
cout << "                   REMINDERS\n";
cout << "========================================================\n\n";

int reminderCount = 1;

for (const Reminder& reminder : reminders)
{
    reminder.displayReminder(reminderCount);
    reminderCount++;
}
}

//==========================================
// Destructor
//==========================================

Student::~Student()
{

}