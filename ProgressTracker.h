#ifndef PROGRESSTRACKER_H
#define PROGRESSTRACKER_H

#include <iostream>
#include <vector>
#include <string>
#include "StudyPlanner.h"

using namespace std;

/*
==========================================
Class : ProgressTracker

This class manages:
- Study Progress
- Completed Tasks
- Pending Tasks
==========================================
*/

class ProgressTracker
{
private:
   StudyPlanner* studyPlanner;

    vector<string> completedTasks;
    vector<string> pendingTasks;

public:
    ProgressTracker();

    ProgressTracker(const StudyPlanner& studyPlanner);

    void setStudyPlanner(const StudyPlanner& studyPlanner);

    const StudyPlanner& getStudyPlanner() const;

    // Read-Only Collection Getters

     const vector<string>& getCompletedTasks() const;
    const vector<string>& getPendingTasks() const;

    void addCompletedTask(string task);
    void addPendingTask(string task);

    void removeCompletedTask(string task);
    void removePendingTask(string task);

    void displayProgress() const;

    ~ProgressTracker();
};

#endif