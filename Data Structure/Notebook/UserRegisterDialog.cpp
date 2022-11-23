#include "UserRegisterDialog.h"
#include "ui_UserRegisterDialog.h"

UserRegisterDialog::UserRegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserRegisterDialog)
{
    ui->setupUi(this);

    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    connect(ui->okButton, &QPushButton::clicked, [=]() mutable {
        userManager.addUser(ui->nameEdit->text().toStdString(),
                            ui->passwordEdit->text().toStdString());
        userManager.saveUsers();
        ui->nameEdit->setText("");
        ui->passwordEdit->setText("");
        this->close();
    });

    connect(ui->cancelButton, &QPushButton::clicked, [=]() mutable {
        ui->nameEdit->setText("");
        ui->passwordEdit->setText("");
        this->close();
    });
}

UserRegisterDialog::~UserRegisterDialog()
{
    delete ui;
}
