#ifndef WIDGET_H
#define WIDGET_H

#include "UserRegisterDialog.h"
#include "UserLoginDialog.h"
#include "User.h"

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

private:
    Ui::Widget *ui;
    UserRegisterDialog *userRegisterDialog;
    UserLoginDialog *userLoginDialog;

    void Update();
};
#endif // WIDGET_H
