/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TimeModule
*/

#include "TimeModule.hpp"

TimeModule::TimeModule()
{
    this->getModuleData();
}

TimeModule::~TimeModule()
{
}

void TimeModule::getModuleData()
{
    time_t now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    this->_timeString = buf;
}

const std::string &TimeModule::getDateTime() const
{
    return this->_timeString;
}