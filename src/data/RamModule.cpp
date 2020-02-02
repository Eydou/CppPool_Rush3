/*
** EPITECH PROJECT, 2020
** 2020
** File description:
** ram
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "RamModule.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>

RamModule::RamModule()
{
    getModuleData();
}

RamModule::~RamModule()
{
}

void RamModule::getModuleData()
{
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    std::string name;
    this->_RamSize = pages * page_size;
    std::ifstream file("/proc/meminfo");
    std::string ram;

    getline(file, ram);
    name = ram.substr(10, ram.length() - 13);
    this->_RamSize = atoi(name.c_str());

    getline(file, ram);
    name = ram.substr(13, ram.length() - 16);
    this->_RamAvail = atoi(name.c_str());

    getline(file, ram);
    name = ram.substr(9, ram.length() - 12);
    this->_RamUsed = this->_RamSize - this->_RamAvail; 
}

int RamModule::getRamSize() const
{
    return this->_RamSize;
}

int RamModule::getRamUsed() const
{
    return this->_RamUsed;
}

int RamModule::getRamAvail() const
{
    return this->_RamAvail;
}
