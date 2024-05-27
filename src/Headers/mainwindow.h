//
// Created by dai on 2024/5/16.
//

#ifndef CPP_PROJECT_MAINWINDOW_H
#define CPP_PROJECT_MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QString>
#include <QDebug>

#include "Company.h"
#include "userinfodialog.h"
#include "sortinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);


    /*页面初始化加载*/
    void onLoad();

    void treeBarLoad();

    void employTableWidgetLoad(Company *data);

    void departmentTreeWidgetLoad(Company *data);

    void jobTreeWidgetLoad(Company *data);

    void queryLoad();//搜索初始化

    void pageLoad();//设置初始页面

    ~MainWindow() override;


private slots:

    void Exit();

    /*每行button操作槽函数*/
    void updateButton();


    void deleteButton();

    void addButton();

    void sortButton();

    void saveButton();

    /*搜索框*/
    void query();

    void checkFuzzyQuery();

    /*treeBar选择*/
    void treeBarClick();

private:
    Ui::MainWindow *ui;
    UserInfoDialog *userInfoDialog;
    SortInfo *sortInfo;
    bool onFuzzyQuery;

    Company *company;
};

void SetBtnStyle(QPushButton *pBtn, const QString &clr);

#endif //CPP_PROJECT_MAINWINDOW_H
