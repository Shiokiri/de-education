#include "User.h"

User::User(){}
User::User(string name, string password):
    userName(name),
    userPassword(password) {}
void User::setUserName(const string name) { userName = name; }
void User::setUserPassword(const string password) { userPassword = password; }
void User::setNextUser(User *user) { nextUser = user; }
string User::getUserName() const { return userName; }
string User::getUserPassword() const { return userPassword; }
User* User::getNextUser() const { return nextUser; }

void User::addNotebook(Notebook* notebook)
{
    notebooks.push_back(notebook);
}
void User::deleteNotebookByNotebookName(const string name)
{
    for(auto notebook = notebooks.begin(); notebook != notebooks.end(); )
    {
        if((*notebook)->getNotebookName() == name)
        {
            notebook = notebooks.erase(notebook);
        }
        else
        {
            notebook++;
        }
    }
}
vector<Notebook*> User::getAllNotebooks() const
{
    return notebooks;
}

void User::setCurrentNotebookByNotebookName(const string name)
{
    for(auto notebook = notebooks.begin(); notebook != notebooks.end(); notebook++)
    {
        if((*notebook)->getNotebookName() == name)
        {
            currentNotebook = *notebook;
            break;
        }
    }
}
Notebook* User::getCurrentNotebook() const
{
    return currentNotebook;
}
