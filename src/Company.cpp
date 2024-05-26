//
// Created by dai on 2024/5/17.
//

#include "Company.h"

Company::Company(QWidget *parent) : QWidget(parent) {}

Company::Company(int key) : key(key) {}


Company::Company(const Company &company) {
    this->key = company.key;
    this->userList = company.userList;
}

Company::Company(const List<User> &userList, int key) {
    this->key = key;
    this->userList = userList;
}

void Company::addUser(User &user) {
    user.SetId(this->key++);
    userList.pushBack(user);
}

void Company::deleteUserById(const int &id) {
    userList.deleteById(id);
}
void Company::deleteUserByParam(const User param) {
    userList.deleteByParam(param);
}
void Company::updateUser(int id, const User &user) {
    userList.updateById(id,user);
}

Company Company::selectUser(const User &param) {
    this->userList.select(param);
    Company result(this->userList.select(param), this->key);
    return result;
}

User Company::selectUserById(const int &id) {
    User param;
    param.SetId(id);
    Company result(this->userList.select(param), this->key);
    return result.userList.get(0);
}

std::ifstream &operator>>(std::ifstream &is, Company &company) {
    is >> company.key;
    User user;
    while (is>>user) {

        company.userList.pushBack(user);
    }
    return is;
}

std::ofstream &operator<<(std::ofstream &os, const Company &company) {
    os << company.key;
    os << company.userList;
    return os;
}

void Company::saveToFile(const std::string &filePath) {
    file::Write(*this, filePath);
}

void Company::loadFromFile(const std::string &filePath) {
    file::Read(*this, filePath);
}

int Company::getSize() {
    return userList.getSize();
}

void Company::sort(QPair<UserInfoEnum,int> *rules,int ruleCount){
    userList.sort(rules,ruleCount);
}

