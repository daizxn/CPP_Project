//
// Created by dai on 2024/5/17.
//

#include "User.h"

#include <utility>

User::User(const QString &numbering, const QString &name, const QString &age, const QString &education,
           const QString &ethnic, const QString &specialized, const QString &job, const QString &department,
           const QString &position) {
    id=-1;
    Info[UserInfoEnum::Numbering] = numbering;
    Info[UserInfoEnum::Name] = name;
    Info[UserInfoEnum::Age] = age;
    Info[UserInfoEnum::Education] = education;
    Info[UserInfoEnum::Ethnic] = ethnic;
    Info[UserInfoEnum::Specialized] = specialized;
    Info[UserInfoEnum::Job] = job;
    Info[UserInfoEnum::department] = department;
    Info[UserInfoEnum::Position] = position;
}

User::User(const User &user) {
    this->id = user.id;
    for (int i = 0; i < UserInfoEnum::USERINFO_COUNT; i++) {
        this->Info[i] = user.Info[i];
    }
}

bool User::operator==(const User &user) const {
    if (this->id != user.id) {
        return false;
    }
    for (int i = 0; i < UserInfoEnum::USERINFO_COUNT; i++) {
        if (this->Info[i] != user.Info[i]) {
            return false;
        }
    }
    return true;
}

User &User::operator=(const User &user) {
    this->id = user.id;
    for (int i = 0; i < UserInfoEnum::USERINFO_COUNT; i++) {
        this->Info[i] = user.Info[i];
    }
    return *this;
}

std::ofstream &operator<<(std::ofstream &os, const User &user) {
    os << user.id << ' ';
    for (const auto &i: user.Info) {
        os << i.toStdString() << ' ';
    }
    return os;
}

std::ifstream &operator>>(std::ifstream &is, User &user) {
    std::string temp;
    is >> user.id;
    for (QString &i: user.Info) {

        is >> temp;
        i = QString::fromStdString(temp);
    }
    return is;
}

User& User::SetInfo(UserInfoEnum index, QString info) {
    Info[index] = info;
    return *this;
}

QString User::GetInfo(UserInfoEnum index) {
    return Info[index];
}

int User::GetId() const {
    return id;
}

User& User::SetId(int id) {
    this->id = id;
    return *this;
}

bool User::isMatch(const User &param) const {
    if(param.id!=-1 && id!=param.id)
        return false;
    for(int i=0;i<UserInfoEnum::USERINFO_COUNT;i++){
        if(param.Info[i]=="null")
            continue;
        if(Info[i]!=param.Info[i])
            return false;
    }
    return true;
}
