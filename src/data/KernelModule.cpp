/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** KernelModule
*/

#include "KernelModule.hpp"

#include <fstream>
#include <iostream>

KernelModule::KernelModule()
{
    uname(&this->_info);
    getModuleData();
}

KernelModule::~KernelModule()
{
}

std::string KernelModule::seekOsName()
{
    const std::string path = "/etc/os-release";
    std::ifstream ifs(path);
    std::string name = "";
    std::string line;

    if (ifs) {
        while (std::getline(ifs, line)) {
            if (line.find("PRETTY_NAME=", 0) == 0) {
                name = line.substr(13, line.length() - 14);
                return name;
            }
        }
    } else
        std::cerr << "Could not open /etc/os-release" << std::endl;
    return "";
}

void KernelModule::getModuleData()
{
    this->_osName = this->seekOsName();
    this->_kernelVersion = std::string(this->_info.release);
}

const std::string &KernelModule::getKernelVersion() const
{
    return this->_kernelVersion;
}

const std::string &KernelModule::getOsName() const
{
    return this->_osName;
}
