/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** KernelModule
*/

#ifndef KERNELMODULE_HPP_
#define KERNELMODULE_HPP_

#include "IMonitorModule.hpp"

#include <string>
#include <sys/utsname.h>

class KernelModule : public virtual IMonitorModule {
	public:
		KernelModule();
		~KernelModule();

        virtual void getModuleData() final;
        std::string seekOsName();

        const std::string &getKernelVersion() const;
        const std::string &getOsName() const;

	protected:
	private:
        struct utsname _info;
        std::string _kernelVersion;
        std::string _osName;
};

#endif /* !KERNELMODULE_HPP_ */
