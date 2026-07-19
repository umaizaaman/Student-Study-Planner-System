#include "ProgressTracker.h"
#include "CustomException.h"
#include <algorithm>

/*
==========================================
Class : ProgressTracker

This class manages:
- Study Progress
- Completed Tasks
- Pending Tasks
==========================================
*/

ProgressTracker::ProgressTracker()
{
    studyPlanner = nullptr;

}

ProgressTracker::ProgressTracker(const StudyPlanner& studyPlanner)
{
    this->studyPlanner = const_cast<StudyPlanner*>(&studyPlanner);
}

void ProgressTracker::setStudyPlanner(const StudyPlanner& studyPlanner)
{
    this->studyPlanner = const_cast<StudyPlanner*>(&studyPlanner);
}

const StudyPlanner& ProgressTracker::getStudyPlanner() const
{
    return *studyPlanner;
}

//==========================================
// Read-Only Collection Getters
//==========================================

const vector<string>& ProgressTracker::getCompletedTasks() const
{
    return completedTasks;
}

const vector<string>& ProgressTracker::getPendingTasks() const
{
    return pendingTasks;
}

void ProgressTracker::addCompletedTask(string task)
{
    if (task.empty())
    {
        throw InvalidTaskException();
    }

    completedTasks.push_back(task);
}

void ProgressTracker::addPendingTask(string task)
{
    if (task.empty())
    {
        throw InvalidTaskException();
    }

    pendingTasks.push_back(task);
}

void ProgressTracker::removeCompletedTask(string task)
{
    auto it = find(completedTasks.begin(),
                   completedTasks.end(),
                   task);

    if (it != completedTasks.end())
    {
        completedTasks.erase(it);
    }
    else
    {
        cout << "Task not found in completed tasks." << endl;
    }
}

void ProgressTracker::removePendingTask(string task)
{
    auto it = find(pendingTasks.begin(),
                   pendingTasks.end(),
                   task);

    if (it != pendingTasks.end())
    {
        pendingTasks.erase(it);
    }
    else
    {
        cout << "Task not found in pending tasks." << endl;
    }
}

void ProgressTracker::displayProgress() const
{
    cout << "\n========================================================\n";
    cout << "               PROGRESS TRACKER\n";
    cout << "========================================================\n";

    cout << "+------------------------------------------------------+\n";
    cout << "| Study Hours     : "
         << studyPlanner->getStudyHours() << " Hours" << endl;

    cout << "| Daily Target    : "
         << studyPlanner->getDailyTarget() << " Hours" << endl;

    cout << "| Status          : "
         << (studyPlanner->isTargetCompleted()
             ? "Target Completed"
             : "Target Pending")
         << endl;

    cout << "+------------------------------------------------------+\n\n";

    // Completed Tasks

    cout << "+------------------------------------------------------+\n";
    cout << "| Completed Tasks\n";
    cout << "|------------------------------------------------------|\n";

    if (completedTasks.empty())
    {
        cout << "| No completed tasks available." << endl;
    }
    else
    {
        int count = 1;

        for (const string& task : completedTasks)
        {
            cout << "| " << count++ << ". " << task << endl;
        }
    }

    cout << "+------------------------------------------------------+\n\n";

    // Pending Tasks

    cout << "+------------------------------------------------------+\n";
    cout << "| Pending Tasks\n";
    cout << "|------------------------------------------------------|\n";

    if (pendingTasks.empty())
    {
        cout << "| No pending tasks available." << endl;
    }
    else
    {
        int count = 1;

        for (const string& task : pendingTasks)
        {
            cout << "| " << count++ << ". " << task << endl;
        }
    }

    cout << "+------------------------------------------------------+\n\n";

    // Summary

    cout << "+------------------------------------------------------+\n";
    cout << "| Completed Tasks : " << completedTasks.size() << endl;
    cout << "| Pending Tasks   : " << pendingTasks.size() << endl;
    cout << "+------------------------------------------------------+\n";
}
ProgressTracker::~ProgressTracker()
{

}