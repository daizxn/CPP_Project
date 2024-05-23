//
// Created by dai on 2024/5/23.
//

#ifndef CPP_PROJECT_USERUPDATA_H
#define CPP_PROJECT_USERUPDATA_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class userUpdata; }
QT_END_NAMESPACE

class userUpdata : public QWidget {
Q_OBJECT

public:
    explicit userUpdata(QWidget *parent = nullptr);

    ~userUpdata() override;

private:
    Ui::userUpdata *ui;
};


#endif //CPP_PROJECT_USERUPDATA_H
