#include "Reminder.h"
#include "CustomException.h"

/*
==========================================
Class : Reminder

This class manages:
- Reminder Message
- Reminder Date
==========================================
*/

Reminder::Reminder()
    : reminderMessage(""), reminderDate("")
{

}

Reminder::Reminder(string reminderMessage,
                   string reminderDate)
{
    setReminderMessage(reminderMessage);
    setReminderDate(reminderDate);
}

void Reminder::setReminderMessage(string reminderMessage)
{
    if (reminderMessage.empty())
    {
        throw InvalidReminderMessageException();
    }

    this->reminderMessage = reminderMessage;
}

void Reminder::setReminderDate(string reminderDate)
{
    if (reminderDate.empty())
    {
        throw InvalidReminderDateException();
    }

    this->reminderDate = reminderDate;
}

string Reminder::getReminderMessage() const
{
    return reminderMessage;
}

string Reminder::getReminderDate() const
{
    return reminderDate;
}

void Reminder::displayReminder(int number) const
{
   
    cout << "+------------------------------------------------------+\n";
      cout << "| Reminder : " << number << endl;
    cout << "| Reminder Message : " << reminderMessage << endl;
    cout << "| Reminder Date    : " << reminderDate << endl;
    cout << "+------------------------------------------------------+\n";

    cout << endl;
}

Reminder::~Reminder()
{

}