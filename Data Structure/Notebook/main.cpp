#include "widget.h"
#include "kmp.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    UserManager& userManager = UserManager::get_instance();
    userManager.addUser("admin","123456");
    userManager.addUser("admin1","afd3dsf");
    userManager.addUser("admin2","@32123");
    std::cout << userManager.judgeUser("admin2","22") << std::endl;
    std::cout << userManager.judgeUser("admin2","@32123") << std::endl;

    Kmp& kmp = Kmp::get_instance();
    std::cout << kmp.judgeSubString("ABAABC","ABA") << std::endl;
    std::cout << kmp.judgeSubString("123456789","5678") << std::endl;
    std::cout << kmp.judgeSubString("123456789","26") << std::endl;
    std::cout << kmp.judgeSubString("数据结构", "结") << std::endl;
    std::cout << kmp.judgeSubString("数据结构", "九") << std::endl;

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
