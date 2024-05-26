//
// Created by dai on 2024/5/25.
//

#ifndef CPP_PROJECT_SORTINFO_H
#define CPP_PROJECT_SORTINFO_H

#include <QDialog>
#include <QPair>
#include <QString>
#include <QComboBox>
#include <QMessageBox>

#include "Company.h"
#include "List/List.h"
#include "Enum/UserInfoEnum.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SortInfo; }
QT_END_NAMESPACE

class SortInfo : public QDialog {
Q_OBJECT

public:
    explicit SortInfo(QWidget *parent = nullptr);

    ~SortInfo() override;

    void load();

    void setCompany(Company *pCompany);

private slots:

    void addRule();

    void deleteRule();

    void no();

    void conformButton();

private:
    Ui::SortInfo *ui;

    Company *company{};

};


#endif //CPP_PROJECT_SORTINFO_H
