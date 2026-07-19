#include "Exam.h"
#include "CustomException.h"

/*
==========================================
Class : Exam

This class manages:
- Exam Details
- Course Information
- Exam Schedule
==========================================
*/

Exam::Exam()
    : examType(""), examDate("")
{

}

Exam::Exam(const Course& course,
           string examType,
           string examDate)
{
    setCourse(course);
    setExamType(examType);
    setExamDate(examDate);
}

void Exam::setCourse(const Course& course)
{
    this->course = course;
}

void Exam::setExamType(string examType)
{
    if (examType.empty())
    {
        throw InvalidExamTypeException();
    }

    this->examType = examType;
}

void Exam::setExamDate(string examDate)
{
    if (examDate.empty())
    {
        throw InvalidExamDateException();
    }

    this->examDate = examDate;
}

const Course& Exam::getCourse() const
{
    return course;
}

string Exam::getExamType() const
{
    return examType;
}

string Exam::getExamDate() const
{
    return examDate;
}

void Exam::displayExam(int number) const
{
   

    cout << "+------------------------------------------------------+\n";
     cout << "| Exam : " << number << endl;
    cout << "| Course Name : " << course.getCourseName() << endl;
    cout << "| Exam Type   : " << examType << endl;
    cout << "| Exam Date   : " << examDate << endl;
    cout << "+------------------------------------------------------+\n";

      cout << endl;
}

Exam::~Exam()
{

}