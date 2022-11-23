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

void UserManager::saveUsers()
{
    current = head;
    while(current->getNextUser() != nullptr)
    {
        std::cout << current->getUserName() << " " << current->getUserPassword() << std::endl;
        current = current->getNextUser();
    }
    std::cout << current->getUserName() << " " << current->getUserPassword() << std::endl;
}
