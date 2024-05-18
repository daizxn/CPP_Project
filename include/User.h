//
// Created by dai on 2024/5/17.
//

#ifndef CPP_PROJECT_USER_H
#define CPP_PROJECT_USER_H

#include <fstream>
#include <string>


#include "Enum/UserInfoEnum.h"

class User  {


public:
    explicit User(const QString &numbering = "null", const QString &name = "null", const QString &age = "null",
                  const QString &education = "null",
                  const QString &ethnic = "null", const QString &specialized = "null", const QString &job = "null",
                  const QString &department = "null",
                  const QString &position = "null");

    User(const User &user);

    bool operator==(const User &user) const;

    User &operator=(const User &user);

    friend std::ifstream &operator>>(std::ifstream &is, User &user);

    friend std::ofstream &operator<<(std::ofstream &os, const User &user);

    User& SetInfo(UserInfoEnum index, QString info);

    QString GetInfo(UserInfoEnum index);

    int GetId() const;

    User& SetId(int id);

    bool isMatch(const User &param) const;
private:
    int id=-1;
    QString Info[UserInfoEnum::USERINFO_COUNT];
};


#endif //CPP_PROJECT_USER_H
