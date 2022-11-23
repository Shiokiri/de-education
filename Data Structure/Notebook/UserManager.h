#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "Singleton.h"
#include <iostream>


class UserManager : public Singleton<UserManager>{
    friend class Singleton<UserManager>;
public:
    UserManager(const UserManager&) = delete;
    UserManager& operator = (const UserManager&) = delete;
    bool addUser(string name, string password);
    bool judgeUser(string name, string password);
    void saveUsers();
private:
    UserManager() = default;
    User *head = new User(), *current;
    int userNumber = 0;
};

#endif // USERMANAGER_H
