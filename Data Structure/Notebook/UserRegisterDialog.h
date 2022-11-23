#ifndef USERREGISTERDIALOG_H
#define USERREGISTERDIALOG_H

#include "UserManager.h"

#include <QDialog>

namespace Ui {
class UserRegisterDialog;
}

class UserRegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserRegisterDialog(QWidget *parent = nullptr);
    ~UserRegisterDialog();

private:
    Ui::UserRegisterDialog *ui;

    UserManager& userManager = UserManager::get_instance();
};

#endif // USERREGISTERDIALOG_H
