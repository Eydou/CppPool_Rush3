/*
** EPITECH PROJECT, 2020
** 2020
** File description:
** hoste
*/
#ifndef HOSTUSERNAME_HPP_
#define HOSTUSERNAME_HPP_

#include <string>
#include "IMonitorModule.hpp"

class UserModule : public virtual IMonitorModule {
    public:
        UserModule();
        ~UserModule();

        virtual void getModuleData() final;

        const std::string &getHost() const;
        const std::string &getUser() const;
    
    protected:
    private:
        std::string _HostName;
        std::string _UserName;
};

#endif 
