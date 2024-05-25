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

    void employTableWidgetLoad();

    ~MainWindow() override;



private slots:

    void Exit();
    /*每行button操作槽函数*/
    void saveButton();
    void updateButton();
    void deleteButton();
    void addButton();

private:
    Ui::MainWindow *ui;
    UserInfoDialog *userInfoDialog;

    Company *company;
};

void SetBtnStyle(QPushButton *pBtn, QString clr);
#endif //CPP_PROJECT_MAINWINDOW_H
