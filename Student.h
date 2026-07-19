#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

#include "UserAccount.h"
#include "Course.h"
#include "Assignment.h"
#include "Exam.h"
#include "StudyPlanner.h"
#include "ProgressTracker.h"
#include "Reminder.h"

using namespace std;

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

class Student
{
private:
    string studentName;
    string studentID;
    string department;
    int semester;

    UserAccount account;

    vector<Course> courses;
    vector<Assignment> assignments;
    vector<Exam> exams;

    StudyPlanner studyPlanner;
    ProgressTracker progressTracker;

    vector<Reminder> reminders;

public:

    Student();

    Student(string studentName,
            string studentID,
            string department,
            int semester);

    // Setter Functions

    void setStudentName(string studentName);
    void setStudentID(string studentID);
    void setDepartment(string department);
    void setSemester(int semester);

    void setUserAccount(const UserAccount& account);

    // Getter Functions

    string getStudentName() const;
    string getStudentID() const;
    string getDepartment() const;
    int getSemester() const;

    const UserAccount& getUserAccount() const;

    StudyPlanner& getStudyPlanner();
    ProgressTracker& getProgressTracker();

    const StudyPlanner& getStudyPlanner() const;
    const ProgressTracker& getProgressTracker() const;

    // Read-Only Collection Getters

    const vector<Course>& getCourses() const;
    const vector<Assignment>& getAssignments() const;
    const vector<Exam>& getExams() const;
    const vector<Reminder>& getReminders() const;

    // Management Functions

    void addCourse(const Course& course);
    void removeCourse(string courseCode);

    void addAssignment(const Assignment& assignment);
    void removeAssignment(string assignmentName);

    void addExam(const Exam& exam);
    void removeExam(string examType);

    void addReminder(const Reminder& reminder);
    void removeReminder(string reminderMessage);

    // Display Function

    void displayStudent() const;
    void displayCompleteStudentRecord() const;

    ~Student();
};

#endif