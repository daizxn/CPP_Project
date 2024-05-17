//
// Created by dai on 2024/5/17.
//

#ifndef CPP_PROJECT_DEPARTMENT_ENUM_H
#define CPP_PROJECT_DEPARTMENT_ENUM_H

#include <QString>

enum DepartmentEnum {
    Personnel = 0,        //人事部
    Technology,         //技术部
    Logistics,          //后勤部
    Information,        //信息部
    DEPARTMENT_COUNT
};

const extern QString DepartmentName_en[DepartmentEnum::DEPARTMENT_COUNT];
const extern QString DepartmentName_zh[DepartmentEnum::DEPARTMENT_COUNT];

#endif //CPP_PROJECT_DEPARTMENT_ENUM_H
