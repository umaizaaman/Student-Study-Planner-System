#include "FileManager.h"
#include "CustomException.h"

//==========================================
// Constructors
//==========================================

FileManager::FileManager()
{

}

//==========================================
// Save Student Data
//==========================================

void FileManager::saveStudent(const Student& student)
{
      ofstream outFile("StudentData.txt");

      if (!outFile)
{
    throw FileOpenException();
}

//==========================================
// Save User Account
//==========================================

outFile << "========================================================\n";
outFile << "                  USER ACCOUNT\n";
outFile << "========================================================\n\n";

outFile << "Username : "
        << student.getUserAccount().getUsername() << endl;

outFile << "Password : "
        << student.getUserAccount().getPassword() << endl << endl;

outFile << "========================================================\n";
outFile << "                 STUDENT PROFILE\n";
outFile << "========================================================\n\n";

outFile << "Student Name : "
        << student.getStudentName() << endl;

outFile << "Student ID   : "
        << student.getStudentID() << endl;

outFile << "Department   : "
        << student.getDepartment() << endl;

outFile << "Semester     : "
        << student.getSemester() << endl;

outFile << "\n\n========================================================\n";
outFile << "                 STUDY PLANNER\n";
outFile << "========================================================\n\n";

outFile << "Study Hours      : "
        << student.getStudyPlanner().getStudyHours()
        << " Hours" << endl;

outFile << "Daily Target     : "
        << student.getStudyPlanner().getDailyTarget()
        << " Hours" << endl;

outFile << "Progress Status  : "
        << (student.getStudyPlanner().isTargetCompleted()
            ? "Target Completed"
            : "Target Pending")
        << endl;

outFile << "\n\n========================================================\n";
outFile << "               PROGRESS TRACKER\n";
outFile << "========================================================\n\n";


outFile << "Completed Tasks\n";
outFile << "----------------------------------------\n";

const auto& completedTasks =
    student.getProgressTracker().getCompletedTasks();

if (completedTasks.empty())
{
    outFile << "No completed tasks available.\n";
}
else
{
    int count = 1;

    for (const string& task : completedTasks)
    {
        outFile << count++ << ". "
                << task << endl;
    }
}


outFile << "\nPending Tasks\n";
outFile << "----------------------------------------\n";

const auto& pendingTasks =
    student.getProgressTracker().getPendingTasks();

if (pendingTasks.empty())
{
    outFile << "No pending tasks available.\n";
}
else
{
    int count = 1;

    for (const string& task : pendingTasks)
    {
        outFile << count++ << ". "
                << task << endl;
    }
}


outFile << "\nCompleted Tasks : "
        << completedTasks.size() << endl;

outFile << "Pending Tasks   : "
        << pendingTasks.size() << endl;

outFile << "\n\n========================================================\n";
outFile << "                    COURSES\n";
outFile << "========================================================\n\n";


const auto& courses = student.getCourses();

if (courses.empty())
{
    outFile << "No courses available.\n";
}
else
{
    int count = 1;

    for (const Course& course : courses)
    {
        outFile << count++ << ". Course Name : "
                << course.getCourseName() << endl;

        outFile << "   Course Code : "
                << course.getCourseCode() << endl;

        outFile << "   Credit Hours: "
                << course.getCreditHours() << endl;

        outFile << endl;
    }
}

outFile << "\n\n========================================================\n";
outFile << "                  ASSIGNMENTS\n";
outFile << "========================================================\n\n";


const auto& assignments = student.getAssignments();

if (assignments.empty())
{
    outFile << "No assignments available.\n";
}
else
{
    int count = 1;

    for (const Assignment& assignment : assignments)
    {
        outFile << count++ << ". Assignment Name : "
                << assignment.getAssignmentName() << endl;

        outFile << "   Course Name     : "
                << assignment.getCourse().getCourseName() << endl;

        outFile << "   Issue Date      : "
                << assignment.getIssueDate() << endl;

        outFile << "   Due Date        : "
                << assignment.getDueDate() << endl;

        outFile << "   Status          : "
                << (assignment.getStatus()
                    ? "Completed"
                    : "Pending")
                << endl;

        outFile << endl;
    }
}

outFile << "\n\n========================================================\n";
outFile << "                     EXAMS\n";
outFile << "========================================================\n\n";


const auto& exams = student.getExams();

if (exams.empty())
{
    outFile << "No exams available.\n";
}
else
{
    int count = 1;

    for (const Exam& exam : exams)
    {
        outFile << count++ << ". Exam Type      : "
                << exam.getExamType() << endl;

        outFile << "   Course Name    : "
                << exam.getCourse().getCourseName() << endl;

        outFile << "   Exam Date      : "
                << exam.getExamDate() << endl;

        outFile << endl;
    }
}

outFile << "\n\n========================================================\n";
outFile << "                   REMINDERS\n";
outFile << "========================================================\n\n";


const auto& reminders = student.getReminders();

if (reminders.empty())
{
    outFile << "No reminders available.\n";
}
else
{
    int count = 1;

    for (const Reminder& reminder : reminders)
    {
        outFile << count++ << ". Reminder Message : "
                << reminder.getReminderMessage() << endl;

        outFile << "   Reminder Date    : "
                << reminder.getReminderDate() << endl;

        outFile << endl;
    }
}

}
//==========================================
// Load Student Data
//==========================================

void FileManager::loadStudent(Student& student)
{
    ifstream inFile("StudentData.txt");

    if (!inFile)
    {
        throw FileOpenException();
    }

 string line;

 string username;
 string password;

string name;
string id;
string department;
int semester;

//==========================================
// Read User Account
//==========================================

// Skip USER ACCOUNT heading
getline(inFile, line);
getline(inFile, line);
getline(inFile, line);
getline(inFile, line);

// Username
getline(inFile, line);
username = line.substr(line.find(":") + 2);

// Password
getline(inFile, line);
password = line.substr(line.find(":") + 2);

UserAccount account;

account.setUsername(username);
account.setPassword(password);

student.setUserAccount(account);

// Skip blank line
getline(inFile, line);

// Skip STUDENT PROFILE heading
getline(inFile, line);
getline(inFile, line);
getline(inFile, line);
getline(inFile, line);

    // Read Student Name
    getline(inFile, line);
    name = line.substr(line.find(":") + 2);


    // Read Student ID
    getline(inFile, line);
    id = line.substr(line.find(":") + 2);


    // Read Department
    getline(inFile, line);
    department = line.substr(line.find(":") + 2);


    // Read Semester
    getline(inFile, line);
    semester = stoi(line.substr(line.find(":") + 2));


    student.setStudentName(name);
    student.setStudentID(id);
    student.setDepartment(department);
    student.setSemester(semester);

    // Skip Study Planner heading

int studyHours;
int dailyTarget;


// Find Study Hours line

while(getline(inFile, line))
{
    if(line.find("Study Hours") != string::npos)
    {
        break;
    }
}


studyHours = stoi(line.substr(line.find(":") + 2, 1));

// Read Daily Target

getline(inFile, line);

dailyTarget = stoi(line.substr(line.find(":") + 2, 1));

student.getStudyPlanner().setStudyHours(studyHours);
student.getStudyPlanner().setDailyTarget(dailyTarget);

// Skip Progress Tracker heading

while(getline(inFile, line))
{
    if(line.find("Completed Tasks") != string::npos)
    {
        break;
    }
}
// Skip separator line

getline(inFile, line);

string task;

// Read completed task

while (getline(inFile, line))
{
    if (line.find("Pending Tasks") != string::npos)
    {
        break;
    }

    if (line.empty() ||
        line.find("----------------------------------------") != string::npos)
    {
        continue;
    }

    if (line.find("No completed tasks available.") != string::npos)
    {
        break;
    }

    task = line.substr(line.find(".") + 2);

    student.getProgressTracker().addCompletedTask(task);
}

// Skip separator line

getline(inFile, line);


// Read Pending Tasks

while (getline(inFile, line))
{
    if (line.find("Completed Tasks :") != string::npos)
    {
        break;
    }

    if (line.empty() ||
        line.find("----------------------------------------") != string::npos)
    {
        continue;
    }

    if (line.find("No pending tasks available.") != string::npos)
    {
        break;
    }

    task = line.substr(line.find(".") + 2);

    student.getProgressTracker().addPendingTask(task);
}

// Find Courses section

while (getline(inFile, line))
{
    if (line.find("COURSES") != string::npos)
    {
        break;
    }
}

// Skip heading line and blank line

getline(inFile, line);
getline(inFile, line);

Course course;

string courseName;
string courseCode;
int creditHours;

// Read Courses

while (getline(inFile, line))
{
    if (line.find("ASSIGNMENTS") != string::npos)
    {
        break;
    }

    if (line.empty() ||
        line.find("========================================================") != string::npos)
    {
        continue;
    }

    if (line.find("No courses available.") != string::npos)
    {
        break;
    }

    if (line.find("Course Name") != string::npos)
    {
        courseName = line.substr(line.find(":") + 2);

        getline(inFile, line);
        courseCode = line.substr(line.find(":") + 2);

        getline(inFile, line);
        creditHours = stoi(line.substr(line.find(":") + 2));

        Course course;

        course.setCourseName(courseName);
        course.setCourseCode(courseCode);
        course.setCreditHours(creditHours);

        student.addCourse(course);
    }
}

// Find Assignments section

/*while (getline(inFile, line))
{
    if (line.find("ASSIGNMENTS") != string::npos)
    {
        break;
    }
}*/

// Skip heading line and blank line

getline(inFile, line);
getline(inFile, line);

Assignment assignment;

string assignmentName;
Course assignmentCourse;
string issueDate;
string dueDate;
bool status;

// Read Assignments

while (getline(inFile, line))
{

    if (line.find("EXAMS") != string::npos)
    {
        break;
    }

    if (line.empty() ||
        line.find("========================================================") != string::npos)
    {
        continue;
    }

    if (line.find("No assignments available.") != string::npos)
    {
        break;
    }

    if (line.find("Assignment Name") != string::npos)
    {
        assignmentName = line.substr(line.find(":") + 2);

        getline(inFile, line);
        string courseName = line.substr(line.find(":") + 2);

        getline(inFile, line);
        issueDate = line.substr(line.find(":") + 2);

        getline(inFile, line);
        dueDate = line.substr(line.find(":") + 2);

        getline(inFile, line);

        string statusText = line.substr(line.find(":") + 2);

        status = (statusText == "Completed");

        assignmentCourse.setCourseName(courseName);

        assignment.setAssignmentName(assignmentName);
        assignment.setCourse(assignmentCourse);
        assignment.setIssueDate(issueDate);
        assignment.setDueDate(dueDate);
        assignment.setStatus(status);

        student.addAssignment(assignment);
    }
}

// Find Exams section

/*while (getline(inFile, line))
{
    if (line.find("EXAMS") != string::npos)
    {
        break;
    }
}*/

// Skip heading line and blank line

getline(inFile, line);
getline(inFile, line);

Exam exam;

string examType;
Course examCourse;
string examDate;

// Read Exams

while (getline(inFile, line))
{

    if (line.find("REMINDERS") != string::npos)
    {
        break;
    }

    if (line.empty() ||
        line.find("========================================================") != string::npos)
    {
        continue;
    }

    if (line.find("No exams available.") != string::npos)
    {
        break;
    }

    if (line.find("Exam Type") != string::npos)
    {
        examType = line.substr(line.find(":") + 2);

        getline(inFile, line);
        string courseName = line.substr(line.find(":") + 2);

        getline(inFile, line);
        examDate = line.substr(line.find(":") + 2);

        examCourse.setCourseName(courseName);

        exam.setExamType(examType);
        exam.setCourse(examCourse);
        exam.setExamDate(examDate);

        student.addExam(exam);
    }
}
//  reminder

// Skip Reminders heading

getline(inFile, line);
getline(inFile, line);

Reminder reminder;

string reminderMessage;
string reminderDate;

// Read Reminders

while (getline(inFile, line))
{
    if (line.empty() ||
        line.find("========================================================") != string::npos)
    {
        continue;
    }

    if (line.find("No reminders available.") != string::npos)
    {
        break;
    }

    if (line.find("Reminder Message") != string::npos)
    {
        reminderMessage = line.substr(line.find(":") + 2);

        getline(inFile, line);
        reminderDate = line.substr(line.find(":") + 2);

        reminder.setReminderMessage(reminderMessage);
        reminder.setReminderDate(reminderDate);

        student.addReminder(reminder);
    }
}
}



//==========================================
// Destructor
//==========================================

FileManager::~FileManager()
{

}