#ifndef WIDGET_H
#define WIDGET_H

#include "UserRegisterDialog.h"
#include "UserLoginDialog.h"
#include "User.h"
#include "UserManager.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void UpdateUI();
    void Debug();

private:
    Ui::Widget *ui;
    UserRegisterDialog *userRegisterDialog;
    UserLoginDialog *userLoginDialog;
    UserManager& userManager = UserManager::get_instance();

};
#endif // WIDGET_H
