#include "widget.h"
#include "ui_widget.h"

#include <QTableWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 笔记本和笔记表格不可修改
    ui->notebookWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->noteWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 注册窗口
    userRegisterDialog = new UserRegisterDialog(this);
    connect(ui->registerButton, SIGNAL(clicked()), userRegisterDialog, SLOT(show()));

    // 登录窗口
    userLoginDialog = new UserLoginDialog(this);
    connect(ui->loginButton, SIGNAL(clicked()), userLoginDialog, SLOT(show()));

    // 新建笔记本
    connect(ui->newNotebookButton, &QPushButton::clicked, [=]() mutable {

    });

    // 新建笔记
    connect(ui->newNoteButton, &QPushButton::clicked, [=]() mutable {

    });

    // 修改选中笔记本名称
    connect(ui->changeNotebookNameButton, &QPushButton::clicked, [=]() mutable {

    });

    // 修改选中笔记名称
    connect(ui->changeNoteNameButton, &QPushButton::clicked, [=]() mutable {

    });

    // 删除选中笔记本
    connect(ui->deleteNotebookButton, &QPushButton::clicked, [=]() mutable {

    });

    // 删除选中笔记
    connect(ui->deleteNoteButton, &QPushButton::clicked, [=]() mutable {

    });

    // 保存按钮
    connect(ui->saveButton, &QPushButton::clicked, [=]() mutable {

    });

    // 笔记本表格选中


    // 笔记表格选中


    Debug();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::UpdateUI()
{
    int currentLine = 0;
    // 当前用户存在
    if(User* currentUser = userManager.getCurrentUser();
            currentUser != nullptr)
    {
        // 更新当前用户显示
        ui->userLabel->setText(QString::fromStdString("当前用户："+currentUser->getUserName()));

        // 更新笔记本表格显示
        ui->notebookWidget->setRowCount(0);
        std::vector<Notebook*> notebooks = currentUser->getAllNotebooks();
        currentLine = 0;
        for(auto notebook = notebooks.begin(); notebook != notebooks.end(); notebook++)
        {
            ui->notebookWidget->insertRow(currentLine);
            ui->notebookWidget->setItem(currentLine, 0,
                                        new QTableWidgetItem(
                                             QString::fromStdString(
                                             (*notebook)->getNotebookName())));
             currentLine += 1;
        }


        // 当前笔记本存在
        if(Notebook *currentNotebook = currentUser->getCurrentNotebook();
                currentNotebook != nullptr)
        {
            // 更新笔记表格显示
            ui->noteWidget->setRowCount(0);
            std::vector<Note*> notes = currentNotebook->getAllNotes();
            currentLine = 0;
            for(auto note = notes.begin(); note != notes.end(); note++)
            {
                ui->noteWidget->insertRow(currentLine);
                ui->noteWidget->setItem(currentLine, 0,
                                            new QTableWidgetItem(
                                                QString::fromStdString(
                                                (*note)->getNoteName())));
                currentLine += 1;
            }

            //当前笔记存在
            if(Note * currentNote = currentNotebook->getCurrentNote();
                    currentNote != nullptr)
            {
                // 更新笔记内容显示
                ui->textEdit->setText(QString::fromStdString(currentNote->getNoteName()));
            }
        }
    }
    Debug();
}

void Widget::Debug()
{
    // Debug
    QTableWidgetItem *user = new QTableWidgetItem("notebookName");
    ui -> notebookWidget -> insertRow(0);
    ui -> notebookWidget -> setItem(0, 0, user);

    ui -> notebookWidget -> insertRow(1);
    ui -> notebookWidget -> setItem(1, 0, new QTableWidgetItem("test"));
}
