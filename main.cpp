#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

#include "List/List.h"
#include "Enum/UserInfoEnum.h"



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    QDebug()<<UserInfoName_en[UserInfoEnum::Numbering].toStdString();

    MainWindow w;
    w.show();

    return QApplication::exec();
}
