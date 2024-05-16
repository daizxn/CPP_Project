//
// Created by dai on 2024/5/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "Forms/ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);


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

MainWindow::~MainWindow() {
    delete ui;
}
