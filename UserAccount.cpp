#include "UserAccount.h"

/*
==========================================
Base Class : UserAccount

This class manages:
- User Registration
- User Login
- Password Management
==========================================
*/

//==========================================
// Constructors
//==========================================

UserAccount::UserAccount()
    : username(""), password("")
{

}

UserAccount::UserAccount(string username, string password)
    : username(username), password(password)
{

}

//==========================================
// Setter Functions
//==========================================

void UserAccount::setUsername(string username)
{
    this->username = username;
}

void UserAccount::setPassword(string password)
{
    this->password = password;
}

//==========================================
// Getter Functions
//==========================================

string UserAccount::getUsername() const
{
    return username;
}

string UserAccount::getPassword() const
{
    return password;
}

//==========================================
// Register User
//==========================================

void UserAccount::registerUser()
{
    cout << "\n========== CREATE ACCOUNT ==========\n";

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    cout << "\nAccount Created Successfully!\n";
}

//==========================================
// Login
//==========================================

bool UserAccount::login()
{
    string enteredUsername;
    string enteredPassword;

    cout << "\n============= LOGIN =============\n";

    cout << "Enter Username : ";
    cin >> enteredUsername;

    cout << "Enter Password : ";
    cin >> enteredPassword;

    if (enteredUsername == username &&
        enteredPassword == password)
    {
        cout << "\nLogin Successful!\n";
        return true;
    }

    cout << "\nInvalid Username or Password!\n";
    return false;
}

//==========================================
// Change Password
//==========================================

void UserAccount::changePassword()
{
    string newPassword;

    cout << "\nEnter New Password : ";
    cin >> newPassword;

    password = newPassword;

    cout << "\nPassword Changed Successfully!\n";
}

//==========================================
// Display
//==========================================

void UserAccount::display() const
{
    cout << "\n========================================================\n";
    cout << "                  USER ACCOUNT\n";
    cout << "========================================================\n";

    cout << "Username : " << username << endl;
}

//==========================================
// Destructor
//==========================================

UserAccount::~UserAccount()
{

}