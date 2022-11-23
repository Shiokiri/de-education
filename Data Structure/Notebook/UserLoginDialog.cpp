#include "UserLoginDialog.h"
#include "ui_UserLoginDialog.h"

#include <iostream>

UserLoginDialog::UserLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLoginDialog)
{
    ui->setupUi(this);

    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    connect(ui->okButton, &QPushButton::clicked, [=]() mutable {
        userManager.addUser(ui->nameEdit->text().toStdString(),
                            ui->passwordEdit->text().toStdString());
        userManager.saveUsers();
        ui->nameEdit->setText("");
        ui->passwordEdit->setText("");
        this->exec();
    });

    connect(ui->cancelButton, &QPushButton::clicked, [=]() mutable {
        ui->nameEdit->setText("");
        ui->passwordEdit->setText("");
        this->exec();
    });

}

UserLoginDialog::~UserLoginDialog()
{
    delete ui;
}
