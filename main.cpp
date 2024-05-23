#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

#include "List/List.h"
#include "Enum/UserInfoEnum.h"
#include "Company.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return QApplication::exec();
}
