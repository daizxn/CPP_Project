//
// Created by dai on 2024/5/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SortInfo.h" resolved

#include "sortinfo.h"
#include "Forms/ui_SortInfo.h"


SortInfo::SortInfo(QWidget *parent) :
        QDialog(parent), ui(new Ui::SortInfo) {
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &SortInfo::addRule);
    connect(ui->deleteButton, &QPushButton::clicked, this, &SortInfo::deleteRule);
    connect(ui->noButton,&QPushButton::clicked,this,&SortInfo::no);
}

SortInfo::~SortInfo() {
    delete company;
    delete ui;
}

void SortInfo::load() {
    //清空残留数据
    ui->SortRuleTableWidget->clear();

    //设置表单格式
    ui->SortRuleTableWidget->setColumnCount(2);
    ui->SortRuleTableWidget->setColumnWidth(0, 215);
    ui->SortRuleTableWidget->setColumnWidth(1, 210);
    ui->SortRuleTableWidget->setRowCount(0);
    //添加表头
    List<QString> colHeader;
    colHeader.pushBack("排序数据");
    colHeader.pushBack("排序方式");
    ui->SortRuleTableWidget->setHorizontalHeaderLabels(colHeader.toQList());

    //隐藏序号
    ui->SortRuleTableWidget->verticalHeader()->hide();
}

void SortInfo::setCompany(Company *pCompany) {
    company = pCompany;
}


/*slot*/
void SortInfo::addRule() {
    int rowCount = ui->SortRuleTableWidget->rowCount();
    ui->SortRuleTableWidget->insertRow(rowCount);

    auto *sortItem = new QComboBox;
    auto *sortMode = new QComboBox;

    //设置排序选项
    for (int i = 0; i < UserInfoEnum::USERINFO_COUNT; i++)
        sortItem->addItem(UserInfoName_zh[i], UserInfoEnum(i));

    //设置排序模式
    sortMode->addItem("升序", 0);
    sortMode->addItem("降序", 1);

    ui->SortRuleTableWidget->setCellWidget(rowCount, 0, sortItem);
    ui->SortRuleTableWidget->setCellWidget(rowCount, 1, sortMode);
}

void SortInfo::deleteRule() {
    //获得当前行号
    int row = ui->SortRuleTableWidget->currentRow();
    //删除
    ui->SortRuleTableWidget->removeRow(row);
}

void SortInfo::no() {
    this->hide();
}
