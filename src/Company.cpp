//
// Created by dai on 2024/5/17.
//

#include "Company.h"


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

void Company::deleteUser(const User &user) {
    userList.erase(user.GetId());
}

void Company::updateUser(int id, const User &user) {
    userList.set(id, user);
}

Company Company::selectUser(const User &param) {
    Company result(this->userList.select(param), this->key);
    return result;
}


