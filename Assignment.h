#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

/*
==========================================
Class : Assignment

This class manages:
- Assignment Details
- Course Information
- Assignment Status
==========================================
*/

class Assignment
{
private:
    string assignmentName;
    Course course;
    string issueDate;
    string dueDate;
    bool isCompleted;

public:
    Assignment();

    Assignment(string assignmentName,
               const Course& course,
               string issueDate,
               string dueDate,
               bool isCompleted);

    void setAssignmentName(string assignmentName);
    void setCourse(const Course& course);
    void setIssueDate(string issueDate);
    void setDueDate(string dueDate);
    void setStatus(bool isCompleted);

    string getAssignmentName() const;
    const Course& getCourse() const;
    string getIssueDate() const;
    string getDueDate() const;
    bool getStatus() const;

    void displayAssignment(int number) const;

    ~Assignment();
};

#endif