//
// Created by dai on 2024/5/24.
//

#ifndef CPP_PROJECT_USERINFODIALOG_H
#define CPP_PROJECT_USERINFODIALOG_H

#include <QDialog>

#include "Enum/UserInfoEnum.h"
#include "Enum/JobEnum.h"
#include "Enum/DepartmentEnum.h"
#include "Enum/PositionEnum.h"

#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UserInfoDialog; }
QT_END_NAMESPACE

class UserInfoDialog : public QDialog {
Q_OBJECT

public:
    explicit UserInfoDialog(QWidget *parent = nullptr);

    void setUser(const User user);

    void load();

    ~UserInfoDialog() override;

private slots:

    void saveButton();
    void noButton();

private:
    Ui::UserInfoDialog *ui;
    User *user;

    bool flag;
};


#endif //CPP_PROJECT_USERINFODIALOG_H
