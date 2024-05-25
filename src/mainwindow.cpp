//
// Created by dai on 2024/5/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved



#include "mainwindow.h"
#include "Company.h"
#include "Forms/ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    company = new Company(parent);
    company->loadFromFile();

    userInfoDialog = new UserInfoDialog(ui->employeeTableWidget);
    sortInfo = new SortInfo(ui->employeeTableWidget);

    this->onLoad();


    /*connect*/
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::Exit);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::saveButton);
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::addButton);
    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::sortButton);
}

MainWindow::~MainWindow() {
    delete company;
    delete ui;
}

void MainWindow::onLoad() {//初始化加载
    treeBarLoad();
    employTableWidgetLoad(company);
}

void MainWindow::treeBarLoad() {//加载侧边栏
    /*treeBar设计*/
    ui->treeBar->setColumnCount(1);//设置列数
    ui->treeBar->setHeaderLabel("公司员工管理系统");//设置头的标题

    QTreeWidgetItem *employeeBar;
    employeeBar = new QTreeWidgetItem(ui->treeBar, QStringList(QString("员工管理")));//employeeBar是员工管理的根节点

    QTreeWidgetItem *departmentBar;
    departmentBar = new QTreeWidgetItem(ui->treeBar, QStringList(QString("部门管理")));//departmentBar是部门管理的节点

    QTreeWidgetItem *jobBar;
    jobBar = new QTreeWidgetItem(ui->treeBar, QStringList(QString("职位管理")));//jobBar是职位管理的节点

    ui->treeBar->addTopLevelItem(employeeBar);//将employeeBar添加到树形控件中
    ui->treeBar->addTopLevelItem(departmentBar);//将departmentBar添加到树形控件中
    ui->treeBar->addTopLevelItem(jobBar);//将jobBar添加到树形控件中
}

void MainWindow::employTableWidgetLoad(Company *data) { //加载数据表

    ui->employeeTableWidget->clear();//清除表原来的数据

    ui->employeeTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
    ui->employeeTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
    ui->employeeTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个


    ui->employeeTableWidget->setColumnCount(UserInfoEnum::USERINFO_COUNT + 2); //设置列数
    ui->employeeTableWidget->setColumnWidth(UserInfoEnum::USERINFO_COUNT + 1, 150);//设置列宽
    ui->employeeTableWidget->setRowCount(data->getSize());//设置行数

    //添加表头
    List<QString> list;
    list.pushBack("id");
    for (const auto &i: UserInfoName_zh) {
        list.pushBack(i);
    }
    list.pushBack("操作");
    ui->employeeTableWidget->setHorizontalHeaderLabels(list.toQList());

    //隐藏id
    ui->employeeTableWidget->hideColumn(0);

    //添加数据
    int rowCount = 0;//设置添加的第几行
    unsigned int size = data->userList.getSize();
    while (rowCount != size) {

        ui->employeeTableWidget->setItem(rowCount, 0, new QTableWidgetItem(
                QString::number(data->userList.get(rowCount).GetId())));

        int i;
        for (i = 0; i < UserInfoEnum::USERINFO_COUNT; i++) {
            ui->employeeTableWidget->setItem(rowCount, i + 1, new QTableWidgetItem(
                    data->userList.get(rowCount).GetInfo(UserInfoEnum(i))));
        }
        /*添加操作button*/
        auto *qWidget = new QWidget(ui->employeeTableWidget);
        auto *qhBoxLayout = new QHBoxLayout(qWidget);

        //修改
        auto *updateButton = new QPushButton(ui->employeeTableWidget);
        updateButton->setText("修改");
        SetBtnStyle(updateButton, "30,227,207");
        connect(updateButton, &QPushButton::clicked, this, &MainWindow::updateButton);

        //删除
        auto *deleteButton = new QPushButton(ui->employeeTableWidget);
        deleteButton->setText("删除");
        SetBtnStyle(deleteButton, "204,153,0");
        connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteButton);

        qhBoxLayout->addWidget(updateButton);
        qhBoxLayout->addWidget(deleteButton);

        qhBoxLayout->setContentsMargins(0, 0, 0, 0);

        ui->employeeTableWidget->setCellWidget(rowCount, i + 1, qWidget);


        ui->employeeTableWidget->setRowHeight(rowCount, 30);
        rowCount++;
    }


}

/*SLOT 实现*/

void MainWindow::Exit() {
    company->saveToFile();
    exit(0);
}

void MainWindow::saveButton() {
    company->saveToFile();
}

void MainWindow::sortButton() {
    sortInfo->setCompany(company);

    sortInfo->load();
    sortInfo->exec();
}

void MainWindow::addButton() {
    //设置模式为添加
    userInfoDialog->setFlag(false);
    //加载数据
    User param;
    userInfoDialog->setUser(param);
    userInfoDialog->setCompany(company);
    userInfoDialog->load();
    userInfoDialog->exec();

    this->employTableWidgetLoad(company);
}

void MainWindow::updateButton() {

    //获得当前行数
    auto *btn = (QPushButton *) (sender());
    auto *w_parent = (QWidget *) btn->parent();
    int x = w_parent->frameGeometry().x();
    int y = w_parent->frameGeometry().y();
    QModelIndex index = ui->employeeTableWidget->indexAt(QPoint(x, y));
    int row = index.row();

    User param;
    param.SetId(ui->employeeTableWidget->item(row, 0)->text().toInt());
    for (int i = 0; i < UserInfoEnum::USERINFO_COUNT; i++) {
        param.SetInfo(UserInfoEnum(i), ui->employeeTableWidget->item(row, i + 1)->text());
    }

    //设置当前模式为更新
    userInfoDialog->setFlag(true);
    //传递数据
    userInfoDialog->setCompany(company);
    userInfoDialog->setUser(param);
    //加载数据
    userInfoDialog->load();
    userInfoDialog->exec();

    this->employTableWidgetLoad(company);
}

void MainWindow::deleteButton() {
    auto *btn = (QPushButton *) (sender());
    auto *w_parent = (QWidget *) btn->parent();
    int x = w_parent->frameGeometry().x();
    int y = w_parent->frameGeometry().y();
    QModelIndex index = ui->employeeTableWidget->indexAt(QPoint(x, y));
    int row = index.row();

    QTableWidgetItem *item = ui->employeeTableWidget->item(row, 0);

    int id = item->text().toInt();

    qDebug() << id;

    User param;
    param.SetId(id);

    company->deleteUserById(id);

    ui->employeeTableWidget->removeRow(row);

}

/*style*/

void SetBtnStyle(QPushButton *pBtn, const QString &clr) {
    QString style = QString(
            "QPushButton{min-height:18px;font-size:10px;color:rgb(255, 255, 255);background:rgba(%1,0.8);border:1px;border-radius:5px;padding:1px 1px;font-family:Microsoft YaHei;}"
            "QPushButton:hover{color:rgb(255, 255, 255);border-style:solid;background: rgba(%2,0.6);border-radius:5px;border:1px;font-family:Microsoft YaHei;}"
            "QPushButton:pressed{color:rgb(255, 255, 255);border-style:solid;border-radius:5px;background: rgba(%3,0.4);border:1px;font-family:Microsoft YaHei;}").arg(
            clr).arg(clr).arg(clr);
    pBtn->setStyleSheet(style);
}