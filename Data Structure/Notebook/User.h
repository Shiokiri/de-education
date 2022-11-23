#ifndef USER_H
#define USER_H

#include "Notebook.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

class User
{
private:
    string userName;
    string userPassword;
    User *nextUser = nullptr;
    vector<Notebook*> notebooks;
public:
    User();
    User(string name, string password);
    void setUserName(const string name);
    void setUserPassword(const string password);
    void setNextUser(User* user);
    string getUserName() const;
    string getUserPassword() const;
    User* getNextUser() const;
    void addNotebook(Notebook* notebook);
    void deleteNotebookByNotebookName(const string name);
    vector<Notebook*> getAllNotebooks() const;
};

#endif // USER_H
