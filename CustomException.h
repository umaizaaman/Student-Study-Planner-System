#ifndef CUSTOMEXCEPTIONS_H
#define CUSTOMEXCEPTIONS_H

#include <iostream>
#include <exception>

using namespace std;

/*
==========================================
Class : Custom Exceptions

This file manages:
- Input Validation
- Login Errors
- File Handling Errors
==========================================
*/

/*
==========================================
User Account Exceptions
==========================================
*/

class InvalidUsernameException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Username cannot be empty!";
    }
};

class InvalidPasswordException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Password must be at least 8 characters long!";
    }
};

/*
==========================================
Student Exceptions
==========================================
*/

class InvalidStudentIDException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Invalid Student ID!";
    }
};

class InvalidSemesterException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Semester must be between 1 and 8!";
    }
};

/*
==========================================
Course Exceptions
==========================================
*/

class InvalidCourseNameException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Course name cannot be empty!";
    }
};

class InvalidCourseCodeException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Course code cannot be empty!";
    }
};

class InvalidCreditHoursException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Credit hours must be greater than 0!";
    }
};

/*
==========================================
Assignment Exceptions
==========================================
*/

class InvalidAssignmentNameException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Assignment name cannot be empty!";
    }
};

class InvalidIssueDateException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Issue date cannot be empty!";
    }
};

class InvalidDueDateException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Due date cannot be empty!";
    }
};

/*
==========================================
Exam Exceptions
==========================================
*/

class InvalidExamTypeException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Exam type cannot be empty!";
    }
};

class InvalidExamDateException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Exam date cannot be empty!";
    }
};

/*
==========================================
Study Planner Exceptions
==========================================
*/

class InvalidStudyHoursException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Study hours must be between 0 and 24!";
    }
};

class InvalidDailyTargetException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Daily target must be between 1 and 24!";
    }
};

/*
==========================================
Reminder Exceptions
==========================================
*/

class InvalidReminderMessageException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Reminder message cannot be empty!";
    }
};

class InvalidReminderDateException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Reminder date cannot be empty!";
    }
};

/*
==========================================
Progress Tracker Exceptions
==========================================
*/

class InvalidTaskException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Task name cannot be empty!";
    }
};

/*
==========================================
Student Profile Exceptions
==========================================
*/

class InvalidStudentNameException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Student name cannot be empty!";
    }
};

class InvalidDepartmentException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Department cannot be empty!";
    }
};

/*
==========================================
General Exceptions
==========================================
*/

class InvalidMenuChoiceException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Invalid menu choice!";
    }
};

class FileOpenException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Error: Unable to open file!";
    }
};

#endif