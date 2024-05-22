//
// Created by dai on 2024/5/16.
//

#ifndef CPP_PROJECT_MAINWINDOW_H
#define CPP_PROJECT_MAINWINDOW_H

#include <QMainWindow>
#include "Company.h"

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

    ~MainWindow() override;

private slots:
    void Exit();

private:
    Ui::MainWindow *ui;
    Company* company;
};


#endif //CPP_PROJECT_MAINWINDOW_H
