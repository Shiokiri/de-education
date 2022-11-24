#include "widget.h"
#include "UserLoginDialog.h"
#include "ui_UserLoginDialog.h"

#include <iostream>

UserLoginDialog::UserLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLoginDialog)
{
    ui->setupUi(this);

    Widget *widget = static_cast<Widget*>(parent);

    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    // 点击确定键
    connect(ui->okButton, &QPushButton::clicked, [=]() mutable {
        if(userManager.judgeUser(ui->nameEdit->text().toStdString(),
                                 ui->passwordEdit->text().toStdString()))
        {
            // 登录成功
            userManager.setCurrentUserByUserName(ui->nameEdit->text().toStdString());
            widget->UpdateUI();
        }
        else
        {
            // 登录失败
            // TO-DO : GUI
        }

        ui->nameEdit->setText("");
        ui->passwordEdit->setText("");
        this->close();

    });

    // 点击取消键
    connect(ui->cancelButton, &QPushButton::clicked, [=]() mutable {

        ui->nameEdit->setText("");
        ui->passwordEdit->setText("");
        this->close();

    });

}

UserLoginDialog::~UserLoginDialog()
{
    delete ui;
}
