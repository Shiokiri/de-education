#include "widget.h"
#include "ui_widget.h"

#include <QTableWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    userRegisterDialog = new UserRegisterDialog(this);
    connect(ui->registerButton, SIGNAL(clicked()), userRegisterDialog, SLOT(show()));
    userLoginDialog = new UserLoginDialog(this);
    connect(ui->loginButton, SIGNAL(clicked()), userLoginDialog, SLOT(show()));


    update();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update()
{
    QTableWidgetItem *user = new QTableWidgetItem("notebookName");
    ui -> tableWidget -> insertRow(0);
    ui -> tableWidget -> setItem(0, 0, user);
}
