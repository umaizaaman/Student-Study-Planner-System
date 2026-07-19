#ifndef REMINDER_H
#define REMINDER_H

#include <iostream>
#include <string>

using namespace std;

/*
==========================================
Class : Reminder

This class manages:
- Reminder Message
- Reminder Date
==========================================
*/

class Reminder
{
private:
    string reminderMessage;
    string reminderDate;

public:
    Reminder();

    Reminder(string reminderMessage,
             string reminderDate);

    void setReminderMessage(string reminderMessage);
    void setReminderDate(string reminderDate);

    string getReminderMessage() const;
    string getReminderDate() const;

   void displayReminder(int number) const;

    ~Reminder();
};

#endif