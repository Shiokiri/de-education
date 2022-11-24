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
    // 添加一个用户
    bool addUser(string name, string password);
    // 判断用户密码是否正确
    bool judgeUser(string name, string password);
    // 通过用户名设置当前用户
    void setCurrentUserByUserName(string name);
    // 获取当前用户指针
    User* getCurrentUser();
    // 本地读取 存储
    void loadAllUsers();
    void saveAllUsers();

private:
    UserManager() = default;
    User *head = new User(), *current;
    int userNumber = 0;
    User *currentUser;
};

#endif // USERMANAGER_H
