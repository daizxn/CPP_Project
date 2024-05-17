//
// Created by dai on 2024/5/17.
//

#ifndef CPP_PROJECT_USER_H
#define CPP_PROJECT_USER_H

#include "Enum/UserInfoEnum.h"

class User {
public:
    explicit User(const QString &numbering = "", const QString &name = "", const QString &age = "",
                  const QString &education = "",
                  const QString &ethnic = "", const QString &specialized = "", const QString &job = "",
                  const QString &department = "",
                  const QString &position = "");

    bool operator==(const User &user) const;



    void SetInfo(UserInfoEnum index, QString info);

    QString GetInfo(UserInfoEnum index);

private:
    QString Info[UserInfoEnum::USERINFO_COUNT];
};


#endif //CPP_PROJECT_USER_H
