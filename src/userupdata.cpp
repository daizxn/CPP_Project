//
// Created by dai on 2024/5/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_userUpdata.h" resolved

#include "userupdata.h"
#include "ui_userUpdata.h"


userUpdata::userUpdata(QWidget *parent) :
        QWidget(parent), ui(new Ui::userUpdata) {
    ui->setupUi(this);
}

userUpdata::~userUpdata() {
    delete ui;
}
