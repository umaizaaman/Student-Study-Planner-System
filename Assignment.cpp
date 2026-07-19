#include "Assignment.h"
#include "CustomException.h"

/*
==========================================
Class : Assignment

This class manages:
- Assignment Details
- Course Information
- Assignment Status
==========================================
*/

Assignment::Assignment()
    : assignmentName(""), issueDate(""), dueDate(""), isCompleted(false)
{

}

Assignment::Assignment(string assignmentName,
                       const Course& course,
                       string issueDate,
                       string dueDate,
                       bool isCompleted)
{
    setAssignmentName(assignmentName);
    setCourse(course);
    setIssueDate(issueDate);
    setDueDate(dueDate);
    setStatus(isCompleted);
}

void Assignment::setAssignmentName(string assignmentName)
{
    if (assignmentName.empty())
    {
        throw InvalidAssignmentNameException();
    }

    this->assignmentName = assignmentName;
}

void Assignment::setCourse(const Course& course)
{
    this->course = course;
}

void Assignment::setIssueDate(string issueDate)
{
    if (issueDate.empty())
    {
        throw InvalidIssueDateException();
    }

    this->issueDate = issueDate;
}

void Assignment::setDueDate(string dueDate)
{
    if (dueDate.empty())
    {
        throw InvalidDueDateException();
    }

    this->dueDate = dueDate;
}

void Assignment::setStatus(bool isCompleted)
{
    this->isCompleted = isCompleted;
}

string Assignment::getAssignmentName() const
{
    return assignmentName;
}

const Course& Assignment::getCourse() const
{
    return course;
}

string Assignment::getIssueDate() const
{
    return issueDate;
}

string Assignment::getDueDate() const
{
    return dueDate;
}

bool Assignment::getStatus() const
{
    return isCompleted;
}

void Assignment::displayAssignment(int number) const
{
    
    cout << "+------------------------------------------------------+\n";
     cout << "| Assignment : " << number << endl;
    cout << "| Assignment Name : " << assignmentName << endl;
    cout << "| Course Name     : " << course.getCourseName() << endl;
    cout << "| Issue Date      : " << issueDate << endl;
    cout << "| Due Date        : " << dueDate << endl;
    cout << "| Status          : "
         << (isCompleted ? "Completed" : "Pending") << endl;
    cout << "+------------------------------------------------------+\n";

    cout << endl;
}

Assignment::~Assignment()
{

}