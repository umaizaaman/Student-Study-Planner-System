#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

/*
==========================================
Class : Exam

This class manages:
- Exam Details
- Course Information
- Exam Schedule
==========================================
*/

class Exam
{
private:
    Course course;
    string examType;
    string examDate;

public:
    Exam();

    Exam(const Course& course,
         string examType,
         string examDate);

    void setCourse(const Course& course);
    void setExamType(string examType);
    void setExamDate(string examDate);

    const Course& getCourse() const;
    string getExamType() const;
    string getExamDate() const;

    void displayExam(int number) const;

    ~Exam();
};

#endif