//
// Created by dai on 2024/5/18.
//

#ifndef CPP_PROJECT_FILE_H
#define CPP_PROJECT_FILE_H


#include <fstream>
#include <iostream>
#include <QFile>

#include "config.h"

namespace file {

    template<typename T>
    void Write(T data, const std::string &path = DATA_PATH) {
        std::ofstream ofs;
        ofs.open(path, std::ios::out | std::ios::trunc);
        if (!ofs.is_open()) {
            std::cout << "File open failed" << std::endl;
        }
        ofs << data;
        ofs.close();
    }

    template<typename T>
    void Read(T &data, const std::string &path = DATA_PATH) {
        std::ifstream ifs;
        ifs.open(path);
        if (!ifs.is_open()) {
            throw std::runtime_error("File open failed");
        }
        while (ifs>>data);//读取文件
        ifs.close();
    }
}


#endif //CPP_PROJECT_FILE_H
