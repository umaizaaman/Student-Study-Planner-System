#ifndef STUDYPLANNER_H
#define STUDYPLANNER_H

#include <iostream>

using namespace std;

/*
==========================================
Class : StudyPlanner

This class manages:
- Daily Study Hours
- Daily Study Target
- Study Progress
==========================================
*/

class StudyPlanner
{
private:
    int studyHours;
    int dailyTarget;

public:
    StudyPlanner();

    StudyPlanner(int studyHours,
                 int dailyTarget);

    void setStudyHours(int studyHours);
    void setDailyTarget(int dailyTarget);

    int getStudyHours() const;
    int getDailyTarget() const;

    bool isTargetCompleted() const;

    void displayStudyPlanner() const;

    ~StudyPlanner();
};

#endif