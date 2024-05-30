//
// Created by dai on 2024/5/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserInfoDialog.h" resolved

#include "userinfodialog.h"
#include "Forms/ui_UserInfoDialog.h"


UserInfoDialog::UserInfoDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::UserInfoDialog) {
    ui->setupUi(this);
    user = new User();

    /*connect*/
    connect(ui->conformButton, &QPushButton::clicked, this, &UserInfoDialog::saveButton);
    connect(ui->noButton, &QPushButton::clicked, this, &UserInfoDialog::noButton);
}

UserInfoDialog::~UserInfoDialog() {
    delete ui;
    delete user;
}

void UserInfoDialog::setUser(const User &userObj) {
    *(this->user) = userObj;
}

void UserInfoDialog::setCompany(Company *ptr) {
    company = ptr;
}

void UserInfoDialog::setFlag(bool flag) {
    this->flag=flag;
}

void UserInfoDialog::load() {//初始化加载
    //初始化
    ui->Numbering->clear();
    ui->Name->clear();
    ui->Age->clear();
    ui->Education->clear();
    ui->Specialized->clear();
    ui->Ethinic->clear();
    ui->Job->clear();
    ui->Department->clear();
    ui->Position->clear();

    //根据原来内容将数据填入最开始的表中
    if (user->GetId() != -1)
        ui->Numbering->setText(user->GetInfo(UserInfoEnum::Numbering));
    if (user->GetId() != -1)
        ui->Name->setText(user->GetInfo(UserInfoEnum::Name));
    if (user->GetId() != -1)
        ui->Age->setText(user->GetInfo(UserInfoEnum::Age));
    if (user->GetId() != -1)
        ui->Education->setText(user->GetInfo(UserInfoEnum::Education));
    if (user->GetId() != -1)
        ui->Ethinic->setText(user->GetInfo(UserInfoEnum::Ethnic));
    if (user->GetId() != -1)
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

    ui->Age->setValidator(new QIntValidator(ui->Age));//年龄只允许输入整型
}

bool UserInfoDialog::checkExist() {
    User param;
    param.SetInfo(UserInfoEnum::Numbering, ui->Numbering->text());
    //判断数据是否存在
    User temp = company->selectUser(param).userList.get(0);
    if (temp.GetId() != user->GetId() && temp.GetId() != -1){
        QMessageBox::warning(nullptr, "waring", "编号已存在", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }

    return true;

}

bool UserInfoDialog::checkEmpty() {
    //判断数据是否为空
    if(ui->Numbering->text().isEmpty()){
        QMessageBox::warning(nullptr,"waring","编号不能为空",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(ui->Name->text().isEmpty()){
        QMessageBox::warning(nullptr,"waring","姓名不能为空",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(ui->Age->text().isEmpty()){
        QMessageBox::warning(nullptr,"waring","年龄不能为空",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(ui->Education->text().isEmpty()){
        QMessageBox::warning(nullptr,"waring","受教育程度不能为空",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(ui->Ethinic->text().isEmpty()){
        QMessageBox::warning(nullptr,"waring","民族不能为空",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    if(ui->Specialized->text().isEmpty()){
        QMessageBox::warning(nullptr,"waring","专业不能为空",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    return true;

}

/*slot*/

void UserInfoDialog::saveButton() {
    //先判断数据是否为空，在判断数据是否存在，避免为空时对数据进行判断
    if(!checkEmpty())
        return;
    if(!checkExist())
        return;
    User info;

    info.SetId(user->GetId());
    info.SetInfo(UserInfoEnum::Numbering, ui->Numbering->text());
    info.SetInfo(UserInfoEnum::Name, ui->Name->text());
    info.SetInfo(UserInfoEnum::Age, ui->Age->text());
    info.SetInfo(UserInfoEnum::Education, ui->Education->text());
    info.SetInfo(UserInfoEnum::Ethnic, ui->Ethinic->text());
    info.SetInfo(UserInfoEnum::Specialized, ui->Specialized->text());
    info.SetInfo(UserInfoEnum::Job, ui->Job->currentText());
    info.SetInfo(UserInfoEnum::Department, ui->Department->currentText());
    info.SetInfo(UserInfoEnum::Position, ui->Position->currentText());

    if(flag)//如果为更新模式
        company->updateUser(user->GetId(), info);
    else//为添加模式
        company->addUser(info);

    this->hide();
}

void UserInfoDialog::noButton() {
    this->hide();
}