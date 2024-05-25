//
// Created by dai on 2024/5/16.
//

#ifndef CPP_PROJECT_USERINFO_ENUM_H
#define CPP_PROJECT_USERINFO_ENUM_H

#include <QString>

enum UserInfoEnum {
    Numbering = 0,        //编号
    Name,               //姓名
    Age,                //年龄
    Education,          //受教育程度
    Ethnic,             //民族
    Specialized,        //专业
    Job,                //职称
    Department,         //部门
    Position,           //职务
    USERINFO_COUNT
};

const extern QString UserInfoName_en[UserInfoEnum::USERINFO_COUNT];
const extern QString UserInfoName_zh[UserInfoEnum::USERINFO_COUNT];

#endif //CPP_PROJECT_USERINFO_ENUM_H
