#include "widget.h"
#include "ui_widget.h"

#include <QTableWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 注册窗口
    userRegisterDialog = new UserRegisterDialog(this);
    connect(ui->registerButton, SIGNAL(clicked()), userRegisterDialog, SLOT(show()));

    // 登录窗口
    userLoginDialog = new UserLoginDialog(this);
    connect(ui->loginButton, SIGNAL(clicked()), userLoginDialog, SLOT(show()));


    Update();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Update()
{
    // Debug
    QTableWidgetItem *user = new QTableWidgetItem("notebookName");
    ui -> tableWidget -> insertRow(0);
    ui -> tableWidget -> setItem(0, 0, user);

    // 更新当前用户显示

    // 更新笔记本表格显示

    // 更新笔记表格显示

    // 更新笔记内容显示
}
