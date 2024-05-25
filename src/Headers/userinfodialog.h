//
// Created by dai on 2024/5/24.
//

#ifndef CPP_PROJECT_USERINFODIALOG_H
#define CPP_PROJECT_USERINFODIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "Enum/UserInfoEnum.h"
#include "Enum/JobEnum.h"
#include "Enum/DepartmentEnum.h"
#include "Enum/PositionEnum.h"

#include "User.h"
#include "Company.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UserInfoDialog; }
QT_END_NAMESPACE

class UserInfoDialog : public QDialog {
Q_OBJECT

public:
    explicit UserInfoDialog(QWidget *parent = nullptr);

    void setUser(const User &userObj);

    void setCompany(Company *ptr);

    void setFlag(bool flag);

    void load();

    bool checkExist();
    bool checkEmpty();


    ~UserInfoDialog() override;

private slots:

    void saveButton();

    void noButton();

private:
    Ui::UserInfoDialog *ui;
    User *user;

    Company *company;

    bool flag;//标记模式 ：0.添加 1修改
};


#endif //CPP_PROJECT_USERINFODIALOG_H
