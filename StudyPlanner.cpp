#include "StudyPlanner.h"
#include "CustomException.h"

/*
==========================================
Class : StudyPlanner

This class manages:
- Daily Study Hours
- Daily Study Target
- Study Progress
==========================================
*/

StudyPlanner::StudyPlanner()
    : studyHours(0), dailyTarget(1)
{

}

StudyPlanner::StudyPlanner(int studyHours,
                           int dailyTarget)
{
    setStudyHours(studyHours);
    setDailyTarget(dailyTarget);
}

void StudyPlanner::setStudyHours(int studyHours)
{
    if (studyHours < 0 || studyHours > 24)
    {
        throw InvalidStudyHoursException();
    }

    this->studyHours = studyHours;
}

void StudyPlanner::setDailyTarget(int dailyTarget)
{
    if (dailyTarget <= 0 || dailyTarget > 24)
    {
        throw InvalidDailyTargetException();
    }

    this->dailyTarget = dailyTarget;
}

int StudyPlanner::getStudyHours() const
{
    return studyHours;
}

int StudyPlanner::getDailyTarget() const
{
    return dailyTarget;
}

bool StudyPlanner::isTargetCompleted() const
{
    return studyHours >= dailyTarget;
}

void StudyPlanner::displayStudyPlanner() const
{
    cout << "\n========================================================\n";
    cout << "                 STUDY PLANNER\n";
    cout << "========================================================\n";

    cout << "+------------------------------------------------------+\n";
    cout << "| Study Hours      : " << studyHours << " Hours" << endl;
    cout << "| Daily Target     : " << dailyTarget << " Hours" << endl;
    cout << "| Progress Status  : "
         << (isTargetCompleted() ? "Target Completed"
                                 : "Target Pending")
         << endl;
    cout << "+------------------------------------------------------+\n";
}

StudyPlanner::~StudyPlanner()
{

}