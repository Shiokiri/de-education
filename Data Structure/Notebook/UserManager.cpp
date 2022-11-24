#include "UserManager.h"

bool UserManager::addUser(string name, string password)
{
    if(name == "" || password == "") return false;
    current = head;
    while(current->getNextUser() != nullptr)
    {
        if(current->getUserName() == name)
        {
            return false;
        }
        current = current->getNextUser();
    }
    if(current->getUserName() == name)
    {
        return false;
    }
    current->setNextUser(new User(name, password));
    //userNumber += 1;
    return true;
}

bool UserManager::judgeUser(string name, string password)
{
    if(name == "" || password == "") return false;
    current = head;
    while(current->getNextUser() != nullptr)
    {
        if(current->getUserName() == name && current->getUserPassword() == password)
        {
            return true;
        }
        current = current->getNextUser();
    }
    if(current->getUserName() == name && current->getUserPassword() == password)
    {
        return true;
    }
    return false;
}

// 通过用户名设置当前用户
void UserManager::setCurrentUserByUserName(string name)
{
    if(name == "") return;
    current = head;
    while(current->getNextUser() != nullptr)
    {
        if(current->getUserName() == name)
        {
            currentUser = current;
        }
        current = current->getNextUser();
    }
    if(current->getUserName() == name)
    {
        currentUser = current;
    }
}
// 获取当前用户指针
User* UserManager::getCurrentUser()
{
    return currentUser;
}
// 本地读取 存储
void UserManager::loadAllUsers()
{

}
void UserManager::saveAllUsers()
{
    current = head;
    while(current->getNextUser() != nullptr)
    {
        std::cout << current->getUserName() << " " << current->getUserPassword() << std::endl;
        current = current->getNextUser();
    }
    std::cout << current->getUserName() << " " << current->getUserPassword() << std::endl;
}
