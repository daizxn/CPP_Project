#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

#include "List/List.h"
#include "Enum/UserInfoEnum.h"
#include "Company.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    QDebug()<<UserInfoName_en[UserInfoEnum::Numbering].toStdString();

    MainWindow w;
//w.show();



    Company company(0);
    company.loadFromFile();
    Company text= company.selectUser(User().SetInfo(UserInfoEnum::Numbering,"a"));
    text.deleteUserById(2);
    text.updateUser(0,text.selectUserById(0).SetInfo(UserInfoEnum::Numbering,"b"));
    text.addUser(User().SetInfo(UserInfoEnum::Numbering,"c"));
    text.saveToFile();
    return QApplication::exec();
}
