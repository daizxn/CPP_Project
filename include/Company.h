//
// Created by dai on 2024/5/17.
//

#ifndef CPP_PROJECT_COMPANY_H
#define CPP_PROJECT_COMPANY_H


#include <fstream>
#include <QWidget>

#include "List/List.h"
#include "User.h"
#include "File.h"

class Company;

class Company :public QWidget{

Q_OBJECT
public:
    explicit Company(QWidget *parent= nullptr);
    explicit Company(int key = 0);

    explicit Company(const List<User> &userList, int key = 0);

    Company(const Company &company);

    void addUser(User &user);

    void deleteUserById(const int &id);

    void updateUser(int id, const User &user);

    Company selectUser(const User &param);

    User selectUserById(const int &id);

    void saveToFile(const std::string &filePath = DATA_PATH);

    void loadFromFile(const std::string &filePath = DATA_PATH);

    void sort();

    void sort(bool (*cmp)(User a, User b, List<User> param));

    friend std::ofstream &operator<<(std::ofstream &os, const Company &company);

    friend std::ifstream &operator>>(std::ifstream &is, Company &company);


private:
    int key{};
    List<User> userList;
signals:
};

#endif //CPP_PROJECT_COMPANY_H
