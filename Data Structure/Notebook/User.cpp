#include "User.h"

User::User(){}
User::User(string name, string password):
    userName(name),
    userPassword(password) {}
void User::setUserName(string name) { userName = name; }
void User::setUserPassword(string password) { userPassword = password; }
void User::setNextUser(User *user) { nextUser = user; }
string User::getUserName() { return userName; }
string User::getUserPassword() { return userPassword; }
User* User::getNextUser() { return nextUser; }
