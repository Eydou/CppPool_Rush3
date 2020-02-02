/*
** EPITECH PROJECT, 2020
** 2020
** File description:
** user
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "UserModule.hpp"
#include <pwd.h>

UserModule::UserModule()
{
    getModuleData();
}

UserModule::~UserModule()
{
}

void UserModule::getModuleData()
{
    char hostname[HOST_NAME_MAX + 1];
    gethostname(hostname, HOST_NAME_MAX + 1);
    this->_HostName = hostname;
    struct passwd *pw;
    uid_t uid;
    uid = geteuid ();
    pw = getpwuid (uid);
    if (pw)
        this->_UserName = pw->pw_name;
}

const std::string &UserModule::getHost() const
{
    return this->_HostName;
}

const std::string &UserModule::getUser() const
{
    return this->_UserName;
}
