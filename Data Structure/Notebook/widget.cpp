#include "widget.h"
#include "ui_widget.h"

#include <QTableWidgetItem>
#include <iostream>

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
        ScanUI();
        // 当前用户存在
        if(User* user = userManager.getCurrentUser();
                user != nullptr)
        {
            if(ui->notebookNameEdit->text() != "")
            {
                user->addNotebook(new Notebook(ui->notebookNameEdit->text().toStdString()));
            }
        }
        ui->noteNameEdit->setText("");
        ui->notebookNameEdit->setText("");
        UpdateUI(UpdateUISignal::GENERAL);
    });

    // 新建笔记
    connect(ui->newNoteButton, &QPushButton::clicked, [=]() mutable {
        ScanUI();
        // 当前用户存在
        if(User* user = userManager.getCurrentUser();
                user != nullptr)
        {
            // 当前笔记本存在
            if(Notebook* notebook = user->getCurrentNotebook();
                    notebook != nullptr)
            {
                if(ui->noteNameEdit->text() != "")
                {
                    notebook->addNote(new Note(ui->noteNameEdit->text().toStdString()));
                }
            }
        }
        ui->noteNameEdit->setText("");
        ui->notebookNameEdit->setText("");
        UpdateUI(UpdateUISignal::GENERAL);
    });

    // 修改选中笔记本名称
    connect(ui->changeNotebookNameButton, &QPushButton::clicked, [=]() mutable {
        ScanUI();
        // 当前用户存在
        if(User* user = userManager.getCurrentUser();
                user != nullptr)
        {
            // 当前笔记本存在
            if(Notebook* notebook = user->getCurrentNotebook();
                    notebook != nullptr)
            {
                if(ui->notebookNameEdit->text() != "")
                {
                    notebook->setNotebookName(ui->notebookNameEdit->text().toStdString());
                }
            }
        }
        ui->noteNameEdit->setText("");
        ui->notebookNameEdit->setText("");
        UpdateUI(UpdateUISignal::GENERAL);
    });

    // 修改选中笔记名称
    connect(ui->changeNoteNameButton, &QPushButton::clicked, [=]() mutable {
        ScanUI();
        // 当前用户存在
        if(User* user = userManager.getCurrentUser();
                user != nullptr)
        {
            // 当前笔记本存在
            if(Notebook* notebook = user->getCurrentNotebook();
                    notebook != nullptr)
            {
                // 当前笔记存在
                if(Note * note = notebook->getCurrentNote();
                        note != nullptr)
                {
                    if(ui->noteNameEdit->text() != "")
                    {
                        note->setNoteName(ui->noteNameEdit->text().toStdString());
                    }
                }
            }
        }
        ui->noteNameEdit->setText("");
        ui->notebookNameEdit->setText("");
        UpdateUI(UpdateUISignal::GENERAL);
    });

    // 删除选中笔记本
    connect(ui->deleteNotebookButton, &QPushButton::clicked, [=]() mutable {
        ScanUI();
        // 当前用户存在
        if(User* user = userManager.getCurrentUser();
                user != nullptr)
        {
            user->deleteNotebookByNotebookName(notebookName.toStdString());
        }
        UpdateUI(UpdateUISignal::GENERAL);
    });

    // 删除选中笔记
    connect(ui->deleteNoteButton, &QPushButton::clicked, [=]() mutable {
        ScanUI();
        // 当前用户存在
        if(User* user = userManager.getCurrentUser();
                user != nullptr)
        {
            // 当前笔记本存在
            if(Notebook* notebook = user->getCurrentNotebook();
                    notebook != nullptr)
            {
                notebook->deleteNoteByNoteName(noteName.toStdString());
            }
        }
        UpdateUI(UpdateUISignal::GENERAL);
    });

    // 保存按钮
    connect(ui->saveButton, &QPushButton::clicked, [=]() mutable {
        ScanUI();
        // 当前用户存在
        if(User* user = userManager.getCurrentUser();
                user != nullptr)
        {
            // 当前笔记本存在
            if(Notebook* notebook = user->getCurrentNotebook();
                    notebook != nullptr)
            {
                // 当前笔记存在
                if(Note * note = notebook->getCurrentNote();
                        note != nullptr)
                {
                    note->setText(ui->textEdit->toPlainText().toStdString());
                }
            }
        }
        UpdateUI(UpdateUISignal::GENERAL);
    });

    connect(ui->notebookWidget, &QTableWidget::itemClicked, [=]() mutable {
        ScanUI();
        UpdateUI(UpdateUISignal::NOTEBOOKWIDGET);
    });

    connect(ui->noteWidget, &QTableWidget::itemClicked, [=]() mutable {
        ScanUI();
        UpdateUI(UpdateUISignal::NOTEWIDGET);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::UpdateUI(UpdateUISignal updateUISignal)
{
    ui->textEdit->setText("");

    int currentLine = 0;
    // 当前用户存在
    if(User* currentUser = userManager.getCurrentUser();
            currentUser != nullptr)
    {
        // 更新当前用户显示
        ui->userLabel->setText(QString::fromStdString("当前用户："+currentUser->getUserName()));
        // 更新笔记本表格显示
        if(updateUISignal != UpdateUISignal::NOTEBOOKWIDGET)
        {
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
        }
        // 当前笔记本存在
        if(Notebook *currentNotebook = currentUser->getCurrentNotebook();
                currentNotebook != nullptr)
        {
            // 更新笔记表格显示
            if(updateUISignal != UpdateUISignal::NOTEWIDGET)
            {
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
            }
            //当前笔记存在
            if(Note * currentNote = currentNotebook->getCurrentNote();
                    currentNote != nullptr)
            {
                // 更新笔记内容显示
                ui->textEdit->setText(QString::fromStdString(currentNote->getText()));
            }
        }
    }

}

void Widget::ScanUI()
{
    QList<QTableWidgetItem*>notebookItems = ui->notebookWidget->selectedItems();
    int count = notebookItems.count();
    for(int i = 0; i < count; i++)
    {
        QTableWidgetItem *notebookItem = notebookItems.at(i);
        notebookName = notebookItem->text();
    }
    QList<QTableWidgetItem*>noteItems = ui->noteWidget->selectedItems();
    count = noteItems.count();
    for(int i = 0; i < count; i++)
    {
        QTableWidgetItem *noteItem = noteItems.at(i);
        noteName = noteItem->text();
    }
    // 当前用户存在
    if(User* user = userManager.getCurrentUser();
            user != nullptr)
    {
        user->setCurrentNotebookByNotebookName(notebookName.toStdString());
        // 当前笔记本存在
        if(Notebook* notebook = user->getCurrentNotebook();
                notebook != nullptr)
        {
            notebook->setCurrentNoteByNoteName(noteName.toStdString());
        }
    }
}
