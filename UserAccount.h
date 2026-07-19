#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

/*
==========================================
Base Class : UserAccount

This class manages:
- User Registration
- User Login
- Password Management
==========================================
*/

class UserAccount
{
private:
    string username;
    string password;

public:

    // Constructors

    UserAccount();
    UserAccount(string username, string password);

    // Setter Functions

    void setUsername(string username);
    void setPassword(string password);

    // Getter Functions

    string getUsername() const;
    string getPassword() const;

    // Member Functions

    void registerUser();
    bool login();
    void changePassword();

    // Display Function

    virtual void display() const;

    // Destructor

    virtual ~UserAccount();
};

#endif