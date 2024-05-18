//
// Created by dai on 2024/5/17.
//

#ifndef CPP_PROJECT_COMPANY_H
#define CPP_PROJECT_COMPANY_H

#include <QWidget>

#include "List/List.h"
#include "User.h"

class Company : public QWidget {
Q_OBJECT

public:
    explicit Company(int key = 0);
    Company(const List<User>& userList, int key = 0);
    Company(const Company &company);

    void addUser(User &user);

    void deleteUser(const User &user);

    void updateUser(int id, const User &user);

    Company selectUser(const User &param);

    void saveToFile(const std::string &filePath);

    void loadFromFile(const std::string &filePath);

    void sort();

    void sort(bool (*cmp)(User a, User b, List<User> param));

private:
    int key;
    List<User> userList;

};

#endif //CPP_PROJECT_COMPANY_H
