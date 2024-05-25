//
// Created by dai on 2024/5/17.
//

#ifndef CPP_PROJECT_POSITION_ENUM_H
#define CPP_PROJECT_POSITION_ENUM_H

#include <QString>

enum PositionEnum{
    Employee = 0,        //员工
    PositionEngineer,    //工程师
    TeamLeader,          //团队领导
    DepartmentLeader,    //部门领导
    CompanyLeader,       //公司领导
    PositionEnum_COUNT
};

const extern QString PositionName_en[PositionEnum::PositionEnum_COUNT];
const extern QString PositionName_zh[PositionEnum::PositionEnum_COUNT];

#endif //CPP_PROJECT_POSITION_ENUM_H
