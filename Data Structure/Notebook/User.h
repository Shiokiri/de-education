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
    void setUserName(string name);
    void setUserPassword(string password);
    void setNextUser(User* user);
    string getUserName();
    string getUserPassword();
    User* getNextUser();
};

#endif // USER_H
