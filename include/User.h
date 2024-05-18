//
// Created by dai on 2024/5/17.
//

#ifndef CPP_PROJECT_USER_H
#define CPP_PROJECT_USER_H

#include <fstream>
#include <string>
#include <QWidget>

#include "Enum/UserInfoEnum.h"

class User : public QWidget {
Q_OBJECT

public:
    explicit User(const QString &numbering = "", const QString &name = "", const QString &age = "",
                  const QString &education = "",
                  const QString &ethnic = "", const QString &specialized = "", const QString &job = "",
                  const QString &department = "",
                  const QString &position = "");

    User(const User &user);

    bool operator==(const User &user) const;

    User &operator=(const User &user);

    friend std::ifstream &operator>>(std::ifstream &is, User &user);

    friend std::ofstream &operator<<(std::ofstream &os, const User &user);

    void SetInfo(UserInfoEnum index, QString info);

    QString GetInfo(UserInfoEnum index);

    int GetId() const;

    void SetId(int id);

    bool isMatch(const User &param) const;
private:
    int id;
    QString Info[UserInfoEnum::USERINFO_COUNT];
};


#endif //CPP_PROJECT_USER_H
