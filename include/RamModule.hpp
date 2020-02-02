/*
** EPITECH PROJECT, 2020
** 2020
** File description:
** ram
*/
#ifndef RAMINFO_HPP_
#define RAMINFO_HPP_

#include <string>
#include "IMonitorModule.hpp"

class RamModule : public virtual IMonitorModule {
public:
    RamModule();
    ~RamModule();

    virtual void getModuleData() final;

    int getRamSize() const;
    int getRamUsed() const;
    int getRamAvail() const;

protected:
private:
    int _RamSize;
    int _RamUsed;
    int _RamAvail;
};

#endif

