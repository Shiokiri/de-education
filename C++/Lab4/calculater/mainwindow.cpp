#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Calculation, SIGNAL(clicked()), this, SLOT(buttonCalculation_clicked()));
    connect(ui->Clear, SIGNAL(clicked()), this, SLOT(buttonClear_clicked()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::buttonCalculation_clicked()
{
    double num1 = ui->Number_1->text().toDouble();
    double num2 = ui->Number_2->text().toDouble();
    uint8_t index = ui->comboBox->currentIndex();
    double result = 0.0;
    switch (index) {
        case 0:
            result = num1 + num2;
            break;
        case 1:
            result = num1 - num2;
            break;
        case 2:
            result = num1 * num2;
            break;
        case 3:
            if(num2 == 0)
            {
                QMessageBox::about(this, "注意", "除数不能为0");
                return;
            }
            result = num1 / num2;
            break;
        default:
            break;
    }
    ui->Result->setText(QString::number(result));
}

void MainWindow::buttonClear_clicked()
{
    ui->Number_1->clear();
    ui->Number_2->clear();
    ui->Result->clear();
}
