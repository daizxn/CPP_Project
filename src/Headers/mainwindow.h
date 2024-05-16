//
// Created by dai on 2024/5/16.
//

#ifndef CPP_PROJECT_MAINWINDOW_H
#define CPP_PROJECT_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //CPP_PROJECT_MAINWINDOW_H
