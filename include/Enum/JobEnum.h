//
// Created by dai on 2024/5/17.
//

#ifndef CPP_PROJECT_JOB_ENUM_H
#define CPP_PROJECT_JOB_ENUM_H

#include <QString>

enum JobEnum {
    AssistantEngineer,      //助理工程师
    JobEngineer,               //工程师
    SeniorEngineer,         //高级工程师
    ProfessorialEngineer,   //教授级高级工程师
    JOB_COUNT
};

const extern QString JobName_en[JobEnum::JOB_COUNT];
const extern QString JobName_zh[JobEnum::JOB_COUNT];

#endif //CPP_PROJECT_JOB_ENUM_H
