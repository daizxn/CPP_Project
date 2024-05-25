//
// Created by dai on 2024/5/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserInfoDialog.h" resolved

#include "userinfodialog.h"
#include "Forms/ui_UserInfoDialog.h"


UserInfoDialog::UserInfoDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::UserInfoDialog) {
    ui->setupUi(this);


}

UserInfoDialog::~UserInfoDialog() {
    delete ui;
    delete user;
}

void UserInfoDialog::setUser(const User user) {
    this->user = new User(user);
}

void UserInfoDialog::load() {
    if (user->GetInfo(UserInfoEnum::Numbering) != "null")
        ui->Numbering->setText(user->GetInfo(UserInfoEnum::Numbering));
    if (user->GetInfo(UserInfoEnum::Name) != "null")
        ui->Name->setText(user->GetInfo(UserInfoEnum::Name));
    if (user->GetInfo(UserInfoEnum::Age) != "null")
        ui->Age->setText(user->GetInfo(UserInfoEnum::Age));
    if (user->GetInfo(UserInfoEnum::Education) != "null")
        ui->Education->setText(user->GetInfo(UserInfoEnum::Education));
    if (user->GetInfo(UserInfoEnum::Ethnic) != "null")
        ui->Ethinic->setText(user->GetInfo(UserInfoEnum::Ethnic));
    if (user->GetInfo(UserInfoEnum::Specialized) != "null");
    ui->Specialized->setText(user->GetInfo(UserInfoEnum::Specialized));

    for (int i = 0; i < JobEnum::JOB_COUNT; i++) {
        ui->Job->addItem(JobName_zh[i]);
        if (user->GetInfo(UserInfoEnum::Job) == JobName_zh[i])
            ui->Job->setCurrentIndex(i);
    }

    for (int i = 0; i < DepartmentEnum::DEPARTMENT_COUNT; i++) {
        ui->Department->addItem(DepartmentName_zh[i]);
        if (user->GetInfo(UserInfoEnum::Department) == DepartmentName_zh[i])
            ui->Department->setCurrentIndex(i);
    }

    for (int i = 0; i < PositionEnum::PositionEnum_COUNT; i++) {
        ui->Position->addItem(PositionName_zh[i]);
        if (user->GetInfo(UserInfoEnum::Position) == PositionName_zh[i])
            ui->Position->setCurrentIndex(i);
    }
}

/*slot*/

void UserInfoDialog::saveButton() {

}

void UserInfoDialog::noButton() {

}